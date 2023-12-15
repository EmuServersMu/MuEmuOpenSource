#include "StdAfx.h"
#if SKYBOX 
#include "SkyBox.h"
#include "ToolKit.h"
#include "Import.h"
#include "glaux.h"
#include "Defines.h"
#include "Util.h"

int IsSky = GetPrivateProfileIntA("Graphics", "SkyBox", 1, "./Settings.ini");
int IsTim = GetPrivateProfileIntA("Graphics", "DayNight", 1, "./Settings.ini");


cSkyBox gSkyBox;

cSkyBox::cSkyBox()
{
    SkyDisplayInitialized = false;
}

cSkyBox::~cSkyBox()
{
}

void cSkyBox::ChangeSky()
{
    SYSTEMTIME sm;
    GetLocalTime(&sm);
    // ----
    int hourstate = sm.wHour % 2;
    int secondstate = sm.wSecond;
    float minutestate = (float)sm.wMinute / 60.0f;
    // ----
    if (hourstate == 0)
    {
        SkyColor.R = minutestate;
        SkyColor.G = minutestate;
        SkyColor.B = minutestate;
    }
    else
    {
        SkyColor.R = 1.0f - minutestate;
        SkyColor.G = 1.0f - minutestate;
        SkyColor.B = 1.0f - minutestate;
    }
}

void cSkyBox::GetCamCoords(double* x_cam, double* y_cam, double* z_cam)
{
    double m[16];
    glGetDoublev(GL_MODELVIEW_MATRIX, m);
    *x_cam = -m[12] * m[0] - m[13] * m[1] - m[14] * m[2];
    *y_cam = -m[12] * m[4] - m[13] * m[5] - m[14] * m[6];
    *z_cam = -m[12] * m[8] - m[13] * m[9] - m[14] * m[10];

}

void CALLBACK SkyTimerProc(HWND hwnd, UINT uMsg, UINT_PTR idEvent, DWORD dwTime)
{
    gSkyBox.ChangeSky();
}

void cSkyBox::InitDisplay()
{
    if (IsSky)
    {
        sprintf_s(this->TexturePath, "%s", SKY_NULL_TEXTURE);
        if (!ToolKit.FileExists(this->TexturePath))
        {
            MessageBox(0, "Cannot find Null.bmp", "Error", MB_OK | MB_ICONERROR);
            ExitProcess(0);
        }
        // ----
        AUX_RGBImageRec* images[MAX_MAP_SKY][MAX_SKY_FACES];
        AUX_RGBImageRec* blankimage = auxDIBImageLoad(this->TexturePath);
        // ----
        try
        {
            for (int i = 0; i < MAX_MAP_SKY; i++)
            {
                for (int j = 0; j < MAX_SKY_FACES; j++)
                {
                    images[i][j] = blankimage;
                }

                sprintf_s(this->TexturePath, SKY_BACK_TEXTURE, i + 1);
                if (ToolKit.FileExists(this->TexturePath))
                    images[i][0] = auxDIBImageLoad(this->TexturePath);
                sprintf_s(this->TexturePath, SKY_BOTTOM_TEXTURE, i + 1);
                if (ToolKit.FileExists(this->TexturePath))
                    images[i][1] = auxDIBImageLoad(this->TexturePath);
                sprintf_s(this->TexturePath, SKY_FRONT_TEXTURE, i + 1);
                if (ToolKit.FileExists(this->TexturePath))
                    images[i][2] = auxDIBImageLoad(this->TexturePath);
                sprintf_s(this->TexturePath, SKY_LEFT_TEXTURE, i + 1);
                if (ToolKit.FileExists(this->TexturePath))
                    images[i][3] = auxDIBImageLoad(this->TexturePath);
                sprintf_s(this->TexturePath, SKY_RIGHT_TEXTURE, i + 1);
                if (ToolKit.FileExists(this->TexturePath))
                    images[i][4] = auxDIBImageLoad(this->TexturePath);
                sprintf_s(this->TexturePath, SKY_TOP_TEXTURE, i + 1);
                if (ToolKit.FileExists(this->TexturePath))
                    images[i][5] = auxDIBImageLoad(this->TexturePath);
            }
        }
        catch (...) {}

        for (int i = 0; i < MAX_MAP_SKY; i++)
        {
            for (int j = 0; j < MAX_SKY_FACES; j++)
            {
                glGenTextures(1, &this->uTextures[i][j]);
                glBindTexture(GL_TEXTURE_2D, this->uTextures[i][j]);
                glPixelStorei(GL_UNPACK_ALIGNMENT, 1);
                glTexImage2D(GL_TEXTURE_2D, 0, 3, images[i][j]->sizeX, images[i][j]->sizeY, 0, GL_RGB, GL_UNSIGNED_BYTE, images[i][j]->data);
                glTexParameteri(GL_TEXTURE_2D, GL_TEXTURE_MIN_FILTER, GL_LINEAR);
                glTexParameteri(GL_TEXTURE_2D, GL_TEXTURE_MAG_FILTER, GL_LINEAR);
            }
        }
        // ----
        SkyColor.R = 1.0f;
        SkyColor.G = 1.0f;
        SkyColor.B = 1.0f;
        // ----
        if (IsTim != 0)
        {
            SetTimer(pGameWindow, 2, 5000, (TIMERPROC)SkyTimerProc);
            ChangeSky();
        }
    }
    // ----
    this->SkyDisplayInitialized = true;
}

bool cSkyBox::CanDrawSky()
{
    sprintf_s(this->TexturePath, SKY_TOP_TEXTURE, pMapNumber + 1);
    // ----
    if (ToolKit.FileExists(this->TexturePath))
    {
        return true;
    }

    return false;
}

bool cSkyBox::SpecialMaps()
{
    if (pMapNumber == Vulcanus || pMapNumber == Raklion || pMapNumber == RaklionBoss || pMapNumber == Calmness || pMapNumber == Elbeland)
    {
        return true;
    }

    return false;
}

bool cSkyBox::EventMaps()
{
    if (pMapNumber == Icarus || pMapNumber == Kalima1 || pMapNumber == Kalima2 || pMapNumber == Kalima3 || pMapNumber == Kalima4 || pMapNumber == Kalima5 || pMapNumber == Kalima6 || pMapNumber == Kalima7)
    {
        return true;
    }

    return false;
}

void cSkyBox::Display()
{
    pSkyHook();
    // ----
    if (pPlayerState == GameProcess && gSkyBox.EventMaps() == false)
    {
        if (!gSkyBox.SkyDisplayInitialized)
            gSkyBox.InitDisplay();

        if (IsSky && gSkyBox.CanDrawSky())
        {
            double x_cam, y_cam, z_cam;
            gSkyBox.GetCamCoords(&x_cam, &y_cam, &z_cam);

            pSetBlend(1);
            glColor3d(gSkyBox.SkyColor.R, gSkyBox.SkyColor.G, gSkyBox.SkyColor.B);

            glBindTexture(GL_TEXTURE_2D, gSkyBox.uTextures[pMapNumber][0]);
            glBegin(GL_QUADS);
            //BACK
            glTexCoord2f(0.0f, 1.0f); glVertex3d(x_cam - 3500, y_cam - 3500, 1500);
            glTexCoord2f(1.0f, 1.0f); glVertex3d(x_cam + 3500, y_cam - 3500, 1500);
            glTexCoord2f(1.0f, 0.0f); glVertex3d(x_cam + 3500, y_cam - 3500, 0);
            glTexCoord2f(0.0f, 0.0f); glVertex3d(x_cam - 3500, y_cam - 3500, 0);
            glEnd();

            if (gSkyBox.SpecialMaps() == true)
            {
                glBindTexture(GL_TEXTURE_2D, gSkyBox.uTextures[pMapNumber][1]);
                glBegin(GL_QUADS);

                //BOTTOM
                glTexCoord2f(1.0f, 1.0f); glVertex3d(x_cam - 3500, y_cam + 3500, -1);
                glTexCoord2f(0.0f, 1.0f); glVertex3d(x_cam + 3500, y_cam + 3500, -1);
                glTexCoord2f(0.0f, 0.0f); glVertex3d(x_cam + 3500, y_cam - 3500, -1);
                glTexCoord2f(1.0f, 0.0f); glVertex3d(x_cam - 3500, y_cam - 3500, -1);
                glEnd();
            }
            else
            {
                glBindTexture(GL_TEXTURE_2D, gSkyBox.uTextures[pMapNumber][1]);
                glBegin(GL_QUADS);

                //BOTTOM
                glTexCoord2f(1.0f, 1.0f); glVertex3d(x_cam - 3500, y_cam + 3500, 0);
                glTexCoord2f(0.0f, 1.0f); glVertex3d(x_cam + 3500, y_cam + 3500, 0);
                glTexCoord2f(0.0f, 0.0f); glVertex3d(x_cam + 3500, y_cam - 3500, 0);
                glTexCoord2f(1.0f, 0.0f); glVertex3d(x_cam - 3500, y_cam - 3500, 0);
                glEnd();
            }

            glBindTexture(GL_TEXTURE_2D, gSkyBox.uTextures[pMapNumber][2]);
            glBegin(GL_QUADS);
            //FRONT
            glTexCoord2f(1.0f, 1.0f); glVertex3d(x_cam - 3500, y_cam + 3500, 1500);
            glTexCoord2f(0.0f, 1.0f); glVertex3d(x_cam + 3500, y_cam + 3500, 1500);
            glTexCoord2f(0.0f, 0.0f); glVertex3d(x_cam + 3500, y_cam + 3500, 0);
            glTexCoord2f(1.0f, 0.0f); glVertex3d(x_cam - 3500, y_cam + 3500, 0);
            glEnd();

            glBindTexture(GL_TEXTURE_2D, gSkyBox.uTextures[pMapNumber][3]);
            glBegin(GL_QUADS);
            //LEFT
            glTexCoord2f(1.0f, 1.0f); glVertex3d(x_cam - 3500, y_cam - 3500, 1500);
            glTexCoord2f(0.0f, 1.0f); glVertex3d(x_cam - 3500, y_cam + 3500, 1500);
            glTexCoord2f(0.0f, 0.0f); glVertex3d(x_cam - 3500, y_cam + 3500, 0);
            glTexCoord2f(1.0f, 0.0f); glVertex3d(x_cam - 3500, y_cam - 3500, 0);
            glEnd();

            glBindTexture(GL_TEXTURE_2D, gSkyBox.uTextures[pMapNumber][4]);
            glBegin(GL_QUADS);
            //RIGHT
            glTexCoord2f(0.0f, 1.0f); glVertex3d(x_cam + 3500, y_cam - 3500, 1500);
            glTexCoord2f(1.0f, 1.0f); glVertex3d(x_cam + 3500, y_cam + 3500, 1500);
            glTexCoord2f(1.0f, 0.0f); glVertex3d(x_cam + 3500, y_cam + 3500, 0);
            glTexCoord2f(0.0f, 0.0f); glVertex3d(x_cam + 3500, y_cam - 3500, 0);
            glEnd();

            glBindTexture(GL_TEXTURE_2D, gSkyBox.uTextures[pMapNumber][5]);
            glBegin(GL_QUADS);
            //TOP
            glTexCoord2f(1.0f, 0.0f); glVertex3d(x_cam - 3500, y_cam + 3500, 1500);
            glTexCoord2f(0.0f, 0.0f); glVertex3d(x_cam + 3500, y_cam + 3500, 1500);
            glTexCoord2f(0.0f, 1.0f); glVertex3d(x_cam + 3500, y_cam - 3500, 1500);
            glTexCoord2f(1.0f, 1.0f); glVertex3d(x_cam - 3500, y_cam - 3500, 1500);
            glEnd();

            pGLSwitch();
        }
    }
}

void cSkyBox::Load()
{
    if (IsSky == SkyOn)
    {
        SetCompleteHook(0xE8, oDisplay, (DWORD)&Display);
    }
}
#endif
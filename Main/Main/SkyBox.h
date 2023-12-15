#pragma once
#if SKYBOX 
#ifndef __SKYBOX_H__
#define __SKYBOX_H__


#include "StdAfx.h"

#include <gl\gl.h>
//#include <gl\glu.h>
#include <tlhelp32.h>

#pragma comment(lib,"OpenGL32.lib")
#pragma comment(lib,"GLu32.lib")
#pragma comment(lib,"GLaux.lib")
#pragma comment(lib,"ADVAPI32.lib")
#pragma comment(lib,"Gdi32.lib")
#pragma comment(lib,"winmm.lib")
#pragma comment(lib,"User32.lib")

#define MAX_SKY_FACES        6
#define MAX_MAP_SKY            100

#define SKY_NULL_TEXTURE    ".\\Data\\Custom\\Sky\\Null.bmp"
#define SKY_BACK_TEXTURE    ".\\Data\\Custom\\Sky\\World%d\\Back.bmp"
#define SKY_BOTTOM_TEXTURE    ".\\Data\\Custom\\Sky\\World%d\\Bottom.bmp"
#define SKY_FRONT_TEXTURE    ".\\Data\\Custom\\Sky\\World%d\\Front.bmp"
#define SKY_LEFT_TEXTURE    ".\\Data\\Custom\\Sky\\World%d\\Left.bmp"
#define SKY_RIGHT_TEXTURE    ".\\Data\\Custom\\Sky\\World%d\\Right.bmp"
#define SKY_TOP_TEXTURE        ".\\Data\\Custom\\Sky\\World%d\\Top.bmp"

enum eSkyState
{
    SkyOff = 0,
    SkyOn = 1,
};

#define oDisplay                        0x004D9AB7
#define pSkyHook                        ((void(__cdecl*)())0x005B9260)


class cSkyBox
{
public:
    cSkyBox();
    virtual ~cSkyBox();
    // ----
    bool SkyDisplayInitialized;
    // ----
    struct SkyStruct
    {
        float R;
        float G;
        float B;
    } Sky;
    // ----
    SkyStruct SkyColor;
    // ----
    unsigned int uTextures[MAX_MAP_SKY][MAX_SKY_FACES];
    // ----
    void Load();
    void ChangeSky();
    void GetCamCoords(double* x_cam, double* y_cam, double* z_cam);
    void InitDisplay();
    bool CanDrawSky();
    bool SpecialMaps();
    bool EventMaps();
    static void Display();
    // ----
private:
    char TexturePath[256];
};

extern cSkyBox gSkyBox;

#endif
#endif
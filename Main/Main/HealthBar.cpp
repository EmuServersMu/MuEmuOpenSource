#include "stdafx.h"
#include "CustomRankUser.h"
#include "Defines.h"
#include "HealthBar.h"
#include "Interface.h"
#include "User.h"
#include "Util.h"
#include "Object.h"
#include "Protect.h"
#include "Import.h"

NEW_HEALTH_BAR gNewHealthBar[MAX_MAIN_VIEWPORT];

void ClearNewHealthBar() // OK
{
	for(int n=0;n < MAX_MAIN_VIEWPORT;n++)
	{
		gNewHealthBar[n].index = 0xFFFF;
		gNewHealthBar[n].type = 0;
		gNewHealthBar[n].rate = 0;
		gNewHealthBar[n].rate2 = 0;
	}
}

void InsertNewHealthBar(WORD index,BYTE type,BYTE rate,BYTE rate2) // OK
{
	for(int n=0;n < MAX_MAIN_VIEWPORT;n++)
	{
		if(gNewHealthBar[n].index == 0xFFFF)
		{
			gNewHealthBar[n].index = index;
			gNewHealthBar[n].type = type;
			gNewHealthBar[n].rate = rate;
			gNewHealthBar[n].rate2 = rate2;
			return;
		}
	}
}

NEW_HEALTH_BAR* GetNewHealthBar(WORD index,BYTE type) // OK
{
	for(int n=0;n < MAX_MAIN_VIEWPORT;n++)
	{
		if(gNewHealthBar[n].index != 0xFFFF)
		{
			if(gNewHealthBar[n].index == index && gNewHealthBar[n].type == type)
			{
				return &gNewHealthBar[n];
			}
		}
	}

	return 0;
}

void DrawNewHealthBar() // OK
{

	int PosX, PosY, LifeProgress, ShieldProgress;
	float LifeBarWidth = 40.0f;
	char LifeDisplay[25];
	VAngle Angle;

	if (gProtect.m_MainInfo.DisablePartyHpBar == 1)
	{
		if (pPartyMemberCount > 0)
		{
			for (int j = 0; j < pPartyMemberCount; j++)
			{

				signed int PartyNummber = *((DWORD*)&pPartyListStruct + 8 * j + 7);

				//lpViewObj lpObj	= &*(ObjectPreview*)pGetPreviewStruct(pPreviewThis(),PartyNummber);

				DWORD ViewportAddress = ((DWORD(__thiscall*)(void*,DWORD))0x0096A4C0)(((void*(*)())0x00402BC0)(),PartyNummber);

				if (ViewportAddress)
				{
					Angle.X = *(float*)(ViewportAddress+0x404);

					Angle.Y = *(float*)(ViewportAddress+0x408);

					Angle.Z = *(float*)(ViewportAddress+0x40C) + *(float*)(ViewportAddress+0x3E8) + 100.0f;

					pGetPosFromAngle(&Angle, &PosX, &PosY);

					pDrawImage(30019, (float)(PosX - 8), (float)(PosY - 32), 24.0, 24.0,0.0, 0.40000001, 1.4, 1.4, 1, 1, 0.0);

				}
			}
		}
	}
	else if (gProtect.m_MainInfo.DisablePartyHpBar == 2)
	{

	}
	else
	{
		((void(*)())0x005BA770)();
	}
	

	for(int n=0;n < MAX_MAIN_VIEWPORT;n++)
	{
		DWORD ViewportAddress = ((DWORD(__thiscall*)(void*,DWORD))0x0096A4C0)(((void*(*)())0x00402BC0)(),n);

		gObjUser.m_Logo[n].Active = 0;

		if(!ViewportAddress)
		{
			continue;
		}

		if(*(BYTE*)(ViewportAddress+0x30C) == 0)
		{
			continue;
		}

		Angle.X = *(float*)(ViewportAddress+0x404);

		Angle.Y = *(float*)(ViewportAddress+0x408);

		Angle.Z = *(float*)(ViewportAddress+0x40C) + *(float*)(ViewportAddress+0x3E8) + 100.0f;

		pGetPosFromAngle(&Angle, &PosX, &PosY);

		if (*(BYTE*)(ViewportAddress+0x320) == 1) //Check User Type
        {
           	gObjUser.m_Logo[n].Active = 1;
			gObjUser.m_Logo[n].X = PosX;
			gObjUser.m_Logo[n].Y = PosY;
        }

		PosX -= (int)floor(LifeBarWidth / (double)2.0);

		PosY -= 16;

		NEW_HEALTH_BAR* lpNewHealthBar = GetNewHealthBar(*(WORD*)(ViewportAddress+0x7E),*(BYTE*)(ViewportAddress+0x320));

		if(lpNewHealthBar == 0)
		{
			continue;
		}

		int LifePercent = lpNewHealthBar->rate/10;
		int ShieldPercent	= lpNewHealthBar->rate2/10;

		if((pCursorX >= PosX - 2) && ((float)pCursorX <= (float)PosX + LifeBarWidth + 2) && (pCursorY >= PosY - 2) && (pCursorY < PosY + 10))
		{

			if (ShieldPercent>0) 
			{
				wsprintf(LifeDisplay, "HP : %d0%% | SD : %d0%%", LifePercent, ShieldPercent);
				pSetTextColor(pTextThis(), 0xFF, 0xE6, 0xD2, 0xFF);
				pDrawText(pTextThis(), PosX - 20, PosY - 10, LifeDisplay, 0, 0, (LPINT)1, 0);
			}
			else
			{
				wsprintf(LifeDisplay, "HP : %d0%%", LifePercent);
				pSetTextColor(pTextThis(), 0xFF, 0xE6, 0xD2, 0xFF);
				pDrawText(pTextThis(), PosX, PosY - 8, LifeDisplay, 0, 0, (LPINT)1, 0);
			}

		}

		pSetBlend(true);

		float Tamanho = (ShieldPercent>0)?Tamanho=10.0f:Tamanho=5.0f;

		glColor4f(0.0, 0.0, 0.0, 0.5);
		pDrawBarForm((float)(PosX - 2), (float)(PosY + 1), LifeBarWidth + 4.0f, Tamanho, 0.0f, 0);
		pGLSwitchBlend();


		glColor3f(0.2f, 0.0, 0.0);
		pDrawBarForm((float)PosX, (float)PosY + 2, LifeBarWidth, 2.0f, 0.0, 0);

		if (ShieldPercent>0) 
		{
			glColor3f(0.22039216f, 0.239215688f, 0.0);
			pDrawBarForm((float)PosX, (float)PosY + 6, LifeBarWidth, 2.0f, 0.0, 0);
		}

		if(LifePercent > 10)
		{
			LifeProgress = 10;
		}
		else
		{
			LifeProgress = LifePercent;
		}

		if(ShieldPercent > 10)
		{
			ShieldProgress = 10;
		}
		else
		{
			ShieldProgress = ShieldPercent;
		}

		glColor3f(0.98039216f, 0.039215688f, 0.0);

		for(int i = 0; i < LifeProgress; i++)
		{
			pDrawBarForm((float)(i * 4 + PosX + 0), (float)(PosY + 2), 4.0, 2.0, 0.0, 0);
		}

		if (ShieldPercent>0) 
		{
			glColor3f(0.98039216f, 5.039215688f, 0.0);

			for(int i = 0; i < ShieldProgress; i++)
			{
				pDrawBarForm((float)(i * 4 + PosX + 0), (float)(PosY + 6), 4.0, 2.0, 0.0, 0);
			}
		}

		pGLSwitch();
	}

	gCustomRankUser.DrawInfo();

	pGLSwitch();

	glColor3f(1.0, 1.0, 1.0);
}


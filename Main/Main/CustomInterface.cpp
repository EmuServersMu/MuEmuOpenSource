#include "stdafx.h"
#include "CustomInterface.h"
#include "Defines.h"
#include "Import.h"
#include "Interface.h"
#include "Object.h"
#include "PrintPlayer.h"
#include "Protect.h"
#include "User.h"
#include "Util.h"

CCustomInterface gCustomInterface;

CCustomInterface::CCustomInterface()
{
	this->XkeyUp = 0;
}

void CCustomInterface::DrawInterfaceS8Buttom()
{

}

void CCustomInterface::DrawInterfaceS8Menu()
{
	if (gCustomInterface.XkeyUp == 1)
	{
		keybd_event(VkKeyScan('x'),0, KEYEVENTF_KEYUP,0); // ‘X’ Release
		gCustomInterface.XkeyUp = 0;
	}
	gInterface.Work();
}

void CCustomInterface::DrawInterfaceS8Skills(int a1)
{
	if (!gObjUser.lpPlayer || !gObjUser.lpViewPlayer)
		return;

	float ReduceHpRate = 0.0;
	float ReduceMpRate = 0.0;

	if ( (signed int)ViewMaxHP > 0 )
	ReduceHpRate = (double)(ViewMaxHP - ViewCurHP) / (double)ViewMaxHP;

	if ( (signed int)ViewMaxMP > 0 )
	ReduceMpRate = (double)(ViewMaxMP - ViewCurMP) / (double)ViewMaxMP;

	pDrawImage(31410, 475.0, 409.0, 65.0, 65.0, 0.0, 0.0, 0.68, 0.75, 1, 1, 0);

	pDrawImage(31410, 110.0, 409.0, 65.0, 65.0, 0.0, 0.0, 0.68, 0.75, 1, 1, 0);

	float Width		= 65.0;
	float Height	= 65.0;
	float PosX		= 110.0;
	float PosY		= 409.0;

	float FinalY	= ReduceHpRate * Height + PosY;
	float FinalH	= Height - ReduceHpRate * Height;

	float ScaleY	= (1.0 - ReduceHpRate) * Height / 90.0;
	float ScaleX	= Width / 90.0;
	float ReduceY	= ReduceHpRate * Height / 90.0;
	
	if (pCheckEffect((LPVOID)(*(DWORD*)0x7BC4F04+1260), 55) == 1)
	{
		pDrawImage(31418, PosX, FinalY, Width, FinalH, 0.0, ReduceY, ScaleX, ScaleY, 1, 1, 0);
	}
	else
	{
		pDrawImage(31412, PosX, FinalY, Width, FinalH, 0.0, ReduceY, ScaleX, ScaleY, 1, 1, 0);
	}
	
	sub_791000(PosX + 30.0, PosY + 23.0, (int)ViewCurHP, 0.8);

	sub_854EE0();

	if ( sub_790B10((int)PosX, (int)PosY, (int)Width, (int)Height) == 1 )
	{
		gInterface.DrawToolTip((int)PosX, 400, "Life: %d/%d",ViewCurHP,ViewMaxHP);
	}

	Width		= 65.0;
	PosX		= 475.0;
	Height		= 65.0;
	PosY		= 409.0;

	FinalY = ReduceMpRate * Height + PosY;
	FinalH = Height - ReduceMpRate * Height;

	ScaleY = (1.0 - ReduceMpRate) * Height / 90.0;
	ScaleX = Width / 90.0;
	ReduceY = ReduceMpRate * Height / 90.0;

	pDrawImage(31411, PosX, FinalY, Width, FinalH, 0.0, ReduceY, ScaleX, ScaleY, 1, 1, 0.0);

	sub_791000(PosX + 40.0, PosY + 23.0, (int)ViewCurMP, 0.8);

	if ( sub_790B10((int)PosX, (int)PosY, (int)Width, (int)Height) == 1 )
	{
		gInterface.DrawToolTip((int)PosX, 400, "Mana: %d/%d",ViewCurMP,ViewMaxMP);
	}

	pDrawImage(31409, 0.0, 406.0, 935.0,110.0,0,0,1.3,1.3,1,1,0);
	
	if ( sub_790B10((int)44.0, (int)449.0, (int)23.0, (int)24.0) == 1 )
	{
		pDrawImage(31420, 44.0, 449.0, 25.0,26.0,0,0,0.85,0.95,1,1,0);
		gInterface.DrawToolTip(48, 439, "Shop");
	}
	else
	{
		pDrawImage(31420, 44.0, 449.0, 23.0,24.0,0,0,0.85,0.95,1,1,0);
	}

	if ( sub_790B10((int)69.0, (int)449.0, (int)23.0, (int)24.0) == 1 )
	{
		pDrawImage(31423, 69.0, 449.0, 25.0,26.0,0,0,0.85,0.95,1,1,0);
		gInterface.DrawToolTip(71, 439, "Stats");
	}
	else
	{
		pDrawImage(31423, 69.0, 449.0, 23.0,24.0,0,0,0.85,0.95,1,1,0);
	}

	if ( sub_790B10((int)93.0, (int)449.0, (int)23.0, (int)24.0) == 1 )
	{
		pDrawImage(31425, 93.0, 450.0, 25.0,26.0,0,0,0.85,0.95,1,1,0);
		gInterface.DrawToolTip(92, 439, "Inventory");
	}
	else
	{
		pDrawImage(31425, 93.0, 450.0, 23.0,24.0,0,0,0.85,0.95,1,1,0);
	}

	if ( sub_790B10((int)541.0, (int)449.0, (int)23.0, (int)24.0) == 1 )
	{
		pDrawImage(31426, 541.0, 449.0, 25.0,26.0,0,0,0.85,0.95,1,1,0);
		gInterface.DrawToolTip(541, 439, "Quests");
	}
	else
	{
		pDrawImage(31426, 541.0, 449.0, 23.0,24.0,0,0,0.85,0.95,1,1,0);
	}

	if ( sub_790B10((int)566.0, (int)449.0, (int)23.0, (int)24.0) == 1 )
	{
		pDrawImage(31427, 566.0, 449.0, 25.0,26.0,0,0,0.85,0.95,1,1,0);
		gInterface.DrawToolTip(568, 439, "Friend");
	}
	else
	{
		pDrawImage(31427, 566.0, 449.0, 23.0,24.0,0,0,0.85,0.95,1,1,0);
	}

	if ( sub_790B10((int)591.0, (int)449.0, (int)23.0, (int)24.0) == 1 )
	{
		pDrawImage(31428, 591.0, 449.0, 25.0,26.0,0,0,0.85,0.95,1,1,0);
		gInterface.DrawToolTip(594, 439, "Menu");
	}
	else
	{
		pDrawImage(31428, 591.0, 449.0, 23.0,24.0,0,0,0.85,0.95,1,1,0);
	}

	//Show Skills
	int Struct = sub_861200((int)sub_861110());

	int SkillNum;
	int SkillPage;
	int SkillFast;
	int SkillMain; 

	if ( gObjUser.lpPlayer->MagicCount > 0 )
	{
		SkillNum = (*(BYTE*)(Struct + 20)) ? 6 : 1;

		PosX = 319.0;
		PosY = 444.0;

		for (int i = 0; i < 5; ++i)
		{
			PosX = PosX + 23.0;
			SkillPage = i + SkillNum;

			if ( i + SkillNum == 10 ) SkillPage = 0;

			DWORD Skill = *(DWORD*)(Struct + 4 * SkillPage + 24);

			if ( Skill != -1 && (Skill < 120 || Skill >= 124 || gObjUser.lpViewPlayer->Unknown676 ))
			{
				SkillFast = (SkillStruct + 88 * *(WORD*)(SkillList + 2 * Skill + 120));

				if ( !SkillFast || *(BYTE*)(SkillFast + 55) != 3 )
				{		
					if ( gObjUser.lpViewPlayer->ActiveMagic == Skill )
					{
						pDrawImage(31313, PosX-2.0, PosY-2.0, 21.0, 28.0, 0.0, 0.0, 1.0, 0.59, 1, 1, 0);
					}
					gCustomInterface.DrawInterfaceS8DrawSkill(Struct,Skill, PosX, PosY, 17.0, 24.0);
				}
			}
		}

		SkillMain = (SkillStruct + 88 * *(WORD*)(SkillList + 2 * gObjUser.lpViewPlayer->ActiveMagic + 120));

		if ( SkillMain && *(BYTE*)(SkillMain + 55) != 3 )
			gCustomInterface.DrawInterfaceS8DrawSkill(Struct,(int)gObjUser.lpViewPlayer->ActiveMagic, 316.0, 443.0, 17.0, 24.0);
	}
	
}

void CCustomInterface::DrawInterfaceS8HP()
{

}

void CCustomInterface::DrawInterfaceS8SD()
{
	float ReduceRate = 0.0;

	if ( (signed int)ViewMaxSD > 0 )
		ReduceRate = (double)(ViewMaxSD - ViewCurSD) / (double)ViewMaxSD;

		if (ReduceRate < 0)
			ReduceRate = 1.0;

	float Width		= 66.0;
	float Height	= 7.0;
	float PosX		= 185.0;
	float PosY		= 428.0;

	float FinalW	= Width - ReduceRate * Width;

	float FinalPosW	= ReduceRate * Width;

	glColor4f(0.7098, 0.48235, 0.0, 1.0);
	pDrawBarForm((float)(PosX)+FinalPosW, (float)(PosY), FinalW, Height, 0.0, 0);
	glColor4f(1.0, 1.0, 1.0, 1.0);

	sub_791000(PosX+53.0, PosY+0.5, ViewCurSD, 0.7);

	if ( sub_790B10(PosX, PosY, Width, Height) == 1 )
	{
		gInterface.DrawToolTip((int)PosX, (int)PosY-20, "SD: %d/%d",ViewCurSD,ViewMaxSD);
	}
}

void CCustomInterface::DrawInterfaceS8AG()
{
	float ReduceRate = 0.0;

	if ( (signed int)ViewMaxBP > 0 )
		ReduceRate = (double)(ViewMaxBP - ViewCurBP) / (double)ViewMaxBP;

		if (ReduceRate < 0)
			ReduceRate = 1.0;

	float Width		= 66.0;
	float Height	= 7.0;
	float PosX		= 407.0;
	float PosY		= 428.0;

	float FinalW	= Width - ReduceRate * Width;

	glColor4f(0.57255, 0.2, 0.67059, 1.0);
	pDrawBarForm((float)(PosX), (float)(PosY), FinalW, Height, 0.0f, 0);
	glColor4f(1.0, 1.0, 1.0, 1.0);

	sub_791000(PosX+15.0, PosY+0.5, ViewCurBP, 0.7);

	if ( sub_790B10(PosX, PosY, Width, Height) == 1 )
	{
		gInterface.DrawToolTip((int)PosX, (int)PosY-20, "AG: %d/%d",ViewCurBP,ViewMaxBP);
	}
}


void CCustomInterface::DrawInterfaceS8Exp()
{
	if (!gObjUser.lpPlayer || !gObjUser.lpViewPlayer)
		return;

	float ReduceRate	= 0.0;

	if(pIsMaster(gObjUser.lpPlayer->Class) && gObjUser.lpPlayer->Level >= 400 && pMasterExp > 0)
	{
		glColor3f(0.2f, 0.8f, 0.2f);

		long double PreviousExp = pMasterExp - (__int64)gCustomInterface.m_MasterLevelExperienceTable[pMasterLevel];
		long double TotalExp    = pMasterNextExp - (__int64)gCustomInterface.m_MasterLevelExperienceTable[pMasterLevel];

		if ( TotalExp > 0 )
			ReduceRate = (TotalExp - PreviousExp) / TotalExp;

		if (ReduceRate < 0)
			ReduceRate = 1.0;

		float Width		= 540.0;
		float Height	= 3.0;
		float PosX		= 65.0;
		float PosY		= 473.0;

		float FinalW	= Width - ReduceRate * Width;

		pDrawBarForm(PosX, PosY, FinalW, Height, 0.0, 0);
		sub_637A30();

		sub_791000(620.0, 469.0, (int)pMasterLevel, 0.8);

		glColor3f(1.0, 1.0, 1.0);

		if ( sub_790B10(PosX, PosY, Width, Height) == 1 )
		{
			gInterface.DrawToolTip((int)PosX+100,(int)PosY-15, "Experience: %I64u/%I64u",pMasterExp,pMasterNextExp);
		}
	}
	else
	{
		glColor3f(0.98039216f, 4.039215688f, 0.0);

		double PreviousExp = gObjUser.lpPlayer->Experience - gCustomInterface.gLevelExperience[gObjUser.lpPlayer->Level-1];
		double TotalExp    = gObjUser.lpPlayer->NextExperience - gCustomInterface.gLevelExperience[gObjUser.lpPlayer->Level-1];

		if ( TotalExp > 0 )
			ReduceRate = (TotalExp - PreviousExp) / TotalExp;

		if (ReduceRate < 0)
			ReduceRate = 1.0;

		float Width		= 540.0;
		float Height	= 3.0;
		float PosX		= 65.0;
		float PosY		= 473.0;

		float FinalW	= Width - ReduceRate * Width;

		pDrawBarForm(PosX, PosY, FinalW, Height, 0.0, 0);
		sub_637A30();

		sub_791000(620.0, 469.0, (int)gObjUser.lpPlayer->Level, 0.8);

		glColor3f(1.0, 1.0, 1.0);

		if ( sub_790B10(PosX, PosY, Width, Height) == 1 )
		{
			gInterface.DrawToolTip((int)PosX+100,(int)PosY-15, "Experience: %d/%d",gObjUser.lpPlayer->Experience,gObjUser.lpPlayer->NextExperience);
		}
	}
}

bool CCustomInterface::DrawInterfaceS8ChatMain(int a1)
{
  pDrawGUI(31279, 0.0, 365.0, 281.0, 47.0);
  return 1;
}

char CCustomInterface::DrawInterfaceS8ChatButtom(int a1, int a2, int a3, int *a4)
{
  float v7; // ST04_4@2
  float v9; // ST04_4@4
  float v11; // ST04_4@6
  char result; // al@7
  float v14; // ST04_4@8
  int v15; // [sp+24h] [bp-4h]@1

  a1 = sub_776CC0(a1);

  v15 = a1;

  float v4 = 370.0;
  float v5 = (double)(27 * *(DWORD*)(a1 + 104));

  gInterface.DrawToolTip(100,100, "Experience: %d",(int)*(DWORD*)(a1 + 104));

  pDrawGUI(*(DWORD*)(a1 + 104) + 31280, 370.0, 0.0, 27.0, 26.0);

  if ( *(BYTE*)(v15 + 108) )
  {
    v7 = (double)(*(DWORD*)(v15 + 20) + 114);
    pDrawGUI(31284, v7, 370.0, 27.0, 26.0);
  }
  if ( *(BYTE*)(v15 + 110) )
  {
    v9 = (double)(*(DWORD*)(v15 + 20) + 168);
    pDrawGUI(31286, v9, 370.0, 27.0, 26.0);
  }
  if ( *(BYTE*)(v15 + 109) )
  {
    v11 = (double)(*(DWORD*)(v15 + 20) + 141);
    pDrawGUI(31285, v11, 370.0, 27.0, 26.0);
  }
  result = *(BYTE*)(*(DWORD*)(v15 + 16) + 344);
  if ( result )
  {
    v14 = (double)(*(DWORD *)(v15 + 20) + 200);
    pDrawGUI(31287, v14, 370.0, 27.0, 26.0);
    sub_7798F0(v15 + 120, 0);
    result = sub_7798F0(v15 + 292, 0);
  }
  return result;
}

void CCustomInterface::DrawInterfaceS8FriendButtom()
{


}

void CCustomInterface::DrawInterfaceS8DrawSkill(int a1, int Skill,float PosX,float PosY,float Width,float Height)
{
	lpCharObj Character = &*(ObjectCharacter*)oUserObjectStruct_;

	//v31 = *(WORD*)(*(DWORD*)0x8128AC8 + 120 + (2 * Skill));

	unsigned __int16 v31 = gObjUser.lpPlayer->pMagicList[Skill];

	if ( v31 )
	{
		bool Disabled = 0;
		char v38 = *(BYTE*)(SkillStruct + 88 * v31 + 55);
		signed int v36 = *(WORD*)(SkillStruct + 88 * v31 + 72);

		if ( !sub_4AD0E0(v31))
			Disabled = 1;

		if ( !sub_5B89C0(v31) )
			Disabled = 1;

		if ( pCheckEffect((DWORD*)(0x7BC4F04 + 1260), 19) && v38 == 2 )
			Disabled = 1;

		if ( v31 == 47 && ((signed int)gObjUser.lpViewPlayer->PetSlot < 7829 || (signed int)gObjUser.lpViewPlayer->PetSlot > 7830) && gObjUser.lpViewPlayer->PetSlot != 7864 )
		{
			Disabled = 1;
		}

		if ( v31 == 47 && (gObjUser.lpViewPlayer->PetSlot == 7829 || gObjUser.lpViewPlayer->PetSlot == 7830 || gObjUser.lpViewPlayer->PetSlot == 7864) )
		{
			if ( ((signed int)Character->pEquipment[1].ItemID < 1536 || (signed int)Character->pEquipment[1].ItemID >= 2048) && ((signed int)Character->pEquipment[0].ItemID < 1536 || (signed int)Character->pEquipment[0].ItemID >= 2048) )
				Disabled = 1;
		}

		if (v31 >= 18 && v31 <= 23 && (gObjUser.lpViewPlayer->PetSlot == 7829 || gObjUser.lpViewPlayer->PetSlot == 7830 || gObjUser.lpViewPlayer->PetSlot == 7864) )
		{
			Disabled = 1;
		}

		if ( (v31 == 56 || v31 == 482) && (gObjUser.lpViewPlayer->PetSlot == 7829 || gObjUser.lpViewPlayer->PetSlot == 7830 || gObjUser.lpViewPlayer->PetSlot == 7864) )
		{
			Disabled = 1;
		}

		int TotalEnergy = ViewEnergy + ViewAddEnergy;

		pUserStat();

		if ( sub_4E8D80(v31, TotalEnergy, 0) )
			Disabled = 1;

		if ( v31 == 63 && pPartyMemberCount <= 0 )
			Disabled = 1;

		if ( v31 == 63 && (DG_MAP_RANGE(pMapNumber)) )
			Disabled = 1;

		if ( (v31 == 62 || v31 == 510 || v31 == 516 || v31 == 512) && (!Character->pEquipment[8].Durability || gObjUser.lpViewPlayer->PetSlot != 7831) )
		{
			Disabled = 1;
		}

		if ( v31 == 77 || v31 == 233 || v31 == 380 || v31 == 383 || v31 == 441 )
		{
			pUserStat();

			if ( sub_4E8D80(v31, TotalEnergy, 0) )
				Disabled = 1;

			if ( pCheckEffect((DWORD*)(0x7BC4F04 + 1260), 6) || pCheckEffect((DWORD*)(0x7BC4F04 + 1260), -113) || pCheckEffect((DWORD*)(0x7BC4F04 + 1260), 82) || pCheckEffect((DWORD*)(0x7BC4F04 + 1260), -118) || pCheckEffect((DWORD*)(0x7BC4F04 + 1260), -117) )
			{
				Disabled = 1;
			}
		}

		if ( v31 == 55 || v31 == 490 )
		{
			if ( (signed int)(unsigned __int16)(*(WORD*)(SkillList + 50) + *(WORD*)(SkillList + 24)) < 596 )
				Disabled = 1;

			signed int v28 = Character->pEquipment[1].ItemID;
			signed int v27 = Character->pEquipment[0].ItemID;

			if ( v27 == -1 || v27 >= 2560 && v27 < 3072 || v28 >= 2560 && v28 < 3072 )
				Disabled = 1;
		}

		if ( (v31 == 51 || v31 == 424) && (signed int)(unsigned __int16)(*(WORD*)(SkillList + 52) + *(WORD*)(SkillList + 26)) < 646 )
		{
			Disabled = 1;
		}

		if ( v31 == 41 || v31 == 330 || v31 == 481 || v31 == 332 )
		{
			signed int v26 = Character->pEquipment[1].ItemID;
			signed int v25 = Character->pEquipment[0].ItemID;

			if ( v25 == -1 || v25 >= 2560 && v25 < 3072 || v26 >= 2560 && v26 < 3072 )
			{
				Disabled = 1;
			}
		}

		if ( CC_MAP_RANGE(pMapNumber) == 1 )
		{
			if ( v31 == 62 || v31 == 49	|| v31 == 510 || v31 == 516 || v31 >= 120 && v31 <= 123 || v31 == 512 )
			{
				Disabled = 1;
			}
		}

		else if ( (v31 == 62 || v31 == 510 || v31 == 516 || v31 == 512) && !Character->pEquipment[8].Durability)
		{
			Disabled = 1;
		}

		int TotalLeadership = ViewLeadership + ViewAddLeadership;

		pUserStat();

		if ( sub_4E8D80(v31, TotalEnergy, TotalLeadership) )
			Disabled = 1;

		if ( !sub_5111D0(v31) )
			Disabled = 1;

		if ( sub_511110(v31, gObjUser.lpViewPlayer->PetSlot) )
			Disabled = 1;

		if ( sub_511290(Character->pEquipment[11].ItemID, Character->pEquipment[10].ItemID,	Character->pEquipment[11].Level, Character->pEquipment[10].Level) && *(BYTE*)(0x7BC4F04 + 19) & 7 == 6 ) // verificar
		{
			Disabled = 1;
		}

		float v34 = 0.0;
		float v39 = 0.0;
		int ImageType =  0;

		pUserStat();

		if ( !sub_4EAC90(v31) )
			Disabled = 1;

		pUserStat();

		if ( !sub_4EAC90(v31) )
			Disabled = 1;

		if ( v31 < 120 || v31 > 124 )
		{
			if ( v31 == 76 )
			{
				v34 = Width * 4.0 / 218.0;
				v39 = 0.0;
				ImageType = 1;
			}
			else if ( v31 < 214 || v31 > 217 )
			{
			if ( v31 < 219 || v31 > 220 )
			{
				if ( v31 == 218 )
				{
					v34 = Width * 10.0 / 218.0;
					v39 = Height * 3.0 / 219.0;
					ImageType = 3;
				}
				else if ( v31 < 221 || v31 > 222 )
				{
				if ( v31 < 223 || v31 > 224 )
				{
					if ( v31 == 225 )
					{
						v34 = Width * 11.0 / 218.0;
						v39 = Height * 3.0 / 219.0;
						ImageType = 3;
					}
					else if ( v31 == 232 )
					{
						v34 = Width * 7.0 / 218.0;
						v39 = Height * 2.0 / 219.0;
						ImageType = 3;
					}
					else if ( v31 != 523 )
					{
					switch ( v31 )
					{
						case 238:
							v34 = Width * 3.0 / 218.0;
							v39 = Height * 8.0 / 219.0;
							ImageType = 3;
						break;
						case 234:
							v34 = Width * 9.0 / 218.0;
							v39 = Height * 2.0 / 219.0;
							ImageType = 3;
						break;
						case 235:
							if ( !sub_587A80() )
								Disabled = 1;
							v34 = Width * 0.0 / 218.0;
							v39 = Height * 8.0 / 219.0;
							ImageType = 3;
						break;
						case 236:
							if ( (signed int)Character->pEquipment[0].ItemID == -1 || (signed int)Character->pEquipment[0].ItemID >= 2560 && (signed int)Character->pEquipment[0].ItemID < 3072 || (signed int)Character->pEquipment[1].ItemID >= 2560 && (signed int)Character->pEquipment[1].ItemID < 3072 )
								Disabled = 1;
							v34 = Width * 1.0 / 218.0;
							v39 = Height * 8.0 / 219.0;
							ImageType = 3;
						break;
						case 237:
							v34 = Width * 2.0 / 218.0;
							v39 = Height * 8.0 / 219.0;
							ImageType = 3;
						break;
						case 230:
							v34 = Width * 2.0 / 218.0;
							v39 = Height * 3.0 / 219.0;
							ImageType = 3;
						break;
						case 456:
							v34 = Width * 6.0 / 218.0;
							v39 = Height * 8.0 / 219.0;
							ImageType = 3;
						break;
						case 233:
							v34 = Width * 8.0 / 218.0;
							v39 = Height * 2.0 / 219.0;
							ImageType = 3;
						break;
						default:
						if ( v38 == 4 )
						{
							v34 = Width / 218.0 * (double)(v36 % 12);
							v39 = Height / 219.0 * (double)(v36 / 12 + 4);
							ImageType = 3;
						}
						else if ( v31 < 260 )
						{
							if ( v31 < 57 )
							{
								v34 = (double)((v31 - 1) % 8) * Width / 218.0;
								v39 = (double)((v31 - 1) / 8) * Height / 219.0;
								ImageType = 2;
							}
							else
							{
								v34 = (double)((v31 - 57) % 8) * Width / 218.0;
								v39 = (double)((v31 - 57) / 8) * Height / 219.0;
								ImageType = 3;
							}
						}
						else
						{
							v34 = (double)((v31 - 260) % 12) * Width / 218.0;
							v39 = (double)((v31 - 260) / 12) * Height / 219.0;
							ImageType = 4;
						}
						break;
					}
					}
				}
				else
				{
					v34 = (double)((v31 - 217) % 8) * Width / 218.0;
					v39 = Height * 3.0 / 219.0;
					ImageType = 3;
				}
				}
				else
				{
					v34 = (double)(v31 - 213) * Width / 218.0;
					v39 = Height * 3.0 / 219.0;
					ImageType = 3;
				}
			}
			else
			{
				v34 = (double)((v31 - 215) % 8) * Width / 218.0;
				v39 = Height * 3.0 / 219.0;
				ImageType = 3;
			}
			}
			else
			{
				v34 = (double)((v31 - 214) % 8) * Width / 218.0;
				v39 = Height * 3.0 / 219.0;
				ImageType = 3;
			}
		}
		else
		{
			v34 = (double)((v31 - 120) % 8) * Width / 218.0;
			v39 = (double)((v31 - 120) / 8) * Height / 219.0;
			ImageType = 1;
		}

		int SkillMaster = (SkillStruct + 88 * v31);

		if ( SkillMaster && *(BYTE*)(SkillMaster + 55) == 4 )
			ImageType = 5;

		int Image = 0;

		switch (ImageType)
		{
			case 1:
				Image = (Disabled) ? 31316 : 31310;
			break;
			case 2:
				Image = (Disabled) ? 31314 : 31308;
			break;
			case 3:
				Image = (Disabled) ? 31315 : 31309;
			break;
			case 4:
				Image = (Disabled) ? 31317 : 31311;
			break;
			case 5:
				Image = (Disabled) ? 31535 : 31534;
			break;
			default:
			break;
		}

		if (Image)
		{
			if ( SkillMaster && *(BYTE*)(SkillMaster + 55) == 4 )
			{
				pDrawImage(Image, PosX, PosY, Width, Height, Width / 436.0 * (double)(*(WORD*)(SkillMaster + 72) % 25), Height / 438.0 * (double)(*(WORD*)(SkillMaster + 72) / 25), Width / 436.0, Height / 438.0, 1, 1, 0.0);
			}
			else
			{
				pDrawImage(Image, PosX, PosY, Width, Height, v34, v39, Width / 218.0, Height / 219.0, 1, 1, 0.0);
			}
		}

		for ( int i = 0; i < 10; ++i )
		{
			if ( *(DWORD*)(a1 + 4 * i + 24) == Skill )
			{
				glColor3f(1.0, 0.89999998, 0.80000001);
				sub_791000(PosX + 14.0, PosY+14.0, i, 1.0);
				break;
			}
		}

		if ( (Skill != 262 && Skill != 265 && Skill != 264 && Skill != 558 && Skill != 560 || !Disabled)	&& Skill != 77 && Skill != 233 && Skill != 380 && Skill != 383 && Skill != 441 )
		{
			sub_814F30(Skill, PosX, PosY, Width, Height);
		}
	}

}

__declspec(naked) void CCustomInterface::DrawInterfaceS8ChatPosition1()
{
	static float ChatPosY1 = 365.0f;
	static DWORD ChatPos_buff1 = 0x007877D7;
	_asm
	{
	FLD DWORD PTR DS:[ChatPosY1]
	PUSH ECX
	FSTP DWORD PTR SS:[ESP]
	jmp [ChatPos_buff1]
	}
}

__declspec(naked) void CCustomInterface::DrawInterfaceS8ChatPosition2()
{
	static float ChatPosY2 = 365.0f;
	static DWORD ChatPos_buff2 = 0x0078782F;
	_asm
	{
	FLD DWORD PTR DS:[ChatPosY2]
	PUSH ECX
	FSTP DWORD PTR SS:[ESP]
	jmp [ChatPos_buff2]
	}
}

__declspec(naked) void CCustomInterface::DrawInterfaceS8ChatPosition3()
{
	static float ChatPosY3 = 365.0f;
	static DWORD ChatPos_buff3 = 0x00787878;
	_asm
	{
	FLD DWORD PTR DS:[ChatPosY3]
	PUSH ECX
	FSTP DWORD PTR SS:[ESP]
	jmp [ChatPos_buff3]
	}
}

__declspec(naked) void CCustomInterface::DrawInterfaceS8ChatPosition4()
{
	static float ChatPosY4 = 365.0f;
	static DWORD ChatPos_buff4 = 0x007878C4;
	_asm
	{
	FLD DWORD PTR DS:[ChatPosY4]
	PUSH ECX
	FSTP DWORD PTR SS:[ESP]
	jmp [ChatPos_buff4]
	}
}

__declspec(naked) void CCustomInterface::DrawInterfaceS8ChatPosition5()
{
	static float ChatPosY5 = 365.0f;
	static DWORD ChatPos_buff5 = 0x00787916;
	_asm
	{
	FLD DWORD PTR DS:[ChatPosY5]
	PUSH ECX
	FSTP DWORD PTR SS:[ESP]
	jmp [ChatPos_buff5]
	}
}

__declspec(naked) void CCustomInterface::DrawInterfaceS8SkillClickPosition()
{
	static float SkillClickPositionX = 310.0f;
	static float SkillClickPositionY = 440.0f;
	static float SkillClickPositionW = 32.0f;
	static float SkillClickPositionH = 38.0f;
	static DWORD SkillClickPosition_buff = 0x00812734;
	_asm
	{
	FLD DWORD PTR DS:[SkillClickPositionX]
	FSTP DWORD PTR SS:[EBP-0x8]
	FLD DWORD PTR DS:[SkillClickPositionY]
	FSTP DWORD PTR SS:[EBP-0x4]
	FLD DWORD PTR DS:[SkillClickPositionW]
	FSTP DWORD PTR SS:[EBP-0x20]
	FLD DWORD PTR DS:[SkillClickPositionH]
	FSTP DWORD PTR SS:[EBP-0x1C]
	jmp [SkillClickPosition_buff]
	}
}

__declspec(naked) void CCustomInterface::DrawInterfaceS8SkillSwitchBar()
{
	static float SkillBarDrawPositionX = 342.0f;
	static float SkillBarDrawPositionY = 440.0f;
	static float SkillBarDrawPositionW = 125.0f;
	static float SkillBarDrawPositionH = 38.0f;
	static DWORD SkillBarDrawPosition_buff = 0x00812968;
	_asm
	{	
	FLD DWORD PTR DS:[SkillBarDrawPositionX]
	FSTP DWORD PTR SS:[EBP-0x8]
	FLD DWORD PTR DS:[SkillBarDrawPositionY]
	FSTP DWORD PTR SS:[EBP-0x4]
	FLD DWORD PTR DS:[SkillBarDrawPositionW]
	FSTP DWORD PTR SS:[EBP-0x20]
	FLD DWORD PTR DS:[SkillBarDrawPositionH]
	FSTP DWORD PTR SS:[EBP-0x1C]
	jmp [SkillBarDrawPosition_buff]
	}
}

__declspec(naked) void CCustomInterface::DrawInterfaceS8SkillSwitchBar2()
{
	static float SkillBarDrawPosition2X = 310.0f;
	static float SkillBarDrawPosition2Y = 440.0f;
	static float SkillBarDrawPosition2W = 25.0f;
	static float SkillBarDrawPosition2H = 38.0f;
	static DWORD SkillBarDrawPosition2_buff = 0x00812A97;
	_asm
	{	
	FLD DWORD PTR DS:[SkillBarDrawPosition2X]
	FSTP DWORD PTR SS:[EBP-0x8]
	FLD DWORD PTR DS:[SkillBarDrawPosition2Y]
	FSTP DWORD PTR SS:[EBP-0x4]
	FLD DWORD PTR DS:[SkillBarDrawPosition2W]
	FSTP DWORD PTR SS:[EBP-0x20]
	FLD DWORD PTR DS:[SkillBarDrawPosition2H]
	FSTP DWORD PTR SS:[EBP-0x1C]
	jmp [SkillBarDrawPosition2_buff]
	}
}

__declspec(naked) void CCustomInterface::DrawInterfaceS8SkillSwitchDraw()
{
	static float SkillSwitchDrawX = 360.0f;
	static float SkillSwitchDrawY = 370.0f;
	static float SkillSwitchDrawW = 32.0f;
	static float SkillSwitchDrawH = 38.0f;
	static float SkillSwitchDrawMW = 360.0f;
	static DWORD SkillSwitchDraw_buff = 0x008139CA;
	_asm
	{
		FLD DWORD PTR DS:[SkillSwitchDrawX]
		FSTP DWORD PTR SS:[EBP-0x8]
		FLD DWORD PTR DS:[SkillSwitchDrawY]
		FSTP DWORD PTR SS:[EBP-0x4]	
		FLD DWORD PTR DS:[SkillSwitchDrawW]
		FSTP DWORD PTR SS:[EBP-0x18]
		FLD DWORD PTR DS:[SkillSwitchDrawH]
		FSTP DWORD PTR SS:[EBP-0x14]
		FLD DWORD PTR DS:[SkillSwitchDrawMW]
		FSTP DWORD PTR SS:[EBP-0x24]
		jmp [SkillSwitchDraw_buff]
	}
}

__declspec(naked) void CCustomInterface::DrawInterfaceS8SkillSwitchClick()
{
	static float SkillSwitchDrawX = 360.0f;
	static float SkillSwitchDrawY = 370.0f;
	static float SkillSwitchDrawW = 32.0f;
	static float SkillSwitchDrawH = 38.0f;
	static float SkillSwitchDrawMW = 360.0f;
	static DWORD SkillSwitchClick_buff = 0x00812D69;
	_asm
	{
		FLD DWORD PTR DS:[SkillSwitchDrawX]
		FSTP DWORD PTR SS:[EBP-0x8]
		FLD DWORD PTR DS:[SkillSwitchDrawY]
		FSTP DWORD PTR SS:[EBP-0x4]
		FLD DWORD PTR DS:[SkillSwitchDrawW]
		FSTP DWORD PTR SS:[EBP-0x20]
		FLD DWORD PTR DS:[SkillSwitchDrawH]
		FSTP DWORD PTR SS:[EBP-0x1C]
		FLD DWORD PTR DS:[SkillSwitchDrawMW]
		FSTP DWORD PTR SS:[EBP-0x14]
		jmp [SkillSwitchClick_buff]
	}
}

__declspec(naked) void CCustomInterface::DrawInterfaceS8SkillDarkRavenDrawPosition()
{
	static float SkillDrawRavenDrawX = 272.0f;
	static float SkillDrawRavenDrawY = 330.0f;
	static float SkillDrawRavenDrawW = 32.0f;
	static float SkillDrawRavenDrawH = 38.0f;
	static DWORD SkillDrawRavenDraw_buff = 0x00813CDD;
	_asm
	{
		FLD DWORD PTR DS:[SkillDrawRavenDrawX]
		FSTP DWORD PTR SS:[EBP-0x8]
		FLD DWORD PTR DS:[SkillDrawRavenDrawY]
		FSTP DWORD PTR SS:[EBP-0x4]
		FLD DWORD PTR DS:[SkillDrawRavenDrawW]
		FSTP DWORD PTR SS:[EBP-0x10]
		FLD DWORD PTR DS:[SkillDrawRavenDrawH]
		FSTP DWORD PTR SS:[EBP-0x0C]
		jmp [SkillDrawRavenDraw_buff]
	}
}

__declspec(naked) void CCustomInterface::DrawInterfaceS8SkillDarkRavenClickPosition()
{
	static float SkillSwitchRavenDrawX = 272.0f;
	static float SkillSwitchRavenDrawY = 330.0f;
	static float SkillSwitchRavenDrawW = 32.0f;
	static float SkillSwitchRavenDrawH = 38.0f;
	static DWORD SkillSwitchRavenClick_buff = 0x008130C5;
	_asm
	{
		FLD DWORD PTR DS:[SkillSwitchRavenDrawX]
		FSTP DWORD PTR SS:[EBP-0x8]
		FLD DWORD PTR DS:[SkillSwitchRavenDrawY]
		FSTP DWORD PTR SS:[EBP-0x4]
		FLD DWORD PTR DS:[SkillSwitchRavenDrawW]
		FSTP DWORD PTR SS:[EBP-0x20]
		FLD DWORD PTR DS:[SkillSwitchRavenDrawH]
		FSTP DWORD PTR SS:[EBP-0x1C]
		jmp [SkillSwitchRavenClick_buff]
	}
}

__declspec(naked) void CCustomInterface::DrawInterfaceS8PotionQ()
{
	static float BarNumberY = 460.0f;
	static float QPosition1X = 203.0f;
	static float BarPotionY = 446.0f;
	static float QPosition4X = 193.0f;

	static DWORD QPosition_buff = 0x00895A70;
	_asm
	{
	FLD DWORD PTR DS:[BarNumberY]
	FSTP DWORD PTR SS:[ESP]
	PUSH ECX
	FLD DWORD PTR DS:[QPosition1X]
	FSTP DWORD PTR SS:[ESP]
	PUSH ECX
	FLD DWORD PTR DS:[BarPotionY]
	FSTP DWORD PTR SS:[ESP]
	PUSH ECX
	FLD DWORD PTR DS:[QPosition4X]
	FSTP DWORD PTR SS:[ESP]
	jmp [QPosition_buff]
	}
}

__declspec(naked) void CCustomInterface::DrawInterfaceS8PotionW()
{
	static float BarNumberY = 460.0f;
	static float QPosition1X = 233.0f;
	static float BarPotionY = 446.0f;
	static float QPosition4X = 223.0f;

	static DWORD QPosition_buff = 0x00895AE5;
	_asm
	{
	FLD DWORD PTR DS:[BarNumberY]
	FSTP DWORD PTR SS:[ESP]
	PUSH ECX
	FLD DWORD PTR DS:[QPosition1X]
	FSTP DWORD PTR SS:[ESP]
	PUSH ECX
	FLD DWORD PTR DS:[BarPotionY]
	FSTP DWORD PTR SS:[ESP]
	PUSH ECX
	FLD DWORD PTR DS:[QPosition4X]
	FSTP DWORD PTR SS:[ESP]
	jmp [QPosition_buff]
	}
}

__declspec(naked) void CCustomInterface::DrawInterfaceS8PotionE()
{
	static float BarNumberY = 460.0f;
	static float QPosition1X = 263.0f;
	static float BarPotionY = 446.0f;
	static float QPosition4X = 253.0f;

	static DWORD QPosition_buff = 0x00895B5A;
	_asm
	{
	FLD DWORD PTR DS:[BarNumberY]
	FSTP DWORD PTR SS:[ESP]
	PUSH ECX
	FLD DWORD PTR DS:[QPosition1X]
	FSTP DWORD PTR SS:[ESP]
	PUSH ECX
	FLD DWORD PTR DS:[BarPotionY]
	FSTP DWORD PTR SS:[ESP]
	PUSH ECX
	FLD DWORD PTR DS:[QPosition4X]
	FSTP DWORD PTR SS:[ESP]
	jmp [QPosition_buff]
	}
}

__declspec(naked) void CCustomInterface::DrawInterfaceS8PotionR()
{
	static float BarNumberY = 460.0f;
	static float QPosition1X = 293.0f;
	static float BarPotionY = 446.0f;
	static float QPosition4X = 283.0f;
	static DWORD RButtonAddress = 0x00895BCF;
	_asm
	{
	FLD DWORD PTR DS:[BarNumberY]
	FSTP DWORD PTR SS:[ESP]
	PUSH ECX
	FLD DWORD PTR DS:[QPosition1X]
	FSTP DWORD PTR SS:[ESP]
	PUSH ECX
	FLD DWORD PTR DS:[BarPotionY]
	FSTP DWORD PTR SS:[ESP]
	PUSH ECX
	FLD DWORD PTR DS:[QPosition4X]
	FSTP DWORD PTR SS:[ESP]
	jmp [RButtonAddress]
	}
}

void CCustomInterface::DrawInterfaceS2Buttom()
{
	
}

void CCustomInterface::DrawInterfaceS2Menu()
{
	if (gCustomInterface.XkeyUp == 1)
	{
		keybd_event(VkKeyScan('x'),0, KEYEVENTF_KEYUP,0); // ‘X’ Release
		gCustomInterface.XkeyUp = 0;
	}

	if ( !gInterface.CheckWindow(ObjWindow::ChatWindow) )
		pDrawImage(31387, 0.0, 387.0, 108.0, 45.0, 0, 0, 0.84375, 0.703125, 1, 1, 0.0);

	if ( !gInterface.MiniMapCheck() )
		pDrawImage(31387, 532.0, 387.0, 108.0, 45.0, 0.84, 0, -0.84375, 0.703125, 1, 1, 0.0);

	pDrawImage(31377, 0, 432.0, 256.0,48.0,0,0,1.0,0.75,1,1,0);
	pDrawImage(31378, 256.0, 432.0, 128.0, 48.0, 0, 0, 1.0, 0.75, 1, 1, 0);
	pDrawImage(31379, 384.0, 432.0, 256.0, 48.0, 0, 0, 1.0, 0.75, 1, 1, 0);

	if (gInterface.IsWorkZone(eNewInterfaceParty))
	{
		gInterface.DrawToolTip((int)gInterface.Data[eNewInterfaceParty].X+4, (int)gInterface.Data[eNewInterfaceParty].Y - 10, "Party");
	}

	if (gInterface.IsWorkZone(eNewInterfaceCharacter))
	{
		gInterface.DrawToolTip((int)gInterface.Data[eNewInterfaceCharacter].X+4, (int)gInterface.Data[eNewInterfaceCharacter].Y - 10, "Stats");
	}

	if (gInterface.IsWorkZone(eNewInterfaceInventory))
	{
		gInterface.DrawToolTip((int)gInterface.Data[eNewInterfaceInventory].X - 4, (int)gInterface.Data[eNewInterfaceInventory].Y - 10, "Inventory");
	}

	if (gInterface.IsWorkZone(eNewInterfaceCashshop))
	{
		gInterface.DrawToolTip((int)gInterface.Data[eNewInterfaceCashshop].X+4, (int)gInterface.Data[eNewInterfaceCashshop].Y - 10, "Shop");
	}


	if (gInterface.CheckWindow(ObjWindow::Party))
	{
		pDrawImage(31384, 348.0, 452.0, 24.0, 24.0, 0, 0, 0.75, 0.75, 1, 1, 0);
	}

	if (gInterface.CheckWindow(ObjWindow::Character))
	{
		pDrawImage(31381, 379.0, 452.0, 24.0, 24.0, 0, 0, 0.75, 0.75, 1, 1, 0);
	}

	if (gInterface.CheckWindow(ObjWindow::Inventory))
	{
		pDrawImage(31383, 410.0, 452.0, 24.0, 24.0, 0, 0, 0.75, 0.75, 1, 1, 0);
	}

	if (gInterface.CheckWindow(ObjWindow::CashShop))
	{
		pDrawImage(31394, 441.0, 452.0, 24.0, 24.0, 0, 0, 0.75, 0.75, 1, 1, 0);
	}

	if (gInterface.CheckWindow(ObjWindow::FastMenu))
	{
		pDrawImage(31390, 5.0, 434.0, 52.0, 18.0, 0, 0, 0.8125, 0.5625, 1, 1, 0);
	}

	if (gInterface.CheckWindow(ObjWindow::FriendList))
	{
		pDrawImage(31391, 580.0, 434.0, 52.0, 18.0, 0, 0, 0.8125, 0.5625, 1, 1, 0);
	}

	if (gInterface.CheckWindow(ObjWindow::Guild))
	{
		pDrawImage(31389, 580.0, 457.0, 52.0, 18.0, 0, 0, 0.8125, 0.5625, 1, 1, 0);
	}

	gInterface.Work();

	if (!gObjUser.lpPlayer || !gObjUser.lpViewPlayer)
		return;

	sub_791000(25.0, 463.0, (int)gObjUser.lpViewPlayer->MapPosX , 0.90);
	sub_791000(45.0, 463.0, (int)gObjUser.lpViewPlayer->MapPosY , 0.90);

	glColor4f(1.0, 1.0, 1.0, 1.0);
}

void CCustomInterface::DrawInterfaceS2Skills(int a1)
{

  float v4; // ST18_4@17
  float v5; // ST14_4@17
  int v6; // [sp+18h] [bp-34h]@1
  int v7; // [sp+20h] [bp-2Ch]@13
  int v8; // [sp+24h] [bp-28h]@7
  int v9; // [sp+2Ch] [bp-20h]@18
  signed int v10; // [sp+30h] [bp-1Ch]@2
  float v11; // [sp+34h] [bp-18h]@4
  signed int i; // [sp+40h] [bp-Ch]@4
  float v13; // [sp+44h] [bp-8h]@4
  float v14; // [sp+48h] [bp-4h]@4

	//LPVOID v1 = sub_861110();
	//int v2 = sub_861200((int)v1);

  v6 = a1;
  //a1 = v2;

  if (!gObjUser.lpPlayer || !gObjUser.lpViewPlayer)
	  return;

  if ( gObjUser.lpPlayer->MagicCount > 0 )
  {
    v10 = 1;
    if ( *(BYTE*)(a1 + 20) )
      v10 = 6;
    v13 = 190.0;
    v14 = 390.0;
    v11 = 32.0;
  //  for ( i = 0; i < 0; ++i )
  //  {
  //    v13 = v13 + v11;
  //    v8 = i + v10;
  //    if ( i + v10 == 10 )
  //      v8 = 0;

		//int teste = *(DWORD*)(v6 + 4 * v8 + 24);

		//int Skill = *(DWORD*)(v6 + 4 * v8 + 24);

  //    if ( Skill != -1
  //      && (Skill < 120
  //       || Skill >= 124
  //       || gObjUser.lpViewPlayer->Unknown676 ))
  //    {
  //      v7 = (0x8128ABC + 88 * *(WORD*)(0x8128AC8 + 2 * Skill + 120));

  //      if ( !v7 || *(BYTE*)(v7 + 55) != 3 )
  //      {

  //        if ( gObjUser.lpViewPlayer->ActiveMagic == Skill )
  //          pDrawGUI((DWORD)31313, v13, v14, v11, 38.0);

  //        v4 = v14 + 6.0;
  //        v5 = v13 + 6.0;
  //        sub_813DC0(a1, Skill, v5, v4, 0.0, 0.0);
  //      }
  //    }
  //  }
    v9 = (SkillStruct + 88 * *(WORD*)(SkillList + 2 * gObjUser.lpViewPlayer->ActiveMagic + 120));

	if ( v9 && *(BYTE*)(v9 + 55) != 3 )
		sub_813DC0(v6,gObjUser.lpViewPlayer->ActiveMagic, 310.0, 450.0, 20.0, 28.0);
  }
	
}

void CCustomInterface::DrawInterfaceS2HP()
{
	if (!gObjUser.lpPlayer || !gObjUser.lpViewPlayer)
		return;

	float ReduceHpRate = 0.0;
	float ReduceMpRate = 0.0;

	if ( (signed int)ViewMaxHP > 0 )
	ReduceHpRate = (double)(ViewMaxHP - ViewCurHP) / (double)ViewMaxHP;

	if ( (signed int)ViewMaxMP > 0 )
	ReduceMpRate = (double)(ViewMaxMP - ViewCurMP) / (double)ViewMaxMP;

	float Width		= 53.0;
	float PosX		= 97.0;
	float Height	= 48.0;
	float PosY		= 432.0;

	float FinalY = ReduceHpRate * Height + PosY;
	float FinalH = Height - ReduceHpRate * Height;

	float ScaleY = (1.0 - ReduceHpRate) * Height / 64.0;
	float ScaleX = Width / 64.0;
	float ReduceY = ReduceHpRate * Height / 64.0;

	if (pCheckEffect((LPVOID)(*(DWORD*)0x7BC4F04+1260), 55) == 1)
	{
		pDrawImage(31382, PosX, FinalY, Width, FinalH, 0.0, ReduceY, ScaleX, ScaleY, 1, 1, 0);
	}
	else
	{
		pDrawImage(31385, PosX, FinalY, Width, FinalH, 0.0, ReduceY, ScaleX, ScaleY, 1, 1, 0);
	}
	
	sub_791000(PosX + 35.0, 460.0, (int)ViewCurHP, 0.95);
	glColor4f(1.0, 1.0, 1.0, 1.0);

	if ( sub_790B10((int)PosX, (int)PosY, (int)Width, (int)Height) == 1 )
	{
		gInterface.DrawToolTip((int)PosX, 418, "Life: %d/%d",ViewCurHP,ViewMaxHP);
		//glColor4f(1.0, 1.0, 1.0, 0.85);
	}

	Width		= 53.0;
	PosX		= 489.0;
	Height		= 48.0;
	PosY		= 432.0;

	FinalY = ReduceMpRate * Height + PosY;
	FinalH = Height - ReduceMpRate * Height;

	ScaleY = (1.0 - ReduceMpRate) * Height / 64.0;
	ScaleX = Width / 64.0;
	ReduceY = ReduceMpRate * Height / 64.0;

	pDrawImage(31380, PosX, FinalY, Width, FinalH, 0.0, ReduceY, ScaleX, ScaleY, 1, 1, 0.0);

	sub_791000(PosX + 25.0, 460.0, (int)ViewCurMP, 0.95);

	if ( sub_790B10((int)PosX, (int)PosY, (int)Width, (int)Height) == 1 )
	{
		gInterface.DrawToolTip((int)PosX, 418, "Mana: %d/%d",ViewCurMP,ViewMaxMP);
	}
}

void CCustomInterface::DrawInterfaceS2SD()
{
	if (gProtect.m_MainInfo.CustomInterfaceType != 1)
	{
		float ReduceRate = 0.0;

		if ( (signed int)ViewMaxSD > 0 )
			ReduceRate = (double)(ViewMaxSD - ViewCurSD) / (double)ViewMaxSD;

		float Width		= 15.0;
		float Height	= 36.0;
		float PosX		= 73.0;
		float PosY		= 438.0;

		float FinalY	= ReduceRate * Height + PosY;
		float FinalH	= Height - ReduceRate * Height;

		float ScaleY	= (1.0 - ReduceRate) * Height / 64.0;
		float ScaleX	= Width / 16.0;
		float ReduceY	= ReduceRate * Height / 64.0;

		pDrawImage(31388, PosX, FinalY, Width, FinalH, 0.0, ReduceY, ScaleX, ScaleY, 1, 1, 0.0);
		sub_791000(PosX+10.0, PosY+30.0, ViewCurSD, 0.9);

		if ( sub_790B10(PosX, PosY, Width, Height) == 1 )
		{
			gInterface.DrawToolTip((int)PosX, (int)PosY-20, "SD: %d/%d",ViewCurSD,ViewMaxSD);
		}
	}
}

void CCustomInterface::DrawInterfaceS2AG()
{
	float ReduceRate = 0.0;

	if ( (signed int)ViewMaxBP > 0 )
		ReduceRate = (double)(ViewMaxBP - ViewCurBP) / (double)ViewMaxBP;

	float Width		= 15.0;
	float Height	= 36.0;
	float PosX		= 551.0;
	float PosY		= 438.0;

	float FinalY	= ReduceRate * Height + PosY;
	float FinalH	= Height - ReduceRate * Height;

	float ScaleY	= (1.0 - ReduceRate) * Height / 64.0;
	float ScaleX	= Width / 16.0;
	float ReduceY	= ReduceRate * Height / 64.0;

	pDrawImage(31386, PosX, FinalY, Width, FinalH, 0.0, ReduceY, ScaleX, ScaleY, 1, 1, 0.0);

	sub_791000(PosX+10.0, PosY+30.0, ViewCurBP, 0.9);

	if ( sub_790B10(PosX, PosY, Width, Height) == 1 )
	{
		gInterface.DrawToolTip((int)PosX, (int)PosY-20, "AG: %d/%d",ViewCurBP,ViewMaxBP);
	}
}


void CCustomInterface::DrawInterfaceS2Exp()
{
	if (!gObjUser.lpPlayer || !gObjUser.lpViewPlayer)
		return;

	

	float ReduceRate	= 0.0;

	if(pIsMaster(gObjUser.lpPlayer->Class) && gObjUser.lpPlayer->Level >= 400 && pMasterExp > 0)
	{
		glColor3f(0.2f, 0.8f, 0.2f);

		long double PreviousExp = pMasterExp - (__int64)gCustomInterface.m_MasterLevelExperienceTable[pMasterLevel];
		long double TotalExp    = pMasterNextExp - (__int64)gCustomInterface.m_MasterLevelExperienceTable[pMasterLevel];

		if ( TotalExp > 0 )
			ReduceRate = (TotalExp - PreviousExp) / TotalExp;

		if (ReduceRate < 0)
			ReduceRate = 1.0;

		float Width		= 198.0;
		float Height	= 5.0;
		float PosX		= 221.0;
		float PosY		= 438.0;

		float FinalW	= Width - ReduceRate * Width;

		pDrawBarForm(PosX, PosY, FinalW, Height, 0.0, 0);

		sub_791000(425.0, 436.0, (int)pMasterLevel, 0.9);

		glColor3f(1.0, 1.0, 1.0);

		if ( sub_790B10(PosX, PosY, Width, Height) == 1 )
		{
			gInterface.DrawToolTip((int)PosX+100,(int)PosY-15, "Experience: %I64u/%I64u",pMasterExp,pMasterNextExp);
		}
	}
	else
	{

		glColor3f(0.98039216f, 4.039215688f, 0.0);

		double PreviousExp = gObjUser.lpPlayer->Experience - gCustomInterface.gLevelExperience[gObjUser.lpPlayer->Level-1];
		double TotalExp    = gObjUser.lpPlayer->NextExperience - gCustomInterface.gLevelExperience[gObjUser.lpPlayer->Level-1];

		if ( TotalExp > 0 )
			ReduceRate = (TotalExp - PreviousExp) / TotalExp;

		if (ReduceRate < 0)
			ReduceRate = 1.0;

		float Width		= 198.0;
		float Height	= 5.0;
		float PosX		= 221.0;
		float PosY		= 438.0;

		float FinalW	= Width - ReduceRate * Width;

		pDrawBarForm(PosX, PosY, FinalW, Height, 0.0, 0);

		sub_791000(425.0, 436.0, (int)gObjUser.lpPlayer->Level, 0.9);

		glColor3f(1.0, 1.0, 1.0);

		if ( sub_790B10(PosX, PosY, Width, Height) == 1 )
		{
			gInterface.DrawToolTip((int)PosX+100,(int)PosY-15, "Experience: %d/%d",gObjUser.lpPlayer->Experience,gObjUser.lpPlayer->NextExperience);
		}
	}


}

void CCustomInterface::DrawInterfaceS2FriendButtom()
{

}

__declspec(naked) void CCustomInterface::DrawInterfaceS2DisableR()
{
	static DWORD RButtonAddress = 0x00895C0C;
	_asm{jmp RButtonAddress}
}

__declspec(naked) void CCustomInterface::DrawInterfaceS2SkillClickPosition()
{
	static float SkillClickPositionX = 310.0f;
	static float SkillClickPositionY = 440.0f;
	static float SkillClickPositionW = 32.0f;
	static float SkillClickPositionH = 38.0f;
	static DWORD SkillClickPosition_buff = 0x00812734;
	_asm
	{
	FLD DWORD PTR DS:[SkillClickPositionX]
	FSTP DWORD PTR SS:[EBP-0x8]
	FLD DWORD PTR DS:[SkillClickPositionY]
	FSTP DWORD PTR SS:[EBP-0x4]
	FLD DWORD PTR DS:[SkillClickPositionW]
	FSTP DWORD PTR SS:[EBP-0x20]
	FLD DWORD PTR DS:[SkillClickPositionH]
	FSTP DWORD PTR SS:[EBP-0x1C]
	jmp [SkillClickPosition_buff]
	}
}

__declspec(naked) void CCustomInterface::DrawInterfaceS2SkillSwitchBar()
{
	static float SkillBarDrawPositionX = 640.0f;
	static float SkillBarDrawPositionY = 480.0f;
	static float SkillBarDrawPositionW = 160.0f;
	static float SkillBarDrawPositionH = 38.0f;
	static DWORD SkillBarDrawPosition_buff = 0x00812968;
	_asm
	{	
	FLD DWORD PTR DS:[SkillBarDrawPositionX]
	FSTP DWORD PTR SS:[EBP-0x8]
	FLD DWORD PTR DS:[SkillBarDrawPositionY]
	FSTP DWORD PTR SS:[EBP-0x4]
	FLD DWORD PTR DS:[SkillBarDrawPositionW]
	FSTP DWORD PTR SS:[EBP-0x20]
	FLD DWORD PTR DS:[SkillBarDrawPositionH]
	FSTP DWORD PTR SS:[EBP-0x1C]
	jmp [SkillBarDrawPosition_buff]
	}
}

__declspec(naked) void CCustomInterface::DrawInterfaceS2SkillSwitchDraw()
{
	static float SkillSwitchDrawX = 360.0f;
	static float SkillSwitchDrawY = 370.0f;
	static float SkillSwitchDrawW = 32.0f;
	static float SkillSwitchDrawH = 38.0f;
	static float SkillSwitchDrawMW = 360.0f;
	static DWORD SkillSwitchDraw_buff = 0x008139CA;
	_asm
	{
		FLD DWORD PTR DS:[SkillSwitchDrawX]
		FSTP DWORD PTR SS:[EBP-0x8]
		FLD DWORD PTR DS:[SkillSwitchDrawY]
		FSTP DWORD PTR SS:[EBP-0x4]	
		FLD DWORD PTR DS:[SkillSwitchDrawW]
		FSTP DWORD PTR SS:[EBP-0x18]
		FLD DWORD PTR DS:[SkillSwitchDrawH]
		FSTP DWORD PTR SS:[EBP-0x14]
		FLD DWORD PTR DS:[SkillSwitchDrawMW]
		FSTP DWORD PTR SS:[EBP-0x24]
		jmp [SkillSwitchDraw_buff]
	}
}

__declspec(naked) void CCustomInterface::DrawInterfaceS2SkillSwitchClick()
{
	static float SkillSwitchDrawX = 360.0f;
	static float SkillSwitchDrawY = 370.0f;
	static float SkillSwitchDrawW = 32.0f;
	static float SkillSwitchDrawH = 38.0f;
	static float SkillSwitchDrawMW = 360.0f;
	static DWORD SkillSwitchClick_buff = 0x00812D69;
	_asm
	{
		FLD DWORD PTR DS:[SkillSwitchDrawX]
		FSTP DWORD PTR SS:[EBP-0x8]
		FLD DWORD PTR DS:[SkillSwitchDrawY]
		FSTP DWORD PTR SS:[EBP-0x4]
		FLD DWORD PTR DS:[SkillSwitchDrawW]
		FSTP DWORD PTR SS:[EBP-0x20]
		FLD DWORD PTR DS:[SkillSwitchDrawH]
		FSTP DWORD PTR SS:[EBP-0x1C]
		FLD DWORD PTR DS:[SkillSwitchDrawMW]
		FSTP DWORD PTR SS:[EBP-0x14]
		jmp [SkillSwitchClick_buff]
	}
}

__declspec(naked) void CCustomInterface::DrawInterfaceS2PotionQ()
{
	static float BarNumberY = 447.0f;
	static float QPosition1X = 227.0f;
	static float BarPotionY = 455.0f;
	static float QPosition4X = 207.0f;

	static DWORD QPosition_buff = 0x00895A70;
	_asm
	{
	FLD DWORD PTR DS:[BarNumberY]
	FSTP DWORD PTR SS:[ESP]
	PUSH ECX
	FLD DWORD PTR DS:[QPosition1X]
	FSTP DWORD PTR SS:[ESP]
	PUSH ECX
	FLD DWORD PTR DS:[BarPotionY]
	FSTP DWORD PTR SS:[ESP]
	PUSH ECX
	FLD DWORD PTR DS:[QPosition4X]
	FSTP DWORD PTR SS:[ESP]
	jmp [QPosition_buff]
	}
}

__declspec(naked) void CCustomInterface::DrawInterfaceS2PotionW()
{
	static float BarNumberY = 447.0f;
	static float QPosition1X = 258.0f;
	static float BarPotionY = 455.0f;
	static float QPosition4X = 238.0f;

	static DWORD QPosition_buff = 0x00895AE5;
	_asm
	{
	FLD DWORD PTR DS:[BarNumberY]
	FSTP DWORD PTR SS:[ESP]
	PUSH ECX
	FLD DWORD PTR DS:[QPosition1X]
	FSTP DWORD PTR SS:[ESP]
	PUSH ECX
	FLD DWORD PTR DS:[BarPotionY]
	FSTP DWORD PTR SS:[ESP]
	PUSH ECX
	FLD DWORD PTR DS:[QPosition4X]
	FSTP DWORD PTR SS:[ESP]
	jmp [QPosition_buff]
	}
}

__declspec(naked) void CCustomInterface::DrawInterfaceS2PotionE()
{
	static float BarNumberY = 447.0f;
	static float QPosition1X = 289.0f;
	static float BarPotionY = 455.0f;
	static float QPosition4X = 269.0f;

	static DWORD QPosition_buff = 0x00895B5A;
	_asm
	{
	FLD DWORD PTR DS:[BarNumberY]
	FSTP DWORD PTR SS:[ESP]
	PUSH ECX
	FLD DWORD PTR DS:[QPosition1X]
	FSTP DWORD PTR SS:[ESP]
	PUSH ECX
	FLD DWORD PTR DS:[BarPotionY]
	FSTP DWORD PTR SS:[ESP]
	PUSH ECX
	FLD DWORD PTR DS:[QPosition4X]
	FSTP DWORD PTR SS:[ESP]
	jmp [QPosition_buff]
	}
}

bool CCustomInterface::EventNewInterface_All(DWORD Event)
{
	if (this->EventNewInterface_Party(Event))
	{
		return 1;
	}
	if (this->EventNewInterface_Character(Event))
	{
		return 1;
	}
	if (this->EventNewInterface_Inventory(Event))
	{
		return 1;
	}
	if (this->EventNewInterface_Cashshop(Event))
	{
		return 1;
	}
	if (this->EventNewInterface_Menu(Event))
	{
		return 1;
	}
	if (this->EventNewInterface_Friend(Event))
	{
		return 1;
	}
	if (this->EventNewInterface_Guild(Event))
	{
		return 1;
	}
	if (this->EventNewInterface_Quest(Event))
	{
		return 1;
	}
	return 0;
}

bool CCustomInterface::EventNewInterface_Party(DWORD Event)
{
	DWORD CurrentTick = GetTickCount();
	DWORD Delay = (CurrentTick - gInterface.Data[eNewInterfaceParty].EventTick);
	// ----
	if (!gInterface.IsWorkZone(eNewInterfaceParty))
	{
		return false;
	}
	// ----
	if (Event == WM_LBUTTONDOWN)
	{
		gInterface.Data[eNewInterfaceParty].OnClick = true;
		return true;
	}
	// ----
	gInterface.Data[eNewInterfaceParty].OnClick = false;
	// ----
	if (Delay < 100)
	{
		return false;
	}

	if (!gInterface.CheckWindow(ObjWindow::Party))
	{
		gInterface.OpenWindow(ObjWindow::Party);
	}
	else
	{
		gInterface.CloseWindow(ObjWindow::Party);
	}

	//gInterface.OpenWindow(ObjWindow::FastMenu);

	//sub_849110();

	//keybd_event(VK_ESCAPE, 0, 0, 0);

	//keybd_event(VK_ESCAPE, 0, KEYEVENTF_KEYUP, 0);

	//PostMessage(pGameWindow, WM_KEYDOWN, VK_ESCAPE, 0);
	// ----
	gInterface.Data[eNewInterfaceParty].EventTick = GetTickCount();
	// ----
	return false;
}

bool CCustomInterface::EventNewInterface_Character(DWORD Event)
{
	DWORD CurrentTick = GetTickCount();
	DWORD Delay = (CurrentTick - gInterface.Data[eNewInterfaceCharacter].EventTick);
	// ----
	if (!gInterface.IsWorkZone(eNewInterfaceCharacter))
	{
		return false;
	}
	// ----
	if (Event == WM_LBUTTONDOWN)
	{
		gInterface.Data[eNewInterfaceCharacter].OnClick = true;
		return true;
	}
	// ----
	gInterface.Data[eNewInterfaceCharacter].OnClick = false;
	// ----
	if (Delay < 100)
	{
		return false;
	}

	if (!gInterface.CheckWindow(ObjWindow::Character))
	{
		gInterface.OpenWindow(ObjWindow::Character);
	}
	else
	{
		gInterface.CloseWindow(ObjWindow::Character);
	}
	// ----
	gInterface.Data[eNewInterfaceCharacter].EventTick = GetTickCount();
	// ----
	return false;
}

bool CCustomInterface::EventNewInterface_Inventory(DWORD Event)
{
	DWORD CurrentTick = GetTickCount();
	DWORD Delay = (CurrentTick - gInterface.Data[eNewInterfaceInventory].EventTick);
	// ----
	if (!gInterface.IsWorkZone(eNewInterfaceInventory))
	{
		return false;
	}
	// ----
	if (Event == WM_LBUTTONDOWN)
	{
		gInterface.Data[eNewInterfaceInventory].OnClick = true;
		return true;
	}
	// ----
	gInterface.Data[eNewInterfaceInventory].OnClick = false;
	// ----
	if (Delay < 100)
	{
		return false;
	}

	if (!gInterface.CheckWindow(ObjWindow::Inventory))
	{
		gInterface.OpenWindow(ObjWindow::Inventory);
	}
	else
	{
		gInterface.CloseWindow(ObjWindow::Inventory);
	}
	// ----
	gInterface.Data[eNewInterfaceInventory].EventTick = GetTickCount();
	// ----
	return false;
}

bool CCustomInterface::EventNewInterface_Cashshop(DWORD Event)
{
	DWORD CurrentTick = GetTickCount();
	DWORD Delay = (CurrentTick - gInterface.Data[eNewInterfaceCashshop].EventTick);
	// ----
	if (!gInterface.IsWorkZone(eNewInterfaceCashshop))
	{
		return false;
	}
	// ----
	if (Event == WM_LBUTTONDOWN)
	{
		gInterface.Data[eNewInterfaceCashshop].OnClick = true;
		return true;
	}
	// ----
	gInterface.Data[eNewInterfaceCashshop].OnClick = false;
	// ----
	if (Delay < 100)
	{
		return false;
	}

	if (!gInterface.CheckWindow(ObjWindow::CashShop))
	{

		//keybd_event(VK_ESCAPE, 0, 0, 0);

		keybd_event(VkKeyScan('x'),0,0 , 0); // ‘A’ Press
		gCustomInterface.XkeyUp = 1;
		//keybd_event(VkKeyScan('x'),0, KEYEVENTF_KEYUP,0); // ‘A’ Release

         // if ( !pGameShopThis())
          //{
			//char v43;
   //         sub_404B40(&v43);
   //         v45 = 3;
   //         sub_404B90(&v43, -63, -46);
   //         sub_4050D0(&v43, 2);
   //         sub_4050D0(&v43, 0);
   //         sub_404D70((int)&v43, a2, (int)a3, (int)a4, 0, 0);
   //         v45 = -1;
   //         sub_404B60();
            //sub_9406A0(pGameShopThis(), 1);

			//LPVOID v1 = sub_861110();
			//int v2 = sub_861200((int)v1);
			//sub_943DC0(v2);
            //v34 = sub_861110((int)a2, (int)a3);
            //v35 = sub_8611E0((int)v34);
            //sub_815130(v35, a2, (int)a3, a4, 0, 1);
        //  }

		//PMSG_CASH_SHOP_OPEN_SEND pMsg;

		//pMsg.header.set(0xD2, 0x02,sizeof(pMsg));

		//pMsg.OpenType = 0;

		//DataSend((BYTE*)&pMsg,pMsg.header.size);
	}
	else
	{
		//gInterface.CloseWindow(ObjWindow::CashShop);
		keybd_event(VkKeyScan('x'),0,0,0); // ‘A’ Press
		gCustomInterface.XkeyUp = 1;
	}
	// ----
	gInterface.Data[eNewInterfaceCashshop].EventTick = GetTickCount();
	// ----
	return false;
}

bool CCustomInterface::EventNewInterface_Menu(DWORD Event)
{
	DWORD CurrentTick = GetTickCount();
	DWORD Delay = (CurrentTick - gInterface.Data[eNewInterfaceMenu].EventTick);
	// ----
	if (!gInterface.IsWorkZone(eNewInterfaceMenu))
	{
		return false;
	}
	// ----
	if (Event == WM_LBUTTONDOWN)
	{
		gInterface.Data[eNewInterfaceMenu].OnClick = true;
		return true;
	}
	// ----
	gInterface.Data[eNewInterfaceMenu].OnClick = false;
	// ----
	if (Delay < 100)
	{
		return false;
	}

	if (!gInterface.CheckWindow(ObjWindow::FastMenu))
	{
		gInterface.OpenWindow(ObjWindow::FastMenu);
	}
	else
	{
		gInterface.CloseWindow(ObjWindow::FastMenu);
	}
	// ----
	gInterface.Data[eNewInterfaceMenu].EventTick = GetTickCount();
	// ----
	return false;
}



bool CCustomInterface::EventNewInterface_Friend(DWORD Event)
{
	DWORD CurrentTick = GetTickCount();
	DWORD Delay = (CurrentTick - gInterface.Data[eNewInterfaceFriend].EventTick);
	// ----
	if (!gInterface.IsWorkZone(eNewInterfaceFriend))
	{
		return false;
	}
	// ----
	if (Event == WM_LBUTTONDOWN)
	{
		gInterface.Data[eNewInterfaceFriend].OnClick = true;
		return true;
	}
	// ----
	gInterface.Data[eNewInterfaceFriend].OnClick = false;
	// ----
	if (Delay < 100)
	{
		return false;
	}

	if (!gInterface.CheckWindow(ObjWindow::FriendList))
	{
		gInterface.OpenWindow(ObjWindow::FriendList);
	}
	else
	{
		gInterface.CloseWindow(ObjWindow::FriendList);
	}
	// ----
	gInterface.Data[eNewInterfaceFriend].EventTick = GetTickCount();
	// ----
	return false;
}

bool CCustomInterface::EventNewInterface_Guild(DWORD Event)
{
	DWORD CurrentTick = GetTickCount();
	DWORD Delay = (CurrentTick - gInterface.Data[eNewInterfaceGuild].EventTick);
	// ----
	if (!gInterface.IsWorkZone(eNewInterfaceGuild))
	{
		return false;
	}
	// ----
	if (Event == WM_LBUTTONDOWN)
	{
		gInterface.Data[eNewInterfaceGuild].OnClick = true;
		return true;
	}
	// ----
	gInterface.Data[eNewInterfaceGuild].OnClick = false;
	// ----
	if (Delay < 100)
	{
		return false;
	}

	if (!gInterface.CheckWindow(ObjWindow::Guild))
	{
		gInterface.OpenWindow(ObjWindow::Guild);
	}
	else
	{
		gInterface.CloseWindow(ObjWindow::Guild);
	}
	// ----
	gInterface.Data[eNewInterfaceGuild].EventTick = GetTickCount();
	// ----
	return false;
}

bool CCustomInterface::EventNewInterface_Quest(DWORD Event)
{
	DWORD CurrentTick = GetTickCount();
	DWORD Delay = (CurrentTick - gInterface.Data[eNewInterfaceQuest].EventTick);
	// ----
	if (!gInterface.IsWorkZone(eNewInterfaceQuest))
	{
		return false;
	}
	// ----
	if (Event == WM_LBUTTONDOWN)
	{
		gInterface.Data[eNewInterfaceQuest].OnClick = true;
		return true;
	}
	// ----
	gInterface.Data[eNewInterfaceQuest].OnClick = false;
	// ----
	if (Delay < 100)
	{
		return false;
	}

	if (!gInterface.CheckWindow(ObjWindow::Quest))
	{
		gInterface.OpenWindow(ObjWindow::Quest);
	}
	else
	{
		gInterface.CloseWindow(ObjWindow::Quest);
	}
	// ----
	gInterface.Data[eNewInterfaceQuest].EventTick = GetTickCount();
	// ----
	return false;
}

void CCustomInterface::Load()
{

	this->gLevelExperience[0] = 0;

	DWORD over = 1;

	for(int n=1;n <= 400;n++)
	{
		this->gLevelExperience[n] = (((n+9)*n)*n)*10;

		if(n > 255)
		{
			this->gLevelExperience[n] += (((over+9)*over)*over)*1000;
			over++;
		}
	}

	this->m_MasterLevelExperienceTable[0] = 0;
	QWORD var1 = 0;
	QWORD var2 = 0;
	QWORD var3 = 0;

	for(int n=1;n < (1001);n++)
	{
		var1 = n+400;

		var3 = ((((var1+9)*var1)*var1)*10);

		var2 = var1-255;

		var3 += ((((var2+9)*var2)*var2)*1000);

		var3 = (var3-3892250000)/2;

		this->m_MasterLevelExperienceTable[n] = var3;

	}

	if (gProtect.m_MainInfo.CustomInterfaceType > 0 && gProtect.m_MainInfo.CustomInterfaceType < 4)
	{
		gInterface.BindObject(eNewInterfaceParty, 31384, 24, 24, 348.0, 452.0);
		gInterface.BindObject(eNewInterfaceCharacter, 31381, 24, 24, 379.0, 452.0);
		gInterface.BindObject(eNewInterfaceInventory, 31383, 24, 24, 410.0, 452.0);
		gInterface.BindObject(eNewInterfaceGuild, 31394, 54, 20, 582.0, 459.0);
		
		if (gProtect.m_MainInfo.CustomInterfaceType >= 2)
		{
			gInterface.BindObject(eNewInterfaceFriend, 31394, 54, 20, 581.0, 432.0);
			gInterface.BindObject(eNewInterfaceMenu, 31394, 55, 21, 5, 432);
		}

		if (gProtect.m_MainInfo.CustomInterfaceType >= 3)
		{
			gInterface.BindObject(eNewInterfaceCashshop, 31394, 24, 24, 441.0, 452.0);
		}

		SetByte(0x00813C1A, 30);

		SetByte(0x00812AD5, 0); // Disable Fast Skill mouseover

		MemorySet(0x00813740,0x90,0x22B); //Disable R option

		SetCompleteHook(0xE8,0x0080F258,&this->DrawInterfaceS2Buttom);
		SetCompleteHook(0xE8,0x0080F7FE,&this->DrawInterfaceS2Menu);
		SetCompleteHook(0xE8,0x0080F833,&this->DrawInterfaceS2Skills);
		SetCompleteHook(0xE8,0x0080F845,&this->DrawInterfaceS2HP);
		SetCompleteHook(0xE8,0x0080F84D,&this->DrawInterfaceS2SD);
		SetCompleteHook(0xE8,0x0080F855,&this->DrawInterfaceS2AG);
		SetCompleteHook(0xE8,0x0080F85D,&this->DrawInterfaceS2FriendButtom);
		SetCompleteHook(0xE8,0x0080F865,&this->DrawInterfaceS2Exp);

		MemorySet(0x00895B8D,0x90,0x7E); //Disable R option
		SetCompleteHook(0xE9,0x00895B8D,&this->DrawInterfaceS2DisableR);

		MemorySet(0x00812713,0x90,0x24); 
		SetCompleteHook(0xE9,0x00812713,&this->DrawInterfaceS2SkillClickPosition);

		MemorySet(0x00812947,0x90,0x24); 
		SetCompleteHook(0xE9,0x00812947,&this->DrawInterfaceS2SkillSwitchBar);

		MemorySet(0x008139A0,0x90,0x2D); 
		SetCompleteHook(0xE9,0x008139A0,&this->DrawInterfaceS2SkillSwitchDraw);

		MemorySet(0x00812D3F,0x90,0x2D); 
		SetCompleteHook(0xE9,0x00812D3F,&this->DrawInterfaceS2SkillSwitchClick);

		MemorySet(0x00895A49,0x90,0x24); 
		SetCompleteHook(0xE9,0x00895A49,&this->DrawInterfaceS2PotionQ);

		MemorySet(0x00895ABE,0x90,0x24); 
		SetCompleteHook(0xE9,0x00895ABE,&this->DrawInterfaceS2PotionW);

		MemorySet(0x00895B33,0x90,0x24); 
		SetCompleteHook(0xE9,0x00895B33,&this->DrawInterfaceS2PotionE);
	}
	else if (gProtect.m_MainInfo.CustomInterfaceType == 4)
	{

		SetByte(0x0085A426, 0x6D); //Chat Position

		gInterface.BindObject(eNewInterfaceCashshop, 31420, 25, 25, 44.0, 449.0);
		gInterface.BindObject(eNewInterfaceCharacter, 31423, 25, 25, 69.0, 449.0);
		gInterface.BindObject(eNewInterfaceInventory, 31425, 25, 25, 93.0, 449.0);
		gInterface.BindObject(eNewInterfaceQuest, 31426, 25, 25, 541.0, 449.0);
		gInterface.BindObject(eNewInterfaceFriend, 31427, 25, 25, 566.0, 449.0);
		gInterface.BindObject(eNewInterfaceMenu, 31428, 25, 25, 591.0, 449.0);

		//MemorySet(0x0080FA10,0x90,0x735);

		SetCompleteHook(0xE8,0x0080F258,&this->DrawInterfaceS8Buttom);
		SetCompleteHook(0xE8,0x0080F7FE,&this->DrawInterfaceS8Menu);
		SetCompleteHook(0xE8,0x0080F833,&this->DrawInterfaceS8Skills);
		SetCompleteHook(0xE8,0x0080F845,&this->DrawInterfaceS8HP);
		SetCompleteHook(0xE8,0x0080F84D,&this->DrawInterfaceS8SD);
		SetCompleteHook(0xE8,0x0080F855,&this->DrawInterfaceS8AG);
		SetCompleteHook(0xE8,0x0080F85D,&this->DrawInterfaceS8FriendButtom);
		SetCompleteHook(0xE8,0x0080F865,&this->DrawInterfaceS8Exp);


		//SetCompleteHook(0xE8,0x00787620,&this->DrawInterfaceS8ChatMain);
		//SetCompleteHook(0xE8,0x00787628,&this->DrawInterfaceS8ChatButtom);
		//MemorySet(0x00812713,0x90,0x24); 
		//SetCompleteHook(0xE9,0x007877D0,&this->DrawInterfaceS8ChatPosition1);
		//SetCompleteHook(0xE9,0x00787828,&this->DrawInterfaceS8ChatPosition2);
		//SetCompleteHook(0xE9,0x00787871,&this->DrawInterfaceS8ChatPosition3);
		//SetCompleteHook(0xE9,0x007878BD,&this->DrawInterfaceS8ChatPosition4);
		//SetCompleteHook(0xE9,0x0078790F,&this->DrawInterfaceS8ChatPosition5);

		MemorySet(0x00812713,0x90,0x24); 
		SetCompleteHook(0xE9,0x00812713,&this->DrawInterfaceS8SkillClickPosition);

		MemorySet(0x00812947,0x90,0x24); 
		SetCompleteHook(0xE9,0x00812947,&this->DrawInterfaceS8SkillSwitchBar);

		MemorySet(0x00812A76,0x90,0x24); 
		SetCompleteHook(0xE9,0x00812A76,&this->DrawInterfaceS8SkillSwitchBar2);

		MemorySet(0x008139A0,0x90,0x2D); 
		SetCompleteHook(0xE9,0x008139A0,&this->DrawInterfaceS8SkillSwitchDraw);

		MemorySet(0x00812D3F,0x90,0x2D); 
		SetCompleteHook(0xE9,0x00812D3F,&this->DrawInterfaceS8SkillSwitchClick);

		MemorySet(0x00813CBC,0x90,0x24); 
		SetCompleteHook(0xE9,0x00813CBC,&this->DrawInterfaceS8SkillDarkRavenDrawPosition);

		MemorySet(0x008130AA,0x90,0x24); 
		SetCompleteHook(0xE9,0x008130AA,&this->DrawInterfaceS8SkillDarkRavenClickPosition);

		MemorySet(0x00895A49,0x90,0x24); 
		SetCompleteHook(0xE9,0x00895A49,&this->DrawInterfaceS8PotionQ);

		MemorySet(0x00895ABE,0x90,0x24); 
		SetCompleteHook(0xE9,0x00895ABE,&this->DrawInterfaceS8PotionW);

		MemorySet(0x00895B33,0x90,0x24); 
		SetCompleteHook(0xE9,0x00895B33,&this->DrawInterfaceS8PotionE);

		MemorySet(0x00895BA8,0x90,0x24); 
		SetCompleteHook(0xE9,0x00895BA8,&this->DrawInterfaceS8PotionR);

		//apenas teste
		//		SetByte(0x004D7179, 0xE0); // Aumenta tamanho da tela
		//SetByte(0x004D7A0E, 0xE0); // Aumenta tamanho da tela
		//SetByte(0x0082B765, 0xE0); // Aumenta tamanho da tela

		SetByte(0x004D9749, 0xE0); // Aumenta tamanho da tela
		//SetByte(0x0048C091, 0xE0); // Aumenta tamanho da tela
	}

	if (gProtect.m_MainInfo.CustomInterfaceHelperBar != 1)
	{
		//Desabilitar Menu Helper e Coord.
		MemorySet(0x007D25C0,0x90,0x2F7);
	}
}
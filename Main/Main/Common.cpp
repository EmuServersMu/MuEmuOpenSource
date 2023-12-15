#include "stdafx.h"
#include "Common.h"
#include "Defines.h"
#include "Import.h"
#include "Interface.h"
#include "Offset.h"
#include "Util.h"

BYTE GensBattleMapCount = 0;
BYTE GensMoveIndexCount = 0;
BYTE GensBattleMap[120];
BYTE GensMoveIndex[120];

	int DisableStaticEffect;
	int DisableDynamicEffect;
	int DisableSkillEffect;
	int DisableGlowEffect;
	int Anisotropy;
	int MaxAnisotropy;
	int Linear;
	int GMT;
	int Tron;
	int MiniMap;
	int MiniMapActive;
	int Fog;
	int DisablePing;

void InitCommon() // OK
{
	SetCompleteHook(0xE9,0x0040B154,&LoginTab);

	SetCompleteHook(0xFF,0x0064A79A,&CheckMasterLevel); // C1:16

	SetCompleteHook(0xFF,0x0064A85F,&CheckMasterLevel); // C1:16

	SetCompleteHook(0xFF,0x00656E03,&CheckMasterLevel); // C1:48

	SetCompleteHook(0xFF,0x0064AB3D,&CheckMasterLevel); // C1:9C

	SetCompleteHook(0xFF,0x0064AC02,&CheckMasterLevel); // C1:9C

	SetCompleteHook(0xFF,0x0063DDF2,&CheckMasterLevel); // C1:F3:03

	SetCompleteHook(0xFF,0x0063DF89,&CheckMasterLevel); // C1:F3:03

	SetCompleteHook(0xFF,0x0063EA4C,&CheckMasterLevel); // C1:F3:04

	SetCompleteHook(0xFF,0x0064CA0C,&CheckMasterLevel); // LevelUp

	SetCompleteHook(0xFF,0x0077FAF9,&CheckMasterLevel); // Print Level

	SetCompleteHook(0xFF,0x0081071B,&CheckMasterLevel); // Experience Bar

	SetCompleteHook(0xFF,0x0081079B,&CheckMasterLevel); // Experience Bar

	SetCompleteHook(0xFF,0x0047FE31,&CheckGensBattleMap);

	SetCompleteHook(0xFF,0x0059890D,&CheckGensBattleMap);

	SetCompleteHook(0xFF,0x0059A399,&CheckGensBattleMap);

	SetCompleteHook(0xFF,0x0059A93C,&CheckGensBattleMap);

	SetCompleteHook(0xFF,0x0059B13B,&CheckGensBattleMap);

	SetCompleteHook(0xFF,0x005A4261,&CheckGensBattleMap);

	SetCompleteHook(0xFF,0x005A4D52,&CheckGensBattleMap);

	SetCompleteHook(0xFF,0x005B6117,&CheckGensBattleMap);

	SetCompleteHook(0xFF,0x0065A6CE,&CheckGensBattleMap);

	SetCompleteHook(0xFF,0x00727987,&CheckGensBattleMap);

	SetCompleteHook(0xFF,0x007861F1,&CheckGensBattleMap);

	SetCompleteHook(0xFF,0x007D32FA,&CheckGensBattleMap);

	SetCompleteHook(0xFF,0x007D3B0D,&CheckGensBattleMap);

	SetCompleteHook(0xE9,0x008317BD,&CompareGensMoveIndex);

	//SetCompleteHook(0xFF,0x00777DC8,&DrawEffectsPic); //??

	//SetByte(0x004ADD59+3, 180); //Efeito Lite

	//SetCompleteHook(0xFF,0x007EFC93,&CheckIsLuckyItem);

	DisableStaticEffect		= GetPrivateProfileIntA("AntiLag", "DisableStaticEffect", 0, "./Settings.ini");
	DisableDynamicEffect	= GetPrivateProfileIntA("AntiLag", "DisableDynamicEffect", 0, "./Settings.ini");
	DisableSkillEffect		= GetPrivateProfileIntA("AntiLag", "DisableSkillEffect", 0, "./Settings.ini");
	DisableGlowEffect		= GetPrivateProfileIntA("AntiLag", "DisableGlowEffect", 0, "./Settings.ini");

	Anisotropy				= GetPrivateProfileIntA("Graphics","Anisotropy",1,"./Settings.ini");
	MaxAnisotropy			= GetPrivateProfileIntA("Graphics","MaxAnisotropy",1,"./Settings.ini");
	Linear					= GetPrivateProfileIntA("Graphics","Linear",1,"./Settings.ini");
	Tron					= GetPrivateProfileIntA("Graphics","TronEffects", 0, "./Settings.ini");
	MiniMap					= GetPrivateProfileIntA("Graphics","MiniMap", 0, "./Settings.ini");
	Fog						= GetPrivateProfileIntA("Graphics","Fog",1,"./Settings.ini");

	GMT						= GetPrivateProfileIntA("Other","ServerTime",0,"./Settings.ini");

	DisablePing				= GetPrivateProfileIntA("Other","DisablePing",0,"./Settings.ini");

	MiniMapActive			= 1;

}

BOOL CheckIsLuckyItem(int ItemID) // OK
{
  bool result;

  if ( ItemID < 4158 || ItemID > 4168 )
  {
    if ( ItemID < 3646 || ItemID > 3656 )
    {
      if ( ItemID < 5694 || ItemID > 5704 )
      {
        if ( ItemID < 5182 || ItemID > 5192 )
          result = ItemID >= 4670 && ItemID <= 4680;
        else
          result = 1;
      }
      else
      {
        result = 1;
      }
    }
    else
    {
      result = 1;
    }
  }
  else
  {
    result = 1;
  }
  return result;
}

BOOL CheckGensBattleMap(int map) // OK
{
	for(int n=0;n < GensBattleMapCount;n++)
	{
		if(GensBattleMap[n] == map)
		{
			return 1;
		}
	}

	return 0;
}

BOOL CheckGensMoveIndex(int idx) // OK
{
	for(int n=0;n < GensMoveIndexCount;n++)
	{
		if(GensMoveIndex[n] == idx)
		{
			return 1;
		}
	}

	return 0;
}

__declspec(naked) void LoginTab() // OK
{
	static DWORD LoginTabAddress1 = 0x0040B16F;

	__asm
	{
		Push 0
		Mov Eax,Dword Ptr Ss:[Ebp-0x38]
		Mov Ecx,Dword Ptr Ds:[Eax+0x350]
		Mov Edx,Dword Ptr Ss:[Ebp-0x38]
		Mov Eax,Dword Ptr Ds:[Edx+0x350]
		Mov Edx,Dword Ptr Ds:[Eax]
		Call Dword Ptr Ds:[Edx+0x30]
		Mov Eax,Dword Ptr Ss:[Ebp-0x38]
		Mov Ecx,Dword Ptr Ds:[Eax+0x354]
		Push Ecx
		Mov Edx,Dword Ptr Ss:[Ebp-0x38]
		Mov Ecx,Dword Ptr Ds:[Edx+0x350]
		Mov Eax,Dword Ptr Ss:[Ebp-0x38]
		Mov Edx,Dword Ptr Ds:[Eax+0x350]
		Mov Eax,Dword Ptr Ds:[Edx]
		Call Dword Ptr Ds:[Eax+0x58]
		Mov Ecx,Dword Ptr Ss:[Ebp-0x38]
		Mov Edx,Dword Ptr Ds:[Ecx+0x350]
		Push Edx
		Mov Eax,Dword Ptr Ss:[Ebp-0x38]
		Mov Ecx,Dword Ptr Ds:[Eax+0x354]
		Mov Edx,Dword Ptr Ss:[Ebp-0x38]
		Mov Eax,Dword Ptr Ds:[Edx+0x354]
		Mov Edx,Dword Ptr Ds:[Eax]
		Call Dword Ptr Ds:[Edx+0x58]
		Jmp [LoginTabAddress1]
	}
}

__declspec(naked) void CheckMasterLevel() // OK
{
	static DWORD CheckMasterLevelAddress1 = 0x005875A0;

	_asm
	{
		Push Ebp
		Mov Ebp,Esp
		Mov Eax,Dword Ptr Ds:[MAIN_CHARACTER_STRUCT]
		Xor Ecx,Ecx
		Mov Cx,Word Ptr Ds:[Eax+0x0E]
		Cmp Ecx,0x190
		Je NEXT
		Xor Eax,Eax
		Jmp EXIT
		NEXT:
		Xor Edx,Edx
		Mov Dl,Byte Ptr Ss:[Ebp+0x08]
		Push Edx
		Call [CheckMasterLevelAddress1]
		Add Esp,0x04
		EXIT:
		Pop Ebp
		Retn
	}
}

__declspec(naked) void CompareGensMoveIndex() // OK
{
	static DWORD CheckGensMoveIndexAddress1 = 0x0051B090;
	static DWORD CheckGensMoveIndexAddress2 = 0x008317FC;
	static DWORD CheckGensMoveIndexAddress3 = 0x008317EA;

	__asm
	{
		Lea Ecx,Dword Ptr Ss:[Ebp-0x08]
		Call [CheckGensMoveIndexAddress1]
		Mov Ecx,Dword Ptr Ds:[Eax]
		Mov Edx,Dword Ptr Ds:[Ecx]
		Push Edx
		Call [CheckGensMoveIndex]
		Add Esp,0x04
		Test Eax,Eax
		Jnz EXIT
		Jmp [CheckGensMoveIndexAddress2]
		EXIT:
		Jmp [CheckGensMoveIndexAddress3]
	}
}

void DrawEffectsPic(int &EffectID, float StartX, float StartY, float StartWidth, float StartHeight )
{
	////console.Log("", "%d | %f | %f | %f | %f", EffectID, StartX, StartY, StartWidth, StartHeight);
	
	if ( EffectID > 0 && EffectID < 180 )
	{
		int EffectValue = (EffectID - 1) % 80;
		float SourceX = (double)(EffectValue % 10) * StartWidth / 256.0;
		float SourceY = (double)(EffectValue / 10) * StartHeight / 256.0;
		float SourceWidth = StartWidth / 256.0;
		float SourceHeight = StartHeight / 256.0;
		pDrawImage((EffectID - 1) / 80 + 31725, StartX, StartY, StartWidth, StartHeight, SourceX, SourceY, SourceWidth, SourceHeight, 1, 1, 0);
	}
}


#if COPY_RIGHT
__declspec(naked) void Copyright()
{
static DWORD	Test_Buff;

static char		Test_LevelBuff[40];

	gInterface.DrawFormat(eWhite, (MAX_WIN_WIDTH / 2) - 50, 455, 200, 0, "EmU - Servers @ Copyright 2024");
	
	gInterface.DrawFormat(eWhite, (MAX_WIN_WIDTH / 2) - 30, 465, 200, 0, "Derechos Reservados");

	_asm
	{
		lea eax, Test_LevelBuff
		push eax
	}
	_asm
	{
		mov Test_Buff, 0x004D7D1D
		jmp Test_Buff
	}
}
#endif
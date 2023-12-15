#pragma once

#include "Protocol.h"

#define pMaxLife		*(WORD*)0x0087935F8
#define pMaxMana		*(WORD*)0x0087935FA
#define sub_791000		((double(__stdcall*)(float a4, float a5, int a6, float a7)) 0x00854FE0)
#define sub_854EE0		((void (__thiscall*)()) 0x00854EE0)


#define sub_9CEBF0		((signed int(__cdecl*)(double a1)) 0x9CEBF0)

#define sub_849110      ((char(__thiscall*)()) 0x00849110)

#define sub_790B10		((bool(__cdecl*)(int a1, int a2, int a3, int a4)) 0x00790B10)

#define sub_813DC0		((void(__thiscall*)(int a1, int a5, float a6, float a7, float a8, float a9)) 0x813DC0)

#define sub_861110		((void *(*)()) 0x00861110)
#define sub_861200		((int(__thiscall*)(int This)) 0x00861200)
#define sub_637A30        ((void(__cdecl*)()) 0x00637A30)

#define sub_9406A0		((int(__thiscall*)(LPVOID This, char a2))0x9406A0)

#define sub_943DC0      ((char(__cdecl*)(int a1)) 0x00943DC0)

#define sub_4AD0E0      ((signed int(__cdecl*)(unsigned __int16 a1)) 0x004AD0E0)
#define sub_5B89C0      ((bool(__cdecl*)(int a1)) 0x005B89C0)
#define sub_4E8D80		((bool(__stdcall*)(signed int a1, signed int a2, signed int a3)) 0x004E8D80)
#define sub_5111D0		((char(__stdcall*)(signed int a4)) 0x005111D0)
#define sub_511110		((char(__stdcall*)(signed int a1, __int16 a2)) 0x00511110)
#define sub_511290		((bool(__stdcall*)(__int16 a1, __int16 a2, int a3, int a4)) 0x00511290)
#define sub_4EAC90		((char(__stdcall*)(int a3)) 0x004EAC90)
#define sub_587A80		((signed int(*)()) 0x00587A80)
#define sub_814F30		((void(__stdcall*)(int a1, float a2, float a3, float a4, float a5)) 0x00814F30)

#define sub_7798F0		((char(__stdcall*)(int a1, char a5)) 0x007798F0)

#define sub_776CC0		((int(__thiscall*)(int This))0x00776CC0)

#define SkillStruct		*(DWORD*)0x8128ABC
#define SkillList		*(DWORD*)0x8128AC8

struct PMSG_CASH_SHOP_OPEN_SEND
{
	#pragma pack(1)
	PSBMSG_HEAD header; // C1:D2:02
	BYTE OpenType;
	#pragma pack()
};

class CCustomInterface
{
public:
	CCustomInterface();
	static void DrawInterfaceS2Menu();
	static void DrawInterfaceS2HP();
	static void DrawInterfaceS2SD();
	static void DrawInterfaceS2AG();
	static void DrawInterfaceS2Buttom();
	static void DrawInterfaceS2Exp();
	static void DrawInterfaceS2Skills(int a1);
	static void DrawInterfaceS2FriendButtom();
	static void DrawInterfaceS2DisableR();
	static void DrawInterfaceS2SkillClickPosition();
	static void DrawInterfaceS2SkillSwitchBar();
	static void DrawInterfaceS2SkillSwitchClick();
	static void DrawInterfaceS2SkillSwitchDraw();
	static void DrawInterfaceS2PotionQ();
	static void DrawInterfaceS2PotionW();
	static void DrawInterfaceS2PotionE();

	static void DrawInterfaceS8Menu();
	static void DrawInterfaceS8HP();
	static void DrawInterfaceS8SD();
	static void DrawInterfaceS8AG();
	static void DrawInterfaceS8Buttom();
	static void DrawInterfaceS8Exp();
	static void DrawInterfaceS8Skills(int a1);
	static void DrawInterfaceS8FriendButtom();
	static bool DrawInterfaceS8ChatMain(int a1);
	static char DrawInterfaceS8ChatButtom(int a1, int a2, int a3, int *a4);
	static void DrawInterfaceS8ChatPosition1(); 
	static void DrawInterfaceS8ChatPosition2(); 
	static void DrawInterfaceS8ChatPosition3(); 
	static void DrawInterfaceS8ChatPosition4(); 
	static void DrawInterfaceS8ChatPosition5(); 
	static void DrawInterfaceS8SkillClickPosition();
	static void DrawInterfaceS8SkillSwitchBar();
	static void DrawInterfaceS8SkillSwitchBar2();
	static void DrawInterfaceS8SkillSwitchClick();
	static void DrawInterfaceS8SkillSwitchDraw();
	static void DrawInterfaceS8SkillDarkRavenDrawPosition();
	static void DrawInterfaceS8SkillDarkRavenClickPosition();
	static void DrawInterfaceS8PotionQ();
	static void DrawInterfaceS8PotionW();
	static void DrawInterfaceS8PotionE();
	static void DrawInterfaceS8PotionR();
	void DrawInterfaceS8DrawSkill(int a1, int Skill,float PosX,float PosY,float Width,float Height);

	bool EventNewInterface_All(DWORD Event);
	bool EventNewInterface_Party(DWORD Event);
	bool EventNewInterface_Character(DWORD Event);
	bool EventNewInterface_Inventory(DWORD Event);
	bool EventNewInterface_Cashshop(DWORD Event);
	bool EventNewInterface_Menu(DWORD Event);
	bool EventNewInterface_Guild(DWORD Event);
	bool EventNewInterface_Friend(DWORD Event);
	bool EventNewInterface_Quest(DWORD Event);
	void Load();
	DWORD gLevelExperience[401];
	QWORD m_MasterLevelExperienceTable[1001];
private:
	bool XkeyUp;

};
extern CCustomInterface gCustomInterface;
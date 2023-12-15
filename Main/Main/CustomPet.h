#pragma once

//#define ItemId(x, y)            ((x * 512) + y)
#define pPreviewPetThis            *(DWORD*)0x007BC4F04

#define sub_57D9A0					((DWORD(__cdecl*)(DWORD)) 0x57D9A0)
#define sub_96A4C0					((int(__thiscall*)(LPVOID This, signed int a2)) 0x96A4C0)
#define sub_402BC0					((LPVOID(*)())0x402BC0)
#define sub_58AA80					((DWORD(__cdecl*)(DWORD)) 0x58AA80)
#define sub_558630					((void(__cdecl*)(int a1, int a2, int a3)) 0x558630)
#define sub_5012D0					((DWORD(__cdecl*)(DWORD)) 0x5012D0)
#define sub_9253D0					((int(__thiscall*)(LPVOID This,int a1, short a2)) 0x9253D0)
#define sub_4DB230					((LPVOID(*)())0x4DB230)
#define sub_501700					((DWORD(__cdecl*)(DWORD, DWORD, DWORD, DWORD, DWORD)) 0x501700)
#define pGetRand					((int(*)()) 0x9CFB8D)

#define sub_5D81B0					((double(__cdecl*)(float a1, float a2)) 0x5D81B0)
#define sub_5EBBB0					((void(__cdecl*)(int a4, char a5, int a6, int a7)) 0x5EBBB0)
#define sub_5DBA10					((bool(__cdecl*)(float a1, float a2, float a3)) 0x5DBA10)

#define sub_4C8CE0					((DWORD(__cdecl*)(DWORD)) 0x4C8CE0)


#include "Item.h"
#include "Protocol.h"

enum eBugType
{
    NewPet        = 7972,
};

//typedef void (__thiscall *ObjCreatePet)(ObjectItem * ItemId);
typedef void (__thiscall *ObjCreatePet)(int ItemId);
extern ObjCreatePet gObjCreatePet;
// --
//typedef int (__cdecl *ObjCreateBug)(int BugId, VAngle* Arg2, ObjectModel* Arg3, int Arg4, int Arg5);
//extern ObjCreateBug gObjCreateBug;

typedef int (__cdecl *ObjCreateBug)(int BugId, int Arg2, int Arg3, int Arg4, int Arg5);
extern ObjCreateBug gObjCreateBug;

// --
void gObjCreatePetExHook();
static void		RefreshViewPortItem(int a1);
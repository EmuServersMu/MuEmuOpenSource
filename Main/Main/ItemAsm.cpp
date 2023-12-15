#include "stdafx.h"
#include "Offset.h"
#include "Util.h"
#include "TMemory.h"
#include "ItemAsm.h"
#include "Import.h"
#include "Defines.h"

DWORD IsBowItem = 0;
DWORD IsCrossItem = 0;
DWORD BowValue = 0x09C;
DWORD MaxBoneCount = 0x108;
DWORD WorldPosition = 0x0FC;

DWORD oCreateEffect = 0x006D9070; // 1.04D ENG
DWORD ReturnBowCode = 0x0074A12E; // 1.04D ENG
DWORD BowPosition = 0x005CC8ED; // 1.04D ENG
DWORD NextBowPosition = 0x005CC92E; // 1.04D ENG
DWORD BowAddPlayerDimension_Offset = 0x0056617F; // 1.04D ENG
DWORD ReturnCrossCode	= 0x00749DD2;

void __declspec(naked) cBowAddSkillEffect()
{
	_asm
	{
			mov ecx, dword ptr ss : [ebp - 0x04]
			mov dword ptr ss : [ebp - 0x14], ecx
			mov IsBowItem, ecx
	}
	// ---
    if(IsBowItem >= ITEM2(4, 25) && IsBowItem <= ITEM2(4, 34)) // Devil Crossbow
	{
		_asm
		{
			push - 1
				push 0
				push 0
				mov dx, word ptr ss : [ebp + 0x18]
				push edx
				mov ax, word ptr ss : [ebp + 0x14]
				push eax
				mov ecx, dword ptr ss : [ebp + 0x0C]
				mov dx, word ptr ds : [ecx + 0x2C]
				push edx
				mov eax, dword ptr ss : [ebp + 0x0C]
				push eax
				mov ecx, dword ptr ss : [ebp - 0x8]
				push ecx
				mov edx, dword ptr ss : [ebp + 0x0C]
				add edx, BowValue
				push edx
				mov eax, dword ptr ss : [ebp + 0x0C]
				add eax, MaxBoneCount
				push eax
				mov ecx, dword ptr ss : [ebp + 0x0C]
				add ecx, WorldPosition
				push ecx
				push 298
				call oCreateEffect
		}
	}
	_asm
	{
		jmp ReturnBowCode
	}
}

void __declspec(naked) cCrossAddSkillEffect()
{
    _asm
    {
		mov ecx, dword ptr ss : [ebp - 0x0C]
		mov dword ptr ss : [ebp - 0x10], ecx
		mov IsCrossItem, ecx
    }
    // ---
    if(IsCrossItem >= ITEM2(4, 25) && IsCrossItem <= ITEM2(4, 44)) // Devil Crossbow
    {
        _asm
        {
			    push - 1
				push 0
				push 0
				mov dx, word ptr ss : [ebp + 0x18]
				push edx
				mov ax, word ptr ss : [ebp + 0x14]
				push eax
				mov ecx, dword ptr ss : [ebp + 0x0C]
				mov dx, word ptr ds : [ecx + 0x2C]
				push edx
				mov eax, dword ptr ss : [ebp + 0x0C]
				push eax
				mov ecx, dword ptr ss : [ebp - 0x8]
				push ecx
				mov edx, dword ptr ss : [ebp + 0x0C]
				add edx, BowValue
				push edx
				mov eax, dword ptr ss : [ebp + 0x0C]
				add eax, MaxBoneCount
				push eax
				mov ecx, dword ptr ss : [ebp + 0x0C]
				add ecx, WorldPosition
				push ecx
				push 298
				call oCreateEffect
        }
    }
    // ---
    _asm
    {
        jmp ReturnCrossCode
    }
}

void __declspec(naked) cBowAddInventoryPos()
{
	_asm
	{
		mov ecx, dword ptr ss : [ebp + 0x8]
			mov dword ptr ss : [ebp + 0x8], ecx
			mov IsBowItem, ecx
	}
	// ---
	if (IsBowItem == 0x0CAB)
	{
		_asm{jmp BowPosition}
	}
	else if (IsBowItem == ITEM2(4, 25))
	{
		_asm{jmp BowPosition}
	}
	else if (IsBowItem == ITEM2(4, 26))
	{
		_asm{jmp BowPosition}
	}
	else if (IsBowItem == ITEM2(4, 27))
	{
		_asm{jmp BowPosition}
	}
	else if (IsBowItem == ITEM2(4, 28))
	{
		_asm{jmp BowPosition}
	}
	else if (IsBowItem == ITEM2(4, 29))
	{
		_asm{jmp BowPosition}
	}
	else if (IsBowItem == ITEM2(4, 30))
	{
		_asm{jmp BowPosition}
	}
	else if (IsBowItem == ITEM2(4, 31))
	{
		_asm{jmp BowPosition}
	}
	else if (IsBowItem == ITEM2(4, 32))
	{
		_asm{jmp BowPosition}
	}
	else if (IsBowItem == ITEM2(4, 33))
	{
		_asm{jmp BowPosition}
	}
	else if (IsBowItem == ITEM2(4, 34))
	{
		_asm{jmp BowPosition}
	}
	else
	{
		_asm{jmp NextBowPosition}
	}
}


void __declspec(naked) cBowAddPlayerDimension()
{
	_asm
	{
			cmp dword ptr ss : [ebp + 0x1c], 0x0CA7
			je ReturnLoad
			cmp dword ptr ss : [ebp + 0x1c], ITEM2(4, 25)
			je ReturnLoad
			cmp dword ptr ss : [ebp + 0x1c], ITEM2(4, 26)
			je ReturnLoad
			cmp dword ptr ss : [ebp + 0x1c], ITEM2(4, 27)
			je ReturnLoad
			cmp dword ptr ss : [ebp + 0x1c], ITEM2(4, 28)
			je ReturnLoad
			cmp dword ptr ss : [ebp + 0x1c], ITEM2(4, 29)
			je ReturnLoad
			cmp dword ptr ss : [ebp + 0x1c], ITEM2(4, 30)
			je ReturnLoad
			cmp dword ptr ss : [ebp + 0x1c], ITEM2(4, 31)
			je ReturnLoad
			cmp dword ptr ss : [ebp + 0x1c], ITEM2(4, 32)
			je ReturnLoad
			cmp dword ptr ss : [ebp + 0x1c], ITEM2(4, 33)
			je ReturnLoad
			cmp dword ptr ss : [ebp + 0x1c], ITEM2(4, 34)
			je ReturnLoad
			// ---
		ReturnLoad :
		// ---
		jmp BowAddPlayerDimension_Offset
	}
}

void __declspec(naked) cCrossBowAddPlayerDimension()
{
    static DWORD Address1 = 0x00565994;
    static DWORD Address2 = 0x005659E7;  

	_asm
	{
	   Mov Ecx, Dword ptr ss : [ebp + 0x1C]
	   Mov Dword ptr ss : [ebp + 0x1C],Ecx
	   Mov IsCrossItem, Ecx
	}

    if(IsCrossItem >= ITEM2(4,8) && IsCrossItem <= ITEM2(4,14)||IsCrossItem == ITEM2(4,16)||IsCrossItem == ITEM2(4,18)||IsCrossItem == ITEM2(4,19) || IsCrossItem >= ITEM2(4, 35) && IsCrossItem <= ITEM2(4, 44)) // Devil Crossbow
    {
		_asm{jmp Address1}
	}
	else
	{
		_asm{jmp Address2}
	}
}



void InitBows()
{
	SetRange((LPVOID)iBowAddSkillEffect, 6, ASM::NOP);
	SetJmp((LPVOID)iBowAddSkillEffect, cBowAddSkillEffect);
	// ----
	SetRange((LPVOID)iBowAddInventoryPos, 6, ASM::NOP);
	SetJmp((LPVOID)iBowAddInventoryPos, cBowAddInventoryPos);
	// ----
	SetRange((LPVOID)iBowAddPlayerDimension, 7, ASM::NOP);
	SetJmp((LPVOID)iBowAddPlayerDimension, cBowAddPlayerDimension);
	// ----
    SetRange((LPVOID)iCrossAddSkillEffect, 6, ASM::NOP);
    SetJmp((LPVOID)iCrossAddSkillEffect, cCrossAddSkillEffect);
	// ----
	SetRange((LPVOID)iCrossBowAddPlayerDimension, 6, ASM::NOP);
	SetJmp((LPVOID)iCrossBowAddPlayerDimension, cCrossBowAddPlayerDimension);
	// ----
}


#include "stdafx.h"
#include "CustomGloves.h"
#include "Item.h"
#include "import.h"
#include "Util.h"

cCustomGloves gCustomGloves;

cCustomGloves::cCustomGloves() // OK
{
	this->Init();
}

cCustomGloves::~cCustomGloves() // OK
{

}

void cCustomGloves::Init() // OK
{
	for(int n=0;n < MAX_CUSTOM_GLOVES;n++)
	{
		this->m_CustomGlovesInfo[n].Index = -1;
	}
}

void cCustomGloves::Load(CUSTOM_RF_GLOVES* info) // OK
{
	for(int n=0;n < MAX_CUSTOM_GLOVES;n++)
	{
		this->SetInfo(info[n]);
	}
}

void cCustomGloves::SetInfo(CUSTOM_RF_GLOVES info) // OK
{
	if(info.Index < 0 || info.Index >= MAX_CUSTOM_GLOVES)
	{
		return;
	}

	this->m_CustomGlovesInfo[info.Index] = info;
}

CUSTOM_RF_GLOVES* cCustomGloves::GetInfoByItem(int index)
{
	for (int i=0;i<MAX_CUSTOM_GLOVES; i++)
	{
		if (this->m_CustomGlovesInfo[i].Index == -1)
		{
			continue;
		}

		if (this->m_CustomGlovesInfo[i].ItemIndex == index)
		{
			return &this->m_CustomGlovesInfo[i];
		}
	}

	return 0;
}

CUSTOM_RF_GLOVES* cCustomGloves::GetInfoByRD(int index)
{
	for (int i=0;i<MAX_CUSTOM_GLOVES; i++)
	{
		if (this->m_CustomGlovesInfo[i].Index == -1)
		{
			return 0;
		}

		if (this->m_CustomGlovesInfo[i].TextureLeftIndex == index)
		{
			return &this->m_CustomGlovesInfo[i];
		}

		if (this->m_CustomGlovesInfo[i].TextureRightIndex == index)
		{
			return &this->m_CustomGlovesInfo[i];
		}
	}

	return 0;
}

bool cCustomGloves::GetCustomItemColor(int ItemIndex,float* ItemColor) // OK
{
	CUSTOM_RF_GLOVES* lpInfo = this->GetInfoByItem(ItemIndex);

	if(lpInfo == 0)
	{
		return 0;
	}

	ItemColor[0] = (float)(lpInfo->ColorR/255.0f);
	ItemColor[1] = (float)(lpInfo->ColorG/255.0f);
	ItemColor[2] = (float)(lpInfo->ColorB/255.0f);
	return 1;
}

#define sub_50D810_Addr		((int(__thiscall*)(int a1, int a2, int a3, int a4)) 0x50D810)
#define sub_512D50_Addr		((void*(__thiscall*)(void* a1)) 0x512D50)
#define sub_513C60_Addr		((char*(__thiscall*)(char *This, void *a2, int a3)) 0x513C60)
#define sub_5135F0_Addr		((char*(__thiscall*)(DWORD *This, int a2, int a3)) 0x5135F0)
#define sub_512D60_Addr		((void(*)()) 0x512D60)

void cCustomGloves::AssocGloves(char* This)
{
	for (int i=0;i<MAX_CUSTOM_GLOVES; i++)
	{
		if (this->m_CustomGlovesInfo[i].Index == -1)
		{
			return;
		}

		sub_50D810_Addr((int)(This + 92), this->m_CustomGlovesInfo[i].ItemIndex+ITEM_BASE_MODEL, this->m_CustomGlovesInfo[i].TextureLeftIndex, this->m_CustomGlovesInfo[i].TextureRightIndex);
		void* v2 = sub_512D50_Addr(This + 92);
		char* v3 = sub_513C60_Addr(This, v2, (int)(This + 92));
		sub_5135F0_Addr((DWORD *)This + 15, (int)This, (int)v3);
		sub_512D60_Addr();
	}
}


bool cCustomGloves::CheckGloves(int ItemID)
{
	for (int i=0;i<MAX_CUSTOM_GLOVES; i++)
	{
		if (this->m_CustomGlovesInfo[i].Index == -1)
		{
			return false;
		}

		if (ItemID == this->m_CustomGlovesInfo[i].ItemIndex)
		{
			return true;
		}
	}
	return false;
}

void cCustomGloves::GlovesAssoc(char *This)
{
	sub_50D810_Addr((int)(This + 92), 1203, 610, 611);
	void* v2 = sub_512D50_Addr(This + 92);
	char* v3 = sub_513C60_Addr(This, v2, (int)(This + 92));
	sub_5135F0_Addr((DWORD *)This + 15, (int)This, (int)v3);
	sub_512D60_Addr();
	// ----
	sub_50D810_Addr((int)(This + 92), 1204, 612, 613);
	v2 = sub_512D50_Addr(This + 92);
	v3 = sub_513C60_Addr(This, v2, (int)(This + 92));
	sub_5135F0_Addr((DWORD *)This + 15, (int)This, (int)v3);
	sub_512D60_Addr();
	// ----
	sub_50D810_Addr((int)(This + 92), 1205, 614, 615);
	v2 = sub_512D50_Addr(This + 92);
	v3 = sub_513C60_Addr(This, v2, (int)(This + 92));
	sub_5135F0_Addr((DWORD *)This + 15, (int)This, (int)v3);
	sub_512D60_Addr();
	// ----
	sub_50D810_Addr((int)(This + 92), 1206, 616, 617);
	v2 = sub_512D50_Addr(This + 92);
	v3 = sub_513C60_Addr(This, v2, (int)(This + 92));
	sub_5135F0_Addr((DWORD *)This + 15, (int)This, (int)v3);
	sub_512D60_Addr();
	// ----
	sub_50D810_Addr((int)(This + 92), 1211, 610, 611);
	v2 = sub_512D50_Addr(This + 92);
	v3 = sub_513C60_Addr(This, v2, (int)(This + 92));
	sub_5135F0_Addr((DWORD *)This + 15, (int)This, (int)v3);
	sub_512D60_Addr();
	// ----
	gCustomGloves.AssocGloves(This);
}

static BOOL bBattleGlovesGlow_Switcher;

void __declspec ( naked ) cCustomGloves::BattleGloveGlow() {
    static DWORD dwBattleGlovesGlow_Pointer;
    static DWORD dwBattleGlovesGlow_Buffer;
    static DWORD dwBattleGlovesNewGlow_Buffer;
    static DWORD dwBattleGlovesGlow_Jump = 0x005F94E8;
    // ----
    bBattleGlovesGlow_Switcher = FALSE;
    // ----
    _asm {
        MOV dwBattleGlovesGlow_Pointer, EAX
    }

    // ----
    if ( dwBattleGlovesGlow_Pointer == GET_ITEM_MODEL ( 0, 35 ) ) {
        bBattleGlovesGlow_Switcher = TRUE;
    }
    else if ( gCustomGloves.CheckGloves(dwBattleGlovesGlow_Pointer-ITEM_BASE_MODEL)/*dwBattleGlovesGlow_Pointer == GET_ITEM_MODEL ( 0, 41 )*/ ) {
        bBattleGlovesGlow_Switcher = FALSE;
        // ----
        _asm {
            MOV DWORD PTR SS:[EBP-0x4], 0x2C
            JMP dwBattleGlovesGlow_Jump
        }
    }

    // ----
    if ( bBattleGlovesGlow_Switcher == TRUE ) {
        _asm {
            MOV dwBattleGlovesGlow_Buffer, 0x005F91C9
            JMP dwBattleGlovesGlow_Buffer
        }
    }
    else {
        _asm {
            MOV dwBattleGlovesGlow_Buffer, 0x005F91D5
            JMP dwBattleGlovesGlow_Buffer
        }
    }
}

void __declspec(naked) cCustomGloves::BattleGlovePos()
{
    static DWORD IsRFItem = 0;
    static DWORD RFPosition = 0x005CD084; // 1.04D ENG
    static DWORD NextRFPosition = 0x005CD086; // 1.04D ENG

	static float GloveSizeX = 0.0f;
	static float GloveSizeY = 0.0f;
	static float GloveSizeZ = 0.0f;

	static double GlovePosX = 0.04299999988824129f;
	static double GlovePosY = 0.08499999966472387f;
    //
    _asm {
        mov ecx, dword ptr ss : [ebp + 0x8]
        mov dword ptr ss : [ebp + 0x8], ecx
        mov IsRFItem, ecx
    }
    // ---
    if ( IsRFItem == 0x04B3 ) {
        _asm {jmp RFPosition}
    }
    else if ( gCustomGloves.CheckGloves(IsRFItem-ITEM_BASE_MODEL) ) {
        _asm 
		{
			FLD DWORD PTR SS:[EBP-0x4C]
			FSUB QWORD PTR DS:[GlovePosX]                     //FLOAT 0.004999999888241291
			FSTP DWORD PTR SS:[EBP-0x4C]
			FLD DWORD PTR SS:[EBP-0x48]
			FADD QWORD PTR DS:[GlovePosY]                     //FLOAT 0.01499999966472387
			FSTP DWORD PTR SS:[EBP-0x48]

			FLD DWORD PTR DS:[GloveSizeX]
			FSTP DWORD PTR DS:[0x82C6320]                     //FLOAT 0.0
			FLD DWORD PTR DS:[GloveSizeY]
			FSTP DWORD PTR DS:[0x82C6324]                     //FLOAT 0.0
			FLD DWORD PTR DS:[GloveSizeZ]
			FSTP DWORD PTR DS:[0x82C6328]                     //FLOAT 0.0
			jmp NextRFPosition
		}
    }
    else {
        _asm {jmp NextRFPosition}
    }
}

void __declspec(naked) cCustomGloves::BattleGloveSize()
{
    static DWORD IsRFItem = 0;
    static DWORD NextRFPosition2 = 0x005CF123; // 1.04D ENG

	static float Scale = 0.0035f;
	static double ScaleX = 0.05f;
    //
    _asm {
        mov ecx, dword ptr ss : [ebp + 0x8]
        mov dword ptr ss : [ebp + 0x8], ecx
        mov IsRFItem, ecx
    }
    // ---
	if ( gCustomGloves.CheckGloves(IsRFItem-ITEM_BASE_MODEL) ) {
        _asm 
		{

			MOV EDX,DWORD PTR SS:[EBP-0x5F4]
			FLD DWORD PTR SS:[Scale]
			FSTP DWORD PTR DS:[EDX+0x60]

			MOV EAX,DWORD PTR SS:[EBP-0x5F4]
			jmp NextRFPosition2
		}
    }
    else {
        _asm 
		{
			MOV EAX,DWORD PTR SS:[EBP-0x5F4]
			jmp NextRFPosition2
		}
    }
}

void cCustomGloves::DrawItemModel(float PosX, float PosY, float Width, float Height, int ItemID, int Level, int Excl, int Anc, bool OnMouse)
{
	if(gCustomGloves.CheckGloves(ItemID))
	{
		PosX -= 5.0f; // Aqui é a horizontal original menos 10.0f  5
		PosY -= 15.0f; // Aqui é a altura original menos 20.0f    15
	}

	pDrawItemModel(PosX, PosY, Width, Height, ItemID, Level, Excl, Anc, OnMouse);
}

void cCustomGloves::Load() 
{
	SetCompleteHook(0xE8,0x0050D905,&this->GlovesAssoc);

	//MemorySet(0x005F91C2,0x90,0x07); 
	//SetCompleteHook(0xE9,0x005F91C2,&this->BattleGloveGlow);

	MemorySet(0x005CD07D,0x90,0x07); 
	SetCompleteHook(0xE9,0x005CD07D,&this->BattleGlovePos);

	SetCompleteHook(0xE9,0x005CF11D,&this->BattleGloveSize);

	//SetCompleteHook(0xE8,0x004D5E40,&this->DrawItemModel);
	//SetCompleteHook(0xE8,0x004D5E87,&this->DrawItemModel);
	//SetCompleteHook(0xE8,0x005D174A,&this->DrawItemModel);
	//SetCompleteHook(0xE8,0x00793C5B,&this->DrawItemModel);
	//SetCompleteHook(0xE8,0x007A3B1B,&this->DrawItemModel);
	//SetCompleteHook(0xE8,0x007C71A8,&this->DrawItemModel);
	//SetCompleteHook(0xE8,0x007C71E6,&this->DrawItemModel);
	//SetCompleteHook(0xE8,0x007D972B,&this->DrawItemModel);
	//SetCompleteHook(0xE8,0x007DD5C0,&this->DrawItemModel);
	//SetCompleteHook(0xE8,0x008354DF,&this->DrawItemModel);
	//SetCompleteHook(0xE8,0x008462CE,&this->DrawItemModel);
	//SetCompleteHook(0xE8,0x00854659,&this->DrawItemModel);
	//SetCompleteHook(0xE8,0x00892EF1,&this->DrawItemModel);
	//SetCompleteHook(0xE8,0x0089443E,&this->DrawItemModel);
	//SetCompleteHook(0xE8,0x0089580C,&this->DrawItemModel);
	//SetCompleteHook(0xE8,0x0089787C,&this->DrawItemModel);
	//SetCompleteHook(0xE8,0x00897A6C,&this->DrawItemModel);
	//SetCompleteHook(0xE8,0x00897C7C,&this->DrawItemModel);
	//SetCompleteHook(0xE8,0x00943D7F,&this->DrawItemModel);
	//SetCompleteHook(0xE8,0x00949089,&this->DrawItemModel);
	//SetCompleteHook(0xE8,0x0094A969,&this->DrawItemModel);
	//SetCompleteHook(0xE8,0x0094CCA9,&this->DrawItemModel);
	//SetCompleteHook(0xE8,0x00949089,&this->DrawItemModel);
	//SetCompleteHook(0xE8,0x00950129,&this->DrawItemModel);
}
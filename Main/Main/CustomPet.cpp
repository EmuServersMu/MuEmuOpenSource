#include "stdafx.h"
#include "CustomPet.h"
#include "Util.h"
#include "Defines.h"
#include "Item.h"
#include "Import.h"
#include "TMemory.h"

ObjCreateBug gObjCreateBug			= (ObjCreateBug)0x00501700;
ObjCreatePet gObjCreatePet			= (ObjCreatePet)0x00835E40;

void gObjCreatePetEx(int ItemId)
{
  //  int ItemSwitch        = *(WORD*)ItemId;
  //  int PetPreview        = LODWORD(pPreviewPetThis) + 776;
  //  // ----
  //  switch (ItemSwitch)
  //  {
		//case GET_ITEM(12,189):
		//case GET_ITEM(12,194):
		//case GET_ITEM(12,220):
		//case GET_ITEM(12,221):
		//pRefreshViewport(oUserPreviewStruct, oUserPreviewStruct + 776, 0);
		//break;
  //  }

  //  //switch (ItemSwitch)
  //  //{
  //  //    case GET_ITEM(13, 200):
  //  //        gObjCreateBug(eBugType::NewPet, PetPreview + 252, PetPreview, 0, 0);
  //  //    break;
  //  //    // ---
  //  //}
  //  gObjCreatePet(ItemId);

    int ItemSwitch        = *(WORD*)ItemId;
    int PetPreview        = LODWORD(pPreviewPetThis) + 776;
    // ----

    switch (ItemSwitch)
    {
        case ITEM(13, 200):
            gObjCreateBug(ITEM2(13, 200), PetPreview + 252, PetPreview, 0, 0);
        break;
        // ---
    }
    gObjCreatePet(ItemId);
}

void RefreshViewPortItem(int a1)
{
	signed int v1; // ST14_4@1
	int result; // eax@1
	int v6; // [sp+Ch] [bp-14h]@2
	int v7; // [sp+10h] [bp-10h]@1
	int v8; // [sp+14h] [bp-Ch]@2
	BYTE v9; // [sp+1Dh] [bp-3h]@2
	BYTE v10; // [sp+1Eh] [bp-2h]@2
	BYTE v11; // [sp+1Fh] [bp-1h]@2

	v1 = sub_57D9A0(*(BYTE *)(a1 + 4) + (*(BYTE *)(a1 + 3) << 8));
	result = sub_96A4C0(sub_402BC0(), v1);
	v7 = result;
	if (result)
	{
		v6 = result + 776;
		v8 = sub_58AA80(a1 + 5);
		v11 = *(BYTE *)(a1 + 6) & 0xF;
		v10 = *(BYTE *)(a1 + 8) & 0x3F;
		v9 = *(BYTE *)(a1 + 9);
		switch ((signed int)*(BYTE *)(a1 + 6) >> 4)
		{
		case 7:
			if (v8 == 0x1FFF)
			{
				if (*(WORD*)(v7 + 520) == ITEM2(12,189)
					|| *(WORD*)(v7 + 520) == ITEM2(12,194)
					|| *(WORD*)(v7 + 520) == ITEM2(12,220)
					|| *(WORD*)(v7 + 520) == ITEM2(12,221))
				{
					sub_558630(v7, v6, 0);
				}
				*(WORD *)(v7 + 520) = -1;
			}
			else
			{
				*(WORD *)(v7 + 520) = v8 + 1171;
				*(BYTE *)(v7 + 522) = 0;
				if (*(WORD*)(v7 + 520) == ITEM2(12, 189)
					|| *(WORD*)(v7 + 520) == ITEM2(12, 194)
					|| *(WORD*)(v7 + 520) == ITEM2(12, 220)
					|| *(WORD*)(v7 + 520) == ITEM2(12, 221))
				{
					sub_558630(v7, v6, 0);
				}
			}
			break;
		case 8:
			if (v8 == 0x1FFF)
			{
				*(WORD *)(v7 + 556) = -1;
				sub_5012D0(v6);
				sub_9253D0(sub_4DB230(), v7, -1);
			}
			else
			{
				*(WORD *)(v7 + 556) = v8 + 1171;
				*(BYTE *)(v7 + 558) = 0;
				if (v8 >= ITEM(13, 147) && v8 <= ITEM(13, 410))
				{
					sub_501700(v8 + 1171, v6 + 252, v6, 0, 0);
				}
			}
			break;
		default:
			break;
		}
	}
	((void(*)(int))0x6411A0)(a1);
}

DWORD IsPet = 0;

Naked(SetNewPetMovement) 
{
	//static DWORD PetMoviment = 0x00503407;
	//static DWORD NextPet = 0x00503407;

	//_asm
	//{
	//	MOV ECX,DWORD PTR SS:[EBP+0x08]
	//	CMP DWORD PTR DS:[ECX+0x30],0x1E93
	//	JE SHORT PetMoviment
	//	//MOV EAX,DWORD PTR SS:[EBP+0x08]
	//	//CMP DWORD PTR DS:[EAX+0x30],0x1F5B
	//	//JE SHORT PetMoviment
	//	MOV EDX,DWORD PTR SS:[EBP+0x08]
	//	CMP DWORD PTR DS:[EDX+0x30],0x1E94
	//	JMP NextPet
	//}

    static DWORD AddressSatan = 0x00503407;
	static DWORD AddressOutro = 0x0050339A;
    static DWORD AddressFinal = 0x00503712;

	static DWORD CallAdress1 = 0x005034DA;
	static DWORD CallAdress2 = 0x00540C30;
	static DWORD CallAdress3 = 0x00540EA0;
	static DWORD CallAdress4 = 0x00959CE0;
	static DWORD CallAdress5 = 0x0095A1E0;
	static DWORD CallAdress6 = 0x009CFB8D;
	static DWORD CallAdress7 = 0x00503572;

	static float PetY = 250.0f;
	static float PetSize = 0.1f;

	_asm
	{
	   MOV ECX,DWORD PTR SS:[EBP+0x08]
	   MOV EDX,DWORD PTR SS:[ECX+0x30]
	   MOV IsPet, EDX
	}

		//char log[1024];

		//sprintf(log,"%d",IsPet);

		//MessageBox(NULL,log,"Warning!",NULL);

    if((IsPet >= ITEM2(13,0) && IsPet <= ITEM2(13,1)) || IsPet == ITEM2(13,200))
    {
		_asm
		{
			FLD DWORD PTR SS:[EBP-0x18]
			MOV EAX,DWORD PTR SS:[EBP+0x8]
			FSUB DWORD PTR DS:[EAX+0xFC]
			FSTP DWORD PTR SS:[EBP-0x108]
			FLD DWORD PTR SS:[EBP-0x14]
			MOV ECX,DWORD PTR SS:[EBP+0x8]
			FSUB DWORD PTR DS:[ECX+0x100]
			FSTP DWORD PTR SS:[EBP-0x104]
			FLD DWORD PTR SS:[EBP-0x10]
			MOV EDX,DWORD PTR SS:[EBP+0x8]
			FSUB DWORD PTR DS:[EDX+0x104]
			FSTP DWORD PTR SS:[EBP-0x100]
			FLD DWORD PTR SS:[EBP-0x108]
			FMUL DWORD PTR SS:[EBP-0x108]
			FLD DWORD PTR SS:[EBP-0x104]
			FMUL DWORD PTR SS:[EBP-0x104]
			FADDP ST(1),ST
			FSTP DWORD PTR SS:[EBP-0x118]
			FLD DWORD PTR SS:[EBP-0x2C]
			FMUL DWORD PTR SS:[EBP-0x2C]
			FLD DWORD PTR SS:[EBP-0x118]
			FCOMPP
			FSTSW AX
			TEST AH,1
			JNZ SHORT JUMP1
			PUSH ECX
			FLD DWORD PTR SS:[EBP-0x14]
			FSTP DWORD PTR SS:[ESP]
			PUSH ECX
			FLD DWORD PTR SS:[EBP-0x18]
			FSTP DWORD PTR SS:[ESP]
			MOV EAX,DWORD PTR SS:[EBP+0x08]
			PUSH ECX
			FLD DWORD PTR DS:[EAX+0x100]
			FSTP DWORD PTR SS:[ESP]
			MOV ECX,DWORD PTR SS:[EBP+0x08]
			PUSH ECX
			FLD DWORD PTR DS:[ECX+0xFC]
			FSTP DWORD PTR SS:[ESP]
			CALL CallAdress2
			ADD ESP,0x10
			FSTP DWORD PTR SS:[EBP-0x11C]
			PUSH ECX
			FLD DWORD PTR DS:[0xD23F68]
			FSTP DWORD PTR SS:[ESP]
			PUSH ECX
			FLD DWORD PTR SS:[EBP-0x11C]
			FSTP DWORD PTR SS:[ESP]
			MOV EDX,DWORD PTR SS:[EBP+0x08]
			PUSH ECX
			FLD DWORD PTR DS:[EDX+0x110]
			FSTP DWORD PTR SS:[ESP]
			CALL CallAdress3
			ADD ESP,0x0C
			MOV EAX,DWORD PTR SS:[EBP+0x08]
			FSTP DWORD PTR DS:[EAX+0x110]

			JUMP1:
			MOV ECX,DWORD PTR SS:[EBP+0x8]
			ADD ECX,0x174
			PUSH ECX
			MOV EDX,DWORD PTR SS:[EBP+0x08]
			ADD EDX,0x108
			PUSH EDX
			CALL CallAdress4
			ADD ESP,8
			LEA EAX,DWORD PTR SS:[EBP-0x114]
			PUSH EAX
			MOV ECX,DWORD PTR SS:[EBP+0x08]
			ADD ECX,0x174
			PUSH ECX
			MOV EDX,DWORD PTR SS:[EBP+0x08]
			ADD EDX,0x0A8
			PUSH EDX
			CALL CallAdress5
			ADD ESP,0x0C
			MOV EAX,DWORD PTR SS:[EBP+0x08]
			FLD DWORD PTR DS:[EAX+0xFC]
			FADD DWORD PTR SS:[EBP-0x114]
			MOV ECX,DWORD PTR SS:[EBP+0x08]
			FSTP DWORD PTR DS:[ECX+0xFC]
			MOV EDX,DWORD PTR SS:[EBP+0x08]
			FLD DWORD PTR DS:[EDX+0x100]
			FADD DWORD PTR SS:[EBP-0x110]
			MOV EAX,DWORD PTR SS:[EBP+0x08]
			FSTP DWORD PTR DS:[EAX+0x100]
			//MOV ECX,DWORD PTR SS:[EBP+0x8]
			//FLD DWORD PTR DS:[EDX+0x104]
			//FADD DWORD PTR SS:[EBP-0x10C]
			//MOV EDX,DWORD PTR SS:[EBP+0x8]
			//FSTP DWORD PTR DS:[EDX+0x104]
			
			//Ajusta a posição Y do pet
			FLD DWORD PTR DS:[PetY]
			FSTP DWORD PTR DS:[EDX+0x104]

			//Ajusta o tamanho do pet
			//FLD DWORD PTR DS:[PetSize]
			//FSTP DWORD PTR DS:[EDX+0x60]

			//Segunda parte: faz o pokemon descer
			//CALL CallAdress6
			//AND EAX,0x8000000F
			//JNS SHORT JUMP2
			//DEC EAX
			//OR EAX,0xFFFFFFF0
			//INC EAX

			//JUMP2:
			//SUB EAX,0x08
			//MOV DWORD PTR SS:[EBP-0x17C],EAX
			//FILD DWORD PTR SS:[EBP-0x17C]
			//MOV EAX,DWORD PTR SS:[EBP+0x08]
			//FADD DWORD PTR DS:[EAX+0x104]
			//MOV ECX,DWORD PTR SS:[EBP+0x08]
			//FSTP DWORD PTR DS:[ECX+0x104]

			//terceira parte: faz o pokemon subir e seguir o char
			CALL CallAdress6
			AND EAX,0x8000001F
			JNS SHORT JUMP3
			DEC EAX
			OR EAX,0xFFFFFFE0
			INC EAX

			JUMP3:
			TEST EAX,EAX
			JNZ FINAL
			FLDZ
			FSTP DWORD PTR SS:[EBP-0x120]
			FLD DWORD PTR SS:[EBP-0x2C]
			FMUL DWORD PTR SS:[EBP-0x2C]
			FLD DWORD PTR SS:[EBP-0x118]
			FCOMPP
			FSTSW AX
			TEST AH,1
			JNZ SHORT JUMP4
			CALL CallAdress6
			AND EAX,0x8000003F
			JNS SHORT JUMP7
			DEC EAX
			OR EAX,0xFFFFFFC0
			INC EAX

			JUMP7:
			ADD EAX,0x80
			MOV DWORD PTR SS:[EBP-0x180],EAX
			FILD DWORD PTR SS:[EBP-0x180]
			FCHS
			FMUL QWORD PTR DS:[0xD24388]
			FSTP DWORD PTR SS:[EBP-0x120]
			JMP SHORT JUMP5

			JUMP4:
			CALL CallAdress6
			AND EAX,0x8000003F
			JNS SHORT JUMP6
			DEC EAX
			OR EAX,0xFFFFFFC0
			INC EAX

			JUMP6:
			ADD EAX,10
			MOV DWORD PTR SS:[EBP-0x184],EAX
			FILD DWORD PTR SS:[EBP-0x184]
			FCHS
			FMUL QWORD PTR DS:[0xD24388]
			FSTP DWORD PTR SS:[EBP-0x120]
			CALL CallAdress6
			CDQ
			MOV ECX,0x168
			IDIV ECX
			MOV DWORD PTR SS:[EBP-0x188],EDX
			FILD DWORD PTR SS:[EBP-0x188]
			MOV EDX,DWORD PTR SS:[EBP+0x8]
			FSTP DWORD PTR DS:[EDX+0x110]

			JUMP5:
			MOV EAX,DWORD PTR SS:[EBP+0x8]
			FLDZ
			FSTP DWORD PTR DS:[EAX+0xA8]
			MOV ECX,DWORD PTR SS:[EBP+0x8]
			FLD DWORD PTR SS:[EBP-0x120]
			FSTP DWORD PTR DS:[ECX+0xAC]

			//Faz o pokemon subir
			//CALL CallAdress6
			//AND EAX,0x8000003F
			//JNS SHORT JUMP8
			//DEC EAX
			//OR EAX,0xFFFFFFC0
			//INC EAX

			//JUMP8:
			//SUB EAX,0x20
			//MOV DWORD PTR SS:[EBP-0x18C],EAX
			//FILD DWORD PTR SS:[EBP-0x18C]
			//FMUL QWORD PTR DS:[0xD24388]
			//MOV EDX,DWORD PTR SS:[EBP+0x08]
			//FSTP DWORD PTR DS:[EDX+0xB0]


			FINAL:


			
			jmp AddressFinal
		
		}
	}
	else
	{
		_asm{jmp AddressFinal}
	}
}

bool ResetPetPreviewEx(int ItemId)
{
    bool Result;
    // ----
    if (ItemId)
        Result = *(WORD*)ItemId == 0x1A00    //Angel
        || *(WORD*)ItemId == 0x1A01        //Satan
        || *(WORD*)ItemId == 0x1A02        //Unicorn
        || *(WORD*)ItemId == 0x1A03        //Dinorant
        || *(WORD*)ItemId == 0x1A04        //Dark Horse
        || *(WORD*)ItemId == 0x1A05        //Dark Raven
        || *(WORD*)ItemId == 0x1A25        //Fenrir     //
		// Reset Custom Pet Preview
        || *(WORD*)ItemId == ITEM(13,200)
		// Reset New Cape Preview
		|| *(WORD*)ItemId == ITEM(12, 189)
		|| *(WORD*)ItemId == ITEM(12, 194)
		|| *(WORD*)ItemId == ITEM(12, 220)
		|| *(WORD*)ItemId == ITEM(12, 221);

    else
        Result = 0;
    return Result;
}

bool SetPetPreviewScale(int a3, int a4, int a5, int a6, int a7)
{
  double v8; // ST0C_8@17
  signed int v9; // [sp+28h] [bp-4h]@4

  if ( CC_MAP_RANGE(pMapNumber) == 1 )
  {
    return 0;
  }
  else if ( *(BYTE *)(a6 + 4) )
  {
    return 1;
  }
  else
  {
    *(DWORD *)(a6 + 48) = a3;
    *(BYTE *)(a6 + 4) = 1;
    *(BYTE *)(a6 + 12) = 0;
    *(BYTE *)(a6 + 9) = 1;
    *(BYTE *)(a6 + 15) = 0;
    *(BYTE *)(a6 + 13) = 0;
    *(BYTE *)(a6 + 14) = 0;
    *(DWORD *)(a6 + 472) = a5;
    *(DWORD *)(a6 + 52) = a7;
    *(DWORD *)(a6 + 60) = -1;
    *(DWORD *)(a6 + 68) = -1;
    *(float *)(a6 + 100) = 1.0;
    *(float *)(a6 + 96) = 0.79999999;
    *(DWORD *)(a6 + 64) = 30;
    *(float *)(a6 + 152) = 0.0;
    *(float *)(a6 + 148) = 1.0;
    *(float *)(a6 + 252) = *(float *)a4;
    *(float *)(a6 + 256) = *(float *)(a4 + 4);
    *(float *)(a6 + 260) = *(float *)(a4 + 8);
    *(float *)(a6 + 264) = *(float *)(a5 + 264);
    *(float *)(a6 + 268) = *(float *)(a5 + 268);
    *(float *)(a6 + 272) = *(float *)(a5 + 272);
    *(float *)(a6 + 156) = 3.0;
    *(float *)(a6 + 160) = 3.0;
    *(float *)(a6 + 164) = 3.0;
    *(float *)(a6 + 144) = 0.0;
    *(float *)(a6 + 140) = 0.0;
    *(float *)(a6 + 120) = 0.5;
    v9 = *(DWORD *)(a6 + 48);
    if ( v9 > 387 )
    {
      if ( v9 == 7827 )
      {
        *(DWORD*)(a6 + 68) = 1;
        *(float*)(a6 + 252) = (double)(pGetRand() % 512 - 256) + *(float *)(a5 + 252);
        *(float*)(a6 + 256) = (double)(pGetRand() % 512 - 256) + *(float *)(a5 + 256);
        *(float*)(a6 + 260) = (double)(pGetRand() % 128 + 128) + *(float *)(a5 + 260);
      }
      else if ( v9 == 7828 )
      {
        *(float*)(a6 + 252) = (double)(pGetRand() % 128 - 64) + *(float *)(a5 + 252);
        *(float*)(a6 + 256) = (double)(pGetRand() % 128 - 64) + *(float *)(a5 + 256);
        *(float*)(a6 + 260) = *(float *)(a5 + 260);
        v8 = sub_5D81B0(*(float *)(a6 + 252), *(float *)(a6 + 256));
        *(float*)(a6 + 260) = (double)(pGetRand() % 100) + v8;
      }
    }
    else if ( v9 >= 384 )
    {
      *(float*)(a6 + 96) = 0.89999998;
    }
    else if ( v9 == 226 )
    {
      *(float*)(a6 + 96) = 1.0;
    }
    else if ( v9 == 233 || v9 == 323 )
    {
      *(float *)(a6 + 96) = 0.89999998;
    }
    else if ( v9 == ITEM2(13,200) )
    {
      *(float *)(a6 + 96) = 0.0000008;
    }
    return 0;
  }
  return 0;
}

bool SetPetPreviewScale2(int a4, char a5)
{
  float v5; // ST2C_4@3
  float v6; // ST28_4@3
  char v8; // [sp+1Fh] [bp-1Dh]@3
  int v9; // [sp+28h] [bp-14h]@18
  float v10; // [sp+2Ch] [bp-10h]@20
  int v11; // [sp+30h] [bp-Ch]@21
  float v12; // [sp+34h] [bp-8h]@21
  float v13; // [sp+38h] [bp-4h]@21

  if ( *(BYTE*)(a4 + 4) )
  {
    if ( a5 )
    {
      v8 = 1;
    }
    else
    {
      v5 = *(float *)(a4 + 256) * 0.009999999776482582;
      v6 = *(float *)(a4 + 252) * 0.009999999776482582;
      v8 = sub_5DBA10(v6, v5, -20.0);
    }
    *(BYTE *)(a4 + 12) = v8;
    if ( *(BYTE*)(a4 + 12) )
    {
      if ( *(DWORD*)(*(DWORD*)(a4 + 472) + 48) != 1163 && *(DWORD *)(a4 + 48) != 7827 )
        return 1;

      if ( a5 )
      {
        *(float *)(a4 + 96) = *(float *)(a4 + 96);
      }
      else if ( pPlayerState == 4 )
      {
        *(float *)(a4 + 96) = 1.2;
      }
      else if ( *(DWORD*)(a4 + 48) != 384
             && *(DWORD*)(a4 + 48) != 386
             && *(DWORD*)(a4 + 48) != 385
             && *(DWORD*)(a4 + 48) != 387 )
      {
        *(float*)(a4 + 96) = 1.0;
      }
      v9 = 0;
      if ( pCheckEffect((DWORD*)(*(DWORD*)(a4 + 472) + 484), 18) )
        v9 = 10;
      sub_5EBBB0(a4, 0, 0, v9);
      v10 = (double)(pGetRand() % 30 + 70) * 0.009999999776482582;
      if ( *(DWORD*)(a4 + 48) == 7827 )
      {
		float ItemColor[3];

		ItemColor[0] = 0.5;

		ItemColor[1] = 0.5;

		ItemColor[2] = 0.5;

        *(float*)&v11 = v10 * 0.5;
        v12 = v10 * 0.800000011920929;
        v13 = v10 * 0.6000000238418579;
        pPlayStaticEffect(32002, a4 + 252, 1.0, ItemColor, a4, 0.0, 0);
      }
    }
  }
  return 1;
}

void SetPetPreviewScale3(int a3)
{
  float v3; // ST48_4@46
  float v4; // ST44_4@47
  float v5; // ST3C_4@49
  float v6; // ST38_4@50
  float v7; // ST34_4@51
  float v8; // ST30_4@52
  float v9; // ST2C_4@53
  float v10; // ST28_4@55
  float v11; // ST0C_4@67
  float v12; // ST08_4@68
  float v13; // ST04_4@74
  signed int v14; // [sp+4Ch] [bp-4h]@4

  *(float*)(a3 + 156) = 0.30000001;
  *(float*)(a3 + 160) = 0.30000001;
  *(float*)(a3 + 164) = 0.30000001;
  *(BYTE*)(a3 + 9) = 1;
  *(BYTE*)(a3 + 13) = 0;
  *(BYTE*)(a3 + 8) = 0;
  *(float*)(a3 + 120) = 0.0;
  *(float*)(a3 + 124) = 50.0;
  *(float*)(a3 + 144) = 0.0;
  *(float*)(a3 + 140) = 0.0;
  *(WORD*)(a3 + 20) = 0;
  *(WORD*)(a3 + 18) = 0;
  *(DWORD*)(a3 + 60) = -1;
  *(float*)(a3 + 132) = 0.0;
  *(float*)(a3 + 152) = 1.0;
  *(DWORD*)(a3 + 68) = -1;
  *(float*)(a3 + 100) = 1.0;
  *(float*)(a3 + 104) = 0.0;
  *(float*)(a3 + 108) = 0.0;
  *(DWORD*)(a3 + 60) = -1;
  *(float*)(a3 + 96) = 0.80000001;
  //sub_4C8CE0(a3 + 484);

  float WorldTime = *(float*)0x005EF5A1C;

  if ( *(DWORD*)(a3 + 48) >= 2707 && *(DWORD*)(a3 + 48) <= 3744 )
    *(float *)(a3 + 96) = 0.69999999;

  v14 = *(DWORD*)(a3 + 48);

  if ( v14 <= 3736 )
  {
    if ( v14 != 3736 )
    {
      if ( v14 > 2199 )
      {
        if ( v14 > 2717 )
        {
          if ( v14 > 3235 )
          {
            if ( v14 == 3731 )
              *(DWORD*)(a3 + 68) = 2;
          }
          else if ( v14 == 3235 )
          {
            *(DWORD*)(a3 + 68) = -2;
            v3 = WorldTime * 0.004000000189989805;
            *(float *)(a3 + 100) = double(v3) * 0.2000000029802322 + 0.8999999761581421;
          }
          else if ( v14 == 3225 || v14 > 3231 && v14 <= 3233 )
          {
            *(DWORD*)(a3 + 68) = -2;
            v6 = WorldTime * 0.004000000189989805;
            *(float *)(a3 + 100) = double(v6) * 0.300000011920929 + 0.699999988079071;
          }
        }
        else if ( v14 == 2717 )
        {
          *(DWORD*)(a3 + 60) = 1;
        }
        else if ( v14 > 2202 )
        {
          if ( v14 == 2707 )
          {
LABEL_68:
            *(DWORD *)(a3 + 68) = 1;
            v12 = WorldTime * 0.004000000189989805;
            *(float*)(a3 + 100) = double(v12) * 0.300000011920929 + 0.699999988079071;
          }
          else if ( v14 == 2716 )
          {
            *(float*)(a3 + 108) = -(double)((signed int)WorldTime % 2000) * 0.0005000000237487257;
          }
        }
        else
        {
          switch ( v14 )
          {
            case 2202:
              *(DWORD*)(a3 + 60) = 2;
              break;
            case 2200:
              *(DWORD*)(a3 + 68) = 0;
              break;
            case 2201:
              *(DWORD*)(a3 + 68) = 1;
              v10 = WorldTime * 0.004000000189989805;
              *(float *)(a3 + 100) = double(v10) * 0.300000011920929 + 0.699999988079071;
              break;
          }
        }
      }
      else if ( v14 == 2199 )
      {
        *(DWORD *)(a3 + 68) = 1;
        v9 = WorldTime * 0.004000000189989805;
        *(float *)(a3 + 100) = double(v9) * 0.2000000029802322 + 0.800000011920929;
      }
      else
      {
        switch ( v14 )
        {
          case 1202:
            *(DWORD*)(a3 + 60) = 2;
            break;
          case 1185:
          case 1210:
            *(DWORD*)(a3 + 68) = 1;
            *(float*)(a3 + 104) = (double)(pGetRand() % 10) * 0.1000000014901161;
            v11 = WorldTime * 0.004000000189989805;
            *(float *)(a3 + 100) = double(v11) * 0.300000011920929 + 0.699999988079071;
            break;
          case 1181:
            goto LABEL_68;
          case 1176:
          case 1184:
            *(DWORD*)(a3 + 68) = 1;
            break;
          default:
            return;
        }
      }
      return;
    }
LABEL_63:
    *(DWORD*)(a3 + 68) = 2;
    *(float *)(a3 + 104) = (double)(pGetRand() % 10) * 0.1000000014901161;
    *(float *)(a3 + 108) = (double)(pGetRand() % 10) * 0.1000000014901161;
    return;
  }

  if ( v14 > 3769 )
  {
    if ( v14 > 7318 )
    {
      if ( v14 > 7827 )
      {
        switch ( v14 )
        {
          case 8340:
            *(float *)(a3 + 96) = 1.0;
            break;
          case 8360:
            *(float *)(a3 + 96) = 0.5;
            break;
          case 8851:
            *(float *)(a3 + 96) = 0.69999999;
            break;
        }
      }
      else if ( v14 == 7827 )
      {
        *(DWORD*)(a3 + 68) = 1;
      }
      else
      {
        switch ( v14 )
        {
          case 7323:
          case 7324:
          case 7325:
          case 7326:
          case 7335:
          case 7447:
            goto LABEL_73;
          default:
            return;
        }
      }
    }
    else if ( v14 == 7318 )
    {
      *(float *)(a3 + 96) = 0.5;
      *(DWORD*)(a3 + 68) = 0;
    }
    else if ( v14 > 4271 )
    {
      if ( v14 == 4779 || v14 == 5803 )
      {
        v7 = WorldTime * 0.001000000047497451;
        *(float *)(a3 + 100) = double(v7) * 0.4000000059604645 + 0.6000000238418579;
      }
      else if ( v14 == 7315 )
      {
LABEL_73:
        *(DWORD*)(a3 + 68) = 0;
      }
    }
    else if ( v14 == 4271 )
    {
LABEL_74:
      *(DWORD*)(a3 + 68) = 1;
      v13 = WorldTime * 0.004000000189989805;
      *(float *)(a3 + 100) = double(v13) * 0.300000011920929 + 0.699999988079071;
    }
    else
    {
      switch ( v14 )
      {
        case 4257:
        case 4270:
          *(DWORD*)(a3 + 68) = 1;
          *(float*)(a3 + 104) = (double)(pGetRand() % 10) * 0.1000000014901161;
          *(float*)(a3 + 108) = (double)(pGetRand() % 10) * 0.1000000014901161;
          break;
        case 4259:
          *(DWORD*)(a3 + 60) = 2;
          break;
        case 4254:
        case 4255:
        case 4256:
          goto LABEL_74;
        default:
          return;
      }
    }
  }
  else
  {
    if ( v14 == 3769 )
      goto LABEL_63;
    switch ( v14 )
    {
      case 3739:
        *(DWORD*)(a3 + 68) = -2;
        v4 = WorldTime * 0.004000000189989805;
        *(float *)(a3 + 100) = double(v4) * 0.2000000029802322 + 0.8999999761581421;
        break;
      case 3738:
        *(DWORD*)(a3 + 68) = 1;
        *(float *)(a3 + 100) = (double)(pGetRand() % 11) * 0.1000000014901161;
        break;
      case 3737:
        *(DWORD*)(a3 + 68) = -2;
        v5 = WorldTime * 0.004000000189989805;
        *(float *)(a3 + 100) = double(v5) * 0.300000011920929 + 0.699999988079071;
        break;
      case 3742:
        *(DWORD*)(a3 + 68) = 2;
        v8 = WorldTime * 0.004000000189989805;
        *(float *)(a3 + 100) = double(v8) * 0.300000011920929 + 0.699999988079071;
        break;
      case 3740:
        *(DWORD*)(a3 + 68) = 1;
        break;
      default:
        return;
    }
  }
}

Naked(SetNewPetScale)
{

    static DWORD AddressSatan = 0x005015A8;
	static DWORD AddressOutro = 0x005016F3;
    static DWORD AddressFinal = 0x00501567;

	static float PetY = 250.0f;
	static float PetSize = 0.3f;

	_asm
	{
	   MOV ECX,DWORD PTR SS:[EBP-0x04]
	   //MOV EDX,DWORD PTR SS:[ECX+0x30]
	   MOV IsPet, ECX
	}

		//char log[1024];

		//sprintf(log,"%d",IsPet);

		//MessageBox(NULL,log,"Warning!",NULL);

    if(IsPet == ITEM2(13,0))
    {
		_asm{jmp AddressSatan}
	}
    else if(IsPet == ITEM2(13,200))
    {
		_asm
		{
			MOV EDX,DWORD PTR SS:[EBP+0x14]
			FLD DWORD PTR DS:[PetSize]
			FSTP DWORD PTR DS:[EDX+0x60]
			jmp AddressOutro
		}
	}
	else
	{
		_asm{jmp AddressFinal}
	}
}

#define pObjOnViewport				((int(__cdecl*)(int Object))0x5F61C0)

void DrawObjectDropOnViewport(int a1)
{
	pObjOnViewport(a1);

	switch(*(DWORD *)(a1 + 48))
      {
		case ITEM2(13,64):
			*(float *)(a1 + 264) = 0.0f;
            *(float *)(a1 + 96) = 0.2f;
			*(float *)(a1 + 272) = 70.0f;
		break;
		case ITEM2(13,200):
            *(float *)(a1 + 96) = 1.0f;		//Scale
		break;
	}
}

void gObjCreatePetExHook()
{

	//SetOp((LPVOID)0x005803E5, (LPVOID)0x0058056F, ASM::JMP); // New Pets fix
	//SetByte(0x005803EA, 0x90); // New Pets fix


	SetCompleteHook(0xE8, 0x007DD304, &gObjCreatePetEx);
	SetCompleteHook(0xE8, 0x00833B08, &gObjCreatePetEx);

	//SetCompleteHook(0xE8, 0x0048F918, &SetPetPreviewScale);
	//SetCompleteHook(0xE8, 0x0048F94B, &SetPetPreviewScale);
	//SetCompleteHook(0xE8, 0x0048F97E, &SetPetPreviewScale);
	//SetCompleteHook(0xE8, 0x0048F9B1, &SetPetPreviewScale);
	//SetCompleteHook(0xE8, 0x0048F9F3, &SetPetPreviewScale);
	//SetCompleteHook(0xE8, 0x0048FA35, &SetPetPreviewScale);
	//SetCompleteHook(0xE8, 0x0048FA74, &SetPetPreviewScale);
	//SetCompleteHook(0xE8, 0x0048FAA4, &SetPetPreviewScale);
	//SetCompleteHook(0xE8, 0x00501777, &SetPetPreviewScale);
	//SetCompleteHook(0xE8, 0x00580178, &SetPetPreviewScale);
	//SetCompleteHook(0xE8, 0x0058035A, &SetPetPreviewScale);
	//SetCompleteHook(0xE8, 0x005803C9, &SetPetPreviewScale);
	//SetCompleteHook(0xE8, 0x0058046F, &SetPetPreviewScale);
	//SetCompleteHook(0xE8, 0x005804C5, &SetPetPreviewScale);
	//SetCompleteHook(0xE8, 0x0058051B, &SetPetPreviewScale);
	//SetCompleteHook(0xE8, 0x00580567, &SetPetPreviewScale);

	//SetCompleteHook(0xE8, 0x0056573A, &SetPetPreviewScale3);
	//SetCompleteHook(0xE8, 0x005CF084, &SetPetPreviewScale3);
	//SetCompleteHook(0xE8, 0x005F7FDC, &SetPetPreviewScale3);
	//SetCompleteHook(0xE8, 0x00721963, &SetPetPreviewScale3);
	//SetCompleteHook(0xE8, 0x00721BA6, &SetPetPreviewScale3);

	//SetCompleteHook(0xE8, 0x0048E504, &SetPetPreviewScale2);
	//SetCompleteHook(0xE8, 0x00503986, &SetPetPreviewScale2);

	//Fix para Monstrar ou não o pet para outros chars
	SetCompleteHook(0xE8, 0x00664267, &RefreshViewPortItem, ASM::CALL);

	//Fix do movimento
	SetOp((LPVOID)0x005033EE, SetNewPetMovement, ASM::JMP);

	//Fix ao remover o pet e colocar não aparecer 2
	SetOp((LPVOID)0x00836481,ResetPetPreviewEx,ASM::CALL);

	//Fix Scale
	//SetOp((LPVOID)0x0050155E, SetNewPetScale, ASM::CALL);

	//Diminui o tamanho do item quando dropa no chão.
	SetOp((LPVOID)0x005F820C, DrawObjectDropOnViewport, ASM::CALL);
	SetOp((LPVOID)0x005F847D, DrawObjectDropOnViewport, ASM::CALL);

}

#include "stdafx.h"
#include "CustomMap.h"
#include "Defines.h"
#include "TMemory.h"
#include "Import.h"

#include "Interface.h"

CCustomMap gCustomMap;

// ----------------------------------------------------------------------------------------------
char * Map82 = "Arkania.tga";
char * Map83 = "Arena.tga";
char * Map84 = "Abuss.tga";
char * Map85 = "Dunes.tga";
char * Map86 = "Acheron.tga";
char * Map87 = "Kalimdor.tga";
char * Map88 = "NewMap1.tga";
char * Map89 = "NewMap2.tga";
char * Map90 = "NewMap3.tga";

char* LoadMapName(signed int MapNumber)
{
	if (MapNumber >= 82 && MapNumber <= 90)
	{
		return pGetTextLine(pTextLineThis, (3160 + MapNumber - 82));
	}
	return pMapName(MapNumber);
}

Naked(LoadInterfaceMapName)
{
	_asm
	{
			MOV DWORD PTR SS : [EBP - 0x848], 0x51
			PUSH 0x00D25498							
			LEA EAX, DWORD PTR SS : [EBP - 0x28]
			PUSH EAX
			LEA ECX, DWORD PTR SS : [EBP - 0x864]
			PUSH ECX
			CALL InterfaceLoad1
			ADD ESP, 0x0C
			MOV DWORD PTR SS : [EBP - 0xA74], EAX
			MOV EDX, DWORD PTR SS : [EBP - 0xA74]
			MOV DWORD PTR SS : [EBP - 0xA78], EDX
			MOV BYTE PTR SS : [EBP - 0x4], 0x43
			MOV EAX, DWORD PTR SS : [EBP - 0xA78]
			PUSH EAX
			LEA ECX, DWORD PTR SS : [EBP - 0x848]
			PUSH ECX
			MOV ECX, DWORD PTR SS : [EBP - 0x868]
			ADD ECX, 0x4
			CALL InterfaceLoad2
			MOV ECX, EAX
			CALL InterfaceLoad3
			MOV BYTE PTR SS : [EBP - 0x4], 0x2
			LEA ECX, DWORD PTR SS : [EBP - 0x864]
			CALL InterfaceLoad4
			MOV DWORD PTR SS : [EBP - 0x4], -0x1
			LEA ECX, DWORD PTR SS : [EBP - 0x28]

			MOV DWORD PTR SS : [EBP - 0x848], 0x52
			PUSH Map82
			LEA EAX, DWORD PTR SS : [EBP - 0x28]
			PUSH EAX
			LEA ECX, DWORD PTR SS : [EBP - 0x864]
			PUSH ECX
			CALL InterfaceLoad1
			ADD ESP, 0x0C
			MOV DWORD PTR SS : [EBP - 0xA74], EAX
			MOV EDX, DWORD PTR SS : [EBP - 0xA74]
			MOV DWORD PTR SS : [EBP - 0xA78], EDX
			MOV BYTE PTR SS : [EBP - 0x4], 0x43
			MOV EAX, DWORD PTR SS : [EBP - 0xA78]
			PUSH EAX
			LEA ECX, DWORD PTR SS : [EBP - 0x848]
			PUSH ECX
			MOV ECX, DWORD PTR SS : [EBP - 0x868]
			ADD ECX, 0x4
			CALL InterfaceLoad2
			MOV ECX, EAX
			CALL InterfaceLoad3
			MOV BYTE PTR SS : [EBP - 0x4], 0x2
			LEA ECX, DWORD PTR SS : [EBP - 0x864]
			CALL InterfaceLoad4
			MOV DWORD PTR SS : [EBP - 0x4], -0x1
			LEA ECX, DWORD PTR SS : [EBP - 0x28]

			MOV DWORD PTR SS : [EBP - 0x848], 0x53
			PUSH Map83
			LEA EAX, DWORD PTR SS : [EBP - 0x28]
			PUSH EAX
			LEA ECX, DWORD PTR SS : [EBP - 0x864]
			PUSH ECX
			CALL InterfaceLoad1
			ADD ESP, 0x0C
			MOV DWORD PTR SS : [EBP - 0xA74], EAX
			MOV EDX, DWORD PTR SS : [EBP - 0xA74]
			MOV DWORD PTR SS : [EBP - 0xA78], EDX
			MOV BYTE PTR SS : [EBP - 0x4], 0x43
			MOV EAX, DWORD PTR SS : [EBP - 0xA78]
			PUSH EAX
			LEA ECX, DWORD PTR SS : [EBP - 0x848]
			PUSH ECX
			MOV ECX, DWORD PTR SS : [EBP - 0x868]
			ADD ECX, 0x4
			CALL InterfaceLoad2
			MOV ECX, EAX
			CALL InterfaceLoad3
			MOV BYTE PTR SS : [EBP - 0x4], 0x2
			LEA ECX, DWORD PTR SS : [EBP - 0x864]
			CALL InterfaceLoad4
			MOV DWORD PTR SS : [EBP - 0x4], -0x1
			LEA ECX, DWORD PTR SS : [EBP - 0x28]

			MOV DWORD PTR SS : [EBP - 0x848], 0x54
			PUSH Map84							
			LEA EAX, DWORD PTR SS : [EBP - 0x28]
			PUSH EAX
			LEA ECX, DWORD PTR SS : [EBP - 0x864]
			PUSH ECX
			CALL InterfaceLoad1
			ADD ESP, 0x0C
			MOV DWORD PTR SS : [EBP - 0xA74], EAX
			MOV EDX, DWORD PTR SS : [EBP - 0xA74]
			MOV DWORD PTR SS : [EBP - 0xA78], EDX
			MOV BYTE PTR SS : [EBP - 0x4], 0x43
			MOV EAX, DWORD PTR SS : [EBP - 0xA78]
			PUSH EAX
			LEA ECX, DWORD PTR SS : [EBP - 0x848]
			PUSH ECX
			MOV ECX, DWORD PTR SS : [EBP - 0x868]
			ADD ECX, 0x4
			CALL InterfaceLoad2
			MOV ECX, EAX
			CALL InterfaceLoad3
			MOV BYTE PTR SS : [EBP - 0x4], 0x2
			LEA ECX, DWORD PTR SS : [EBP - 0x864]
			CALL InterfaceLoad4
			MOV DWORD PTR SS : [EBP - 0x4], -0x1
			LEA ECX, DWORD PTR SS : [EBP - 0x28]

			MOV DWORD PTR SS : [EBP - 0x848], 0x55	
			PUSH Map85							
			LEA EAX, DWORD PTR SS : [EBP - 0x28]
			PUSH EAX
			LEA ECX, DWORD PTR SS : [EBP - 0x864]
			PUSH ECX
			CALL InterfaceLoad1
			ADD ESP, 0x0C
			MOV DWORD PTR SS : [EBP - 0xA74], EAX
			MOV EDX, DWORD PTR SS : [EBP - 0xA74]
			MOV DWORD PTR SS : [EBP - 0xA78], EDX
			MOV BYTE PTR SS : [EBP - 0x4], 0x43
			MOV EAX, DWORD PTR SS : [EBP - 0xA78]
			PUSH EAX
			LEA ECX, DWORD PTR SS : [EBP - 0x848]
			PUSH ECX
			MOV ECX, DWORD PTR SS : [EBP - 0x868]
			ADD ECX, 0x4
			CALL InterfaceLoad2
			MOV ECX, EAX
			CALL InterfaceLoad3
			MOV BYTE PTR SS : [EBP - 0x4], 0x2
			LEA ECX, DWORD PTR SS : [EBP - 0x864]
			CALL InterfaceLoad4
			MOV DWORD PTR SS : [EBP - 0x4], -0x1
			LEA ECX, DWORD PTR SS : [EBP - 0x28]


			MOV DWORD PTR SS : [EBP - 0x848], 0x56
			PUSH Map86							
			LEA EAX, DWORD PTR SS : [EBP - 0x28]
			PUSH EAX
			LEA ECX, DWORD PTR SS : [EBP - 0x864]
			PUSH ECX
			CALL InterfaceLoad1
			ADD ESP, 0x0C
			MOV DWORD PTR SS : [EBP - 0xA74], EAX
			MOV EDX, DWORD PTR SS : [EBP - 0xA74]
			MOV DWORD PTR SS : [EBP - 0xA78], EDX
			MOV BYTE PTR SS : [EBP - 0x4], 0x43
			MOV EAX, DWORD PTR SS : [EBP - 0xA78]
			PUSH EAX
			LEA ECX, DWORD PTR SS : [EBP - 0x848]
			PUSH ECX
			MOV ECX, DWORD PTR SS : [EBP - 0x868]
			ADD ECX, 0x4
			CALL InterfaceLoad2
			MOV ECX, EAX
			CALL InterfaceLoad3
			MOV BYTE PTR SS : [EBP - 0x4], 0x2
			LEA ECX, DWORD PTR SS : [EBP - 0x864]
			CALL InterfaceLoad4
			MOV DWORD PTR SS : [EBP - 0x4], -0x1
			LEA ECX, DWORD PTR SS : [EBP - 0x28]

			MOV DWORD PTR SS : [EBP - 0x848], 0x57
			PUSH Map87					
			LEA EAX, DWORD PTR SS : [EBP - 0x28]
			PUSH EAX
			LEA ECX, DWORD PTR SS : [EBP - 0x864]
			PUSH ECX
			CALL InterfaceLoad1
			ADD ESP, 0x0C
			MOV DWORD PTR SS : [EBP - 0xA74], EAX
			MOV EDX, DWORD PTR SS : [EBP - 0xA74]
			MOV DWORD PTR SS : [EBP - 0xA78], EDX
			MOV BYTE PTR SS : [EBP - 0x4], 0x43
			MOV EAX, DWORD PTR SS : [EBP - 0xA78]
			PUSH EAX
			LEA ECX, DWORD PTR SS : [EBP - 0x848]
			PUSH ECX
			MOV ECX, DWORD PTR SS : [EBP - 0x868]
			ADD ECX, 0x4
			CALL InterfaceLoad2
			MOV ECX, EAX
			CALL InterfaceLoad3
			MOV BYTE PTR SS : [EBP - 0x4], 0x2
			LEA ECX, DWORD PTR SS : [EBP - 0x864]
			CALL InterfaceLoad4
			MOV DWORD PTR SS : [EBP - 0x4], -0x1
			LEA ECX, DWORD PTR SS : [EBP - 0x28]

			MOV DWORD PTR SS : [EBP - 0x848], 0x58
			PUSH Map88					
			LEA EAX, DWORD PTR SS : [EBP - 0x28]
			PUSH EAX
			LEA ECX, DWORD PTR SS : [EBP - 0x864]
			PUSH ECX
			CALL InterfaceLoad1
			ADD ESP, 0x0C
			MOV DWORD PTR SS : [EBP - 0xA74], EAX
			MOV EDX, DWORD PTR SS : [EBP - 0xA74]
			MOV DWORD PTR SS : [EBP - 0xA78], EDX
			MOV BYTE PTR SS : [EBP - 0x4], 0x43
			MOV EAX, DWORD PTR SS : [EBP - 0xA78]
			PUSH EAX
			LEA ECX, DWORD PTR SS : [EBP - 0x848]
			PUSH ECX
			MOV ECX, DWORD PTR SS : [EBP - 0x868]
			ADD ECX, 0x4
			CALL InterfaceLoad2
			MOV ECX, EAX
			CALL InterfaceLoad3
			MOV BYTE PTR SS : [EBP - 0x4], 0x2
			LEA ECX, DWORD PTR SS : [EBP - 0x864]
			CALL InterfaceLoad4
			MOV DWORD PTR SS : [EBP - 0x4], -0x1
			LEA ECX, DWORD PTR SS : [EBP - 0x28]

			MOV DWORD PTR SS : [EBP - 0x848], 0x59
			PUSH Map89					
			LEA EAX, DWORD PTR SS : [EBP - 0x28]
			PUSH EAX
			LEA ECX, DWORD PTR SS : [EBP - 0x864]
			PUSH ECX
			CALL InterfaceLoad1
			ADD ESP, 0x0C
			MOV DWORD PTR SS : [EBP - 0xA74], EAX
			MOV EDX, DWORD PTR SS : [EBP - 0xA74]
			MOV DWORD PTR SS : [EBP - 0xA78], EDX
			MOV BYTE PTR SS : [EBP - 0x4], 0x43
			MOV EAX, DWORD PTR SS : [EBP - 0xA78]
			PUSH EAX
			LEA ECX, DWORD PTR SS : [EBP - 0x848]
			PUSH ECX
			MOV ECX, DWORD PTR SS : [EBP - 0x868]
			ADD ECX, 0x4
			CALL InterfaceLoad2
			MOV ECX, EAX
			CALL InterfaceLoad3
			MOV BYTE PTR SS : [EBP - 0x4], 0x2
			LEA ECX, DWORD PTR SS : [EBP - 0x864]
			CALL InterfaceLoad4
			MOV DWORD PTR SS : [EBP - 0x4], -0x1
			LEA ECX, DWORD PTR SS : [EBP - 0x28]

			MOV DWORD PTR SS : [EBP - 0x848], 0x60
			PUSH Map90					
			LEA EAX, DWORD PTR SS : [EBP - 0x28]
			PUSH EAX
			LEA ECX, DWORD PTR SS : [EBP - 0x864]
			PUSH ECX
			CALL InterfaceLoad1
			ADD ESP, 0x0C
			MOV DWORD PTR SS : [EBP - 0xA74], EAX
			MOV EDX, DWORD PTR SS : [EBP - 0xA74]
			MOV DWORD PTR SS : [EBP - 0xA78], EDX
			MOV BYTE PTR SS : [EBP - 0x4], 0x43
			MOV EAX, DWORD PTR SS : [EBP - 0xA78]
			PUSH EAX
			LEA ECX, DWORD PTR SS : [EBP - 0x848]
			PUSH ECX
			MOV ECX, DWORD PTR SS : [EBP - 0x868]
			ADD ECX, 0x4
			CALL InterfaceLoad2
			MOV ECX, EAX
			CALL InterfaceLoad3
			MOV BYTE PTR SS : [EBP - 0x4], 0x2
			LEA ECX, DWORD PTR SS : [EBP - 0x864]
			CALL InterfaceLoad4
			MOV DWORD PTR SS : [EBP - 0x4], -0x1
			LEA ECX, DWORD PTR SS : [EBP - 0x28]

		CALL InterfaceLoad4
		MOV ECX, DWORD PTR SS : [EBP - 0xC]
		MOV DWORD PTR FS : [0x0], ECX

		MOV EDI, 0x0047FD08
			JMP EDI

		InterfaceLoad1 :
		MOV EDI, 0x0047C220
			JMP EDI

		InterfaceLoad2 :
		MOV EDI, 0x00480160
			JMP EDI

		InterfaceLoad3 :
		MOV EDI, 0x00409AF0
			JMP EDI

		InterfaceLoad4 :
		MOV EDI, 0x00409AD0
			JMP EDI

			MOV ESP, EBP
			POP EBP
			RETN
		}
}

void LoadMapMusic(HDC Arg1)
{
 static PCHAR MusicID;
 // ----
 if(pPlayerState == 5)       // -> Si el PJ esta adentro del Juego
 {
  switch(pMapNumber)
  {
   case 82:        // -> Si el PJ esta en el Mapa Numero: 82
   {
		MusicID = "Data\\Music\\Map82.mp3";
    // ----
    //if(*(BYTE*)(*(DWORD*)0x7BC4F04+14)) // -> Si el PJ esta en Zona Segura del Mapa 82 (Comienza a reproducirse la Musica)
    //{
		pWzAudioPlay(MusicID,0);
    //}
    //else        // -> Si el PJ NO esta en una Zona Segura del Mapa 82 (Se detiene la Musica)
    //{
     //pWzAudioStop(MusicID,0);
    //}
   }
   break;
   case 83:        // -> Si el PJ esta en el Mapa Numero: 82
   {
		MusicID = "Data\\Music\\Map83.mp3";
		pWzAudioPlay(MusicID,0);
   }
   break;
   case 84:        // -> Si el PJ esta en el Mapa Numero: 82
   {
		MusicID = "Data\\Music\\Map84.mp3";
		pWzAudioPlay(MusicID,0);
   }
   break;
   case 85:        // -> Si el PJ esta en el Mapa Numero: 82
   {
		MusicID = "Data\\Music\\Map85.mp3";
		pWzAudioPlay(MusicID,0);
   }
   break;
   case 86:        // -> Si el PJ esta en el Mapa Numero: 82
   {
		MusicID = "Data\\Music\\Map86.mp3";
		pWzAudioPlay(MusicID,0);
   }
   break;
   case 87:        // -> Si el PJ esta en el Mapa Numero: 82
   {
		MusicID = "Data\\Music\\Map87.mp3";
		pWzAudioPlay(MusicID,0);
   }
   break;
   case 88:        // -> Si el PJ esta en el Mapa Numero: 82
   {
		MusicID = "Data\\Music\\Map88.mp3";
		pWzAudioPlay(MusicID,0);
   }
   break;
   case 89:        // -> Si el PJ esta en el Mapa Numero: 82
   {
		MusicID = "Data\\Music\\Map89.mp3";
		pWzAudioPlay(MusicID,0);
   }
   break;
   case 90:        // -> Si el PJ esta en el Mapa Numero: 82
   {
		MusicID = "Data\\Music\\Map90.mp3";
		pWzAudioPlay(MusicID,0);
   }
   break;
  }
 }
 // ----
 pLoadGameStuffs(Arg1);
}

void CCustomMap::Load()
{
	SetOp((LPVOID)0x00520ECF, (LPVOID)LoadMapName, ASM::CALL);
	SetOp((LPVOID)0x00520F1F, (LPVOID)LoadMapName, ASM::CALL);
	SetOp((LPVOID)0x0063E743, (LPVOID)LoadMapName, ASM::CALL);
	SetOp((LPVOID)0x00640EB2, (LPVOID)LoadMapName, ASM::CALL);
	SetOp((LPVOID)0x007D2DD9, (LPVOID)LoadMapName, ASM::CALL);
	SetOp((LPVOID)0x007E6C0F, (LPVOID)LoadMapName, ASM::CALL);
	SetOp((LPVOID)0x0084AEF7, (LPVOID)LoadMapName, ASM::CALL);

	SetRange((LPVOID)0x0047FC85, 131, ASM::NOP);
	SetOp((LPVOID)0x0047FC85, (LPVOID)LoadInterfaceMapName, ASM::JMP);

	//Bypass in terrains files
	SetByte((LPVOID)0x0062EBF8,0xEB);
	SetByte((LPVOID)0x0062EBFE,0xEB);
	SetByte((LPVOID)0x0062EE42,0xEB);
	SetByte((LPVOID)0x0062EE48,0xEB);
	SetByte((LPVOID)0x0062EEE5,0xEB);
	SetByte((LPVOID)0x0062EEEB,0xEB);
	
	//Increase terrains amount
	SetByte((LPVOID)0x0062EBF7,0x69);
	SetByte((LPVOID)0x0062EE41,0x69);
	SetByte((LPVOID)0x0062EEE4,0x69);

	//Set Music
	SetOp((LPVOID)0x004DADA4,(LPVOID)LoadMapMusic,ASM::CALL);
}
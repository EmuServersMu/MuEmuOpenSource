#include "stdafx.h"
#include "Protocol.h"
#include "Common.h"
#include "CustomEventTime.h"
#include "CustomPing.h"
#include "CustomRankUser.h"
#include "CustomRanking.h"
#include "HealthBar.h"
#include "Interface.h"
#include "ItemShopValue.h"
#include "Offset.h"
#include "OffTrade.h"
#include "PacketManager.h"
#include "PrintPlayer.h"
#include "Protect.h"
#include "Reconnect.h"
#include "Util.h"

BOOL ProtocolCoreEx(BYTE head,BYTE* lpMsg,int size,int key) // OK
{
#if(ANTIHACK)	
	if (*(BYTE *)0x004DA3E0 != 40)
	{
		MessageBoxA(NULL, "¡La gerencia te recomienda no hacer trampa cuando juegues! 1", "[ElfCheat]", ERROR); //velocidad de pirateo
		ExitProcess(0);
	}

	if (*(BYTE*)0x005DE171 != 137 || *(BYTE*)0x005DE172 != 138
		|| *(BYTE*)0x005DE173 != 160 || *(BYTE*)0x005DE174 != 0
		|| *(BYTE*)0x005DE175 != 0 || *(BYTE*)0x005DE176 != 0
		|| *(BYTE*)0x005B5FFF != 245 || *(BYTE*)0x005B6000 != 0
		|| *(BYTE*)0x005B6001 != 0 || *(BYTE*)0x005B6002 != 0)
	{
		MessageBoxA(NULL, "¡La junta directiva te recomienda no hacer trampa cuando juegues! 2", "[ElfCheat]", ERROR); // retrasar el hackeo
		ExitProcess(0);
	}

	if (*(BYTE*)0x005A1797 != 141 || *(BYTE*)0x005A1798 != 212
		|| *(BYTE*)0x005A1799 != 247 || *(BYTE*)0x005A179A != 255
		|| *(BYTE*)0x005A179B != 255
		|| *(BYTE*)0x005AD824 != 141 || *(BYTE*)0x005AD825 != 172 || *(BYTE*)0x005AD826 != 239 || *(BYTE*)0x005AD827 != 255 || *(BYTE*)0x005AD828 != 255
		|| *(BYTE*)0x005AF96D != 141 || *(BYTE*)0x005AF96E != 28 || *(BYTE*)0x005AF96F != 142 || *(BYTE*)0x005AF970 != 255 || *(BYTE*)0x005AF971 != 255
		|| *(BYTE*)0x0059C79D != 141 || *(BYTE*)0x0059C79E != 212 || *(BYTE*)0x0059C79F != 247 || *(BYTE*)0x0059C7A0 != 255 || *(BYTE*)0x0059C7A1 != 255
		|| *(BYTE*)0x005AFBF1 != 141 || *(BYTE*)0x005AFBF2 != 4 || *(BYTE*)0x005AFBF3 != 134 || *(BYTE*)0x005AFBF4 != 255 || *(BYTE*)0x005AFBF5 != 255
		|| *(BYTE*)0x0059CEDC != 141 || *(BYTE*)0x0059CEDD != 228 || *(BYTE*)0x0059CEDE != 247 || *(BYTE*)0x0059CEDF != 255 || *(BYTE*)0x0059CEE0 != 255
		|| *(BYTE*)0x005B1CCB != 141 || *(BYTE*)0x005B1CCC != 4 || *(BYTE*)0x005B1CCD != 151 || *(BYTE*)0x005B1CCE != 255 || *(BYTE*)0x005B1CCF != 255
		|| *(BYTE*)0x005B170A != 141 || *(BYTE*)0x005B170B != 52 || *(BYTE*)0x005B170C != 175 || *(BYTE*)0x005B170D != 255 || *(BYTE*)0x005B170E != 255
		|| *(BYTE*)0x005B0C07 != 141 || *(BYTE*)0x005B0C08 != 124 || *(BYTE*)0x005B0C09 != 207 || *(BYTE*)0x005B0C0A != 255 || *(BYTE*)0x005B0C0B != 255
		|| *(BYTE*)0x005B187C != 141 || *(BYTE*)0x005B187D != 36 || *(BYTE*)0x005B187E != 167 || *(BYTE*)0x005B187F != 255 || *(BYTE*)0x005B1880 != 255
		|| *(BYTE*)0x0059D1E2 != 141 || *(BYTE*)0x0059D1E3 == 144 || *(BYTE*)0x0059D1E4 != 231 || *(BYTE*)0x0059D1E5 != 255 || *(BYTE*)0x0059D1E6 != 255
		|| *(BYTE*)0x005B1AA9 != 141 || *(BYTE*)0x005B1AAA != 20 || *(BYTE*)0x005B1AAB != 159 || *(BYTE*)0x005B1AAC != 255 || *(BYTE*)0x005B1AAD != 255
		|| *(BYTE*)0x005AC554 != 141 || *(BYTE*)0x005AC555 != 116 || *(BYTE*)0x005AC556 != 182 || *(BYTE*)0x005AC557 != 255 || *(BYTE*)0x005AC558 != 255
		|| *(BYTE*)0x0059D6AD != 141 || *(BYTE*)0x0059D6AE != 204 || *(BYTE*)0x0059D6AF != 239 || *(BYTE*)0x0059D6B0 != 255 || *(BYTE*)0x0059D6B1 != 255
		|| *(BYTE*)0x005AC22C != 141 || *(BYTE*)0x005AC22D != 252 || *(BYTE*)0x005AC22E != 190 || *(BYTE*)0x005AC22F != 255 || *(BYTE*)0x005AC230 != 255
		|| *(BYTE*)0x00534FD2 != 141 || *(BYTE*)0x00534FD3 == 144 || *(BYTE*)0x00534FD4 != 247 || *(BYTE*)0x00534FD5 != 255 || *(BYTE*)0x00534FD6 != 255
		|| *(BYTE*)0x0059DED9 != 141 || *(BYTE*)0x0059DEDA == 144 || *(BYTE*)0x0059DEDB != 239 || *(BYTE*)0x0059DEDC != 255 || *(BYTE*)0x0059DEDD != 255
		|| *(BYTE*)0x0059DC87 != 141 || *(BYTE*)0x0059DC88 == 144 || *(BYTE*)0x0059DC89 != 247 || *(BYTE*)0x0059DC8A != 255 || *(BYTE*)0x0059DC8B != 255
		//hetsum
		|| *(BYTE*)0x005B2C98 != 141 || *(BYTE*)0x005B2C99 != 108 || *(BYTE*)0x005B2C9A != 110 || *(BYTE*)0x005B2C9B != 255 || *(BYTE*)0x005B2C9C != 255
		//Rf damdat
		|| *(BYTE*)0x0059F471 != 141 || *(BYTE*)0x0059F472 != 36 || *(BYTE*)0x0059F473 != 191 || *(BYTE*)0x0059F474 != 255 || *(BYTE*)0x0059F475 != 255
		//vatnga
		|| *(BYTE*)0x005AF96D != 141 || *(BYTE*)0x005AF96E == 144 || *(BYTE*)0x005AF96F == 144 || *(BYTE*)0x005AF970 != 255 || *(BYTE*)0x005AF971 != 255
		//AALH1
		|| *(BYTE*)0x0059F211 != 141 || *(BYTE*)0x0059F212 != 68 || *(BYTE*)0x0059F213 != 199 || *(BYTE*)0x0059F214 != 255 || *(BYTE*)0x0059F215 != 255

		|| *(BYTE*)0x0050FB50 != 141 || *(BYTE*)0x0050FB51 == 90 || *(BYTE*)0x0050FB52 != 247 || *(BYTE*)0x0050FB53 != 255 || *(BYTE*)0x0050FB54 != 255
		//manhlong		
		|| *(BYTE*)0x0050F357 != 141 || *(BYTE*)0x0050F358 != 180 || *(BYTE*)0x0050F359 != 239 || *(BYTE*)0x0050F35A != 255 || *(BYTE*)0x0050F35B != 255

		//MG
		|| *(BYTE*)0x005ADE26 != 141 || *(BYTE*)0x005ADE27 != 116 || *(BYTE*)0x005ADE28 != 223 || *(BYTE*)0x005ADE29 != 255 || *(BYTE*)0x005ADE2A != 255
		|| *(BYTE*)0x005ADACC != 141 || *(BYTE*)0x005ADACD != 140 || *(BYTE*)0x005ADACE != 231 || *(BYTE*)0x005ADACF != 255 || *(BYTE*)0x005ADAD0 != 255
		|| *(BYTE*)0x005AE854 != 141 || *(BYTE*)0x005AE855 != 188 || *(BYTE*)0x005AE856 != 206 || *(BYTE*)0x005AE857 != 255 || *(BYTE*)0x005AE858 != 255
		//DL
		|| *(BYTE*)0x005AF1B1 != 141 || *(BYTE*)0x005AF1B2 != 92 || *(BYTE*)0x005AF1B3 != 166 || *(BYTE*)0x005AF1B4 != 255 || *(BYTE*)0x005AF1B5 != 255
		|| *(BYTE*)0x005AE1B5 != 141 || *(BYTE*)0x005AE1B6 != 236 || *(BYTE*)0x005AE1B7 != 214 || *(BYTE*)0x005AE1B8 != 255 || *(BYTE*)0x005AE1B9 != 255
		//saitama
		|| *(BYTE*)0x0064CF51 != 51 || *(BYTE*)0x0064CF52 != 1 || *(BYTE*)0x0064CF53 != 0 || *(BYTE*)0x0064CF54 != 0)

	{
		MessageBoxA(NULL, "¡La junta directiva te recomienda no hacer trampa cuando juegues! 2", "[ElfCheat]", ERROR); //Xdame
		ExitProcess(0);
	}

	if (*(BYTE*)0x00564D30 == 233)
	{
		MessageBoxA(NULL, "¡Recomiendo no hacer trampa cuando juegues! 0", "[ElfCheat]", ERROR); //cahy rapido
		//system("shutdown -s -t 0");
		ExitProcess(0);
	}
	if (*(BYTE*)(*(DWORD*)(0x7BC4F04) + 0x397) > 65)// loi khi su dung /Dance
	{
		MessageBoxA(NULL, "¡Recomiendo no hacer trampa cuando juegues! 2", "[ElfCheat]", ERROR); // hithack ok
		//system("shutdown -s -t 0");
		ExitProcess(0);
	}

	if ((*(BYTE *)0x006407C0 == 195)		//khang day lui ok
		|| (*(BYTE *)0x005528A0 == 195)	    //khang sat thuong ok
		|| (*(BYTE *)0x00749A30 == 195)		//khang sat thuong ok
		|| (*(BYTE *)0x004C8F00 == 195)	    // khang hieu ung x?u ok
		|| (*(BYTE *)0x00596500 == 195)	    // Xoa hoi chieu va noi luc
		|| (*(BYTE *)0x0057D760 == 195))	//khangtele dw ok
	{
		MessageBoxA(NULL, "¡Recomiendo no hacer trampa cuando juegues! 3", "[ElfCheat]", ERROR); // OK
		//system("shutdown -s -t 0"); //mo cai nay ra la xap nguon khi hack vao cai nay
		ExitProcess(0);
	}


	if ((*(BYTE *)0x006407C0 != 85)		//khang vete ok
		|| (*(BYTE *)0x005528A0 != 85)	//khang sat thuong ok
		|| (*(BYTE *)0x00749A30 != 236)	//khang sat thuong ok
		|| (*(BYTE *)0x004C8F00 != 85)	// khang hieu ung x?u ok
		|| (*(BYTE *)0x00596500 != 85)	// Xoa hoi chieu va noi luc
		|| (*(BYTE *)0x0057D760 != 85))	//khangtele dw ok
	{
		MessageBoxA(NULL, "¡Recomiendo no hacer trampa cuando juegues! 4", "[ElfCheat]", ERROR); // OK
		//system("shutdown -s -t 0");
		ExitProcess(0);
	}

	if (*(BYTE *)0x0073A641 != 91 || *(BYTE *)0x0055D515 == 100 || *(BYTE *)0x0055D515 != 4)
	{
		MessageBoxA(NULL, "¡Recomiendo no hacer trampa cuando juegues! 5", "[ElfCheat]", ERROR); //Evilhit está bien
		//system("shutdown -s -t 0");
		ExitProcess(0);
	}

	if (*(DWORD *)0x0054539E == 1166749052 || *(DWORD *)0x00545248 == 1300967031
		|| *(BYTE *)0x0054539E == 118 || *(BYTE *)0x0054539E == 124
		|| *(BYTE *)0x00545248 == 117 || *(BYTE *)0x00545248 == 119
		|| *(BYTE *)0x00545248 == 123 || *(BYTE *)0x0054539E != 117
		|| *(BYTE *)0x00545248 != 122 || *(BYTE *)0x005B5FFA == 233)
	{
		MessageBoxA(NULL, "¡Recomiendo no hacer trampa cuando juegues! 7", "[ElfCheat]", ERROR); //enlace de luz?n habilidad ok
		//system("shutdown -s -t 0");
		ExitProcess(0);
	}

	if (*(BYTE *)0x00561746 == 0 || *(BYTE *)0x00561746 != 1)
	{
		MessageBoxA(NULL, "¡Recomiendo no hacer trampa cuando juegues! 8", "[ElfCheat]", ERROR); //habilidad en la barra ok
		//system("shutdown -s -t 0");
		ExitProcess(0);
	}

	if (*(BYTE *)0x0065FC76 == 235 || *(BYTE *)0x0065FC76 != 117)
	{
		MessageBoxA(NULL, "¡Recomiendo no hacer trampa cuando juegues! 9", "[ElfCheat]", ERROR); //modo dios ok
		//system("shutdown -s -t 0");
		ExitProcess(0);
	}

	if (*(BYTE *)0x005DE16C != 102)
	{
		MessageBoxA(NULL, "¡Recomiendo no hacer trampa cuando juegues! 10", "[ElfCheat]", ERROR); //delaycuoi soi
		//system("shutdown -s -t 0");
		ExitProcess(0);
	}

	if ((*(BYTE*)*(DWORD *)0x5B1705 == 10)			//quayrong
		|| (*(BYTE*)*(DWORD *)0x5A1792 == 10)		//danh thuong Dk
		|| (*(BYTE*)*(DWORD *)0x5AD81F == 10)		//xoay kiem
		|| (*(BYTE*)*(DWORD *)0x59C798 == 10)
		//----DW
		|| (*(BYTE*)*(DWORD *)0x59CED7 == 10)		//skill don
		|| (*(BYTE*)*(DWORD *)0x5B1CC6 == 10)		//muabangtuyet
		|| (*(BYTE*)*(DWORD *)0x5B0C02 == 10)		//Lua Dia Nguc
		|| (*(BYTE*)*(DWORD *)0x59D1DD == 10)		//muasaobang
		|| (*(BYTE*)*(DWORD *)0x5B1877 == 10)		//Kame
		|| (*(BYTE*)*(DWORD *)0x5B05C6 == 10)		//Nova
		|| (*(BYTE*)*(DWORD *)0x5B071D == 10)		//Nova1
		|| (*(BYTE*)*(DWORD *)0x5B1AA4 == 10)		//Cot lua
		//-------EFL
		|| (*(BYTE*)*(DWORD *)0x5AC54F == 10)		//Ngu Tien
		|| (*(BYTE*)*(DWORD *)0x59D6A8 == 10)		//Ban bang
		|| (*(BYTE*)*(DWORD *)0x5AC227 == 10)		//Buff mau
		//--------SUM
		|| (*(BYTE*)*(DWORD *)0x534FCD == 10)		//Skill sach
		|| (*(BYTE*)*(DWORD *)0x59DED4 == 10)		//Giat Set
		|| (*(BYTE*)*(DWORD *)0x59DC82 == 10)		//Hut Mau
		|| (*(BYTE*)*(DWORD *)0x5B2C93 == 10)		//Shok Dien
		//--------RF
		|| (*(BYTE*)*(DWORD *)0x59F46C == 10)		//D?m ??t
		|| (*(BYTE*)*(DWORD *)0x59F20C == 10)		//AALH
		//--------MG
		|| (*(BYTE*)*(DWORD *)0x5ADE21 == 10)		//Cú chém
		|| (*(BYTE*)*(DWORD *)0x5ADAC7 == 10)		//Chem Lua
		|| (*(BYTE*)*(DWORD *)0x5AE84F == 10)		//Hoa Diem
		//--------DL
		|| (*(BYTE*)*(DWORD *)0x59C798 == 10)		//Quat xich
		|| (*(BYTE*)*(DWORD *)0x5AF1AC == 10)		//Hoa Am
		|| (*(BYTE*)*(DWORD *)0x5AE1B0 == 10)		//Hon loan
		|| (*(BYTE *)0x00400354 != 0))				//So lan Xdame	
	{
		MessageBoxA(NULL, "¡Recomiendo no hacer trampa cuando juegues! 11", "[ElfCheat]", ERROR); // XSdame ok
		//system("shutdown -s -t 0");
		ExitProcess(0);
	}

	if (*(BYTE*)(*(DWORD*)(0x0400000) + 0x00927C88) != 0)
	{
		MessageBoxA(NULL, "¡Recomiendo no hacer trampa cuando juegues! 12", "[ElfCheat]", ERROR); // hithack ok
		//system("shutdown -s -t 0");
		ExitProcess(0);
	}

	if (*(FLOAT*)0x00400020 > 0) // DOUBLE
	{
		MessageBoxA(NULL, "¡Recomiendo no hacer trampa cuando juegues! 13", "[ElfCheat]", ERROR); //ataque ok
		//system("shutdown -s -t 0");
		ExitProcess(0);
	}

	if (*(FLOAT*)0x00D27BFC > 60)
	{
		MessageBoxA(NULL, "¡Te recomiendo que no extiendas el espacio cuando juegues! 14", "[ElfCheat]", ERROR); //Zoom
		//system("shutdown -s -t 0");
		ExitProcess(0);
	}

	if ((*(BYTE*)0x005B1705 != 106)			//quayrong
		|| (*(BYTE*)0x005A1792 != 106)		//danh thuong Dk
		|| (*(BYTE*)0x005AD81F != 106)		//xoay kiem
		|| (*(BYTE*)0x0059C798 != 106)
		//----DW
		|| (*(BYTE*)0x0059CED7 != 106)		//skill don
		|| (*(BYTE*)0x005B1CC6 != 106)		//muabangtuyet
		|| (*(BYTE*)0x005B0C02 != 106)		//Lua Dia Nguc
		|| (*(BYTE*)0x0059D1DD != 106)		//muasaobang
		|| (*(BYTE*)0x005B1877 != 106)		//Kame
		|| (*(BYTE*)0x005B05C6 != 106)		//Nova
		|| (*(BYTE*)0x005B071D != 106)		//Nova1
		|| (*(BYTE*)0x005B1AA4 != 106)		//Cot lua
		//-------EFL
		|| (*(BYTE*)0x005AC54F != 106)		//Ngu Tien
		|| (*(BYTE*)0x0059D6A8 != 106)		//Ban bang
		|| (*(BYTE*)0x005AC227 != 106)		//Buff mau
		//--------SUM
		|| (*(BYTE*)0x00534FCD != 106)		//Skill sach
		|| (*(BYTE*)0x0059DED4 != 106)		//Giat Set
		|| (*(BYTE*)0x0059DC82 != 106)		//Hut Mau
		|| (*(BYTE*)0x005B2C93 != 106)		//Shok Dien
		//--------RF
		|| (*(BYTE*)0x0059F46C != 106)		//D?m ??t
		|| (*(BYTE*)0x0059F20C != 106)		//AALH
		//--------MG
		|| (*(BYTE*)0x005ADE21 != 106)		//Cú chém
		|| (*(BYTE*)0x005ADAC7 != 106)		//Chem Lua
		|| (*(BYTE*)0x005AE84F != 106)		//Hoa Diem
		//--------DL
		|| (*(BYTE*)0x0059C798 != 106)		//Quat xich
		|| (*(BYTE*)0x005AF1AC != 106)		//Hoa Am
		|| (*(BYTE*)0x005AE1B0 != 106)		//Hon loan
		|| (*(BYTE *)0x00400354 != 0))		//So lan Xdame
	{
		MessageBoxA(NULL, "¡Recomiendo no hacer trampa cuando juegues! 15", "[ElfCheat]", ERROR); //XSdame
		//ExitProcess(0);
	}

	if (*(BYTE*)0x004DA3E4 != 139 || *(BYTE*)0x004DA3E9 != 255)
	{
		MessageBoxA(NULL, "¡Te recomendamos que no hagas trampa cuando juegues! 16", "[ElfCheat]", ERROR); // Nueva velocidad
		//ExitProcess(0);
	}
	if (*(BYTE*)0x00596343 == 233)
	{
		MessageBoxA(NULL, "¡Te recomendamos que no hagas trampa cuando juegues! 17", "[ElfoTramposo]", ERROR);	//hackear nombre remoto
		//ExitProcess(0);
	}

	if (*(BYTE*)0x0054539E != 117 || *(BYTE*)0x004DA3E9 == 124)
	{
		MessageBoxA(NULL, "¡Te recomendamos que no hagas trampa cuando juegues! 160", "[ElfCheat]", ERROR);	// tipo de transacción
		//ExitProcess(0);
	}

	if (*(BYTE*)GetProcAddress(GetModuleHandle("ntdll.dll"), "LdrLoadDll") != 233)	//Anti-Bypass
	{
		//MessageBoxA(NULL, "¡Te recomendamos que no hagas trampa cuando juegues! 18", "[ElfCheat]", ERROR);	//hackear nombre remoto
	    //ExitProcess(0);
	}
#endif
	switch(head)
	{
		case 0x11:
			GCDamageRecv((PMSG_DAMAGE_RECV*)lpMsg);
			break;
		case 0x16:
			GCMonsterDieRecv((PMSG_MONSTER_DIE_RECV*)lpMsg);
			break;
		case 0x17:
			GCUserDieRecv((PMSG_USER_DIE_RECV*)lpMsg);
			break;
		case 0x26:
			GCLifeRecv((PMSG_LIFE_RECV*)lpMsg);
			break;
		case 0x27:
			GCManaRecv((PMSG_MANA_RECV*)lpMsg);
			break;
		case 0x2C:
			GCFruitResultRecv((PMSG_FRUIT_RESULT_RECV*)lpMsg);
			break;
		case 0x9C:
			GCRewardExperienceRecv((PMSG_REWARD_EXPERIENCE_RECV*)lpMsg);
			break;
		case 0xA3:
			GCQuestRewardRecv((PMSG_QUEST_REWARD_RECV*)lpMsg);
			break;
		case 0xB1:
			switch(((lpMsg[0]==0xC1)?lpMsg[3]:lpMsg[4]))
			{
				case 0x00:
					GCMapServerMoveRecv((PMSG_MAP_SERVER_MOVE_RECV*)lpMsg);
					break;
				case 0x01:
					GCMapServerMoveAuthRecv((PMSG_MAP_SERVER_MOVE_AUTH_RECV*)lpMsg);
					break;
			}
			break;
		case 0xF1:
			switch(((lpMsg[0]==0xC1)?lpMsg[3]:lpMsg[4]))
			{
				case 0x00:
					GCConnectClientRecv((PMSG_CONNECT_CLIENT_RECV*)lpMsg);
					break;
				case 0x01:
					GCConnectAccountRecv((PMSG_CONNECT_ACCOUNT_RECV*)lpMsg);
					break;
				case 0x02:
					GCCloseClientRecv((PMSG_CLOSE_CLIENT_RECV*)lpMsg);
					break;
			}
			break;
		case 0xF3:
			switch(((lpMsg[0]==0xC1)?lpMsg[3]:lpMsg[4]))
			{
				case 0x00:
					GCCharacterListRecv((PMSG_CHARACTER_LIST_RECV*)lpMsg);
					break;
				case 0x03:
					GCCharacterInfoRecv((PMSG_CHARACTER_INFO_RECV*)lpMsg);
					break;
				case 0x04:
					GCCharacterRegenRecv((PMSG_CHARACTER_REGEN_RECV*)lpMsg);
					break;
				case 0x05:
					GCLevelUpRecv((PMSG_LEVEL_UP_RECV*)lpMsg);
					break;
				case 0x06:
					GCLevelUpPointRecv((PMSG_LEVEL_UP_POINT_RECV*)lpMsg);
					break;
				case 0x07:
					GCMonsterDamageRecv((PMSG_MONSTER_DAMAGE_RECV*)lpMsg);
					break;
				case 0x50:
					GCMasterInfoRecv((PMSG_MASTER_INFO_RECV*)lpMsg);
					break;
				case 0x51:
					GCMasterLevelUpRecv((PMSG_MASTER_LEVEL_UP_RECV*)lpMsg);
					break;
				case 0xE0:
					GCNewCharacterInfoRecv((PMSG_NEW_CHARACTER_INFO_RECV*)lpMsg);
					return 1;
				case 0xE1:
					GCNewCharacterCalcRecv((PMSG_NEW_CHARACTER_CALC_RECV*)lpMsg);
					return 1;
				case 0xE2:
					GCNewHealthBarRecv((PMSG_NEW_HEALTH_BAR_RECV*)lpMsg);
					return 1;
				case 0xE3:
					GCNewGensBattleInfoRecv((PMSG_NEW_GENS_BATTLE_INFO_RECV*)lpMsg);
					return 1;
				case 0xE4:
					GCNewMessageRecv((PMSG_NEW_MESSAGE_RECV*)lpMsg);
					return 1;
				case 0xE5:
					gCustomRankUser.GCReqRankLevelUser((PMSG_CUSTOM_RANKUSER*)lpMsg);
					return 1;
				case 0xE6:
					gCustomRanking.GCReqRanking((PMSG_CUSTOM_RANKING_RECV*)lpMsg);
					return 1;
				case 0xE7:
					gCustomRanking.GCReqRankingCount((PMSG_CUSTOM_RANKING_COUNT_RECV*)lpMsg);
					return 1;
				case 0xE8:
					gCustomEventTime.GCReqEventTime((PMSG_CUSTOM_EVENTTIME_RECV*)lpMsg);
					return 1;
				case 0xE9:
					gItemPrice.GCItemValueRecv((PMSG_ITEM_VALUE_RECV*)lpMsg);
					return 1;
				case 0xEA:
					GCRecvCoin((PMSG_COIN_RECV*)lpMsg);
					return 1;
				case 0xEB:
					gOffTrade.RecvPShop((PMSG_OFFTRADE_RECV*)lpMsg);
					return 1;
				case 0xEC:
					gOffTrade.PShopActiveRecv((PMSG_SHOPACTIVE_RECV*)lpMsg);
					return 1;
				case 0xED:
					GCBuyConfirmRecv((PMSG_ITEM_BUY_RECV*)lpMsg);
					break;
				case 0xF1:
					gCustomPing.PingRecv();
					break;
			}
			break;

	}

	return ProtocolCore(head,lpMsg,size,key);
}

void GCDamageRecv(PMSG_DAMAGE_RECV* lpMsg) // OK
{
	int aIndex = MAKE_NUMBERW(lpMsg->index[0],lpMsg->index[1]) & 0x7FFF;

	if(ViewIndex == aIndex)
	{
		ViewCurHP = lpMsg->ViewCurHP;
		ViewCurSD = lpMsg->ViewCurSD;
	}

	ViewDamageHP = lpMsg->ViewDamageHP;
	ViewDamageSD = lpMsg->ViewDamageSD;

	if((lpMsg->type & 0x10) != 0)
	{
		if(ViewDamageCount < 3)
		{
			ViewDamageTable[ViewDamageCount++] = lpMsg->ViewDamageHP;
			ViewDamageValue = ViewDamageCount;
		}
	}

	if((lpMsg->type & 0x20) != 0)
	{
		if(ViewDamageCount < 4)
		{
			ViewDamageTable[ViewDamageCount++] = lpMsg->ViewDamageHP;
			ViewDamageValue = ViewDamageCount;
		}
	}
}

void GCMonsterDieRecv(PMSG_MONSTER_DIE_RECV* lpMsg) // OK
{
	ViewDamageHP = lpMsg->ViewDamageHP;
}

void GCUserDieRecv(PMSG_USER_DIE_RECV* lpMsg) // OK
{
	int aIndex = MAKE_NUMBERW(lpMsg->index[0],lpMsg->index[1]) & 0x7FFF;

	if(ViewIndex == aIndex)
	{
		ViewCurHP = 0;
	}
}

void GCLifeRecv(PMSG_LIFE_RECV* lpMsg) // OK
{
	if(lpMsg->type == 0xFE)
	{
		ViewMaxHP = lpMsg->ViewHP;
		ViewMaxSD = lpMsg->ViewSD;
	}

	if(lpMsg->type == 0xFF)
	{
		ViewCurHP = ((ViewCurHP==0)?ViewCurHP:lpMsg->ViewHP);
		ViewCurSD = lpMsg->ViewSD;
	}
}

void GCManaRecv(PMSG_MANA_RECV* lpMsg) // OK
{
	if(lpMsg->type == 0xFE)
	{
		ViewMaxMP = lpMsg->ViewMP;
		ViewMaxBP = lpMsg->ViewBP;
	}

	if(lpMsg->type == 0xFF)
	{
		ViewCurMP = lpMsg->ViewMP;
		ViewCurBP = lpMsg->ViewBP;
	}
}

void GCFruitResultRecv(PMSG_FRUIT_RESULT_RECV* lpMsg) // OK
{
	if(lpMsg->result == 0 || lpMsg->result == 3 || lpMsg->result == 6 || lpMsg->result == 17)
	{
		ViewValue = lpMsg->ViewValue;
		ViewPoint = lpMsg->ViewPoint;
		ViewStrength = lpMsg->ViewStrength;
		ViewDexterity = lpMsg->ViewDexterity;
		ViewVitality = lpMsg->ViewVitality;
		ViewEnergy = lpMsg->ViewEnergy;
		ViewLeadership = lpMsg->ViewLeadership;
	}
}

void GCRewardExperienceRecv(PMSG_REWARD_EXPERIENCE_RECV* lpMsg) // OK
{
	ViewDamageHP = lpMsg->ViewDamageHP;
}

void GCQuestRewardRecv(PMSG_QUEST_REWARD_RECV* lpMsg) // OK
{
	int aIndex = MAKE_NUMBERW(lpMsg->index[0],lpMsg->index[1]) & 0x7FFF;

	if(ViewIndex == aIndex)
	{
		ViewPoint = lpMsg->ViewPoint;
	}
}

void GCMapServerMoveRecv(PMSG_MAP_SERVER_MOVE_RECV* lpMsg) // OK
{
	ReconnectOnMapServerMove(lpMsg->IpAddress,lpMsg->ServerPort);
}

void GCMapServerMoveAuthRecv(PMSG_MAP_SERVER_MOVE_AUTH_RECV* lpMsg) // OK
{
	ReconnectOnMapServerMoveAuth(lpMsg->result);
}

void GCConnectClientRecv(PMSG_CONNECT_CLIENT_RECV* lpMsg) // OK
{
	ViewIndex = MAKE_NUMBERW(lpMsg->index[0],lpMsg->index[1]);
}

void GCConnectAccountRecv(PMSG_CONNECT_ACCOUNT_RECV* lpMsg) // OK
{
	ReconnectOnConnectAccount(lpMsg->result);
}

void GCCloseClientRecv(PMSG_CLOSE_CLIENT_RECV* lpMsg) // OK
{
	ReconnectOnCloseClient(lpMsg->result);
}

void GCCharacterListRecv(PMSG_CHARACTER_LIST_RECV* lpMsg) // OK
{
	ReconnectOnCharacterList();
}

void GCCharacterInfoRecv(PMSG_CHARACTER_INFO_RECV* lpMsg) // OK
{
	ReconnectOnCharacterInfo();

	ViewReset = lpMsg->ViewReset;
	ViewPoint = lpMsg->ViewPoint;
	ViewCurHP = lpMsg->ViewCurHP;
	ViewMaxHP = lpMsg->ViewMaxHP;
	ViewCurMP = lpMsg->ViewCurMP;
	ViewMaxMP = lpMsg->ViewMaxMP;
	ViewCurBP = lpMsg->ViewCurBP;
	ViewMaxBP = lpMsg->ViewMaxBP;
	ViewCurSD = lpMsg->ViewCurSD;
	ViewMaxSD = lpMsg->ViewMaxSD;
	ViewStrength = lpMsg->ViewStrength;
	ViewDexterity = lpMsg->ViewDexterity;
	ViewVitality = lpMsg->ViewVitality;
	ViewEnergy = lpMsg->ViewEnergy;
	ViewLeadership = lpMsg->ViewLeadership;

	*(WORD*)(*(DWORD*)(MAIN_VIEWPORT_STRUCT)+0x07E) = 0;

	*(BYTE*)(*(DWORD*)(MAIN_VIEWPORT_STRUCT)+0x30C) = 0;

	switch(((*(BYTE*)(*(DWORD*)(MAIN_CHARACTER_STRUCT)+0x0B)) & 7))
	{
		case 0:
			SetByte(0x00556C38,((gProtect.m_MainInfo.DWMaxAttackSpeed>=0xFFFF)?0x02:0x0F));
			break;
		case 1:
			SetByte(0x00556C38,((gProtect.m_MainInfo.DKMaxAttackSpeed>=0xFFFF)?0x0F:0x0F));
			break;
		case 2:
			SetByte(0x00556C38,((gProtect.m_MainInfo.FEMaxAttackSpeed>=0xFFFF)?0x02:0x0F));
			break;
		case 3:
			SetByte(0x00556C38,((gProtect.m_MainInfo.MGMaxAttackSpeed>=0xFFFF)?0x02:0x0F));
			break;
		case 4:
			SetByte(0x00556C38,((gProtect.m_MainInfo.DLMaxAttackSpeed>=0xFFFF)?0x02:0x0F));
			break;
		case 5:
			SetByte(0x00556C38,((gProtect.m_MainInfo.SUMaxAttackSpeed>=0xFFFF)?0x02:0x0F)); 
			break;
		case 6:
			SetByte(0x00556C38,((gProtect.m_MainInfo.RFMaxAttackSpeed>=0xFFFF)?0x0F:0x0F));
			break;
	}
}

void GCCharacterRegenRecv(PMSG_CHARACTER_REGEN_RECV* lpMsg) // OK
{
	ViewCurHP = lpMsg->ViewCurHP;
	ViewCurMP = lpMsg->ViewCurMP;
	ViewCurBP = lpMsg->ViewCurBP;
	ViewCurSD = lpMsg->ViewCurSD;
}

void GCLevelUpRecv(PMSG_LEVEL_UP_RECV* lpMsg) // OK
{
	ViewPoint = lpMsg->ViewPoint;
	ViewMaxHP = lpMsg->ViewMaxHP;
	ViewMaxMP = lpMsg->ViewMaxMP;
	ViewMaxBP = lpMsg->ViewMaxBP;
	ViewMaxSD = lpMsg->ViewMaxSD;
	ViewExperience = lpMsg->ViewExperience;
	ViewNextExperience = lpMsg->ViewNextExperience;
}

void GCLevelUpPointRecv(PMSG_LEVEL_UP_POINT_RECV* lpMsg) // OK
{
	if(lpMsg->result >= 16 && lpMsg->result <= 20)
	{
		ViewPoint = lpMsg->ViewPoint;
		ViewMaxHP = lpMsg->ViewMaxHP;
		ViewMaxMP = lpMsg->ViewMaxMP;
		ViewMaxBP = lpMsg->ViewMaxBP;
		ViewMaxSD = lpMsg->ViewMaxSD;
		ViewStrength = lpMsg->ViewStrength;
		ViewDexterity = lpMsg->ViewDexterity;
		ViewVitality = lpMsg->ViewVitality;
		ViewEnergy = lpMsg->ViewEnergy;
		ViewLeadership = lpMsg->ViewLeadership;
	}
}

void GCMonsterDamageRecv(PMSG_MONSTER_DAMAGE_RECV* lpMsg) // OK
{
	ViewCurHP = lpMsg->ViewCurHP;
	ViewCurSD = lpMsg->ViewCurSD;
	ViewDamageHP = lpMsg->ViewDamageHP;
	ViewDamageSD = lpMsg->ViewDamageSD;
}

void GCMasterInfoRecv(PMSG_MASTER_INFO_RECV* lpMsg) // OK
{
	ViewMaxHP = lpMsg->ViewMaxHP;
	ViewMaxMP = lpMsg->ViewMaxMP;
	ViewMaxBP = lpMsg->ViewMaxBP;
	ViewMaxSD = lpMsg->ViewMaxSD;
}

void GCMasterLevelUpRecv(PMSG_MASTER_LEVEL_UP_RECV* lpMsg) // OK
{
	ViewMaxHP = lpMsg->ViewMaxHP;
	ViewMaxMP = lpMsg->ViewMaxMP;
	ViewMaxBP = lpMsg->ViewMaxBP;
	ViewMaxSD = lpMsg->ViewMaxSD;
	ViewMasterExperience = lpMsg->ViewMasterExperience;
	ViewMasterNextExperience = lpMsg->ViewMasterNextExperience;
}

void GCNewCharacterInfoRecv(PMSG_NEW_CHARACTER_INFO_RECV* lpMsg) // OK
{
	*(WORD*)(*(DWORD*)(MAIN_CHARACTER_STRUCT)+0x0E) = lpMsg->Level;

	*(WORD*)(*(DWORD*)(MAIN_CHARACTER_STRUCT)+0x74) = lpMsg->LevelUpPoint;

	*(WORD*)(*(DWORD*)(MAIN_CHARACTER_STRUCT)+0x18) = lpMsg->Strength;

	*(WORD*)(*(DWORD*)(MAIN_CHARACTER_STRUCT)+0x1A) = lpMsg->Dexterity;

	*(WORD*)(*(DWORD*)(MAIN_CHARACTER_STRUCT)+0x1C) = lpMsg->Vitality;

	*(WORD*)(*(DWORD*)(MAIN_CHARACTER_STRUCT)+0x1E) = lpMsg->Energy;

	*(WORD*)(*(DWORD*)(MAIN_CHARACTER_STRUCT)+0x20) = lpMsg->Leadership;

	*(WORD*)(*(DWORD*)(MAIN_CHARACTER_STRUCT)+0x22) = lpMsg->Life;

	*(WORD*)(*(DWORD*)(MAIN_CHARACTER_STRUCT)+0x26) = lpMsg->MaxLife;

	*(WORD*)(*(DWORD*)(MAIN_CHARACTER_STRUCT)+0x24) = lpMsg->Mana;

	*(WORD*)(*(DWORD*)(MAIN_CHARACTER_STRUCT)+0x28) = lpMsg->MaxMana;

	*(WORD*)(*(DWORD*)(MAIN_CHARACTER_STRUCT)+0x40) = lpMsg->BP;

	*(WORD*)(*(DWORD*)(MAIN_CHARACTER_STRUCT)+0x42) = lpMsg->MaxBP;

	*(WORD*)(*(DWORD*)(MAIN_CHARACTER_STRUCT)+0x2A) = lpMsg->Shield;

	*(WORD*)(*(DWORD*)(MAIN_CHARACTER_STRUCT)+0x2C) = lpMsg->MaxShield;

	*(WORD*)(*(DWORD*)(MAIN_CHARACTER_STRUCT)+0x4C) = lpMsg->FruitAddPoint;

	*(WORD*)(*(DWORD*)(MAIN_CHARACTER_STRUCT)+0x4E) = lpMsg->MaxFruitAddPoint;

	*(WORD*)(*(DWORD*)(MAIN_CHARACTER_STRUCT)+0x50) = lpMsg->FruitSubPoint;

	*(WORD*)(*(DWORD*)(MAIN_CHARACTER_STRUCT)+0x52) = lpMsg->MaxFruitSubPoint;

	*(DWORD*)(*(DWORD*)(MAIN_CHARACTER_STRUCT)+0x10) = lpMsg->Experience;

	*(DWORD*)(*(DWORD*)(MAIN_CHARACTER_STRUCT)+0x14) = lpMsg->NextExperience;

	//EXTRA
	ViewReset = lpMsg->ViewReset;
	ViewPoint = lpMsg->ViewPoint;
	ViewCurHP = lpMsg->ViewCurHP;
	ViewMaxHP = lpMsg->ViewMaxHP;
	ViewCurMP = lpMsg->ViewCurMP;
	ViewMaxMP = lpMsg->ViewMaxMP;
	ViewCurBP = lpMsg->ViewCurBP;
	ViewMaxBP = lpMsg->ViewMaxBP;
	ViewCurSD = lpMsg->ViewCurSD;
	ViewMaxSD = lpMsg->ViewMaxSD;
	ViewStrength = lpMsg->ViewStrength;
	ViewDexterity = lpMsg->ViewDexterity;
	ViewVitality = lpMsg->ViewVitality;
	ViewEnergy = lpMsg->ViewEnergy;
	ViewLeadership = lpMsg->ViewLeadership;
}

void GCNewCharacterCalcRecv(PMSG_NEW_CHARACTER_CALC_RECV* lpMsg) // OK
{
	ViewCurHP = lpMsg->ViewCurHP;
	ViewMaxHP = lpMsg->ViewMaxHP;
	ViewCurMP = lpMsg->ViewCurMP;
	ViewMaxMP = lpMsg->ViewMaxMP;
	ViewCurBP = lpMsg->ViewCurBP;
	ViewMaxBP = lpMsg->ViewMaxBP;
	ViewCurSD = lpMsg->ViewCurSD;
	ViewMaxSD = lpMsg->ViewMaxSD;
	ViewAddStrength = lpMsg->ViewAddStrength;
	ViewAddDexterity = lpMsg->ViewAddDexterity;
	ViewAddVitality = lpMsg->ViewAddVitality;
	ViewAddEnergy = lpMsg->ViewAddEnergy;
	ViewAddLeadership = lpMsg->ViewAddLeadership;
	ViewPhysiDamageMin = lpMsg->ViewPhysiDamageMin;
	ViewPhysiDamageMax = lpMsg->ViewPhysiDamageMax;
	ViewMagicDamageMin = lpMsg->ViewMagicDamageMin;
	ViewMagicDamageMax = lpMsg->ViewMagicDamageMax;
	ViewCurseDamageMin = lpMsg->ViewCurseDamageMin;
	ViewCurseDamageMax = lpMsg->ViewCurseDamageMax;
	ViewMulPhysiDamage = lpMsg->ViewMulPhysiDamage;
	ViewDivPhysiDamage = lpMsg->ViewDivPhysiDamage;
	ViewMulMagicDamage = lpMsg->ViewMulMagicDamage;
	ViewDivMagicDamage = lpMsg->ViewDivMagicDamage;
	ViewMulCurseDamage = lpMsg->ViewMulCurseDamage;
	ViewDivCurseDamage = lpMsg->ViewDivCurseDamage;
	ViewMagicDamageRate = lpMsg->ViewMagicDamageRate;
	ViewCurseDamageRate = lpMsg->ViewCurseDamageRate;
	ViewPhysiSpeed = lpMsg->ViewPhysiSpeed;
	ViewMagicSpeed = lpMsg->ViewMagicSpeed;
	ViewAttackSuccessRate = lpMsg->ViewAttackSuccessRate;
	ViewAttackSuccessRatePvP = lpMsg->ViewAttackSuccessRatePvP;
	ViewDefense = lpMsg->ViewDefense;
	ViewDefenseSuccessRate = lpMsg->ViewDefenseSuccessRate;
	ViewDefenseSuccessRatePvP = lpMsg->ViewDefenseSuccessRatePvP;
	ViewDamageMultiplier = lpMsg->ViewDamageMultiplier;
	ViewRFDamageMultiplierA = lpMsg->ViewRFDamageMultiplierA;
	ViewRFDamageMultiplierB = lpMsg->ViewRFDamageMultiplierB;
	ViewRFDamageMultiplierC = lpMsg->ViewRFDamageMultiplierC;
	ViewDarkSpiritAttackDamageMin = lpMsg->ViewDarkSpiritAttackDamageMin;
	ViewDarkSpiritAttackDamageMax = lpMsg->ViewDarkSpiritAttackDamageMax;
	ViewDarkSpiritAttackSpeed = lpMsg->ViewDarkSpiritAttackSpeed;
	ViewDarkSpiritAttackSuccessRate = lpMsg->ViewDarkSpiritAttackSuccessRate;
}

void GCNewHealthBarRecv(PMSG_NEW_HEALTH_BAR_RECV* lpMsg) // OK
{
	ClearNewHealthBar();

	for(int n=0;n < lpMsg->count;n++)
	{
		PMSG_NEW_HEALTH_RECV* lpInfo = (PMSG_NEW_HEALTH_RECV*)(((BYTE*)lpMsg)+sizeof(PMSG_NEW_HEALTH_BAR_RECV)+(sizeof(PMSG_NEW_HEALTH_RECV)*n));

		InsertNewHealthBar(lpInfo->index,lpInfo->type,lpInfo->rate,lpInfo->rate2);
	}
}

void GCNewGensBattleInfoRecv(PMSG_NEW_GENS_BATTLE_INFO_RECV* lpMsg) // OK
{
	GensBattleMapCount = lpMsg->GensBattleMapCount;

	GensMoveIndexCount = lpMsg->GensMoveIndexCount;

	memcpy(GensBattleMap,lpMsg->GensBattleMap,sizeof(GensBattleMap));

	memcpy(GensMoveIndex,lpMsg->GensMoveIndex,sizeof(GensMoveIndex));
}

void GCNewMessageRecv(PMSG_NEW_MESSAGE_RECV* lpMsg) // OK
{

}

void DataSend(BYTE* lpMsg,DWORD size) // OK
{
	BYTE EncBuff[2048];

	if(gPacketManager.AddData(lpMsg,size) != 0 && gPacketManager.ExtractPacket(EncBuff) != 0)
	{
		BYTE send[2048];

		memcpy(send,EncBuff,size);

		if(EncBuff[0] == 0xC3 || EncBuff[0] == 0xC4)
		{
			if(EncBuff[0] == 0xC3)
			{
				BYTE save = EncBuff[1];

				EncBuff[1] = (*(BYTE*)(MAIN_PACKET_SERIAL))++;

				size = gPacketManager.Encrypt(&send[2],&EncBuff[1],(size-1))+2;

				EncBuff[1] = save;

				send[0] = 0xC3;
				send[1] = LOBYTE(size);
			}
			else
			{
				BYTE save = EncBuff[2];

				EncBuff[2] = (*(BYTE*)(MAIN_PACKET_SERIAL))++;

				size = gPacketManager.Encrypt(&send[3],&EncBuff[2],(size-2))+3;

				EncBuff[2] = save;

				send[0] = 0xC4;
				send[1] = HIBYTE(size);
				send[2] = LOBYTE(size);
			}
		}

		((void(__thiscall*)(void*,BYTE*,DWORD))0x00405110)((void*)0x08793750,send,size);
	}
}

void GCRecvCoin(PMSG_COIN_RECV* lpMsg) // OK
{
	Coin1 = lpMsg->Coin1;
	Coin2 = lpMsg->Coin2;
	Coin3 = lpMsg->Coin3;
}

void GCBuyConfirmRecv(PMSG_ITEM_BUY_RECV* lpMsg) // OK
{
	gInterface.Data[eCONFIRM_MAIN].OnShow = true;
	pSetCursorFocus = true;
	gInterface.ConfirmSlot = lpMsg->slot;
}
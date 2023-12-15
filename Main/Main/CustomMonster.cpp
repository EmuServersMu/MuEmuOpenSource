#include "stdafx.h"
#include "MemScript.h"
#include "Util.h"
#include "Defines.h"
#include "Reconnect.h"
#include "CustomMonster.h"
#include "CustomNpcName.h"
#include "Import.h"
#include "Defines.h"

CCustomMonster gCustomMonster;

CCustomMonster::CCustomMonster()
{
	this->Init();
}

CCustomMonster::~CCustomMonster()
{
	
}

void CCustomMonster::Init()
{
	for (int i=0; i<MAX_CUSTOMMONSTER; i++)
	{
		this->m_CustomMonster[i].Index = -1;
	}
	memset(this->m_NpcName,0,sizeof(this->m_NpcName));
}

void CCustomMonster::Load(CUSTOMMONSTER_DATA* info)
{
	for (int i=0; i<MAX_CUSTOMMONSTER; i++)
	{
		this->SetInfo(info[i]);
	}
}

void CCustomMonster::SetInfo(CUSTOMMONSTER_DATA info)
{
	if(info.Index < 0 || info.Index >= MAX_CUSTOMMONSTER)
	{
		return;
	}

	this->m_CustomMonster[info.Index] = info;
}

CUSTOMMONSTER_DATA* CCustomMonster::GetInfoByMonsterID(int MonsterID)
{
	for(int n=0;n < MAX_CUSTOMMONSTER;n++)
	{
		CUSTOMMONSTER_DATA* lpInfo = this->GetInfoByIndex(n);

		if(lpInfo == 0)
		{
			continue;
		}

		if(MonsterID == lpInfo->ID)
		{
			return lpInfo;
		}
	}

	return 0;
}

CUSTOMMONSTER_DATA* CCustomMonster::GetInfoByIndex(int index)
{
	if(index < 0 || index >= MAX_CUSTOMMONSTER)
	{
		return 0;
	}

	if(this->m_CustomMonster[index].Index != index)
	{
		return 0;
	}

	return &this->m_CustomMonster[index];
}

void CCustomMonster::InitMonster()
{
	SetCompleteHook(0xE8, 0x0061FE3F, &LoadMonsterBMD);
	SetCompleteHook(0xE8, 0x0061FEEA, &LoadMonsterTexture);

	//Limit kill

	//SetByte(0x00557B50,0x78);
	//SetByte(0x00559B86,0x04);

	//SetByte(0x005582CF,0x78);
	//SetByte(0x00559B86,0x04);

	//SetByte(0x00559B85,0x78);
	//SetByte(0x00559B86,0x04);

	SetCompleteHook(0xE8, 0x004E199D, &ShowMonster);
	SetCompleteHook(0xE8, 0x00587049, &ShowMonster);
	SetCompleteHook(0xE8, 0x00590CCC, &ShowMonster);
	SetCompleteHook(0xE8, 0x005BBEE6, &ShowMonster);
	SetCompleteHook(0xE8, 0x0064229D, &ShowMonster);
	SetCompleteHook(0xE8, 0x00642D51, &ShowMonster);
	SetCompleteHook(0xE8, 0x00643229, &ShowMonster);
	SetCompleteHook(0xE8, 0x0065EA86, &ShowMonster);
	SetCompleteHook(0xE8, 0x00911A53, &ShowMonster);
	SetCompleteHook(0xE8, 0x00911A6D, &ShowMonster);
	SetCompleteHook(0xE8, 0x00911A87, &ShowMonster);
	SetCompleteHook(0xE8, 0x00911AA1, &ShowMonster);
	SetCompleteHook(0xE8, 0x00911ABB, &ShowMonster);

	SetCompleteHook(0xFF, 0x0058101A, &this->SetMainAttribute);
	SetCompleteHook(0xFF, 0x0058105B, &this->SetMainAttribute);
	SetCompleteHook(0xFF, 0x0058109C, &this->SetMainAttribute);
	SetCompleteHook(0xFF, 0x005810DD, &this->SetMainAttribute);
	SetCompleteHook(0xFF, 0x0058111E, &this->SetMainAttribute);
	SetCompleteHook(0xFF, 0x0058115F, &this->SetMainAttribute);
	SetCompleteHook(0xFF, 0x005811A0, &this->SetMainAttribute);
	SetCompleteHook(0xFF, 0x005811E1, &this->SetMainAttribute);
	SetCompleteHook(0xFF, 0x00581222, &this->SetMainAttribute);
	SetCompleteHook(0xFF, 0x00581263, &this->SetMainAttribute);
	SetCompleteHook(0xFF, 0x005812A8, &this->SetMainAttribute);
	SetCompleteHook(0xFF, 0x005812ED, &this->SetMainAttribute);
	SetCompleteHook(0xFF, 0x0058132E, &this->SetMainAttribute);
	SetCompleteHook(0xFF, 0x0058136F, &this->SetMainAttribute);
	SetCompleteHook(0xFF, 0x005813B4, &this->SetMainAttribute);
	SetCompleteHook(0xFF, 0x005813F9, &this->SetMainAttribute);
	SetCompleteHook(0xFF, 0x00586859, &this->SetMainAttribute);
}

void CCustomMonster::LoadMonsterBMD(signed int Class, char* FileDir, char* BmdName, signed int BmdType)
{
	int MonsterID = Class - MAX_MONSTER_MODEL;
	// ----
	CUSTOMMONSTER_DATA* lpInfo = gCustomMonster.GetInfoByMonsterID(MonsterID);
	
	if (lpInfo == 0)
	{
		pLoadMonsterBMD(Class, FileDir, BmdName, BmdType);
	}
	else
	{
		pLoadMonsterBMD(Class, lpInfo->Dir, lpInfo->BMDFile, -1);
	}
}

void CCustomMonster::LoadMonsterTexture(signed int Class, char* FolderDir, int a3, int a4)
{
	int MonsterID = Class - MAX_MONSTER_MODEL;

	CUSTOMMONSTER_DATA* lpInfo = gCustomMonster.GetInfoByMonsterID(MonsterID);

	if (lpInfo == 0)
	{
		pLoadTexture(Class, FolderDir, a3, a4,0);
	}
	else
	{
		pLoadTexture(Class, lpInfo->Folder, a3, a4,0);
	}
}

int CCustomMonster::ShowMonster(int Class, int a2, int a3, int a4)
{

	for (int i = 0; i < MAX_CUSTOMMONSTER; i++)
	{
		if (gCustomMonster.m_CustomMonster[i].Index == -1)
		{
			continue;
		}
		if (Class != gCustomMonster.m_CustomMonster[i].ID)
		{
			continue;
		}
	
		pLoadMonsterID(Class);

		DWORD ObjectStruct = pViewObject(a4, Class + MAX_MONSTER_MODEL, a2, a3, 0.0);

		ObjectPreview* Object = &*(ObjectPreview*)ObjectStruct;

		memcpy(Object->Name, gCustomMonster.m_CustomMonster[i].Name, sizeof(gCustomMonster.m_CustomMonster[i].Name));

		NPCNAME_DATA* NpcName = gNPCName.GetNPCName(Class, pMapNumber, Object->RespawnPosX, Object->RespawnPosY);

		if (NpcName != 0)
		{
			sprintf(Object->Name, NpcName->Name);
		}

		switch (gCustomMonster.m_CustomMonster[i].Type)
		{
			case CUSTOM_MONSTER_TYPE_NPC:
				*(BYTE*)(ObjectStruct + 800) = emNPC;
				break;
			case CUSTOM_MONSTER_TYPE_MOB:
				*(BYTE*)(ObjectStruct + 800) = emMonster;
				break;
			default:
				*(BYTE*)(ObjectStruct + 800) = emNone;
				break;
		}

		*(float *)(ObjectStruct + 872) = gCustomMonster.m_CustomMonster[i].Size;

		Object->ID = Class;

		*(BYTE*)(ObjectStruct + 798) = 0;

		Object->Unknown128 = *(DWORD*)0x879343C;
			
		return ObjectStruct;
	}

	return (int)pShowMonster(Class, a2, a3, a4);

	
}

//int CCustomMonster::ShowMonster(int MonsterID, int a2, int a3, int a4)
//{
//	for (int n = 0; n < MAX_CUSTOMMONSTER; n++)
//	{
//		if (MonsterID == gCustomMonster.m_CustomMonster[n].ID)
//		{
//			pLoadMonsterID(MonsterID);
//			//pOpenMonsterModel(MonsterID);
//
//			DWORD ObjectStruct = pViewObject(a4, MonsterID + MAX_MONSTER_MODEL, a2, a3, 0.0); //665?
//
//			lpViewObj Object = &*(ObjectPreview*)ObjectStruct;
//
//			//memcpy(Object->Name, gCustomMonster.m_CustomMonsterInfo[n].Name, sizeof(Object->Name));
//			strcpy((char *)(ObjectStruct + 56), gCustomMonster.m_CustomMonster[n].Name);
//			//wsprintf(Object->Name, gCustomMonster.m_CustomMonsterInfo[n].Name);
//
//			if (gCustomMonster.m_CustomMonster[n].Type == 0)
//			{
//				*(BYTE*)(ObjectStruct + 800) = emNPC;
//				//Object->ID = MonsterID;
//			}
//			else
//			{
//				*(BYTE*)(ObjectStruct + 800) = emMonster;
//			}
//
//			*(float *)(ObjectStruct + 872) = gCustomMonster.m_CustomMonster[n].Size;
//
//			//Object->ID = MonsterID;
//			//*(BYTE*)(ObjectStruct + 798) = 0;
//			//Object->Unknown128 = *(WORD*)0x879343C;
//			//sub_580BB0(ObjectStruct, MonsterID);
//			//Monster::SetMainAttribute(ObjectStruct, MonsterID);
//			//return sub_580BB0(ObjectStruct, MonsterID);
//
//			//sub_580BB0(ObjectStruct, MonsterID);
//			//gCustomMonsters.SetMainAttribute()
//			CCustomMonster::SetMainAttribute((lpViewObj)ObjectStruct, MonsterID);
//			return ObjectStruct;
//		}
//	}
//
//	return (int)pShowMonster(MonsterID, a2, a3, a4);
//}

void CCustomMonster::SetMainAttribute(lpViewObj Object, int MonsterID)
{
	sub_580BB0((int)Object,MonsterID);

	NPCNAME_DATA* NpcName = gNPCName.GetNPCName(MonsterID, pMapNumber, Object->RespawnPosX, Object->RespawnPosY);

	if (NpcName != 0)
	{
		sprintf(Object->Name, NpcName->Name);
	}
}
//
//void CCustomMonster::SetMainAttribute(lpViewObj Object, int MonsterID)
//{
//	//lpViewObj Object	= &*(ObjectPreview*)ObjectPointer;
//	int MapClass		= pMapNumber - 9;	//ebp-4
//	// ----
//	if( MapClass > 0 && MapClass <= 8 && MonsterID >= 84 && MonsterID <= 143 )
//	{
//		Object->Unknown130				= 0;
//		Object->m_Model.Scale	+= (double)(MapClass / 3) * 0.05000000074505806;
//	}
//	// ----
//	if( !Object )
//	{
//		return;
//	}
//
//	//g_Console.AddMessage(3,"%s",pGetMonsterName(MonsterID));
//
//	//memcpy(Object->Name, pGetMonsterName(MonsterID), sizeof(Object->Name));
//
//	//if (pGetMonsterName(MonsterID) == 0)
//	//{
//	//	for( int i = 0; i < MAX_MONSTER; i++ )
//	//	{
//	//		//g_Console.AddMessage(3,"%s",sub_590DD0_Addr(i));
//	//		gCustomMonster.lpNpcName[i] = *(NpcNameList*)(oNpcName + (sizeof(NpcNameList)*2) * i);
//	//		if( MonsterID == gCustomMonsters.lpNpcName[i].ObjectID )
//	//		{
//	//			// ----
//	//			memcpy(Object->Name, gCustomMonsters.lpNpcName[i].Name, sizeof(gCustomMonsters.lpNpcName[i].Name)-1);
//	//			break;
//	//		}
//
//	//		/*if (i == MonsterID)
//	//		{
//	//			memcpy(Object->Name, pGetMonsterName(i), sizeof(Object->Name));
//	//			break;
//	//		}*/
//	//	}
//	//}
//	//else
//	//{
//		memcpy(Object->Name, pGetMonsterName(MonsterID), sizeof(Object->Name));
//		//g_Console.AddMessage(3,"MonsterName = %s", Object->Name);
//	//}
//
//	NPCNAME_DATA* NpcName = gNPCName.GetNPCName(MonsterID, pMapNumber, Object->RespawnPosX, Object->RespawnPosY);
//
//	if (NpcName != 0)
//	{
//		sprintf(Object->Name, NpcName->Name);
//	}
//
//	if( MonsterID == 0)
//	{
//		sprintf(Object->Name, "Bull Fighter");
//	}
//
//	if (MonsterID == 42)
//	{
//		sprintf(Object->Name, "Red Dragon");
//	}
//
//	// ----
//	//for( int i = 0; i < MAX_MONSTER; i++ )
//	//{
//	//	//g_Console.AddMessage(3,"%s",sub_590DD0_Addr(i));
//	//	//gCustomMonsters.lpNpcName[i] = *(NpcNameList*)(oNpcName + (sizeof(NpcNameList)*2) * i);
//	//	// ----
//	//	//if( MonsterID == gCustomMonsters.lpNpcName[i].ObjectID )
//	//	//{
//	//	//	// ----
//	//	//	memcpy(Object->Name, gCustomMonsters.lpNpcName[i].Name, sizeof(gCustomMonsters.lpNpcName[i].Name)-1);
//	//	//	break;
//	//	//}
//
//	//	if (i == MonsterID)
//	//	{
//	//		memcpy(Object->Name, pGetMonsterName(i), sizeof(Object->Name));
//	//		break;
//	//	}
//
//	//	NPCNAME_DATA* NpcName = gNPCName.GetNPCName(MonsterID, pMapNumber, Object->RespawnPosX, Object->RespawnPosY);
//
//	//	if (NpcName != 0)
//	//	{
//	//		sprintf(Object->Name, NpcName->Name);
//	//		break;
//	//	}
//
//	//	if( MonsterID == 0)
//	//	{
//	//		sprintf(Object->Name, "Bull Fighter");
//	//		break;
//	//	}
//	//}
//	// ----
//	Object->ID = MonsterID;
//	Object->m_Model.Unknown22 = 0;
//	Object->Unknown128 = *(DWORD*)0x879343C;
//	// ----
//	//console.Log("", "ID %d | Name %s", MonsterID, Object->Name);
//	if( MonsterID == 200 )	//-> Soccerball
//	{
//		Object->m_Model.ObjectType = emMonster;
//	}
//	else
//	{
//		if( MonsterID < 260 )
//		{
//			if( MonsterID <= 200 )
//			{
//				if( MonsterID < 150 )
//				{
//					if( MonsterID <= 110 )
//					{
//						if( MonsterID < 100 )
//						{
//							Object->m_Model.ObjectType	= emMonster;
//						}
//						else
//						{
//							Object->m_Model.ObjectType	= emNone;
//						}
//					}
//					else
//					{
//						Object->m_Model.ObjectType = emMonster;
//					}
//				}
//				else
//				{
//					Object->m_Model.ObjectType	= emMonster;
//				}
//			}
//			else
//			{
//				Object->m_Model.ObjectType = emNPC;
//			}
//		}
//		else
//		{
//			Object->m_Model.ObjectType = emMonster;
//		}
//	}
//	// ----
//	switch(MonsterID)
//	{
//	case 367:	//-> Gateway Machine
//	case 368:	//-> Elpis
//	case 369:	//-> Osbourne
//	case 370:	//-> Jerridon
//	case 371:	//-> Leo the Helper
//	case 375:	//-> Chaos Card Master
//	case 376:	//-> Pamela the Supplier
//	case 377:	//-> Angela the Supplier
//	case 379:	//-> Natasha the Firecracker Merchant
//	case 380:	//-> Stone Statue
//	case 381:	//-> MU Allies General
//	case 382:	//-> Illusion Sorcerer Elder
//	case 383:	//-> Alliance Sacred Item Storage
//	case 384:	//-> Illusion Castle Sacred Item Storage
//	case 385:	//-> Mirage
//	case 406:	//-> Apostle Devin
//	case 407:	//-> Werewolf Quarel
//	case 408:	//-> Gatekeeper
//	case 414:	//-> Helper Ellen
//	case 415:	//-> Silvia
//	case 416:	//-> Rhea
//	case 417:	//-> Marce
//	case 450:	//-> Cherry Blossom Spirit
//	case 452:	//-> Seed Master
//	case 453:	//-> Seed Researcher
//	case 464:	//-> Re-Initialization Helper
//	case 465:	//-> Santa Claus
//	case 467:	//-> Snowman
//	case 468:	//-> Dasher
//	case 469:	//-> Kermit
//	case 470:	//-> Little Santa
//	case 471:	//-> Cupid
//	case 472:	//-> Prancer
//	case 473:	//-> Donner
//	case 474:	//-> Vixen
//	case 475:	//-> Blitzen
//	case 478:	//-> Delgado
//	case 479:	//-> Doorkeeper Titus
//	case 492:	//-> Moss
//	case 522:	//-> Jerint the Assistant
//	case 540:	//-> Lugard
//	case 541:	//-> Interim Reward Chest
//	case 542:	//-> Final Reward Chest
//	case 543:	//-> Gens Duprian Steward
//	case 544:	//-> Gens Vanert Steward
//	case 545:	//-> Christine the General Goods Merchant
//	case 546:	//-> Jeweler Raul
//	case 547:	//-> Market Union Member Julia
//	case 566:	//-> Mercenary Guild Manager Tercia
//	case 567:	//-> Priestess Veina
//	case 568:	//-> Wandering Merchant Zyro
//	case 577:	//-> Leina the General Goods Merchant
//	case 578:	//-> Weapons Merchant Bolo	
//	case 579:	//-> David
//		{
//			Object->m_Model.ObjectType = emNPC;
//		}
//		break;
//	}
//	// ----
//	if( MonsterID >= 480 && MonsterID <= 491 )
//	{
//		Object->m_Model.ObjectType = emMonster;
//	}
//	// ----
//	if( MonsterID == 451 )	//-> Cherry Blossom Tree
//	{
//		Object->m_Model.ObjectType = emNone;
//	}
//
//	for (int n = 0; n < MAX_CUSTOMMONSTER; n++)
//	{
//		if (MonsterID == gCustomMonster.m_CustomMonster[n].ID)
//		{
//			if (gCustomMonster.m_CustomMonster[n].Type == 0)
//			{
//				Object->m_Model.ObjectType = emNPC;
//			}
//			else
//			{
//				Object->m_Model.ObjectType = emMonster;
//			}
//		}
//	}
//}

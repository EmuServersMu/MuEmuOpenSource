// Protect.h: interface for the CProtect class.
//
//////////////////////////////////////////////////////////////////////

#pragma once

#include "CustomBuyVip.h"
#include "CustomCommandInfo.h"
#include "CustomEventTime.h"
#include "CustomFog.h"
#include "CustomGloves.h"
#include "CustomItem.h"
#include "CustomItemDescription.h"
#include "CustomJewel.h"
#include "CustomMessage.h"
#include "CustomMonster.h"
#include "CustomNpcName.h"
#include "CustomWing.h"
#include "ItemSmoke.h"
#include "StaticEffect.h"
#include "DynamicEffect.h"

struct MAIN_FILE_INFO
{
/*MainInfo==========================================================================================================================*/
/*MainInfo==========================================================================================================================*/
/*MainInfo==========================================================================================================================*/
	BYTE LauncherType; 
	char LauncherName[32];
	char CustomerName[32];
	char IpAddress[32];
	WORD IpAddressPort;
	char ClientVersion[8];
	char ClientSerial[17];
	char WindowName[32];
	char ScreenShotPath[50];
/*==================================================================================================================================*/
	char ClientName[32];
	char PluginName1[32];           
	char PluginName2[32];           
	char PluginName3[32];           
	char PluginName4[32];           
	char PluginName5[32];           
	char PluginName6[32];           
	char PluginName7[32];           
	char PluginName8[32];           
	char PluginName9[32];           
	char PluginName10[32];    
/*==================================================================================================================================*/
#if SERVER_NAME
	char ServerName1[32];
	char ServerName2[32];
	char ServerName3[32];
	char ServerName4[32];
#endif
/*==================================================================================================================================*/
	DWORD ClientCRC32;	            
	DWORD Plugin1CRC32;             
	DWORD Plugin2CRC32;	            
	DWORD Plugin3CRC32;	            
	DWORD Plugin4CRC32;	            
	DWORD Plugin5CRC32;	            
	DWORD Plugin6CRC32;	            
	DWORD Plugin7CRC32;	            
	DWORD Plugin8CRC32;	            
	DWORD Plugin9CRC32;	            
	DWORD Plugin10CRC32;
/*HelperInfo========================================================================================================================*/
/*HelperInfo========================================================================================================================*/
/*HelperInfo========================================================================================================================*/
	DWORD HelperActiveAlert;
	DWORD HelperActiveLevel;
/*CharacterInfo=====================================================================================================================*/
/*CharacterInfo=====================================================================================================================*/
/*CharacterInfo=====================================================================================================================*/
	DWORD DWMaxAttackSpeed;
	DWORD DKMaxAttackSpeed;
	DWORD FEMaxAttackSpeed;
	DWORD MGMaxAttackSpeed;
	DWORD DLMaxAttackSpeed;
	DWORD SUMaxAttackSpeed;
	DWORD RFMaxAttackSpeed;
/*ReconnectInfo=====================================================================================================================*/
/*ReconnectInfo=====================================================================================================================*/
/*ReconnectInfo=====================================================================================================================*/
	DWORD ReconnectTime;
	DWORD ItemLevel_15;
/*CUSTOM============================================================================================================================*/
/*CUSTOM============================================================================================================================*/
/*CUSTOM============================================================================================================================*/
	DWORD RemoveClass;
	DWORD RankUserType;
	DWORD DisableTree;
	DWORD CsSkill;
	DWORD DisableReflectEffect;
	DWORD EnableVipShop;
	DWORD VipTypes;
	DWORD PrintLogo;
/*==================================================================================================================================*/
	DWORD CustomMenuSwitch;
	DWORD CustomMenuType;
/*==================================================================================================================================*/
	DWORD EnableEventTimeButton;
	DWORD EnableVipShopButton;
	DWORD EnableRankingButton;
	DWORD EnableCommandButton;
	DWORD EnableOptionButton;
	DWORD EnableCoinStatus;
	DWORD EnableShopValueSystem;
/*==================================================================================================================================*/
	DWORD CustomStoreEnableJoB;
	DWORD CustomStoreEnableJoS;
	DWORD CustomStoreEnableJoC;
	DWORD CustomStoreEnableCoin1;
	DWORD CustomStoreEnableCoin2;
	DWORD CustomStoreEnableCoin3;
	DWORD CustomOffStoreEnable;
	DWORD CustomMonsterEnable;
/*==================================================================================================================================*/
	DWORD DisablePartyHpBar;
	DWORD RankUserShowOverHead;
	DWORD RankUserOnlyOnSafeZone;
	DWORD RankUserShowReset;
	DWORD RankUserShowMasterReset;
	DWORD RankUserNeedAltKey;
	DWORD CustomInterfaceType;
	DWORD CustomInterfaceHelperBar;
/*==================================================================================================================================*/
#if SELEC_CHAR_X700
	DWORD CustomSelectX700;
#endif
#if CHATATEC_ANIMATE
	DWORD SelectCharAnimate;
#endif
/*==================================================================================================================================*/
	DWORD PingTest;
	DWORD CustomGlovesEnable;
/*==================================================================================================================================*/
#if REDUCE_MEMORY
	DWORD ReduceMemory;    
	DWORD ReduceMemoryUsage; 
#endif
/*UPGRADE===========================================================================================================================*/
/*UPGRADE===========================================================================================================================*/
/*UPGRADE===========================================================================================================================*/
#if LIMITE_FPS
	DWORD LimitFPS;
#endif

#if DISABLE_BOTON
	DWORD DisableBoton;
#endif
/*==================================================================================================================================*/
	CUSTOM_MESSAGE_INFO EngCustomMessageInfo[MAX_CUSTOM_MESSAGE];
	CUSTOM_MESSAGE_INFO PorCustomMessageInfo[MAX_CUSTOM_MESSAGE];
	CUSTOM_MESSAGE_INFO SpnCustomMessageInfo[MAX_CUSTOM_MESSAGE];
/*==================================================================================================================================*/
	CUSTOM_JEWEL_INFO CustomJewelInfo[MAX_CUSTOM_JEWEL];
/*==================================================================================================================================*/
	CUSTOM_WING_INFO CustomWingInfo[MAX_CUSTOM_WING];
	CUSTOM_ITEM_INFO CustomItemInfo[MAX_CUSTOM_ITEM];
/*==================================================================================================================================*/
	CUSTOM_WING_EFFECT_INFO CustomWingEffectInfo[MAX_CUSTOM_WING_EFFECT];
	DYNAMIC_WING_EFFECT_INFO DynamicWingEffectInfo[MAX_DYNAMIC_WING_EFFECT];
	CUSTOM_BUYVIP_INFO CustomBuyVipInfo[MAX_CUSTOM_BUYVIP];
	CUSTOM_COMMAND_INFO CustomCommandInfo[MAX_CUSTOM_COMMAND];
/*==================================================================================================================================*/
	CUSTOM_EVENT_INFO CustomEventInfo[MAX_EVENTTIME];
	CUSTOM_DESCRIPTION_INFO CustomDescriptionInfo[MAX_CUSTOM_DESCRIPTION];
	CUSTOM_SMOKEEFFECT CustomSmokeEffect[MAX_SMOKE_ITEMS];
	CUSTOM_FOG CustomFog[MAX_FOG];
	CUSTOMMONSTER_DATA CustomMonsters[MAX_CUSTOMMONSTER];
	NPCNAME_DATA CustomNPCName[MAX_CUSTOM_NPCNAME];
	CUSTOM_RF_GLOVES CustomGloves[MAX_CUSTOM_GLOVES];
/*==================================================================================================================================*/
};

class CProtect
{
public:
	CProtect();
	virtual ~CProtect();
	bool ReadMainFile(char* name);
	void CheckLauncher();
	void CheckInstance();
	void CheckClientFile();
	void CheckPlugin1File();
	void CheckPlugin2File();
	void CheckPlugin3File();
	void CheckPlugin4File();
	void CheckPlugin5File();
	void CheckPlugin6File();
	void CheckPlugin7File();
	void CheckPlugin8File();
	void CheckPlugin9File();
	void CheckPlugin10File();
public:
	MAIN_FILE_INFO m_MainInfo;
	DWORD m_ClientFileCRC;
};

extern CProtect gProtect;

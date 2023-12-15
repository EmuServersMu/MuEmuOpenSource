#include "stdafx.h"
#include "..\..\Util\CCRC32.H"
#include "CustomBuyVip.h"
#include "CustomCommandInfo.h"
#include "CustomEventTimeText.h"
#include "CustomGloves.h"
#include "CustomItem.h"
#include "CustomItemDescription.h"
#include "CustomJewel.h"
#include "CustomMessage.h"
#include "CustomMonster.h"
#include "CustomNpcName.h"
#include "CustomWing.h"
#include "CustomWIngEffect.h"
#include "CustomEffectDynamic.h"
#include "SmokeEffect.h"
#include "ThemidaSDK.h"
#include "Fog.h" 

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
	CUSTOM_DESCRIPTION_INFO CustomDescriptionInfo[MAX_DESCRIPTION_ITEM];
	CUSTOM_SMOKEEFFECT CustomSmokeEffect[MAX_SMOKE_ITEMS];
	CUSTOM_FOG CustomFog[MAX_FOG];
	CUSTOMMONSTER_DATA CustomMonsters[MAX_CUSTOMMONSTERS];
	NPCNAME_DATA CustomNPCName[MAX_CUSTOM_NPCNAME];
	CUSTOM_RF_GLOVES CustomGloves[MAX_CUSTOM_GLOVES];
/*==================================================================================================================================*/
};

int _tmain(int argc,_TCHAR* argv[]) // OK
{
	CLEAR_START

	ENCODE_START

	MAIN_FILE_INFO info;

	memset(&info,0,sizeof(info));

/*MainInfo==========================================================================================================================*/
/*MainInfo==========================================================================================================================*/
/*MainInfo==========================================================================================================================*/

	info.LauncherType = GetPrivateProfileInt   ("MainInfo","LauncherType",0,".\\MainInfo.ini");
	GetPrivateProfileString                    ("MainInfo","LauncherName","XTLauncherExecutable",info.LauncherName,sizeof(info.LauncherName),".\\MainInfo.ini");
	info.IpAddressPort = GetPrivateProfileInt  ("MainInfo","IpAddressPort",44405,".\\MainInfo.ini");
	GetPrivateProfileString                    ("MainInfo","CustomerName","",info.CustomerName,sizeof(info.CustomerName),".\\MainInfo.ini");
	GetPrivateProfileString                    ("MainInfo","IpAddress","",info.IpAddress,sizeof(info.IpAddress),".\\MainInfo.ini");
	GetPrivateProfileString                    ("MainInfo","ClientVersion","",info.ClientVersion,sizeof(info.ClientVersion),".\\MainInfo.ini");
	GetPrivateProfileString                    ("MainInfo","ClientSerial","",info.ClientSerial,sizeof(info.ClientSerial),".\\MainInfo.ini");
	GetPrivateProfileString                    ("MainInfo","WindowName","",info.WindowName,sizeof(info.WindowName),".\\MainInfo.ini");
	GetPrivateProfileString                    ("MainInfo","ScreenShotPath","",info.ScreenShotPath,sizeof(info.ScreenShotPath),".\\MainInfo.ini");
	GetPrivateProfileString                    ("MainInfo","ClientName","",info.ClientName,sizeof(info.ClientName),".\\MainInfo.ini");

/*==================================================================================================================================*/

	GetPrivateProfileString                    ("MainInfo","PluginName1","",info.PluginName1,sizeof(info.PluginName1),".\\MainInfo.ini");																		         
	GetPrivateProfileString                    ("MainInfo","PluginName2","",info.PluginName2,sizeof(info.PluginName2),".\\MainInfo.ini");																		         
	GetPrivateProfileString                    ("MainInfo","PluginName3","",info.PluginName3,sizeof(info.PluginName3),".\\MainInfo.ini");																			         
	GetPrivateProfileString                    ("MainInfo","PluginName4","",info.PluginName4,sizeof(info.PluginName4),".\\MainInfo.ini");																		         
	GetPrivateProfileString                    ("MainInfo","PluginName5","",info.PluginName5,sizeof(info.PluginName5),".\\MainInfo.ini");																		         
	GetPrivateProfileString                    ("MainInfo","PluginName6","",info.PluginName6,sizeof(info.PluginName6),".\\MainInfo.ini");																		         
	GetPrivateProfileString                    ("MainInfo","PluginName7","",info.PluginName7,sizeof(info.PluginName7),".\\MainInfo.ini");																			         
	GetPrivateProfileString                    ("MainInfo","PluginName8","",info.PluginName8,sizeof(info.PluginName8),".\\MainInfo.ini");																			         
	GetPrivateProfileString                    ("MainInfo","PluginName9","",info.PluginName9,sizeof(info.PluginName9),".\\MainInfo.ini");
	GetPrivateProfileString                    ("MainInfo","PluginName10","",info.PluginName10,sizeof(info.PluginName10),".\\MainInfo.ini");
											   
#if SERVER_NAME								   
	GetPrivateProfileString                    ("MainInfo","ServerName1","",info.ServerName1,sizeof(info.ServerName1),".\\MainInfo.ini");	
	GetPrivateProfileString                    ("MainInfo","ServerName2","",info.ServerName2,sizeof(info.ServerName2),".\\MainInfo.ini");																			         
	GetPrivateProfileString                    ("MainInfo","ServerName3","",info.ServerName3,sizeof(info.ServerName3),".\\MainInfo.ini");																		         
	GetPrivateProfileString                    ("MainInfo","ServerName4","",info.ServerName4,sizeof(info.ServerName4),".\\MainInfo.ini");
#endif 

/*HelperInfo========================================================================================================================*/
/*HelperInfo========================================================================================================================*/
/*HelperInfo========================================================================================================================*/

	info.HelperActiveAlert = GetPrivateProfileInt                  ("HelperInfo","HelperActiveAlert",0,".\\MainInfo.ini");												                   
	info.HelperActiveLevel = GetPrivateProfileInt                  ("HelperInfo","HelperActiveLevel",80,".\\MainInfo.ini");

/*CharacterInfo=====================================================================================================================*/
/*CharacterInfo=====================================================================================================================*/
/*CharacterInfo=====================================================================================================================*/

	info.DWMaxAttackSpeed = GetPrivateProfileInt                   ("CharacterInfo","DWMaxAttackSpeed",65535,".\\MainInfo.ini");											                   
	info.DKMaxAttackSpeed = GetPrivateProfileInt                   ("CharacterInfo","DKMaxAttackSpeed",65535,".\\MainInfo.ini");											                   
	info.FEMaxAttackSpeed = GetPrivateProfileInt                   ("CharacterInfo","FEMaxAttackSpeed",65535,".\\MainInfo.ini");											                   
	info.MGMaxAttackSpeed = GetPrivateProfileInt                   ("CharacterInfo","MGMaxAttackSpeed",65535,".\\MainInfo.ini");											                   
	info.DLMaxAttackSpeed = GetPrivateProfileInt                   ("CharacterInfo","DLMaxAttackSpeed",65535,".\\MainInfo.ini");											                   
	info.SUMaxAttackSpeed = GetPrivateProfileInt                   ("CharacterInfo","SUMaxAttackSpeed",65535,".\\MainInfo.ini");											                   
	info.RFMaxAttackSpeed = GetPrivateProfileInt                   ("CharacterInfo","RFMaxAttackSpeed",65535,".\\MainInfo.ini");

/*ReconnectInfo=====================================================================================================================*/
/*ReconnectInfo=====================================================================================================================*/
/*ReconnectInfo=====================================================================================================================*/

	info.ReconnectTime = GetPrivateProfileInt                      ("ReconnectInfo","ReconnectTime",0,".\\MainInfo.ini");
	info.ItemLevel_15 = GetPrivateProfileInt                       ("Fix","ItemLevel_15",0,".\\MainInfo.ini");

/*CUSTOM============================================================================================================================*/
/*CUSTOM============================================================================================================================*/
/*CUSTOM============================================================================================================================*/

	info.RemoveClass = GetPrivateProfileInt                        ("Custom","RemoveClass",0,".\\MainInfo.ini");	
/*==================================================================================================================================*/
	info.RankUserType = GetPrivateProfileInt                       ("Custom","RankUserType",0,".\\MainInfo.ini");		
	info.RankUserShowOverHead = GetPrivateProfileInt               ("Custom","RankUserShowOverHead",0,".\\MainInfo.ini");	
	info.RankUserShowReset = GetPrivateProfileInt                  ("Custom","RankUserShowReset",1,".\\MainInfo.ini");	
	info.RankUserShowMasterReset = GetPrivateProfileInt            ("Custom","RankUserShowMasterReset",1,".\\MainInfo.ini");
	info.RankUserOnlyOnSafeZone = GetPrivateProfileInt             ("Custom","RankUserOnlyOnSafeZone",1,".\\MainInfo.ini");													               											               													               
	info.RankUserNeedAltKey = GetPrivateProfileInt                 ("Custom","RankUserNeedAltKey",0,".\\MainInfo.ini");			
/*==================================================================================================================================*/
	info.DisableTree = GetPrivateProfileInt                        ("Custom","DisableMasterSkillTree",0,".\\MainInfo.ini");
	info.CsSkill = GetPrivateProfileInt                            ("Custom","EnableCsSkillsAllMaps",0,".\\MainInfo.ini");
	info.DisableReflectEffect = GetPrivateProfileInt               ("Custom","DisableReflectEffect",0,".\\MainInfo.ini");	
/*==================================================================================================================================*/
	info.EnableVipShop = GetPrivateProfileInt                      ("Custom","EnableVipShop",0,".\\MainInfo.ini");													               
	info.VipTypes = GetPrivateProfileInt                           ("Custom","VipTypes",3,".\\MainInfo.ini");	
/*==================================================================================================================================*/
	info.PrintLogo = GetPrivateProfileInt                          ("Custom","PrintLogo",0,".\\MainInfo.ini");
/*==================================================================================================================================*/
	info.CustomMenuSwitch = GetPrivateProfileInt                   ("Custom","CustomMenuSwitch",0,".\\MainInfo.ini");												                   
	info.CustomMenuType = GetPrivateProfileInt                     ("Custom","CustomMenuType",0,".\\MainInfo.ini");														           
	info.EnableEventTimeButton = GetPrivateProfileInt              ("Custom","EnableEventTimeButton",0,".\\MainInfo.ini");	  													           
	info.EnableVipShopButton = GetPrivateProfileInt                ("Custom","EnableVipShopButton",0,".\\MainInfo.ini");												                   
	info.EnableRankingButton = GetPrivateProfileInt                ("Custom","EnableRankingButton",0,".\\MainInfo.ini");												                   
	info.EnableCommandButton = GetPrivateProfileInt                ("Custom","EnableCommandButton",0,".\\MainInfo.ini");														           
	info.EnableOptionButton = GetPrivateProfileInt                 ("Custom","EnableOptionButton",0,".\\MainInfo.ini");												                   
	info.EnableCoinStatus = GetPrivateProfileInt                   ("Custom","EnableCoinStatus",0,".\\MainInfo.ini");	
/*==================================================================================================================================*/
	info.EnableShopValueSystem  = GetPrivateProfileInt             ("Custom","EnableShopValueSystem",0,".\\MainInfo.ini");													               
	info.CustomStoreEnableJoB  = GetPrivateProfileInt              ("Custom","EnableStoreBlessButtom",0,".\\MainInfo.ini");													               
	info.CustomStoreEnableJoS  = GetPrivateProfileInt              ("Custom","EnableStoreSoulButtom",0,".\\MainInfo.ini");													               
	info.CustomStoreEnableJoC  = GetPrivateProfileInt              ("Custom","EnableStoreChaosButtom",0,".\\MainInfo.ini");													               
	info.CustomStoreEnableCoin1  = GetPrivateProfileInt            ("Custom","EnableStoreCoin1Buttom",0,".\\MainInfo.ini");													               
	info.CustomStoreEnableCoin2  = GetPrivateProfileInt            ("Custom","EnableStoreCoin2Buttom",0,".\\MainInfo.ini");														           
	info.CustomStoreEnableCoin3  = GetPrivateProfileInt            ("Custom","EnableStoreCoin3Buttom",0,".\\MainInfo.ini");														           
	info.CustomOffStoreEnable  = GetPrivateProfileInt              ("Custom","EnableOffStoreButtom",0,".\\MainInfo.ini");		
/*==================================================================================================================================*/
	info.CustomMonsterEnable  = GetPrivateProfileInt               ("Custom","CustomMonsterEnable",0,".\\MainInfo.ini");	
/*==================================================================================================================================*/
	info.DisablePartyHpBar  = GetPrivateProfileInt                 ("Custom","DisablePartyHpBar",0,".\\MainInfo.ini");	
/*==================================================================================================================================*/
	info.CustomInterfaceType  = GetPrivateProfileInt               ("Custom","CustomInterfaceType",0,".\\MainInfo.ini");
	info.CustomInterfaceHelperBar  = GetPrivateProfileInt          ("Custom","CustomInterfaceHelperBar",1,".\\MainInfo.ini");	
/*==================================================================================================================================*/
#if SELEC_CHAR_X700
	info.CustomSelectX700  = GetPrivateProfileInt                  ("Custom","CustomSelectX700",0,".\\MainInfo.ini");	
#endif
#if CHATATEC_ANIMATE
	info.SelectCharAnimate  = GetPrivateProfileInt                 ("Custom","SelectCharAnimate",0,".\\MainInfo.ini");		
#endif
/*==================================================================================================================================*/
	info.PingTest  = GetPrivateProfileInt                          ("Custom","PingTest",0,".\\MainInfo.ini");		
/*==================================================================================================================================*/
	info.CustomGlovesEnable  = GetPrivateProfileInt                ("Custom","CustomGlovesEnable",0,".\\MainInfo.ini");
/*==================================================================================================================================*/
#if REDUCE_MEMORY
	info.ReduceMemory = GetPrivateProfileInt                       ("Custom","ReduceMemory",0,".\\MainInfo.ini");
	info.ReduceMemoryUsage = GetPrivateProfileInt                  ("Custom","ReduceMemoryUsage",0, ".\\MainInfo.ini");
#endif

/*UPGRADE===========================================================================================================================*/
/*UPGRADE===========================================================================================================================*/
/*UPGRADE===========================================================================================================================*/
#if LIMITE_FPS
	info.LimitFPS  = GetPrivateProfileInt                          ("UPGRADE","LimitFPS",0,".\\MainInfo.ini");					
#endif
#if DISABLE_BOTON
	info.DisableBoton  = GetPrivateProfileInt                      ("UPGRADE","DisableBoton",0,".\\MainInfo.ini");		
#endif
/*==================================================================================================================================*/
	gCustomMessage.Load                                            ("Custom/CustomMessage.txt");					                  
	gCustomJewel.Load                                              ("Custom/CustomJewel.txt");					                  
	gCustomWing.Load                                               ("Custom/CustomWing.txt");					                  
	gCustomItem.Load                                               ("Custom/CustomItem.txt");					                  
	gCustomBuyVip.Load                                             ("Custom/CustomBuyVip.txt");
	gCustomCommandInfo.Load                                        ("Custom/CustomCommandInfo.txt");
	gCustomEventTimeText.Load                                      ("Custom/CustomEventTimeText.txt");
	gCustomItemDescription.Load                                    ("Custom/CustomItemDescription.txt");
	gCustomWingEffect.Load                                         ("Custom/CustomEffectStatic.txt");						              
	gDynamicWingEffect.Load                                        ("Custom/CustomEffectDynamic.txt");						              
	gSmokeEffect.Load                                              ("Custom/CustomSmokeEffect.txt");					              
	gFog.Load                                                      ("Custom/CustomFog.txt");						              
	gMonsters.Load                                                 ("Custom/CustomMonster.txt");						              
	gNPCName.Load                                                  ("Custom/CustomNPCName.txt");						              
	gCustomGloves.Load                                             ("Custom/CustomGloves.txt");

/*==================================================================================================================================*/

	memcpy(info.EngCustomMessageInfo,gCustomMessage.m_EngCustomMessageInfo,sizeof         (info.EngCustomMessageInfo));																				          
	memcpy(info.PorCustomMessageInfo,gCustomMessage.m_PorCustomMessageInfo,sizeof         (info.PorCustomMessageInfo));																				          
	memcpy(info.SpnCustomMessageInfo,gCustomMessage.m_SpnCustomMessageInfo,sizeof         (info.SpnCustomMessageInfo));
	memcpy(info.CustomJewelInfo,gCustomJewel.m_CustomJewelInfo,sizeof                     (info.CustomJewelInfo));
	memcpy(info.CustomWingInfo,gCustomWing.m_CustomWingInfo,sizeof                        (info.CustomWingInfo));																                          
	memcpy(info.CustomItemInfo,gCustomItem.m_CustomItemInfo,sizeof                        (info.CustomItemInfo));
	memcpy(info.CustomWingEffectInfo,gCustomWingEffect.m_CustomWingEffectInfo,sizeof      (info.CustomWingEffectInfo));																					      
	memcpy(info.DynamicWingEffectInfo,gDynamicWingEffect.m_DynamicWingEffectInfo,sizeof   (info.DynamicWingEffectInfo));
	memcpy(info.CustomBuyVipInfo,gCustomBuyVip.m_CustomBuyVipInfo,sizeof                  (info.CustomBuyVipInfo));																				          
	memcpy(info.CustomCommandInfo,gCustomCommandInfo.m_CustomCommandInfo,sizeof           (info.CustomCommandInfo));																				          
	memcpy(info.CustomEventInfo,gCustomEventTimeText.m_CustomEventInfo,sizeof             (info.CustomEventInfo));																				          
	memcpy(info.CustomDescriptionInfo,gCustomItemDescription.m_Info,sizeof                (info.CustomDescriptionInfo));																		                  
	memcpy(info.CustomSmokeEffect, gSmokeEffect.m_CustomSmokeEffect, sizeof               (info.CustomSmokeEffect));																		                  
	memcpy(info.CustomFog, gFog.m_CustomFog, sizeof                                       (info.CustomFog));															                              
	memcpy(info.CustomMonsters, gMonsters.m_Monsters, sizeof                              (info.CustomMonsters));															                              
	memcpy(info.CustomNPCName, gNPCName.m_CustomNpcName, sizeof                           (info.CustomNPCName));																		                  
	memcpy(info.CustomGloves, gCustomGloves.m_CustomGlovesInfo, sizeof                    (info.CustomGloves));

/*==================================================================================================================================*/

	CCRC32 CRC32;

	if(CRC32.FileCRC(info.ClientName,&info.ClientCRC32,1024) == 0)
	{
		info.ClientCRC32 = 0;
	}

	if(CRC32.FileCRC(info.PluginName1,&info.Plugin1CRC32,1024) == 0)
	{
		info.Plugin1CRC32 = 0;
	}

	if(CRC32.FileCRC(info.PluginName2,&info.Plugin2CRC32,1024) == 0)
	{
		info.Plugin2CRC32 = 0;
	}

	if(CRC32.FileCRC(info.PluginName3,&info.Plugin3CRC32,1024) == 0)
	{
		info.Plugin3CRC32 = 0;
	}

	if(CRC32.FileCRC(info.PluginName4,&info.Plugin4CRC32,1024) == 0)
	{
		info.Plugin4CRC32 = 0;
	}

	if(CRC32.FileCRC(info.PluginName5,&info.Plugin5CRC32,1024) == 0)
	{
		info.Plugin5CRC32 = 0;
	}

	if(CRC32.FileCRC(info.PluginName6,&info.Plugin6CRC32,1024) == 0)
	{
		info.Plugin6CRC32 = 0;
	}

	if(CRC32.FileCRC(info.PluginName7,&info.Plugin7CRC32,1024) == 0)
	{
		info.Plugin7CRC32 = 0;
	}

	if(CRC32.FileCRC(info.PluginName8,&info.Plugin8CRC32,1024) == 0)
	{
		info.Plugin8CRC32 = 0;
	}

	if(CRC32.FileCRC(info.PluginName9,&info.Plugin9CRC32,1024) == 0)
	{
		info.Plugin9CRC32 = 0;
	}

	if(CRC32.FileCRC(info.PluginName10,&info.Plugin10CRC32,1024) == 0)
	{
		info.Plugin10CRC32 = 0;
	}
	

	for(int n=0;n < sizeof(MAIN_FILE_INFO);n++)
	{
		((BYTE*)&info)[n] ^= (BYTE)(0xDA^LOBYTE(n));
		((BYTE*)&info)[n] -= (BYTE)(0x95^HIBYTE(n));
	}

/*==================================================================================================================================*/

#if(GAMESERVER_PREMIUM==1)
	HANDLE file = CreateFile("Client/EmuServer",GENERIC_WRITE,FILE_SHARE_READ,0,CREATE_ALWAYS,FILE_ATTRIBUTE_ARCHIVE,0);
#else
	HANDLE file = CreateFile("free/main.free",GENERIC_WRITE,FILE_SHARE_READ,0,CREATE_ALWAYS,FILE_ATTRIBUTE_ARCHIVE,0);
#endif

/*==================================================================================================================================*/

	if(file == INVALID_HANDLE_VALUE)
	{
		return 0;
	}

	DWORD OutSize = 0;

	if(WriteFile(file,&info,sizeof(MAIN_FILE_INFO),&OutSize,0) == 0)
	{
		CloseHandle(file);
		return 0;
	}

	CloseHandle(file);

	ENCODE_END

	CLEAR_END

	return 0;
}

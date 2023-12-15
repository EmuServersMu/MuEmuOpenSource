#include "stdafx.h"
#include "Common.h"
#include "CustomPing.h"
#include "CustomCommandInfo.h"
#include "CustomEventTime.h"
#include "CustomRanking.h"
#include "Interface.h"
#include "Import.h"
#include "Reconnect.h"
#include "TMemory.h"
#include "Defines.h"
#include "OffTrade.h"
#include "Protect.h"
#include "Protocol.h"
#include "PrintPlayer.h"
#include "User.h"
#include "Util.h"


Interface	gInterface;

static const char* StoreName = "Teste";

void Interface::Load()
{
	
	this->BindObject(eTIME, 0x787F, 131, 70, -10, 359);
	this->BindObject(eFlag01, 0x7880, 78, 78, -1, -1);
	this->BindObject(eFlag02, 0x7881, 78, 78, -1, -1);
	this->BindObject(eFlag03, 0x7882, 78, 78, -1, -1);
	this->BindObject(eFlag04, 0x7883, 78, 78, -1, -1);
	this->BindObject(eFlag05, 0x7884, 78, 78, -1, -1);
	this->BindObject(eFlag06, 0x7885, 78, 78, -1, -1);
	this->BindObject(eFlag07, 0x7886, 78, 78, -1, -1);
	this->BindObject(eFlag08, 0x7887, 78, 78, -1, -1);
	this->BindObject(eFlag09, 0x7888, 78, 78, -1, -1);
	this->BindObject(eFlag10, 0x7889, 78, 78, -1, -1);
	this->BindObject(eFlag11, 0x7890, 78, 78, -1, -1);
	this->BindObject(eFlag12, 0x7891, 78, 78, -1, -1);
	this->BindObject(eFlag13, 0x7892, 78, 78, -1, -1);
	this->BindObject(eFlag14, 0x7893, 78, 78, -1, -1);
	this->BindObject(eFlag15, 0x7894, 78, 78, -1, -1);
	this->BindObject(eFlag16, 0x7895, 78, 78, -1, -1);
	this->BindObject(eFlag17, 0x7896, 78, 78, -1, -1);
	this->BindObject(eFlag18, 0x7897, 78, 78, -1, -1);
	this->BindObject(eFlag19, 0x7898, 78, 78, -1, -1);
	this->BindObject(eFlag20, 0x7899, 78, 78, -1, -1);
	this->BindObject(eFlag21, 0x7900, 78, 78, -1, -1);
	this->BindObject(eFlag22, 0x7901, 78, 78, -1, -1);
	this->BindObject(eRanking, 0x7902, 179, 27, -1, -1);
	this->BindObject(eSAMPLEBUTTON, 0x7903, 25, 40, -1, -1);
	this->BindObject(eSAMPLEBUTTON2, 0x7904, 25, 40, -1, -1);

	//Premium system
	this->BindObject(eVip_MAIN, 0x7A5A, 222, 250, -1, -1);
	this->BindObject(eVip_TITLE, 0x7A63, 230, 67, -1, -1);
	this->BindObject(eVip_FRAME, 0x7A58, 230, 15, -1, -1);
	this->BindObject(eVip_FOOTER, 0x7A59, 230, 50, -1, -1);
	this->BindObject(eVip_DIV, 0x7A62, 223, 21, -1, -1);
	this->BindObject(eVip_CLOSE, 0x7EC5, 36, 29, -1, -1);
	this->BindObject(eVip_BRONZE, 0x7A5E, 108, 29, -1, -1);
	this->BindObject(eVip_SILVER, 0x7A5E, 108, 29, -1, -1);
	this->BindObject(eVip_GOLD, 0x7A5E, 108, 29, -1, -1);
	this->BindObject(eVip_PLATINUM, 0x7A5E, 108, 29, -1, -1);
	this->BindObject(eVip_STATUS, 0x7A5E, 108, 29, -1, -1);

	//Menu
	this->BindObject(eMenu_MAIN, 0x7A5A, 222, 240, -1, -1);
	this->BindObject(eMenu_TITLE, 0x7A63, 230, 67, -1, -1);
	this->BindObject(eMenu_FRAME, 0x7A58, 230, 15, -1, -1);
	this->BindObject(eMenu_FOOTER, 0x7A59, 230, 50, -1, -1);
	this->BindObject(eMenu_DIV, 0x7A62, 223, 21, -1, -1);
	this->BindObject(eMenu_CLOSE, 0x7EC5, 36, 29, -1, -1);
	this->BindObject(eMenu_OPT1, 0x7A5E, 108, 29, -1, -1);
	this->BindObject(eMenu_OPT2, 0x7A5E, 108, 29, -1, -1);
	this->BindObject(eMenu_OPT3, 0x7A5E, 108, 29, -1, -1);
	this->BindObject(eMenu_OPT4, 0x7A5E, 108, 29, -1, -1);
	this->BindObject(eMenu_OPT20, 0x7A5E, 108, 29, -1, -1);

	//Command info
	this->BindObject(eCommand_MAIN, 0x7A5A, 222, 300, -1, -1);
	this->BindObject(eCommand_TITLE, 0x7A63, 230, 67, -1, -1);
	this->BindObject(eCommand_FRAME, 0x7A58, 230, 15, -1, -1);
	this->BindObject(eCommand_FOOTER, 0x7A59, 230, 50, -1, -1);
	this->BindObject(eCommand_DIV, 0x7A62, 223, 21, -1, -1);
	this->BindObject(eCommand_CLOSE, 0x7EC5, 36, 29, -1, -1);

	this->BindObject(eRanking_MAIN, 0x7A5A, 222, 195, -1, -1);
	this->BindObject(eRanking_CLOSE, 0x7EC5, 36, 29, -1, -1);

	this->BindObject(eEventTime_MAIN, 0x7A5A, 222, 225, -1, -1);
	this->BindObject(eEventTime_CLOSE, 0x7EC5, 36, 29, -1, -1);

	this->BindObject(eCONFIRM_MAIN, 0x7A5A, 222, 120, -1, -1);
	this->BindObject(eCONFIRM_TITLE, 0x7A63, 230, 67, -1, -1);
	this->BindObject(eCONFIRM_FRAME, 0x7A58, 230, 15, -1, -1);
	this->BindObject(eCONFIRM_FOOTER, 0x7A59, 230, 50, -1, -1);
	this->BindObject(eCONFIRM_DIV, 0x7A62, 223, 21, -1, -1);
	this->BindObject(eCONFIRM_BTN_OK, 0x7A5B, 54, 30, -1, -1);
	this->BindObject(eCONFIRM_BTN_CANCEL, 0x7A5C, 54, 30, -1, -1);

	this->BindObject(eLogo, 0x7905, 150, 114, -1, -1);

	if (gProtect.m_MainInfo.CustomMenuType == 1)
	{
		this->BindObject(eMenu, 0x7906, 102, 29, -1, -1);
	}
	else
	{
		this->BindObject(eMenu, 0x7906, 16, 12, -1, -1);
		this->BindObject(eMenuBG, 0x7907, 36, 18, 174, 0);
	}

	//Custom Store
	this->BindObject(eOFFTRADE_JoB, 0x7908, 40, 19, -1, -1);
	this->BindObject(eOFFTRADE_JoS, 0x7908, 40, 19, -1, -1);
	this->BindObject(eOFFTRADE_JoC, 0x7908, 40, 19, -1, -1);
	this->BindObject(eOFFTRADE_WCC, 0x7908, 40, 19, -1, -1);
	this->BindObject(eOFFTRADE_WCP, 0x7908, 40, 19, -1, -1);
	this->BindObject(eOFFTRADE_WCG, 0x7908, 40, 19, -1, -1);
	this->BindObject(eOFFTRADE_OPEN, 0x7BFD, 108, 30, -1, -1);

	//Minimap
	this->BindObject(ePLAYER_POINT, 31460, 3, 3, -1, -1);
	this->BindObject(eNULL_MAP, 31461, 128, 128, -1, -1);
	this->BindObject(eLORENCIA_MAP, 31462, 128, 128, -1, -1);
	this->BindObject(eDUNGEON_MAP, 31463, 128, 128, -1, -1);
	this->BindObject(eDEVIAS_MAP, 31464, 128, 128, -1, -1);
	this->BindObject(eNORIA_MAP, 31465, 128, 128, -1, -1);
	this->BindObject(eLOSTTOWER_MAP, 31466, 128, 128, -1, -1);
	this->BindObject(eATLANS_MAP, 31467, 128, 128, -1, -1);
	this->BindObject(eTarkan_MAP, 31468, 128, 128, -1, -1);
	this->BindObject(eElbeland_MAP, 31469, 128, 128, -1, -1);
	this->BindObject(eICARUS_MAP, 31470, 128, 128, -1, -1);
	this->BindObject(eLANDOFTRIALS_MAP, 31461, 128, 128, -1, -1);
	this->BindObject(eAIDA_MAP, 31472, 128, 128, -1, -1);
	this->BindObject(eCRYWOLF_MAP, 31473, 128, 128, -1, -1);
	this->BindObject(eKANTRU_MAP, 31474, 128, 128, -1, -1);
	this->BindObject(eKANTRU3_MAP, 31475, 128, 128, -1, -1);
	this->BindObject(eBARRACKS_MAP, 31476, 128, 128, -1, -1);
	this->BindObject(eCALMNESS_MAP, 31477, 128, 128, -1, -1);
	this->BindObject(eRAKLION_MAP, 31478, 128, 128, -1, -1);
	this->BindObject(eVULCANUS_MAP, 31479, 128, 128, -1, -1);
	this->BindObject(eKALRUTAN_MAP, 31480, 128, 128, -1, -1);
	this->BindObject(eKALRUTAN2_MAP, 31481, 128, 128, -1, -1);

	this->BindObject(eNextCommand, 0x7903, 25, 40, -1, -1);
	this->BindObject(ePrevCommand, 0x7904, 25, 40, -1, -1);

	this->BindObject(eNextEvent, 0x7903, 25, 40, -1, -1);
	this->BindObject(ePrevEvent, 0x7904, 25, 40, -1, -1);

	this->Data[eTIME].OnShow = false;

	teste=0;

	SetOp((LPVOID)oLoadSomeForm_Call, this->LoadImages, ASM::CALL);

	if (gProtect.m_MainInfo.CustomInterfaceType == 0)
	{
		SetOp((LPVOID)oDrawInterface_Call, this->Work, ASM::CALL);
	}

	SetCompleteHook(0xFF, 0x00633FFB, &this->LoadModels);

	//==========================================
	// - Remove Texts PShop
	//==========================================
	SetRange((LPVOID)0x00842086, 5, ASM::NOP);
	SetRange((LPVOID)0x0084234F, 5, ASM::NOP);
	SetRange((LPVOID)0x008423C3, 5, ASM::NOP);

	//SetDword(0x0D47384,(DWORD)40);z
}

void Interface::LoadModels()
{
	pLoadModel(406, "Data\\Custom\\Bmd\\VIP1\\", "musign", -1);
	pLoadTexture(406, "Custom\\Bmd\\VIP1\\", 0x2901, 0x2600, 1);
	pLoadModel(407, "Data\\Custom\\Bmd\\VIP2\\", "musign", -1);
	pLoadTexture(407, "Custom\\Bmd\\VIP2\\", 0x2901, 0x2600, 1);
	pLoadModel(408, "Data\\Custom\\Bmd\\VIP3\\", "musign", -1);
	pLoadTexture(408, "Custom\\Bmd\\VIP3\\", 0x2901, 0x2600, 1);
	// ----
	pInitModelData2();
}

void Interface::LoadImages()
{

	pLoadImage("Custom\\Interface\\TimeBar.tga", 0x787F, 0x2601, 0x2901, 1, 0);

	pLoadImage("Custom\\Interface\\Rank01.tga", 0x7880, 0x2601, 0x2901, 1, 0);
	pLoadImage("Custom\\Interface\\Rank02.tga", 0x7881, 0x2601, 0x2901, 1, 0);
	pLoadImage("Custom\\Interface\\Rank03.tga", 0x7882, 0x2601, 0x2901, 1, 0);
	pLoadImage("Custom\\Interface\\Rank04.tga", 0x7883, 0x2601, 0x2901, 1, 0);
	pLoadImage("Custom\\Interface\\Rank05.tga", 0x7884, 0x2601, 0x2901, 1, 0);
	pLoadImage("Custom\\Interface\\Rank06.tga", 0x7885, 0x2601, 0x2901, 1, 0);
	pLoadImage("Custom\\Interface\\Rank07.tga", 0x7886, 0x2601, 0x2901, 1, 0);
	pLoadImage("Custom\\Interface\\Rank08.tga", 0x7887, 0x2601, 0x2901, 1, 0);
	pLoadImage("Custom\\Interface\\Rank09.tga", 0x7888, 0x2601, 0x2901, 1, 0);
	pLoadImage("Custom\\Interface\\Rank10.tga", 0x7889, 0x2601, 0x2901, 1, 0);
	pLoadImage("Custom\\Interface\\Rank11.tga", 0x7890, 0x2601, 0x2901, 1, 0);
	pLoadImage("Custom\\Interface\\Rank12.tga", 0x7891, 0x2601, 0x2901, 1, 0);
	pLoadImage("Custom\\Interface\\Rank13.tga", 0x7892, 0x2601, 0x2901, 1, 0);
	pLoadImage("Custom\\Interface\\Rank14.tga", 0x7893, 0x2601, 0x2901, 1, 0);
	pLoadImage("Custom\\Interface\\Rank15.tga", 0x7894, 0x2601, 0x2901, 1, 0);
	pLoadImage("Custom\\Interface\\Rank16.tga", 0x7895, 0x2601, 0x2901, 1, 0);
	pLoadImage("Custom\\Interface\\Rank17.tga", 0x7896, 0x2601, 0x2901, 1, 0);
	pLoadImage("Custom\\Interface\\Rank18.tga", 0x7897, 0x2601, 0x2901, 1, 0);
	pLoadImage("Custom\\Interface\\Rank19.tga", 0x7898, 0x2601, 0x2901, 1, 0);
	pLoadImage("Custom\\Interface\\Rank20.tga", 0x7899, 0x2601, 0x2901, 1, 0);
	pLoadImage("Custom\\Interface\\Rank21.tga", 0x7900, 0x2601, 0x2901, 1, 0);
	pLoadImage("Custom\\Interface\\Rank22.tga", 0x7901, 0x2601, 0x2901, 1, 0);
	pLoadImage("Custom\\Interface\\Ranking.tga", 0x7902, 0x2601, 0x2901, 1, 0);
	pLoadImage("Custom\\Interface\\Next.tga", 0x7903, 0x2601, 0x2901, 1, 0);
	pLoadImage("Custom\\Interface\\Previous.tga", 0x7904, 0x2601, 0x2901, 1, 0);
	pLoadImage("Custom\\Interface\\MU-logo.tga", 0x7905, 0x2601, 0x2901, 1, 0);

	if (gProtect.m_MainInfo.CustomMenuType == 1)
	{
		pLoadImage("Custom\\Interface\\Menu1.tga", 0x7906, 0x2601, 0x2901, 1, 0);
	}
	else
	{
		pLoadImage("Custom\\Interface\\Menu2.tga", 0x7906, 0x2601, 0x2901, 1, 0);
		pLoadImage("Custom\\Interface\\Menu_BG.tga", 0x7907, 0x2601, 0x2901, 1, 0);
	}

	pLoadImage("Custom\\Interface\\Button.tga", 0x7908, 0x2601, 0x2900,1,0);

	//MiniMap
	pLoadImage("Custom\\Maps\\PlayerPoint.jpg", 31460, 0x2600, 0x2900, 1, 0);
	pLoadImage("Custom\\Maps\\null.tga", 31461, 0x2601, 0x2900, 1, 0);
	pLoadImage("Custom\\Maps\\Lorencia.tga", 31462, 0x2601, 0x2900, 1, 0);
	pLoadImage("Custom\\Maps\\Dungeon.tga", 31463, 0x2601, 0x2900, 1, 0);
	pLoadImage("Custom\\Maps\\Devias.tga", 31464, 0x2601, 0x2900, 1, 0);
	pLoadImage("Custom\\Maps\\Noria.tga", 31465, 0x2601, 0x2900, 1, 0);
	pLoadImage("Custom\\Maps\\Losttower.tga", 31466, 0x2601, 0x2900, 1, 0);
	pLoadImage("Custom\\Maps\\Atlans.tga", 31467, 0x2601, 0x2900, 1, 0);
	pLoadImage("Custom\\Maps\\Tarkan.tga", 31468, 0x2601, 0x2900, 1, 0);
	pLoadImage("Custom\\Maps\\Elbeland.tga", 31469, 0x2601, 0x2900, 1, 0);
	pLoadImage("Custom\\Maps\\Icarus.tga", 31470, 0x2601, 0x2900, 1, 0);
	pLoadImage("Custom\\Maps\\LandOfTrials.tga", 31471, 0x2601, 0x2900, 1, 0);
	pLoadImage("Custom\\Maps\\Aida.tga", 31472, 0x2601, 0x2900, 1, 0);
	pLoadImage("Custom\\Maps\\Crywolf.tga", 31473, 0x2601, 0x2900, 1, 0);
	pLoadImage("Custom\\Maps\\Kantru.tga", 31474, 0x2601, 0x2900, 1, 0);
	pLoadImage("Custom\\Maps\\Kantru3.tga", 31475, 0x2601, 0x2900, 1, 0);
	pLoadImage("Custom\\Maps\\Barracks.tga", 31476, 0x2601, 0x2900, 1, 0);
	pLoadImage("Custom\\Maps\\Calmness.tga", 31477, 0x2601, 0x2900, 1, 0);
	pLoadImage("Custom\\Maps\\Raklion.tga", 31478, 0x2601, 0x2900, 1, 0);
	pLoadImage("Custom\\Maps\\Vulcanus.tga", 31479, 0x2601, 0x2900, 1, 0);
	pLoadImage("Custom\\Maps\\Kalrutan.tga", 31480, 0x2601, 0x2900, 1, 0);
	pLoadImage("Custom\\Maps\\Kalrutan2.tga", 31481, 0x2601, 0x2900, 1, 0);

	if (gProtect.m_MainInfo.CustomInterfaceType > 0 && gProtect.m_MainInfo.CustomInterfaceType < 4)
	{
		if (gProtect.m_MainInfo.CustomInterfaceType == 1)
		{
			pLoadImage("Custom\\Interface\\MenuS1_left.jpg", 31377, 0x2601, 0x2901, 1, 0);
			pLoadImage("Custom\\Interface\\MenuS1_right.jpg", 31379, 0x2601, 0x2901, 1, 0);
		}
		if (gProtect.m_MainInfo.CustomInterfaceType == 2)
		{
			pLoadImage("Custom\\Interface\\MenuS2_left.jpg", 31377, 0x2601, 0x2901, 1, 0);
			pLoadImage("Custom\\Interface\\MenuS2_right.jpg", 31379, 0x2601, 0x2901, 1, 0);
		}
		if (gProtect.m_MainInfo.CustomInterfaceType == 3)
		{
			pLoadImage("Custom\\Interface\\MenuS2_left.jpg", 31377, 0x2601, 0x2901, 1, 0);
			pLoadImage("Custom\\Interface\\MenuS3_right.jpg", 31379, 0x2601, 0x2901, 1, 0);
			pLoadImage("Custom\\Interface\\MenuS3_cashshop.jpg", 31394, 0x2601, 0x2901, 1, 0);
		}

		pLoadImage("Custom\\Interface\\MenuS2_middle.jpg", 31378, 0x2601, 0x2901, 1, 0);
		pLoadImage("Custom\\Interface\\MenuS2_Blue.jpg", 31380, 0x2601, 0x2900, 1, 0);
		pLoadImage("Custom\\Interface\\MenuS2_Character.jpg", 31381, 0x2601, 0x2901, 1, 0);
		pLoadImage("Custom\\Interface\\MenuS2_Green.jpg", 31382, 0x2601, 0x2900, 1, 0);
		pLoadImage("Custom\\Interface\\MenuS2_Inventory.jpg", 31383, 0x2601, 0x2901, 1, 0);
		pLoadImage("Custom\\Interface\\MenuS2_Party.jpg", 31384, 0x2601, 0x2901, 1, 0);
		pLoadImage("Custom\\Interface\\MenuS2_Red.jpg", 31385, 0x2601, 0x2900, 1, 0);
		pLoadImage("Custom\\Interface\\MenuS2_AG.jpg", 31386, 0x2601, 0x2901, 1, 0);
		pLoadImage("Custom\\Interface\\MenuS2_dragon.tga", 31387, 0x2601, 0x2901, 1, 0);
		pLoadImage("Custom\\Interface\\MenuS2_SD.jpg", 31388, 0x2601, 0x2901, 1, 0);
		pLoadImage("Custom\\Interface\\MenuS2_guild.jpg", 31389, 0x2601, 0x2901, 1, 0);
		pLoadImage("Custom\\Interface\\MenuS2_fastmenu.jpg", 31390, 0x2601, 0x2901, 1, 0);
		pLoadImage("Custom\\Interface\\MenuS2_friend.jpg", 31391, 0x2601, 0x2901, 1, 0);
	}

	if (gProtect.m_MainInfo.CustomInterfaceType == 4)
	{
		pLoadImage("Custom\\Interface\\MenuS8_main.tga", 31409, 0x2601, 0x2901, 1, 0);
		pLoadImage("Custom\\Interface\\MenuS8_black.tga", 31410, 0x2601, 0x2901, 1, 0);
		pLoadImage("Custom\\Interface\\MenuS8_blue.tga", 31411, 0x2601, 0x2901, 1, 0);
		pLoadImage("Custom\\Interface\\MenuS8_red.tga", 31412, 0x2601, 0x2901, 1, 0);
		pLoadImage("Custom\\Interface\\MenuS8_green.tga", 31418, 0x2601, 0x2901, 1, 0);
		pLoadImage("Custom\\Interface\\MenuS8_shop.tga", 31420, 0x2601, 0x2901, 1, 0);
		pLoadImage("Custom\\Interface\\MenuS8_character.tga", 31423, 0x2601, 0x2901, 1, 0);
		pLoadImage("Custom\\Interface\\MenuS8_inventory.tga", 31425, 0x2601, 0x2901, 1, 0);
		pLoadImage("Custom\\Interface\\MenuS8_quest.tga", 31426, 0x2601, 0x2901, 1, 0);
		pLoadImage("Custom\\Interface\\MenuS8_friend.tga", 31427, 0x2601, 0x2901, 1, 0);
		pLoadImage("Custom\\Interface\\MenuS8_btmenu.tga", 31428, 0x2601, 0x2901, 1, 0);
	}

#if SELEC_CHAR_X700
   pLoadImage("Logo\\MU-logo.tga", 531018, GL_LINEAR, GL_REPEAT, 1, 0);
   pLoadImage("Logo\\MU-logo_g.jpg", 531019, GL_LINEAR, GL_REPEAT, 1, 0);
   pLoadImage("Effect\\magic_ground1_3.jpg", 32779, GL_LINEAR, GL_REPEAT, 1, 0);
#endif

	// ----
	pLoadSomeForm();
}

void Interface::BindObject(short MonsterID, DWORD ModelID, float Width, float Height, float X, float Y)
{
	this->Data[MonsterID].EventTick	= 0;
	this->Data[MonsterID].OnClick	= false;
	this->Data[MonsterID].OnShow	= false;
	this->Data[MonsterID].ModelID	= ModelID;
	this->Data[MonsterID].Width		= Width;
	this->Data[MonsterID].Height	= Height;
	this->Data[MonsterID].X			= X;
	this->Data[MonsterID].Y			= Y;
	this->Data[MonsterID].MaxX		= X + Width;
	this->Data[MonsterID].MaxY		= Y + Height;
	this->Data[MonsterID].Attribute	= 0;
}

void Interface::DrawGUI(short ObjectID, float PosX, float PosY)
{
	if( this->Data[ObjectID].X == -1 || this->Data[ObjectID].Y == -1 )
	{
		this->Data[ObjectID].X		= PosX;
		this->Data[ObjectID].Y		= PosY;
		this->Data[ObjectID].MaxX	= PosX + this->Data[ObjectID].Width;
		this->Data[ObjectID].MaxY	= PosY + this->Data[ObjectID].Height;
	}

	pDrawGUI(this->Data[ObjectID].ModelID, PosX, PosY,this->Data[ObjectID].Width, this->Data[ObjectID].Height);
}

void Interface::DrawIMG(short ObjectID, float PosX, float PosY, float ScaleX, float ScaleY)
{
	if( this->Data[ObjectID].X == -1 || this->Data[ObjectID].Y == -1 )
	{
		this->Data[ObjectID].X		= PosX;
		this->Data[ObjectID].Y		= PosY;
		this->Data[ObjectID].MaxX	= PosX + this->Data[ObjectID].Width;
		this->Data[ObjectID].MaxY	= PosY + this->Data[ObjectID].Height;
	}

	pDrawImage(this->Data[ObjectID].ModelID, PosX, PosY,this->Data[ObjectID].Width, this->Data[ObjectID].Height,0,0,ScaleX,ScaleY,1,1,0);
}

void Interface::ResetDrawIMG(short ObjectID)
{
	if( this->Data[ObjectID].X != -1 || this->Data[ObjectID].Y != -1 )
	{
		this->Data[ObjectID].X		= -1;
		this->Data[ObjectID].Y		= -1;
		this->Data[ObjectID].MaxX	= -1;
		this->Data[ObjectID].MaxY	= -1;
	}
}

static int MapTabCount = 0;

DWORD TickTab = GetTickCount();


void Interface::Work()
{

	 if(pPlayerState == 5)       // -> Si el PJ esta adentro del Juego
	 {
		gCustomPing.StartPing();
	 }

	gObjUser.Refresh();
	gCustomRanking.DrawRankPanelWindow();
	gCustomEventTime.DrawEventTimePanelWindow();
	gInterface.DrawTimeUI();
	ReconnectMainProc();
	gInterface.DrawVipWindow();
	gInterface.DrawMenu();
	gInterface.DrawMenuOpen();
	gCustomCommandInfo.DrawCommandWindow();
	gOffTrade.DrawOffTradeWindow();
	gInterface.DrawConfirmOpen();
	gInterface.DrawMiniMap();
	gCustomPing.ShowPing();
	
	if( GetForegroundWindow() == pGameWindow )
	{

		if (GetKeyState(VK_SNAPSHOT) < 0) 
		{
			gInterface.DrawLogo(1); 
		}
		if (GetKeyState(VK_END) & 0x4000) 
		{
			if((GetTickCount()-gInterface.Data[eVip_MAIN].EventTick) > 300)
			{
				if (gInterface.CheckVipWindow())
				{
					gInterface.Data[eVip_MAIN].EventTick = GetTickCount();
					gInterface.CloseVipWindow();
				}
				else
				{
					gInterface.Data[eVip_MAIN].EventTick = GetTickCount();
					gInterface.CloseCustomWindow();
					gInterface.OpenVipWindow();
				}
			}
		}
		if (GetKeyState('H') & 0x4000) 
		{
			gCustomEventTime.OpenWindow();
		}
		if (GetKeyState(VK_F8) & 0x4000) 
		{
			gCustomRanking.OpenWindow();
		}

		int MapTab		= 0;

		if (GetKeyState(VK_TAB) & 0x8000) 
		{
			if ((GetTickCount() - TickTab) > 100)
			{
				MapTab = 1;
				TickTab = GetTickCount();
			}
		}

		if(!MiniMapActive && MapTabCount > 2)
		{
			MiniMapActive = 1;
			MapTabCount = 0;
			MapTab = 0;
		}
		else if(MapTab && MiniMapActive && MapTabCount < 2)
		{
			MiniMapActive = 0;
			MapTab = 0;
		}
		else if(MapTab)
		{
			MapTabCount++;
		}

		//if (gInterface.CheckWindow(ObjWindow::FullMap))
		//{

		//	else if (MapTab)
		//	{
		//		
		//	}
		//	MapTab = 0;
		//}

		if (GetKeyState(VK_ESCAPE) < 0) 
		{
			if (gInterface.Data[eCommand_MAIN].OnShow == true)
			{
				gInterface.Data[eCommand_MAIN].OnShow = false;
				pSetCursorFocus = false;
			}

			if (gInterface.Data[eRankPANEL_MAIN].OnShow == true)
			{
				gInterface.Data[eRankPANEL_MAIN].OnShow = false;
				pSetCursorFocus = false;
			}

			if (gInterface.Data[eEventTimePANEL_MAIN].OnShow == true)
			{
				gInterface.Data[eEventTimePANEL_MAIN].OnShow = false;
				pSetCursorFocus = false;
			}

			if (gInterface.CheckVipWindow())
			{
				gInterface.CloseVipWindow();
			}

			if (gInterface.CheckMenuWindow())
			{
				gInterface.CloseMenuWindow();
			}
		}
	}

	gInterface.DrawLogo(0);

	if (gProtect.m_MainInfo.CustomInterfaceType == 0)
	{
		pDrawInterface();
	}
}


void Interface::DrawTimeUI()
{

	//if (gProtect.m_MainInfo.DisableTree == 1 && this->CheckWindow(ObjWindow::SkillTree))
	//{
	//	this->CloseWindow(ObjWindow::SkillTree);
	//}

	if( !this->Data[eTIME].OnShow )
	{
		return;
	}
	// ----
	/*if( this->CheckWindow(ObjWindow::ChatWindow) || this->CheckWindow(ObjWindow::CashShop)
	|| this->CheckWindow(ObjWindow::FullMap) || this->CheckWindow(ObjWindow::SkillTree)
	|| this->CheckWindow(ObjWindow::MoveList) || gObjUser.m_MapNumber == 34 || gObjUser.m_MapNumber == 30 )*/
	if(this->CheckWindow(ObjWindow::CashShop)|| this->CheckWindow(ObjWindow::FullMap) || this->CheckWindow(ObjWindow::ChatWindow) || this->CheckWindow(ObjWindow::SkillTree)
		|| this->CheckWindow(ObjWindow::MoveList) || pMapNumber == 34 || pMapNumber == 30 )
	{
		return;
	}
	// ----
	//this->DrawGUI(eTIME, 0, -3);
	this->DrawGUI(eTIME, this->Data[eTIME].X, this->Data[eTIME].Y);
	this->DrawGUI(eTIME, this->Data[eTIME].X, this->Data[eTIME].Y+22);
	// -----
	time_t TimeServer, TimeLocal;
	struct tm * ServerT, * LocalT;
	time(&TimeServer);
	time(&TimeLocal);
	// ----
	ServerT = gmtime(&TimeServer);
	// ----
	char ServerTimeName[25] = "Server:";
	char ServerTime[30];

	sprintf(ServerTime, "%2d:%02d:%02d", (ServerT->tm_hour)%24, ServerT->tm_min, ServerT->tm_sec);
	// -----
	LocalT = localtime(&TimeLocal); 
	// -----
	char LocalTimeName[25] = "Local:";
	char LocalTime[30];
	sprintf(LocalTime, "%2d:%02d:%02d", LocalT->tm_hour, LocalT->tm_min, LocalT->tm_sec);
	// -----
	this->DrawFormat(eGold, 5, 391, 50, 1, ServerTimeName);
	this->DrawFormat(eWhite, 55, 391, 100, 1, ServerTime);
	// ----
	this->DrawFormat(eGold, 5, 413, 50, 1, LocalTimeName);
	this->DrawFormat(eWhite, 55, 413, 100, 1, LocalTime);
}

int Interface::DrawFormat(DWORD Color, int PosX, int PosY, int Width, int Align, LPCSTR Text, ...)
{
	char Buff[2048];
	int BuffLen	= sizeof(Buff)-1;
	ZeroMemory(Buff, BuffLen);
	
	va_list args;
	va_start(args, Text);
	int Len	= vsprintf_s(Buff, BuffLen, Text, args);
	va_end(args);
	
	int LineCount = 0;
	
	char * Line = strtok(Buff, "\n");
	
	while( Line != NULL )
	{
		pDrawColorText(Line, PosX, PosY, Width, 0, Color, 0, Align);
		PosY += 10;
		Line = strtok(NULL, "\n");
	}
	
	return PosY;
}

bool Interface::CheckWindow(int WindowID)
{
	return pCheckWindow(pWindowThis(), WindowID);
}
int Interface::CloseWindow(int WindowID)
{
	return pCloseWindow(pWindowThis(), WindowID);
}
int Interface::OpenWindow(int WindowID)
{
	return pOpenWindow(pWindowThis(), WindowID);
}

bool Interface::IsWorkZone(short ObjectID)
{
	if( (gObjUser.m_CursorX < this->Data[ObjectID].X || gObjUser.m_CursorX > this->Data[ObjectID].MaxX) || (gObjUser.m_CursorY < this->Data[ObjectID].Y || gObjUser.m_CursorY > this->Data[ObjectID].MaxY) )
		return false;

	return true;
}

float Interface::GetResizeX(short ObjectID)
{
	if( pWinWidth == 800 )
	{
		return this->Data[ObjectID].X + 16.0;
	}
	else if( pWinWidth != 1024 )
	{
		return this->Data[ObjectID].X - 16.0;
	}
	
	return this->Data[ObjectID].X;
}

int Interface::DrawToolTip(int X, int Y, LPCSTR Text, ...)
{
	char Buff[2048];
	int BuffLen	= sizeof(Buff);
	ZeroMemory(Buff, BuffLen);
	
	va_list args;
	va_start(args, Text);
	int Len	= vsprintf_s(Buff, BuffLen, Text, args);
	va_end(args);
	
	return pDrawToolTip(X, Y, Buff);
}

int Interface::DrawMessage(int Mode, LPCSTR Text, ...)
{
	char Buff[2048];
	int BuffLen	= sizeof(Buff);
	ZeroMemory(Buff, BuffLen);
	// ----
	va_list args;
	va_start(args, Text);
	int Len	= vsprintf_s(Buff, BuffLen, Text, args);
	va_end(args);
	// ----
	return pDrawMessage(Buff, Mode);
}


void Interface::DrawVipWindow()
{

	if( !this->Data[eVip_MAIN].OnShow )
	{
		return;
	}

	if( gProtect.m_MainInfo.EnableVipShop != 1 )
	{
		this->CloseVipWindow();
		return;
	}

	if (this->CheckWindow(ObjWindow::MoveList) || this->CheckWindow(ObjWindow::CashShop) || this->CheckWindow(ObjWindow::SkillTree) || this->CheckWindow(ObjWindow::FullMap)
		||  (this->CheckWindow(Inventory) 
		&& this->CheckWindow(ExpandInventory) 
		&& this->CheckWindow(Store)) 
		||  (this->CheckWindow(Inventory) 
		&& this->CheckWindow(Warehouse) 
		&& this->CheckWindow(ExpandWarehouse)) )
	{
		CloseVipWindow();
		return;
	}

	// ----
	float MainWidth			= 230.0;
	float MainHeight		= 180.0;
	float StartBody			= 40.0;
	float StartY			= 40.0;
	float StartX			= (MAX_WIN_WIDTH / 2) - (MainWidth / 2);
	float MainCenter		= StartX + (MainWidth / 3);
	float ButtonX			= MainCenter - (float)(29.0 / 2);
	// ----
	this->DrawGUI(eVip_MAIN, StartX, StartY + (float)2.0);
	this->DrawGUI(eVip_TITLE, StartX, StartY);
	StartY = this->DrawRepeatGUI(eVip_FRAME, StartX, StartY + (float)15.0, 13);
	this->DrawGUI(eVip_FOOTER, StartX, StartY);
	this->DrawGUI(eVip_CLOSE, StartX + MainWidth - this->Data[eVip_CLOSE].Width, StartBody);
	// ----
	if (this->IsWorkZone(eVip_CLOSE))
	{
		DWORD Color = eGray100;
		// ----
		if (this->Data[eVip_CLOSE].OnClick)
		{
			Color = eGray150;
		}
		// ----
		this->DrawColoredGUI(eVip_CLOSE, this->Data[eVip_CLOSE].X, StartBody, Color);
		this->DrawToolTip((int)this->Data[eVip_CLOSE].X + 5, StartBody + 25, "Close");
	}
	// ----
	this->DrawFormat(eGold, (int)StartX + 10, (int)StartBody + 10, 210, 3, gCustomMessage.GetMessage(5));
	int LineY = this->DrawFormat(eWhite, (int)StartX + 30, (int)StartBody + 35, 210, 1, gCustomMessage.GetMessage(6), gObjUser.lpPlayer->Name);
	LineY = this->DrawFormat(eGold, (int)StartX + 30, (int)LineY, 210, 1, gCustomMessage.GetMessage(14));
	LineY = this->DrawFormat(eWhite, (int)StartX + 30, (int)LineY, 210, 1, gCustomMessage.GetMessage(7));
	LineY = this->DrawFormat(eWhite, (int)StartX + 30, (int)LineY, 210, 1, gCustomMessage.GetMessage(8));
	// ----
	this->DrawGUI(eVip_DIV, StartX, StartBody + 70);
	this->DrawFormat(eGold, (int)StartX + 30, (int)StartBody + 95 - 2, 210, 1, "Plan");
	this->DrawFormat(eGold, (int)StartX + 80, (int)StartBody + 95 - 2 , 210, 1, "Exp");
	this->DrawFormat(eGold, (int)StartX + 130, (int)StartBody + 95 - 2, 210, 1, "Drop");
	this->DrawFormat(eGold, (int)StartX + 170, (int)StartBody + 95 - 2, 210, 1, "Time");
	// ----

	if (gProtect.m_MainInfo.VipTypes < 1 || gProtect.m_MainInfo.VipTypes > 3)
	{
		gProtect.m_MainInfo.VipTypes = 3;
	}

	for( int i = 0; i < gProtect.m_MainInfo.VipTypes; i++ )
	{
		this->DrawFormat(eWhite, (int)StartX + 30, (int)StartBody + 110 + (12 * i) - 5, 210, 1, gCustomBuyVip.m_CustomBuyVipInfo[i].VipName);
		// ----
		this->DrawFormat(eWhite, (int)StartX + 80, (int)StartBody + 110 + (12 * i) - 5, 210, 1, "+%d%%", gCustomBuyVip.m_CustomBuyVipInfo[i].Exp);
		// ----
		this->DrawFormat(eWhite, (int)StartX + 130, (int)StartBody + 110 + (12 * i) - 5, 210, 1, "+%d%%", gCustomBuyVip.m_CustomBuyVipInfo[i].Drop);
		// ----
		this->DrawFormat(eWhite, (int)StartX + 170, (int)StartBody + 110 + (12 * i) - 5, 210, 1, "%d day(s)", gCustomBuyVip.m_CustomBuyVipInfo[i].Days);

		pDrawGUI(0x7B5E, StartX + 30, StartBody + 110 + (12 * i) + 9 - 5, 82.0, 2.0);
		pDrawGUI(0x7B5E, StartX + 30 + 82, StartBody + 110 + (12 * i) + 9 - 5, 82.0, 2.0);
	}

	if (gProtect.m_MainInfo.VipTypes > 0)
	{
	// ---- bronze start 
	if (IsWorkZone(eVip_BRONZE))
	{
		if (this->Data[eVip_BRONZE].OnClick)
			this->DrawButton(eVip_BRONZE, StartX + 64, 195, 0, 58);
		else
			this->DrawButton(eVip_BRONZE, StartX + 64, 195, 0, 29);
		// ----
		this->DrawFormat(eGold, (int)StartX + 30, (int)StartBody + 142, 210, 1, gCustomMessage.GetMessage(10));
		this->DrawFormat(eGold, (int)StartX + 70, (int)StartBody + 142, 210, 1, gCustomMessage.GetMessage(11), gCustomBuyVip.m_CustomBuyVipInfo[0].Coin1);
		this->DrawFormat(eGold, (int)StartX + 120, (int)StartBody + 142, 210, 1, gCustomMessage.GetMessage(12), gCustomBuyVip.m_CustomBuyVipInfo[0].Coin2);
		this->DrawFormat(eGold, (int)StartX + 160, (int)StartBody + 142, 210, 1, gCustomMessage.GetMessage(13), gCustomBuyVip.m_CustomBuyVipInfo[0].Coin3);
	}
	else
		this->DrawButton(eVip_BRONZE, StartX + 64, 195, 0, 0);
	// ----
	this->DrawFormat(eWhite, (int)StartX + 90, 195 + 9, 160, 1, gCustomMessage.GetMessage(9),gCustomBuyVip.m_CustomBuyVipInfo[0].VipName);
	// ---- bronze end ------------------------------------
	}

	if (gProtect.m_MainInfo.VipTypes > 1)
	{
	// ---- Silver start ------------------------------------
	if (IsWorkZone(eVip_SILVER))
	{
		if (this->Data[eVip_SILVER].OnClick)
			this->DrawButton(eVip_SILVER, StartX + 64, 225, 0, 58);
		else
			this->DrawButton(eVip_SILVER, StartX + 64, 225, 0, 29);
		// ----
		this->DrawFormat(eGold, (int)StartX + 30, (int)StartBody + 142, 210, 1, gCustomMessage.GetMessage(10));
		this->DrawFormat(eGold, (int)StartX + 70, (int)StartBody + 142, 210, 1, gCustomMessage.GetMessage(11), gCustomBuyVip.m_CustomBuyVipInfo[1].Coin1);
		this->DrawFormat(eGold, (int)StartX + 120, (int)StartBody + 142, 210, 1, gCustomMessage.GetMessage(12), gCustomBuyVip.m_CustomBuyVipInfo[1].Coin2);
		this->DrawFormat(eGold, (int)StartX + 160, (int)StartBody + 142, 210, 1, gCustomMessage.GetMessage(13), gCustomBuyVip.m_CustomBuyVipInfo[1].Coin3);
	}
	else
		this->DrawButton(eVip_SILVER, StartX + 64, 225, 0, 0);

	this->DrawFormat(eWhite, (int)StartX + 90, 225 + 9, 160, 1, gCustomMessage.GetMessage(9),gCustomBuyVip.m_CustomBuyVipInfo[1].VipName);
	// ---- silver end ------------------------------------
	}

	if (gProtect.m_MainInfo.VipTypes > 2)
	{
	// ---- gold start ------------------------------------
	if (IsWorkZone(eVip_GOLD))
	{
		if (this->Data[eVip_GOLD].OnClick)
			this->DrawButton(eVip_GOLD, StartX + 64, 255, 0, 58);
		else
			this->DrawButton(eVip_GOLD, StartX + 64, 255, 0, 29);
		// ----
		this->DrawFormat(eGold, (int)StartX + 30, (int)StartBody + 142, 210, 1, gCustomMessage.GetMessage(10));
		this->DrawFormat(eGold, (int)StartX + 70, (int)StartBody + 142, 210, 1, gCustomMessage.GetMessage(11), gCustomBuyVip.m_CustomBuyVipInfo[2].Coin1);
		this->DrawFormat(eGold, (int)StartX + 120, (int)StartBody + 142, 210, 1, gCustomMessage.GetMessage(12), gCustomBuyVip.m_CustomBuyVipInfo[2].Coin2);
		this->DrawFormat(eGold, (int)StartX + 160, (int)StartBody + 142, 210, 1, gCustomMessage.GetMessage(13), gCustomBuyVip.m_CustomBuyVipInfo[2].Coin3);
	}
	else
		this->DrawButton(eVip_GOLD, StartX + 64, 255, 0, 0);

	this->DrawFormat(eWhite, (int)StartX + 90, 255 + 9, 160, 1, gCustomMessage.GetMessage(9),gCustomBuyVip.m_CustomBuyVipInfo[2].VipName);
	// ---- gold end ------------------------------------
	}
}

bool Interface::EventVipWindow_Close(DWORD Event)
{
	DWORD CurrentTick = GetTickCount();
	DWORD Delay = (CurrentTick - this->Data[eVip_CLOSE].EventTick);
	// ----
	if (!this->Data[eVip_MAIN].OnShow || !IsWorkZone(eVip_CLOSE))
	{
		return false;
	}
	// ----
	if (Event == WM_LBUTTONDOWN)
	{
		this->Data[eVip_CLOSE].OnClick = true;
		return true;
	}
	// ----
	this->Data[eVip_CLOSE].OnClick = false;
	// ----
	if (Delay < 500)
	{
		return false;
	}
	// ----
	this->Data[eVip_CLOSE].EventTick = GetTickCount();
	this->CloseVipWindow();
	// ----
	return false;
}
// ----------------------------------------------------------------------------------------------

bool Interface::EventVipWindow_Bronze(DWORD Event)
{
	DWORD CurrentTick = GetTickCount();
	DWORD Delay = (CurrentTick - this->Data[eVip_BRONZE].EventTick);
	// ----
	if (!this->Data[eVip_MAIN].OnShow || !IsWorkZone(eVip_BRONZE))
	{
		return false;
	}
	// ----
	if (Event == WM_LBUTTONDOWN)
	{
		this->Data[eVip_BRONZE].OnClick = true;
		return true;
	}
	// ----
	this->Data[eVip_BRONZE].OnClick = false;;
	// ----
	if (Delay < 500)
	{
		return false;
	}
	// ----
	this->Data[eVip_BRONZE].EventTick = GetTickCount();
	gCustomBuyVip.BuyStatus(1);
	this->CloseVipWindow();
	// ----
	return false;
}
// ----------------------------------------------------------------------------------------------

bool Interface::EventVipWindow_Silver(DWORD Event)
{
	DWORD CurrentTick = GetTickCount();
	DWORD Delay = (CurrentTick - this->Data[eVip_SILVER].EventTick);
	// ----
	if (!this->Data[eVip_MAIN].OnShow || !IsWorkZone(eVip_SILVER))
	{
		return false;
	}
	if (gProtect.m_MainInfo.VipTypes < 2)
	{
		return false;
	}
	// ----
	if (Event == WM_LBUTTONDOWN)
	{
		this->Data[eVip_SILVER].OnClick = true;
		return true;
	}
	// ----
	this->Data[eVip_SILVER].OnClick = false;;
	// ----
	if (Delay < 500)
	{
		return false;
	}
	// ----
	this->Data[eVip_SILVER].EventTick = GetTickCount();
	gCustomBuyVip.BuyStatus(2);
	this->CloseVipWindow();
	// ----
	return false;
}

// ----------------------------------------------------------------------------------------------
bool Interface::EventVipWindow_Gold(DWORD Event)
{
	DWORD CurrentTick = GetTickCount();
	DWORD Delay = (CurrentTick - this->Data[eVip_GOLD].EventTick);
	// ----
	if (!this->Data[eVip_MAIN].OnShow || !IsWorkZone(eVip_GOLD))
	{
		return false;
	}
	if (gProtect.m_MainInfo.VipTypes < 3)
	{
		return false;
	}
	// ----
	if (Event == WM_LBUTTONDOWN)
	{
		this->Data[eVip_GOLD].OnClick = true;
		return true;
	}
	// ----
	this->Data[eVip_GOLD].OnClick = false;;
	// ----
	if (Delay < 500)
	{
		return false;
	}
	// ----
	this->Data[eVip_GOLD].EventTick = GetTickCount();
	gCustomBuyVip.BuyStatus(3);
	this->CloseVipWindow();
	// ----
	return false;
}
// ----------------------------------------------------------------------------------------------

bool Interface::EventVipWindow_Main(DWORD Event)
{
	this->EventVipWindow_Close(Event);
	this->EventVipWindow_Bronze(Event);
	this->EventVipWindow_Silver(Event);
	this->EventVipWindow_Gold(Event);
	// ----
	return true;
}

float Interface::DrawRepeatGUI(short MonsterID, float X, float Y, int Count)
{
	float StartY = Y;
	// ----
	for( int i = 0; i < Count; i++ )
	{
		pDrawGUI(this->Data[MonsterID].ModelID, X, StartY,
			this->Data[MonsterID].Width, this->Data[MonsterID].Height);
		// ----
		StartY += this->Data[MonsterID].Height;
	}
	// ----
	return StartY;
}

void Interface::DrawButton(short ObjectID, float PosX, float PosY, float ScaleX, float ScaleY)
{
	if (this->Data[ObjectID].X == -1 || this->Data[ObjectID].Y == -1)
	{
		this->Data[ObjectID].X = PosX;
		this->Data[ObjectID].Y = PosY;
		this->Data[ObjectID].MaxX = PosX + this->Data[ObjectID].Width;
		this->Data[ObjectID].MaxY = PosY + this->Data[ObjectID].Height;
	}
	// ----
	pDrawButton(this->Data[ObjectID].ModelID, PosX, PosY,
		this->Data[ObjectID].Width, this->Data[ObjectID].Height, ScaleX, ScaleY);
}


void Interface::DrawColoredGUI(short ObjectID, float X, float Y, DWORD Color)
{
	if( this->Data[ObjectID].X == -1 || this->Data[ObjectID].Y == -1 )
	{
		this->Data[ObjectID].X		= X;
		this->Data[ObjectID].Y		= Y;
		this->Data[ObjectID].MaxX	= X + this->Data[ObjectID].Width;
		this->Data[ObjectID].MaxY	= Y + this->Data[ObjectID].Height;
	}
	// ----
	pDrawColorButton(this->Data[ObjectID].ModelID, X, Y, 
		this->Data[ObjectID].Width, this->Data[ObjectID].Height, 0, 0, Color);
}

void Interface::DrawLogo(bool active)
{
	if (gProtect.m_MainInfo.PrintLogo != 0)
	{

		if (active == 1)
		{
			this->Data[eLogo].EventTick = GetTickCount()+1500;
		}

		if (gInterface.Data[eLogo].EventTick > GetTickCount())
		{
			if (gProtect.m_MainInfo.PrintLogo == 1)
			{
				this->DrawGUI(eLogo, 10, 10);
			}

			if (gProtect.m_MainInfo.PrintLogo == 2)
			{
				this->DrawGUI(eLogo, MAX_WIN_WIDTH - 160, 10);

			}

			if (gProtect.m_MainInfo.PrintLogo == 3)
			{
				this->DrawGUI(eLogo, 10, MAX_WIN_HEIGHT - 144);
			}

			if (gProtect.m_MainInfo.PrintLogo == 4)
			{
				this->DrawGUI(eLogo, MAX_WIN_WIDTH - 160, MAX_WIN_HEIGHT - 144);
			}

			if (gProtect.m_MainInfo.PrintLogo == 5)
			{
				this->DrawGUI(eLogo, (MAX_WIN_WIDTH/2)-(150/2), (MAX_WIN_HEIGHT/2)-(114/2));
			}
		}
	}
}

void Interface::DrawMenu()
{
	if (gProtect.m_MainInfo.CustomMenuSwitch != 1)
	{
		return;
	}

	if (this->Data[eMenu].OnShow)
	{
		this->Data[eMenu].OnShow = false;
	}

	if (this->CheckWindow(ObjWindow::MoveList) || this->CheckWindow(ObjWindow::CashShop) || this->CheckWindow(ObjWindow::SkillTree) || this->CheckWindow(ObjWindow::FullMap)
		||  (this->CheckWindow(Inventory) 
		&& this->CheckWindow(ExpandInventory) 
		&& this->CheckWindow(Store)) 
		||  (this->CheckWindow(Inventory) 
		&& this->CheckWindow(Warehouse) 
		&& this->CheckWindow(ExpandWarehouse)) )
	{
		CloseMenuWindow();
		return;
	}
	
	this->Data[eMenu].OnShow = true;

	if (gProtect.m_MainInfo.CustomMenuType == 1)
	{
		this->DrawGUI(eMenu, 3, 72);
	}
	else
	{
		float PosX = this->GetResizeX(eMenuBG);

		this->DrawGUI(eMenuBG, PosX, 0);

		this->DrawGUI(eMenu, PosX + 0.5, 1);

	if (IsWorkZone(eMenu))
	{
		this->DrawToolTip(PosX + 0.5 - 5, 25, "Especial Menu");
		// ----
		if (this->Data[eMenu].OnClick)
		{
			this->DrawColoredGUI(eMenu, PosX + 0.5, 1, pMakeColor(40, 20, 3, 130));
			return;
		}
		// ----
		this->DrawColoredGUI(eMenu, PosX + 0.5, 1, pMakeColor(255, 204, 20, 200));
	}
	}

}

bool Interface::EventDrawMenu_Open(DWORD Event)
{
	DWORD CurrentTick = GetTickCount();
	DWORD Delay = (CurrentTick - this->Data[eMenu].EventTick);
	// ----
	if (!this->Data[eMenu].OnShow || !IsWorkZone(eMenu))
	{
		return false;
	}
	// ----
	if (Event == WM_LBUTTONDOWN)
	{
		pSetCursorFocus = true;
		this->Data[eMenu].OnClick = true;
		return true;
	}
	// ----
	this->Data[eMenu].OnClick = false;
	// ----
	if (Delay < 500)
	{
		return false;
	}
	
	// ----
	this->Data[eMenu].EventTick = GetTickCount();
	
	if (CheckMenuWindow())
	{
		CloseMenuWindow();
	}
	else
	{
		CloseCustomWindow();
		OpenMenuWindow();
		//OpenWindow(46+teste);
		//teste++;

	}
	// ----
	return false;
}

void Interface::DrawMenuOpen()
{

	if (gProtect.m_MainInfo.CustomMenuSwitch != 1)
	{
		return;
	}

	if( !this->Data[eMenu_MAIN].OnShow )
	{
		return;
	}


	float MainWidth			= 230.0;
	float MainHeight		= 130.0;
	float StartBody			= 30.0;
	float StartY			= 30.0;
	float StartX			= (MAX_WIN_WIDTH / 2) - (MainWidth / 2);
	float MainCenter		= StartX + (MainWidth / 3);
	float ButtonX			= MainCenter - (float)(29.0 / 2);

	//	float CenterX			= StartX + (MainWidth / 2);
	//		float ContentY = StartY+40;

	//	ItemBmdStruct* ItemInfo = pGetItemBmdStruct(10);
	//	const int WidthValue = 18;
	//	const int HeightValue = 20;
	//	float barWidth = WidthValue*ItemInfo->ItemWidth;
	//	float barHeight = HeightValue*ItemInfo->ItemHeight;

	//	gInterface.DrawItem(CenterX-(WidthValue*(float)(ItemInfo->ItemWidth/2.0f)),ContentY-10,barWidth,barHeight,10,SET_ITEMOPT_LEVEL(5),0,0,0);

	//return;
	// ----
	this->DrawGUI(eMenu_MAIN, StartX, StartY + (float)2.0);
	this->DrawGUI(eMenu_TITLE, StartX, StartY);
	StartY = this->DrawRepeatGUI(eMenu_FRAME, StartX, StartY + (float)20.0, 12);
	this->DrawGUI(eMenu_FOOTER, StartX, StartY);
	this->DrawGUI(eMenu_CLOSE, StartX + MainWidth - this->Data[eVip_CLOSE].Width, StartBody);
	// ----
	if (this->IsWorkZone(eMenu_CLOSE))
	{
		DWORD Color = eGray100;
		// ----
		if (this->Data[eMenu_CLOSE].OnClick)
		{
			Color = eGray150;
		}
		// ----
		this->DrawColoredGUI(eVip_CLOSE, this->Data[eMenu_CLOSE].X, StartBody, Color);
		this->DrawToolTip((int)this->Data[eMenu_CLOSE].X + 5, StartBody + 25, "Close");
	}

	this->DrawFormat(eGold, (int)StartX + 10, (int)StartBody + 10, 210, 3, "Menu");

	if(gProtect.m_MainInfo.EnableCoinStatus == 1)
	{
		this->DrawFormat(eGold, (int)StartX + 10, (int)StartBody + 35, 210, 3, gCustomMessage.GetMessage(50));

		this->DrawFormat(eWhite, (int)StartX + 25, (int)StartBody + 50, 40, 1, gCustomMessage.GetMessage(51));
		this->DrawFormat(eGold, (int)StartX + 50, (int)StartBody + 50, 40, 1, "%d",Coin1);

		this->DrawFormat(eWhite, (int)StartX + 90, (int)StartBody + 50, 40, 1, gCustomMessage.GetMessage(52));
		this->DrawFormat(eGold, (int)StartX + 115, (int)StartBody + 50, 40, 1, "%d",Coin2);

		this->DrawFormat(eWhite, (int)StartX + 153, (int)StartBody + 50, 40, 1, gCustomMessage.GetMessage(53));
		this->DrawFormat(eGold, (int)StartX + 176, (int)StartBody + 50, 40, 1, "%d",Coin3);
	}
	else
	{
		this->DrawFormat(eGold, (int)StartX + 10, (int)StartBody + 45, 210, 3, gCustomMessage.GetMessage(54));
	}

	this->DrawGUI(eVip_DIV, StartX, StartBody + 60);

	int BtCount		= 0;
	int BtStart		= StartBody + 78;
	int BtDistance	= 33;

	if (gProtect.m_MainInfo.EnableEventTimeButton == 1)
	{
		BtCount++;
	}
	else
	{	
		BtStart	-= 33;
	}
	if (gProtect.m_MainInfo.EnableVipShopButton == 1)
	{
		BtCount++;
	}
	if (gProtect.m_MainInfo.EnableRankingButton == 1)
	{
		BtCount++;
	}
	if (gProtect.m_MainInfo.EnableCommandButton == 1)
	{
		BtCount++;
	}
	if (gProtect.m_MainInfo.EnableOptionButton == 1)
	{
		BtCount++;
	}

	if (BtCount == 4)
	{
		BtStart		+= 15;
	}
	if (BtCount == 3)
	{
		BtStart		+= 30;
	}
	if (BtCount == 2)
	{
		BtStart		+= 45;
	}
	if (BtCount == 1)
	{
		BtStart		+= 60;
	}

	//Horario eventos
	if (gProtect.m_MainInfo.EnableEventTimeButton == 1)
	{
	
	if (IsWorkZone(eMenu_OPT1))
	{
		if (this->Data[eMenu_OPT1].OnClick)
			this->DrawButton(eMenu_OPT1, StartX + 64, BtStart, 0, 58);
		else
			this->DrawButton(eMenu_OPT1, StartX + 64, BtStart, 0, 29);
		// ----
	}
	else
		this->DrawButton(eMenu_OPT1, StartX + 64, BtStart, 0, 0);

	this->DrawFormat(eWhite, (int)StartX + 64, BtStart + 9, 108, 3, gCustomMessage.GetMessage(25));
	}

	//Comprar vip
	if (gProtect.m_MainInfo.EnableVipShopButton == 1)
	{
	
	BtStart += BtDistance;

	if (IsWorkZone(eMenu_OPT2))
	{
		if (this->Data[eMenu_OPT2].OnClick)
			this->DrawButton(eMenu_OPT2, StartX + 64, BtStart, 0, 58);
		else
			this->DrawButton(eMenu_OPT2, StartX + 64, BtStart, 0, 29);
		// ----
	}
	else
		this->DrawButton(eMenu_OPT2, StartX + 64, BtStart, 0, 0);

	this->DrawFormat(eWhite, (int)StartX + 64, BtStart + 9, 108, 3, gCustomMessage.GetMessage(26));
	}

	//Ranking
	if (gProtect.m_MainInfo.EnableRankingButton == 1)
	{
	BtStart += BtDistance;

	if (IsWorkZone(eMenu_OPT3))
	{
		if (this->Data[eMenu_OPT3].OnClick)
			this->DrawButton(eMenu_OPT3, StartX + 64, BtStart, 0, 58);
		else
			this->DrawButton(eMenu_OPT3, StartX + 64, BtStart, 0, 29);
		// ----
	}
	else
		this->DrawButton(eMenu_OPT3, StartX + 64, BtStart, 0, 0);

	this->DrawFormat(eWhite, (int)StartX + 64, BtStart + 9, 108, 3, gCustomMessage.GetMessage(27));
	}

	if (gProtect.m_MainInfo.EnableCommandButton == 1)
	{
	//Commandos
	BtStart += BtDistance;

	if (IsWorkZone(eMenu_OPT4))
	{
		if (this->Data[eMenu_OPT4].OnClick)
			this->DrawButton(eMenu_OPT4, StartX + 64, BtStart, 0, 58);
		else
			this->DrawButton(eMenu_OPT4, StartX + 64, BtStart, 0, 29);
		// ----
	}
	else
		this->DrawButton(eMenu_OPT4, StartX + 64, BtStart, 0, 0);

	this->DrawFormat(eWhite, (int)StartX + 64, BtStart + 9, 108, 3, gCustomMessage.GetMessage(28));
	}

	if (gProtect.m_MainInfo.EnableOptionButton == 1)
	{
	//Opções
	BtStart += BtDistance;

	if (IsWorkZone(eMenu_OPT20))
	{
		if (this->Data[eMenu_OPT20].OnClick)
			this->DrawButton(eMenu_OPT20, StartX + 64, BtStart, 0, 58);
		else
			this->DrawButton(eMenu_OPT20, StartX + 64, BtStart, 0, 29);
		// ----
	}
	else
		this->DrawButton(eMenu_OPT20, StartX + 64, BtStart, 0, 0);

	this->DrawFormat(eWhite, (int)StartX + 64, BtStart + 9, 108, 3, gCustomMessage.GetMessage(44));
	}

}

bool Interface::EventDrawMenu_Close(DWORD Event)
{
	DWORD CurrentTick = GetTickCount();
	DWORD Delay = (CurrentTick - this->Data[eMenu_CLOSE].EventTick);
	// ----
	if (!this->Data[eMenu_MAIN].OnShow || !IsWorkZone(eMenu_CLOSE))
	{
		return false;
	}
	// ----
	if (Event == WM_LBUTTONDOWN)
	{
		this->Data[eMenu_CLOSE].OnClick = true;
		return true;
	}
	// ----
	this->Data[eMenu_CLOSE].OnClick = false;
	// ----
	if (Delay < 500)
	{
		return false;
	}
	// ----
	this->Data[eMenu_CLOSE].EventTick = GetTickCount();
	this->CloseMenuWindow();
	// ----
	return false;
}
// ----------------------------------------------------------------------------------------------

bool Interface::EventDrawMenu_Op1(DWORD Event)
{
	DWORD CurrentTick = GetTickCount();
	DWORD Delay = (CurrentTick - this->Data[eMenu_OPT1].EventTick);
	// ----
	if (!this->Data[eMenu_MAIN].OnShow || !IsWorkZone(eMenu_OPT1))
	{
		return false;
	}
	// ----
	if (Event == WM_LBUTTONDOWN)
	{
		this->Data[eMenu_OPT1].OnClick = true;
		return true;
	}
	// ----
	this->Data[eMenu_OPT1].OnClick = false;;
	// ----
	if (Delay < 500)
	{
		return false;
	}
	// ----
	this->Data[eMenu_OPT1].EventTick = GetTickCount();

	this->CloseMenuWindow();

	gCustomEventTime.OpenWindow();
	// ----
	return false;
}

bool Interface::EventDrawMenu_Op2(DWORD Event)
{
	DWORD CurrentTick = GetTickCount();
	DWORD Delay = (CurrentTick - this->Data[eMenu_OPT2].EventTick);
	// ----
	if (!this->Data[eMenu_MAIN].OnShow || !IsWorkZone(eMenu_OPT2))
	{
		return false;
	}
	// ----
	if (Event == WM_LBUTTONDOWN)
	{
		this->Data[eMenu_OPT2].OnClick = true;
		return true;
	}
	// ----
	this->Data[eMenu_OPT2].OnClick = false;;
	// ----
	if (Delay < 500)
	{
		return false;
	}
	// ----
	this->Data[eMenu_OPT2].EventTick = GetTickCount();

	this->CloseCustomWindow();

	this->OpenVipWindow();
	// ----
	return false;
}

bool Interface::EventDrawMenu_Op3(DWORD Event)
{
	DWORD CurrentTick = GetTickCount();
	DWORD Delay = (CurrentTick - this->Data[eMenu_OPT3].EventTick);
	// ----
	if (!this->Data[eMenu_MAIN].OnShow || !IsWorkZone(eMenu_OPT3))
	{
		return false;
	}
	// ----
	if (Event == WM_LBUTTONDOWN)
	{
		this->Data[eMenu_OPT3].OnClick = true;
		return true;
	}
	// ----
	this->Data[eMenu_OPT3].OnClick = false;;
	// ----
	if (Delay < 500)
	{
		return false;
	}
	// ----
	this->Data[eMenu_OPT3].EventTick = GetTickCount();

	this->CloseMenuWindow();

	gCustomRanking.OpenWindow();
	// ----
	return false;
}

bool Interface::EventDrawMenu_Op4(DWORD Event)
{
	DWORD CurrentTick = GetTickCount();
	DWORD Delay = (CurrentTick - this->Data[eMenu_OPT4].EventTick);
	// ----
	if (!this->Data[eMenu_MAIN].OnShow || !IsWorkZone(eMenu_OPT4))
	{
		return false;
	}
	// ----
	if (Event == WM_LBUTTONDOWN)
	{
		this->Data[eMenu_OPT4].OnClick = true;
		return true;
	}
	// ----
	this->Data[eMenu_OPT4].OnClick = false;;
	// ----
	if (Delay < 500)
	{
		return false;
	}
	// ----
	this->Data[eMenu_OPT4].EventTick = GetTickCount();

	this->CloseMenuWindow();

	gCustomCommandInfo.OpenCommandWindow();
	// ----
	return false;
}

bool Interface::EventDrawMenu_Op20(DWORD Event)
{
	DWORD CurrentTick = GetTickCount();
	DWORD Delay = (CurrentTick - this->Data[eMenu_OPT20].EventTick);
	// ----
	if (!this->Data[eMenu_MAIN].OnShow || !IsWorkZone(eMenu_OPT20))
	{
		return false;
	}
	// ----
	if (Event == WM_LBUTTONDOWN)
	{
		this->Data[eMenu_OPT20].OnClick = true;
		return true;
	}
	// ----
	this->Data[eMenu_OPT20].OnClick = false;;
	// ----
	if (Delay < 500)
	{
		return false;
	}
	// ----
	this->Data[eMenu_OPT20].EventTick = GetTickCount();

	this->CloseMenuWindow();

	this->OpenWindow(ObjWindow::Options);
	// ----
	return false;
}

void Interface::DrawMiniMap()
{

	if (!MiniMap || !MiniMapActive)
	{
		return;
	}
	//if (gInterface.showMiniMap)
	//{
		float MainWidth = 138.0;
		float MainHeight = 265.0;
		float StartY = 230.0;
		float StartX = 512.0;
		// ----
		if (this->MiniMapCheck() || this->CombinedChecks() || CheckMap())
		{
			return;
		}
		// ----
		switch (gObjUser.m_MapNumber)
		{
		case 0:    //Lorencia
		{
					   this->DrawGUI(eLORENCIA_MAP, StartX, StartY + 30);
		}
			break;
			// --
		case 1:    //Dungeon
		{
					   this->DrawGUI(eDUNGEON_MAP, StartX, StartY + 30);
		}
			break;
			// --
		case 2:    //Devias
		{
					   this->DrawGUI(eDEVIAS_MAP, StartX, StartY + 30);
		}
			break;
			// --
		case 3:    //Noria
		{
					   this->DrawGUI(eNORIA_MAP, StartX, StartY + 30);
		}
			break;
			// --
		case 4:    //LostTower
		{
					   this->DrawGUI(eLOSTTOWER_MAP, StartX, StartY + 30);
		}
			break;
			// --
		case 5:    //Exile (disabled)
		{
					   return;
		}
			break;
			// --
			// --
		case 7:    //Atlans
		{
					   this->DrawGUI(eATLANS_MAP, StartX, StartY + 30);
		}
			break;
			// --
		case 8:    //Tarkan
		{
					   this->DrawGUI(eTarkan_MAP, StartX, StartY + 30);
		}
			break;
			// --
		case 10:    //Icarus
		{
						this->DrawGUI(eICARUS_MAP, StartX, StartY + 30);
		}
			break;
			// --
		case 31:    //Land of Trials
		{
						this->DrawGUI(eLANDOFTRIALS_MAP, StartX, StartY + 30);
		}
			break;
			// --
		case 33:    //Aida
		{
						this->DrawGUI(eAIDA_MAP, StartX, StartY + 30);
		}
			break;
			// --
		case 34:    //Crywolf Fortress
		{
						this->DrawGUI(eCRYWOLF_MAP, StartX, StartY + 30);
		}
			break;
			// --
		case 37:    //Kantru
		{
						this->DrawGUI(eKANTRU_MAP, StartX, StartY + 30);
		}
			break;
			// --
		case 38:    //Kantru 3
		{
						this->DrawGUI(eKANTRU3_MAP, StartX, StartY + 30);
		}
			break;
			// --
		case 41:    //Barracks
		{
						this->DrawGUI(eBARRACKS_MAP, StartX, StartY + 30);
		}
			break;
			// --
		case 51:    //Elbeland
		{
						this->DrawGUI(eElbeland_MAP, StartX, StartY + 30);
		}
			break;
			// --
		case 56:    //Swamp of Calmness
		{
						this->DrawGUI(eCALMNESS_MAP, StartX, StartY + 30);
		}
			break;
			// --
		case 57:    //Raklion
		{
						this->DrawGUI(eRAKLION_MAP, StartX, StartY + 30);
		}
			break;
			// --
		case 63:    //Vulcanus
		{
						this->DrawGUI(eVULCANUS_MAP, StartX, StartY + 30);
		}
			break;
			// --
		case 80:    //Kalrutan
		{
						this->DrawGUI(eKALRUTAN_MAP, StartX, StartY + 30);
		}
			break;
			// --
		case 81:    //Kalrutan 2
		{
						this->DrawGUI(eKALRUTAN2_MAP, StartX, StartY + 30);
		}
			break;

			// --
		default: //Default
		{
					 this->DrawGUI(eNULL_MAP, StartX, StartY + 30);
		}
			break;
		}
		// ----
		this->DrawGUI(ePLAYER_POINT, (float)(StartX - 1 + gObjUser.lpViewPlayer->MapPosX / 2), (float)(294 - 1 + (255 - gObjUser.lpViewPlayer->MapPosY) / 2)-35);
	//}
}

bool Interface::MiniMapCheck()
{
	if (this->CheckWindow(Inventory) ||
		this->CheckWindow(CashShop) ||
		this->CheckWindow(ChaosBox) ||
		this->CheckWindow(Character) ||
		this->CheckWindow(CommandWindow) ||
		this->CheckWindow(ExpandInventory) ||
		this->CheckWindow(ExpandWarehouse) ||
		this->CheckWindow(FullMap) ||
		this->CheckWindow(GensInfo) ||
		this->CheckWindow(Guild) ||
		this->CheckWindow(NPC_Dialog) ||
		this->CheckWindow(NPC_Julia) ||
		this->CheckWindow(NPC_Titus) ||
		this->CheckWindow(OtherStore) ||
		this->CheckWindow(Party) ||
		this->CheckWindow(PetInfo) ||
		this->CheckWindow(Shop) ||
		this->CheckWindow(SkillTree) ||
		this->CheckWindow(Store) ||
		this->CheckWindow(Trade) ||
		this->CheckWindow(FriendList) ||
		this->CheckWindow(FastMenu) ||
		this->CheckWindow(MuHelper) ||
		this->CheckWindow(Quest) ||
		this->CheckWindow(Lugard) ||
		this->CheckWindow(Jerint) ||
		this->CheckWindow(GoldenArcher1) ||
		this->CheckWindow(GoldenArcher2) ||
		this->CheckWindow(LuckyCoin1) ||
		this->CheckWindow(LuckyCoin2) ||
		this->CheckWindow(NPC_Duel) ||
		this->CheckWindow(NPC_Devin) ||
		this->CheckWindow(GuardNPC) ||
		this->CheckWindow(SeniorNPC) ||
		this->CheckWindow(GuardNPC2) ||
		this->CheckWindow(CastleGateSwitch) ||
		this->CheckWindow(CatapultNPC) ||
		this->CheckWindow(DuelScore) ||
		this->CheckWindow(CreateGuild) ||
		this->CheckWindow(Warehouse)) 
	{
		return true;
	}
	return false;
}

bool Interface::CombinedChecks()
{
	if ((this->CheckWindow(Inventory)
		&& this->CheckWindow(ExpandInventory)
		&& this->CheckWindow(Store)) ||
		(this->CheckWindow(Inventory)
		&& this->CheckWindow(Warehouse)
		&& this->CheckWindow(ExpandWarehouse)) ||
		(this->CheckWindow(Inventory)
		&& this->CheckWindow(Character)
		&& this->CheckWindow(Store)))
		return true;
	return false;
}

bool Interface::CheckMap()
{
	switch(gObjUser.m_MapNumber)
	{
		case eMapNumber::Lorencia:
			return false;
			break;
		case eMapNumber::Dungeon:
			return false;
			break;
		case eMapNumber::Devias:
			return false;
			break;
		case eMapNumber::Noria:
			return false;
			break;
		case eMapNumber::LostTower:
			return false;
			break;
		case eMapNumber::Atlans:
			return false;
			break;
		case eMapNumber::Tarkan:
			return false;
			break;
		case eMapNumber::Elbeland:
			return false;
			break;
		case eMapNumber::Icarus:
			return false;
			break;
		case eMapNumber::Trials:
			return false;
			break;
		case eMapNumber::Aida:
			return false;
			break;
		case eMapNumber::Crywolf:
			return false;
			break;
		case eMapNumber::Kanturu1:
			return false;
			break;
		case eMapNumber::Kanturu3:
			return false;
			break;
		case eMapNumber::Barracks:
			return false;
			break;
		case eMapNumber::Calmness:
			return false;
			break;
		case eMapNumber::Raklion:
			return false;
			break;
		case eMapNumber::Vulcanus:
			return false;
			break;
		case eMapNumber::Karutan1:
			return false;
			break;
		case eMapNumber::Karutan2:
			return false;
			break;
		default:
			return true;
			break;
	}
}

void Interface::CloseCustomWindow()
{
	this->CloseMenuWindow();
	this->CloseVipWindow();
	this->Data[eRankPANEL_MAIN].OnShow		= false;
	this->Data[eEventTimePANEL_MAIN].OnShow = false;
	this->Data[eCommand_MAIN].OnShow		= false;
	pSetCursorFocus = false;
}

void Interface::DrawItem(float PosX, float PosY, float Width, float Height, int ItemID, int Level, int Excl, int Anc, bool OnMouse)
{

	if (this->CheckWindow(ObjWindow::MoveList) || this->CheckWindow(ObjWindow::CashShop) || this->CheckWindow(ObjWindow::SkillTree) || this->CheckWindow(ObjWindow::FullMap)
		||  (this->CheckWindow(Inventory) 
		&& this->CheckWindow(ExpandInventory) 
		&& this->CheckWindow(Store)) 
		||  (this->CheckWindow(Inventory) 
		&& this->CheckWindow(Warehouse) 
		&& this->CheckWindow(ExpandWarehouse)) )
	{
		return;
	}

	pSetBlend(true);
	glMatrixMode(0x1701);
	glPushMatrix();
	glLoadIdentity();

	sub_6363D0_Addr(0, 0, *(GLsizei*)MAIN_RESOLUTION_X, *(GLsizei*)MAIN_RESOLUTION_Y);

	float v2 = *(float*)MAIN_RESOLUTION_X / *(float*)MAIN_RESOLUTION_Y;

	if (ItemID == 406)
	{
		sub_6358A0_Addr(0.4, v2, *(float*)0xE61E38, *(float*)0xE61E3C); //tamanho do bmd
	}
	else if (ItemID == 407)
	{
		sub_6358A0_Addr(0.5, v2, *(float*)0xE61E38, *(float*)0xE61E3C); //tamanho do bmd
	}
	else
	{
		sub_6358A0_Addr(0.7, v2, *(float*)0xE61E38, *(float*)0xE61E3C); //tamanho do bmd
	}

	glMatrixMode(0x1700);
	glPushMatrix();
	glLoadIdentity();

	sub_635830_Addr((LPVOID)0x87933A0); 
	sub_635DE0_Addr();
	sub_635E40_Addr();

	//posX 
	//posY
	//Width
	//Height
	//unk
	// 1 - Excellent Effect
	// 1 - Aura +7
	// 1 - original size
	glClear(0x100);

	//pDrawItemModel(PosX, PosY, Width, Height, ItemID, Level, Excl, Anc, OnMouse);

	 // int v31 = pTest((double)PosY);
	  //int v32 = pTest((double)PosX);

	VAngle v45;

	unsigned __int8 v44 = 1; //0 = parado / 1 = girando

	sub_6359B0_Addr(PosX, PosY, (int)&v45, 0); //posição do bmd
	sub_5CA0D0_Addr(ItemID, Level, Excl, Anc, (int)&v45, v44, 0); //funão que mostra o BMD
	
	sub_636720_Addr();

	glMatrixMode(0x1700);
	glPopMatrix();
	glMatrixMode(0x1701);
	glPopMatrix();

	sub_637770_Addr();

	glColor3f(1,1,1);
	pSetBlend(false);
}

void Interface::DrawConfirmOpen()
{
	if(!this->CheckWindow(Shop) && this->Data[eCONFIRM_MAIN].OnShow == true)
	{
		this->Data[eCONFIRM_MAIN].OnShow = false;
		pSetCursorFocus = false;
	}

	if ((GetTickCount() - this->Data[eCONFIRM_BTN_OK].EventTick) < 100)
	{
		this->Data[eCONFIRM_MAIN].OnShow = false;
		pSetCursorFocus = false;
	}

	if ((GetTickCount() - this->Data[eCONFIRM_BTN_CANCEL].EventTick) < 100)
	{
		this->Data[eCONFIRM_MAIN].OnShow = false;
		pSetCursorFocus = false;
	}

	if( !this->Data[eCONFIRM_MAIN].OnShow )
	{
		return;
	}

	//this->Data[eCONFIRM_MAIN].EventTick = GetTickCount();

	float MainWidth			= 230.0;
	float MainHeight		= 130.0;
	float StartBody			= 90.0;
	float StartY			= 90.0;
	float StartX			= 25;
	float MainCenter		= StartX + (MainWidth / 3);
	float ButtonX			= MainCenter - (float)(29.0 / 2);

	gInterface.DrawGUI(eCONFIRM_MAIN, StartX, StartY + (float)2.0);
	gInterface.DrawGUI(eVip_TITLE, StartX, StartY);
	StartY = gInterface.DrawRepeatGUI(eVip_FRAME, StartX, StartY + (float)5.0, 5);
	gInterface.DrawGUI(eVip_FOOTER, StartX, StartY);

		this->DrawFormat(eGold, (int)StartX + 10, (int)StartBody + 10, 210, 3, gCustomMessage.GetMessage(66));

		this->DrawFormat(eGold, (int)StartX + 10, (int)StartBody + 40, 210, 3, gCustomMessage.GetMessage(67));

		this->DrawButton(eCONFIRM_BTN_OK, (int)StartX+40, (int)StartBody + 70, 0, 0);

		if( this->IsWorkZone(eCONFIRM_BTN_OK) )
		{
			int ScaleY = 30;
			// ----
			if( this->Data[eCONFIRM_BTN_OK].OnClick )
			{
				ScaleY = 60;
			}
			// ----
			this->DrawButton(eCONFIRM_BTN_OK, (int)StartX+40, (int)StartBody + 70, 0, ScaleY);
		}

		this->DrawButton(eCONFIRM_BTN_CANCEL, (int)StartX+140, (int)StartBody + 70, 0, 0);

		if( this->IsWorkZone(eCONFIRM_BTN_CANCEL) )
		{
			int ScaleY = 30;
			// ----
			if( this->Data[eCONFIRM_BTN_CANCEL].OnClick )
			{
				ScaleY = 60;
			}
			// ----
			this->DrawButton(eCONFIRM_BTN_CANCEL, (int)StartX+140, (int)StartBody + 70, 0, ScaleY);
		}

}

bool Interface::EventConfirm_OK(DWORD Event)
{
	DWORD CurrentTick = GetTickCount();
	DWORD Delay = (CurrentTick - this->Data[eCONFIRM_BTN_OK].EventTick);
	// ----
	if (!this->Data[eCONFIRM_MAIN].OnShow || !IsWorkZone(eCONFIRM_BTN_OK))
	{
		return false;
	}
	// ----
	if (Event == WM_LBUTTONDOWN)
	{
		this->Data[eCONFIRM_BTN_OK].OnClick = true;
		return true;
	}
	// ----
	this->Data[eCONFIRM_BTN_OK].OnClick = false;;
	// ----
	if (Delay < 500)
	{
		return false;
	}
	// ----
	this->Data[eCONFIRM_BTN_OK].EventTick = GetTickCount();

	PMSG_ITEM_BUY_RECV pMsg;

	pMsg.header.set(0xF3, 0xED,sizeof(pMsg));

	pMsg.slot = this->ConfirmSlot;

	DataSend((BYTE*)&pMsg,pMsg.header.size);

	this->Data[eCONFIRM_MAIN].OnShow = false;
	pSetCursorFocus = false;
	// ----
	return false;
}

bool Interface::EventConfirm_CANCEL(DWORD Event)
{
	DWORD CurrentTick = GetTickCount();
	DWORD Delay = (CurrentTick - this->Data[eCONFIRM_BTN_CANCEL].EventTick);
	// ----
	if (!this->Data[eCONFIRM_MAIN].OnShow || !IsWorkZone(eCONFIRM_BTN_CANCEL))
	{
		return false;
	}
	// ----
	if (Event == WM_LBUTTONDOWN)
	{
		this->Data[eCONFIRM_BTN_CANCEL].OnClick = true;
		return true;
	}
	// ----
	this->Data[eCONFIRM_BTN_CANCEL].OnClick = false;;
	// ----
	if (Delay < 500)
	{
		return false;
	}
	// ----
	this->Data[eCONFIRM_BTN_CANCEL].EventTick = GetTickCount();

	this->Data[eCONFIRM_MAIN].OnShow = false;
	pSetCursorFocus = false;
	// ----
	return false;
}


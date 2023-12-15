#include "stdafx.h"
#include "Defines.h"
#include "Import.h"
#include "Interface.h"
#include "OffTrade.h"
#include "Offset.h"
#include "Protect.h"
#include "Util.h"
#include "CustomMessage.h"


cOffTrade gOffTrade;

cOffTrade::cOffTrade()
{
	this->ShopActive	= 0;
	this->TypeShop		= 0;
	this->Init();
}

cOffTrade::~cOffTrade()
{
	
}

void cOffTrade::Init()
{
	SetCompleteHook(0xFF, 0x007E4641, &this->ShowPrice);

	SetCompleteHook(0xFF, 0x007E4753, &this->ShowTwoString);

	SetCompleteHook(0xE9,0x007E46A0,&ChangePSValueColor);
}

__declspec(naked) void ChangePSValueColor()
{
	static DWORD AdressFinal = 0x007E46AB;
	_asm
	{
        MOV DWORD PTR DS:[EAX*4+0x81C0A68],0x08 //cor
		//MOV DWORD PTR DS:[EAX*4+0x7B52C30],0x02 //borda
        //INC EAX
		JMP [AdressFinal]
	}
}

void cOffTrade::ShowPrice(DWORD a1, const char *a2, char *Price)
{
	if(gOffTrade.ShopActive != 0 || gOffTrade.ShopList != 0)
	{
		if(gOffTrade.TypeShop == 0)
		{
			pSetItemTextLine(a1,gCustomMessage.GetMessage(61),Price);
		}
		else if(gOffTrade.TypeShop == 1)
		{
			pSetItemTextLine(a1,gCustomMessage.GetMessage(62),Price);
		}
		else if(gOffTrade.TypeShop == 2)
		{
			pSetItemTextLine(a1,gCustomMessage.GetMessage(63),Price);
		}
		else if(gOffTrade.TypeShop == 3)
		{
			pSetItemTextLine(a1,gCustomMessage.GetMessage(55),Price);
		}
		else if(gOffTrade.TypeShop == 4)
		{
			pSetItemTextLine(a1,gCustomMessage.GetMessage(56),Price);
		}
		else if(gOffTrade.TypeShop == 5)
		{
			pSetItemTextLine(a1,gCustomMessage.GetMessage(57),Price); 
		}
		else
		{
			pSetItemTextLine(a1,gCustomMessage.GetMessage(49),Price);
		}
	}
	else
	{
		pSetItemTextLine(a1,gCustomMessage.GetMessage(64),Price);
	}
}

void cOffTrade::ShowTwoString(DWORD a1, const char *a2)
{
	if(gOffTrade.TypeShop == 0)
	{
		pSetItemTextLine(a1,"\n");
	}
	else if(gOffTrade.TypeShop == 1)
	{
		pSetItemTextLine(a1,"\n");
	}
	else if(gOffTrade.TypeShop == 2)
	{
		pSetItemTextLine(a1,"\n");		
	}
	else if(gOffTrade.TypeShop == 3)
	{
		pSetItemTextLine(a1,"\n",gCustomMessage.GetMessage(58));
	}
	else if(gOffTrade.TypeShop == 4)
	{
		pSetItemTextLine(a1,"\n",gCustomMessage.GetMessage(59));
	}
	else if(gOffTrade.TypeShop == 5)
	{
		pSetItemTextLine(a1,"\n",gCustomMessage.GetMessage(60));
	}
	else
	{
		pSetItemTextLine(a1,"You are short of Zen");
	}
}

void cOffTrade::DrawOffTradeWindow()
{

	if (gInterface.CheckWindow(ObjWindow::OtherStore) == false)
	{
		if(this->ShopList == 1)
		{
			this->ShopList = 0;
		}
	}

	if (gInterface.CheckWindow(ObjWindow::Store) == false)
	{
		return;
	}

	bool ExpandedInventory = gInterface.CheckWindow(ObjWindow::ExpandInventory);

	int X = 0;
	if (ExpandedInventory == true)
	{
		X = 190;
	}

	gInterface.Data[eOFFTRADE_OPEN].OnShow = false;
	gInterface.Data[eOFFTRADE_JoB].OnShow = false;
	gInterface.Data[eOFFTRADE_JoS].OnShow = false;
	gInterface.Data[eOFFTRADE_JoC].OnShow = false;
	gInterface.Data[eOFFTRADE_WCC].OnShow = false;
	gInterface.Data[eOFFTRADE_WCP].OnShow = false;
	gInterface.Data[eOFFTRADE_WCG].OnShow = false;

	if(this->ShopActive != 0)
	{

		if(gProtect.m_MainInfo.CustomOffStoreEnable)
		{
			if (gInterface.IsWorkZone(eOFFTRADE_OPEN))
			{
				if (gInterface.Data[eOFFTRADE_OPEN].OnClick)
				{
					gInterface.DrawButton(eOFFTRADE_OPEN, 300-X ,350, 0, 30);
				}
				else
				{
					gInterface.DrawButton(eOFFTRADE_OPEN, 300-X ,350, 0, 90);
				}
		
				gInterface.DrawToolTip(320-X, 330, "Open Off-Store");
			}
			else
			{
				gInterface.DrawButton(eOFFTRADE_OPEN, 300-X ,350, 0, 0);
			}

				gInterface.DrawFormat(eYellow, 300-X, 360, 108, 3, "OFF STORE");

			gInterface.Data[eOFFTRADE_OPEN].OnShow = true;
		}
		return;
	}



	if (gProtect.m_MainInfo.CustomStoreEnableJoB)
	{
		gInterface.DrawGUI(eOFFTRADE_JoB, 281.5-X, 341);
		gInterface.DrawFormat(eYellow, 252-X, 346, 100, 3, "Bless");
		gInterface.Data[eOFFTRADE_JoB].OnShow = true;
	}

	if (gProtect.m_MainInfo.CustomStoreEnableJoS)
	{
		gInterface.DrawGUI(eOFFTRADE_JoS, 338-X, 341);
		gInterface.DrawFormat(eYellow, 309-X, 346, 100, 3, "Soul");
		gInterface.Data[eOFFTRADE_JoS].OnShow = true;
	}

	if (gProtect.m_MainInfo.CustomStoreEnableJoC)
	{
		gInterface.DrawGUI(eOFFTRADE_JoC, 393.5-X, 341);
		gInterface.DrawFormat(eYellow, 364-X, 346, 100, 3, "Chaos");
		gInterface.Data[eOFFTRADE_JoC].OnShow = true;
	}

	if (gProtect.m_MainInfo.CustomStoreEnableCoin1)
	{
		gInterface.DrawGUI(eOFFTRADE_WCC, 281.5-X, 362);
		gInterface.DrawFormat(eYellow, 252-X, 368, 100, 3, gCustomMessage.GetMessage(58));
		gInterface.Data[eOFFTRADE_WCC].OnShow = true;
	}

	if (gProtect.m_MainInfo.CustomStoreEnableCoin2)
	{
		gInterface.DrawGUI(eOFFTRADE_WCP, 338-X, 362);
		gInterface.DrawFormat(eYellow, 309-X, 368, 100, 3, gCustomMessage.GetMessage(59));
		gInterface.Data[eOFFTRADE_WCP].OnShow = true;
	}

	if (gProtect.m_MainInfo.CustomStoreEnableCoin3)
	{
		gInterface.DrawGUI(eOFFTRADE_WCG, 393.5-X, 362);
		gInterface.DrawFormat(eYellow, 364-X, 368, 100, 3, gCustomMessage.GetMessage(60));
		gInterface.Data[eOFFTRADE_WCG].OnShow = true;
	}
	// ----
		

	//if (gInterface.IsWorkZone(eOFFTRADE_OPEN))
	//{
	//	if (gInterface.Data[eOFFTRADE_OPEN].OnClick)
	//	{
	//		gInterface.DrawButton(eOFFTRADE_OPEN, 393-X ,391, 0, 30);
	//	}
	//	else
	//		gInterface.DrawButton(eOFFTRADE_OPEN, 393-X ,391, 0, 90);
	//	
	//	gInterface.DrawToolTip(390-X, 385, "Open Off-Store");
	//}
	//else
	//	gInterface.DrawButton(eOFFTRADE_OPEN, 393-X ,391, 0, 0);


	int ObjectIDs[6] = 
	{ 
		eOFFTRADE_JoB,
		eOFFTRADE_JoS,
		eOFFTRADE_JoC,
		eOFFTRADE_WCC,
		eOFFTRADE_WCP,
		eOFFTRADE_WCG
	};

	for (int i=0; i<6; i++)
	{
		if( gInterface.IsWorkZone(ObjectIDs[i]) && gInterface.Data[ObjectIDs[i]].OnShow)
		{
			DWORD Color = eGray100;
			// ----
			if( gInterface.Data[ObjectIDs[i]].OnClick )
			{
				Color = eGray150;
			}
			// ----
			gInterface.DrawColoredGUI(ObjectIDs[i], gInterface.Data[ObjectIDs[i]].X, gInterface.Data[ObjectIDs[i]].Y, Color);
		}
	}
}
// ----------------------------------------------------------------------------------------------

bool cOffTrade::EventOffTradeWindow_Main(DWORD Event)
{	
	DWORD CurrentTick	= GetTickCount();
	//DWORD Delay			= (CurrentTick - this->Data[eDIABLO_CLOSE].EventTick);
	if (gInterface.CheckWindow(ObjWindow::Store) == false)
	{
		return false;
	}

	int ObjectIDs[6] = 
	{ 
		eOFFTRADE_JoB,
		eOFFTRADE_JoS,
		eOFFTRADE_JoC,
		eOFFTRADE_WCC,
		eOFFTRADE_WCP,
		eOFFTRADE_WCG
	};

	for (int i = 0; i<6; i++)
	{
		if (gInterface.IsWorkZone(ObjectIDs[i]) && gInterface.Data[ObjectIDs[i]].OnShow)
		{
			DWORD Delay			= (CurrentTick - gInterface.Data[ObjectIDs[i]].EventTick);

			if( Event == WM_LBUTTONDOWN )
			{
				gInterface.Data[ObjectIDs[i]].OnClick = true;
				return true;
			}
			// ----
			gInterface.Data[ObjectIDs[i]].OnClick = false;
			// ----
			if( Delay < 500 )
			{
				return false;
			}
			// ----
			gInterface.Data[ObjectIDs[i]].EventTick = GetTickCount();

			CGSendOffTrade(i);
		}
	}

	if (gInterface.IsWorkZone(eOFFTRADE_OPEN))
	{
		if (!gInterface.Data[eOFFTRADE_OPEN].OnShow)
		{
			return false;
		}

		DWORD Delay			= (CurrentTick - gInterface.Data[eOFFTRADE_OPEN].EventTick);

		if( Event == WM_LBUTTONDOWN )
		{
			gInterface.Data[eOFFTRADE_OPEN].OnClick = true;
			return true;
		}
		// ----
		gInterface.Data[eOFFTRADE_OPEN].OnClick = false;
		// ----
		if( Delay < 500 )
		{
			return false;
		}
		// ----
		gInterface.Data[eOFFTRADE_OPEN].EventTick = GetTickCount();
		CGSendOffTrade(6);
	}
	return false;
}
// ----------------------------------------------------------------------------------------------

void cOffTrade::CGSendOffTrade(int Type)
{
	PMSG_OFFTRADE_SEND pMsg;
	pMsg.header.set(0xF3, 0xEB, sizeof(pMsg));
	pMsg.Type = Type;
	DataSend((BYTE*)&pMsg,pMsg.header.size);
}

void cOffTrade::RecvPShop(PMSG_OFFTRADE_RECV *Data)
{
		this->ShopList		= 1;
		this->TypeShop		= Data->Type;
}

void cOffTrade::PShopActiveRecv(PMSG_SHOPACTIVE_RECV *Data)
{
		this->ShopActive	= Data->Active;
		this->TypeShop		= Data->Type;
}
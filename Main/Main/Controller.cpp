#include "stdafx.h"
#include "Controller.h"
#include "CustomCommandInfo.h"
#include "CustomEventTime.h"
#include "CustomRanking.h"
#include "Defines.h"
#include "CustomInterface.h"
#include "OffTrade.h"
#include "Protocol.h"
#include "Import.h"
#include "Interface.h"
// ----------------------------------------------------------------------------------------------

Controller	gController;
// ----------------------------------------------------------------------------------------------

bool Controller::Load()
{
	if( !this->MouseHook )
	{
		this->MouseHook = SetWindowsHookEx(WH_MOUSE, this->Mouse, gController.Instance, GetCurrentThreadId());
		// ----
		if( !this->MouseHook )
		{
			return false;
		}
	}
	// ----
	if( !this->KeyboardHook )
	{
		//this->KeyboardHook = SetWindowsHookEx(WH_KEYBOARD_LL, this->Keyboard, NULL, NULL);
		//// ----
		//if( !this->KeyboardHook )
		//{
		//	return false;
		//}
	}
	// ----
	return true;
}
// ----------------------------------------------------------------------------------------------

LRESULT Controller::Mouse(int Code, WPARAM wParam, LPARAM lParam)
{
	if( GetForegroundWindow() != pGameWindow )
	{
		return CallNextHookEx(gController.MouseHook, Code, wParam, lParam);
	}
	// ----
	MOUSEHOOKSTRUCTEX * Mouse	= (MOUSEHOOKSTRUCTEX*)lParam;
	// ----
	//gCamera.Run(Mouse, wParam);
	// ----
	switch(wParam)
	{
	case WM_LBUTTONUP:
	case WM_LBUTTONDOWN:
		{
			gCustomRanking.EventRankingNext(wParam);
			gCustomRanking.EventRankingBack(wParam);
			gInterface.EventVipWindow_Main(wParam);
			gCustomRanking.EventVipWindow_Close(wParam);
			gCustomCommandInfo.EventCommandWindow_Close(wParam);
			gCustomCommandInfo.CommandNext(wParam);
			gCustomCommandInfo.CommandPrev(wParam);
			gCustomEventTime.EventEventTimeWindow_Close(wParam);
			gCustomEventTime.EventNext(wParam);
			gCustomEventTime.EventPrev(wParam);
			gInterface.EventDrawMenu_Open(wParam);
			gInterface.EventDrawMenu_Close(wParam);
			gInterface.EventDrawMenu_Op1(wParam);
			gInterface.EventDrawMenu_Op2(wParam);
			gInterface.EventDrawMenu_Op3(wParam);
			gInterface.EventDrawMenu_Op4(wParam);
			gInterface.EventDrawMenu_Op20(wParam);
			gInterface.EventConfirm_CANCEL(wParam);
			gInterface.EventConfirm_OK(wParam);
			gCustomInterface.EventNewInterface_All(wParam);
			gOffTrade.EventOffTradeWindow_Main(wParam);
		}
		
		break;
	}
	// ----
	return CallNextHookEx(gController.MouseHook, Code, wParam, lParam);
}
// ----------------------------------------------------------------------------------------------

LRESULT Controller::Keyboard(int Code, WPARAM wParam, LPARAM lParam)
{
	if( GetForegroundWindow() != pGameWindow )
	{
		return CallNextHookEx(gController.KeyboardHook, Code, wParam, lParam);
	}

	if (Code < 0) return CallNextHookEx(gController.KeyboardHook, Code, wParam, lParam);
	
	if( (Code == HC_ACTION) && (wParam == WM_KEYDOWN))
	{
		KBDLLHOOKSTRUCT Hook = *((KBDLLHOOKSTRUCT*)lParam);
		switch(Hook.vkCode)
		{
			// --
		case VK_F8:
		{
			gCustomRanking.OpenWindow();
		}
		break;	
		case 0x48:
		{
			gCustomEventTime.OpenWindow();
		}
		break;
		case VK_ESCAPE:
		{

			if (gInterface.Data[eCommand_MAIN].OnShow == true)
			{
				gInterface.Data[eCommand_MAIN].OnShow = false;
				pSetCursorFocus = false;
				return -1;
			}

			if (gInterface.Data[eRankPANEL_MAIN].OnShow == true)
			{
				gInterface.Data[eRankPANEL_MAIN].OnShow = false;
				pSetCursorFocus = false;
				return -1;
			}

			if (gInterface.Data[eEventTimePANEL_MAIN].OnShow == true)
			{
				gInterface.Data[eEventTimePANEL_MAIN].OnShow = false;
				pSetCursorFocus = false;
				return -1;
			}

			if (gInterface.CheckVipWindow())
			{
				gInterface.CloseVipWindow();
				return -1;
			}

			if (gInterface.CheckMenuWindow())
			{
				gInterface.CloseMenuWindow();
				return -1;
			}
		}
		break;
		case VK_END:
		{
			if (gInterface.CheckVipWindow())
			{
				gInterface.CloseVipWindow();
			}
			else
			{
				gInterface.CloseCustomWindow();
				gInterface.OpenVipWindow();
			}
		}
		break;
		case VK_SNAPSHOT:
		{
			gInterface.Data[eLogo].EventTick = GetTickCount()+1500;
			//gInterface.Data[eLogo].OnShow = true;
			//gInterface.DrawLogo();
			return CallNextHookEx(gController.KeyboardHook, Code, wParam, lParam);
		}
		break;
	//case 0x41: //disable button
	//	{
	//		return 1;
	//	}
	//	break;
		default:
		break;
		}
	} 
	return (LRESULT) NULL;
	
}
// ----------------------------------------------------------------------------------------------

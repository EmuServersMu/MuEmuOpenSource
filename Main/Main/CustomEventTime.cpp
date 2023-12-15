#include "stdafx.h"
#include "CustomEventTime.h"
#include "CustomMessage.h"
#include "Defines.h"
#include "HealthBar.h"
#include "Interface.h"
#include "Util.h"
#include "Object.h"
#include "Import.h"

CCustomEventTime::CCustomEventTime()
{
}

CCustomEventTime gCustomEventTime;

void CCustomEventTime::Load(CUSTOM_EVENT_INFO* info) // OK
{
	for(int n=0;n < MAX_EVENTTIME;n++)
	{
		this->SetInfo(info[n]);
	}
}

void CCustomEventTime::SetInfo(CUSTOM_EVENT_INFO info) // OK
{
	if(info.Index < 0 || info.Index >= MAX_EVENTTIME)
	{
		return;
	}

	this->m_CustomEventInfo[info.Index] = info;
}

void CCustomEventTime::ClearCustomEventTime() // OK
{
	for(int n=0;n < MAX_EVENTTIME;n++)
	{
		gCustomEventTime[n].time = -1;
	}
	this->count				= 0;
	this->EventTimeEnable	= 0;
}

void CCustomEventTime::GCReqEventTime(PMSG_CUSTOM_EVENTTIME_RECV* lpMsg) // OK
{
	this->count = lpMsg->count;

	for(int n=0;n < lpMsg->count;n++)
	{
		CUSTOM_EVENTTIME_DATA* lpInfo = (CUSTOM_EVENTTIME_DATA*)(((BYTE*)lpMsg)+sizeof(PMSG_CUSTOM_EVENTTIME_RECV)+(sizeof(CUSTOM_EVENTTIME_DATA)*n));

		this->gCustomEventTime[n].index = lpInfo->index;
		this->gCustomEventTime[n].time = lpInfo->time;

		if (this->gCustomEventTime[n].index >= 28 && this->gCustomEventTime[n].time != -1) this->Arena = 1;
	}

	this->EventTimeEnable = 1;
}


void CCustomEventTime::DrawEventTimePanelWindow()
{
	if( !gInterface.Data[eEventTimePANEL_MAIN].OnShow )
	{
		return;
	}

	float MainWidth			= 230.0;
	float MainHeight		= 180.0;
	float StartBody			= 80.0;
	float StartY			= 80.0;
	float StartX			= (MAX_WIN_WIDTH / 2) - (MainWidth / 2);
	float MainCenter		= StartX + (MainWidth / 3);
	float ButtonX			= MainCenter - (float)(29.0 / 2);
	// ----
	gInterface.DrawGUI(eEventTime_MAIN, StartX, StartY + (float)2.0);
	gInterface.DrawGUI(eVip_TITLE, StartX, StartY);
	StartY = gInterface.DrawRepeatGUI(eVip_FRAME, StartX, StartY + (float)5.0, 12);
	gInterface.DrawGUI(eVip_FOOTER, StartX, StartY);
	gInterface.DrawGUI(eEventTime_CLOSE, StartX + MainWidth - gInterface.Data[eEventTime_CLOSE].Width, StartBody);
	// ----
	DWORD Color = eGray100;
	if (gInterface.IsWorkZone(eEventTime_CLOSE))
	{
		// ----
		if (gInterface.Data[eEventTime_CLOSE].OnClick)
		{
			Color = eGray150;
		}
		// ----
		gInterface.DrawColoredGUI(eEventTime_CLOSE, gInterface.Data[eEventTime_CLOSE].X, StartBody, Color);
		gInterface.DrawToolTip((int)gInterface.Data[eEventTime_CLOSE].X + 5, (int)gInterface.Data[eEventTime_CLOSE].Y + 25, "Close");
	}

	if ((this->Page == 0) || (this->Page == 1 && this->Arena==1))
	{
		gInterface.DrawGUI(eNextEvent, StartX + MainWidth - 38, 150);
	}
	else 
	{
		gInterface.ResetDrawIMG(eNextEvent);
	}

	if (this->Page == 1 || this->Page == 2)
	{
		gInterface.DrawGUI(ePrevEvent, StartX + 10, 150);
	}
	else
	{
		gInterface.ResetDrawIMG(ePrevEvent);
	}

	gInterface.DrawFormat(eGold, (int)StartX + 10, (int)StartBody + 10, 210, 3, "Events");

	if (this->EventTimeEnable == 1)
	{

		gInterface.DrawFormat(eGold,  StartX + 60, StartBody + 37, 52, 1,"Event:");

		gInterface.DrawFormat(eGold,  StartX + 145, StartBody + 37, 52, 1,"Time:");

		if((GetTickCount()-this->EventTimeTickCount) > 1000)
		{
			for (int i=0; i < this->count; i++)
			{
				if (this->gCustomEventTime[i].time > 0)
				{
					this->gCustomEventTime[i].time = this->gCustomEventTime[i].time-1;
				}
			}
			this->EventTimeTickCount = GetTickCount();
		}

		char text1[20];
		char text2[30];
		int totalseconds;
		int hours;
		int minutes;
		int seconds;
		int days;

		int line = 0;

		for( int i = (14*Page)+0; i < (14*Page)+14; i++ )
		{
			if (this->gCustomEventTime[i].time <= -1)
			{
				//wsprintf(text2, "Disabled");
				continue;
			}
			else if (this->gCustomEventTime[i].time == 0)
			{
				wsprintf(text2, "Online");
			}
			else
			{
				totalseconds	= this->gCustomEventTime[i].time;
				hours			= totalseconds/3600;
				minutes			= (totalseconds/60) % 60;  
				seconds			= totalseconds % 60;
				wsprintf(text2, "%02d:%02d:%02d", hours, minutes, seconds);

				if (hours > 23)
				{
					days = hours/24;
					wsprintf(text2, "%d day(s)+", days);
				}
				else
				{
					wsprintf(text2, "%02d:%02d:%02d", hours, minutes, seconds);
				}
			}
	
			if (this->gCustomEventTime[i].time <= -1)
			{
				Color = eRed2;
			}
			else if (this->gCustomEventTime[i].time == 0)
			{
				Color = eExcellent;
			}
			else if (this->gCustomEventTime[i].time < 300)
			{
				Color = eExcellent;
			}
			else
			{
				Color = eYellow;
			}


			gInterface.DrawFormat(eWhite,  StartX + 60, StartBody + 55 + (line), 52, 1,this->m_CustomEventInfo[i].Name);

			gInterface.DrawFormat(Color,  StartX + 145, StartBody + 55 + (line), 52, 1,text2);

			gInterface.DrawFormat(eGray100,  StartX + 64, StartBody + 55 + (line) + 2, 110, 1,"_________________________________");
			
			line += 12;
		}
	}
	else 
	{
		if (this->EventTimeLoad == 1)
		{
			gInterface.DrawFormat(eGold, MainCenter + 20, StartBody + 100, 52, 1,"Loading ..");
			this->EventTimeLoad = 2;
		}
		else if(this->EventTimeLoad == 2)
		{
			gInterface.DrawFormat(eGold, MainCenter + 20, StartBody + 100, 52, 1,"Loading ...");
			this->EventTimeLoad = 3;
		}
		else if(this->EventTimeLoad == 3)
		{
			gInterface.DrawFormat(eGold, MainCenter + 20, StartBody + 100, 52, 1,"Loading ....");
			this->EventTimeLoad = 4;
		}
		else if(this->EventTimeLoad == 4)
		{
			gInterface.DrawFormat(eGold, MainCenter + 20, StartBody + 100, 52, 1,"Loading .....");
			this->EventTimeLoad = 0;
		}
		else
		{
			gInterface.DrawFormat(eGold, MainCenter + 20, StartBody + 100, 52, 1,"Loading .");
			this->EventTimeLoad = 1;
		}
	}

}
bool CCustomEventTime::EventEventTimeWindow_Close(DWORD Event)
{
	DWORD CurrentTick = GetTickCount();
	DWORD Delay = (CurrentTick - gInterface.Data[eEventTime_CLOSE].EventTick);
	// ----
	if (!gInterface.Data[eEventTimePANEL_MAIN].OnShow || !gInterface.IsWorkZone(eEventTime_CLOSE))
	{
		return false;
	}
	// ----
	if (Event == WM_LBUTTONDOWN)
	{
		gInterface.Data[eEventTime_CLOSE].OnClick = true;
		return true;
	}
	// ----
	gInterface.Data[eEventTime_CLOSE].OnClick = false;
	// ----
	if (Delay < 500)
	{
		return false;
	}
	// ----
	gInterface.Data[eEventTime_CLOSE].EventTick = GetTickCount();
	gInterface.Data[eEventTimePANEL_MAIN].OnShow = false;
	pSetCursorFocus = false;
	// ----
	return false;
}

void CCustomEventTime::OpenWindow()
{

	if (gInterface.CheckWindow(ObjWindow::CreateGuild) || gInterface.CheckWindow(ObjWindow::ChatWindow) || gInterface.CheckWindow(ObjWindow::FriendList) || gInterface.CheckWindow(ObjWindow::NPC_Dialog) || gInterface.CheckWindow(ObjWindow::MuHelper) || gInterface.CheckWindow(ObjWindow::Store)  || gInterface.CheckWindow(ObjWindow::Warehouse) || gInterface.CheckWindow(ObjWindow::Trade) || gInterface.CheckWindow(ObjWindow::CashShop))
	{
		return;
	}

	if((GetTickCount() - gInterface.Data[eEventTimePANEL_MAIN].EventTick) < 1000 )
	{
		//gInterface.Data[eEventTimePANEL_MAIN].OnShow = false;
		return;
	}

	gInterface.Data[eEventTimePANEL_MAIN].EventTick = GetTickCount();


	if (gInterface.Data[eEventTimePANEL_MAIN].OnShow == true)
	{
		gInterface.Data[eEventTimePANEL_MAIN].OnShow = false;
		pSetCursorFocus = false;
		return;
	}

	gInterface.CloseCustomWindow();

	this->ClearCustomEventTime();

	PMSG_CUSTOM_EVENTTIME_SEND pMsg;

	pMsg.header.set(0xF3, 0xE8,sizeof(pMsg));

	DataSend((BYTE*)&pMsg,pMsg.header.size);

	//gInterface.Data[eEventTimePANEL_MAIN].EventTick = GetTickCount();
	gInterface.Data[eEventTimePANEL_MAIN].OnShow = true;
	pSetCursorFocus = true;

}


bool CCustomEventTime::EventNext(DWORD Event)
{
	DWORD CurrentTick	= GetTickCount();
	DWORD Delay			= (CurrentTick - gInterface.Data[eNextEvent].EventTick);
	DWORD Delay2		= (CurrentTick - gInterface.Data[ePrevEvent].EventTick);

	if( !gInterface.Data[eEventTimePANEL_MAIN].OnShow )
	{
		return false;
	}
	
	if( !gInterface.IsWorkZone(eNextEvent) )
	{
		return false;
	}

	if( Event == WM_LBUTTONDOWN )
	{
		gInterface.Data[eNextEvent].OnClick = true;
		return true;
	}

	if( Delay < 100 || Delay2 < 100 )
	{
		return false;
	}
	
	gInterface.Data[eNextEvent].OnClick = false;
	
	this->Page++;
	
	gInterface.Data[eNextEvent].EventTick = GetTickCount();
	

	return true;
}

bool CCustomEventTime::EventPrev(DWORD Event)
{
	DWORD CurrentTick	= GetTickCount();
	DWORD Delay			= (CurrentTick - gInterface.Data[ePrevEvent].EventTick);
	DWORD Delay2		= (CurrentTick - gInterface.Data[eNextEvent].EventTick);

	if( !gInterface.Data[eEventTimePANEL_MAIN].OnShow )
	{
		return false;
	}
	
	if( !gInterface.IsWorkZone(ePrevEvent) )
	{
		return false;
	}

	if( Event == WM_LBUTTONDOWN )
	{
		gInterface.Data[ePrevEvent].OnClick = true;
		return true;
	}

	if( Delay < 100 || Delay2 < 100 )
	{
		return false;
	}
	
	gInterface.Data[ePrevEvent].OnClick = false;
	
	gInterface.Data[ePrevEvent].EventTick = GetTickCount();

	this->Page--;
	
	return true;
}


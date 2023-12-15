#include "StdAfx.h"
#include "CustomPing.h"
#include "Common.h"
#include "Defines.h"
#include "Interface.h"
#include "Protect.h"
#include "Protocol.h"
#include "Util.h"
// -------------------------------------------------------------------------------

CCustomPing gCustomPing;
// -------------------------------------------------------------------------------

CCustomPing::CCustomPing()
{
	this->PingDelaySend		= GetTickCount();
	this->PingDelaySend		= 0;
	this->PingDelayRecv		= -1;
	this->RealPingDelaySend = 0;
	this->RealPingDelayRecv = -1;
	this->m_fpscount		= 0;
	this->m_fps				= 0;
	this->TickCount			= GetTickCount();
	this->PingStart			= 0;
}
// -------------------------------------------------------------------------------

CCustomPing::~CCustomPing()
{
	// ----
}

void CCustomPing::ShowPing()
{

	if (gInterface.MiniMapCheck() || gInterface.CombinedChecks())
	{
		return;
	}

	if ((int)this->RealPingDelayRecv >= 0)
	{
		pSetBlend(1);
		glColor4f(0.0, 0.0, 0.0, 0.8);
		pDrawBarForm((float)490, (float)0, 150.0f, 15.0f, 0.0f, 0);
		pGLSwitchBlend();
		pGLSwitch();
		glColor4f(1.0, 1.0, 1.0, 1.0);

		pSetBlend(1);

		DWORD elapsed = GetTickCount()-this->TickCount;

        this->m_fpscount++;

        // one second elapsed? (= 1000 milliseconds)
        if (elapsed > 1000)
        {
            // save the current counter value to m_fps
            this->m_fps         = m_fpscount;
            // reset the counter and the interval
            this->m_fpscount    = 0;
			// set tick count
			this->TickCount = GetTickCount();
        }

		gInterface.DrawFormat(eGold, 500, 4, 100, 1, "RTT: %d ms", this->RealPingDelayRecv);

		gInterface.DrawFormat(eGold, 550, 4, 100, 1, "PING: %d ms", this->PingDelayRecv);

		gInterface.DrawFormat(eGold, 600, 4, 100, 1, "FPS: %d", this->m_fps);
	

	}
}

void CCustomPing::PingRecv()
{
	this->RealPingDelayRecv = (GetTickCount()-this->RealPingDelaySend)+1;
}

void CCustomPing::PingSend()
{

	this->RealPingDelaySend = GetTickCount();

	PMSG_PING_SEND lpMsg;

	lpMsg.header.set(0xF3,0xF1, sizeof(lpMsg));

	DataSend((LPBYTE)&lpMsg, lpMsg.header.size);
	
}

void PingTest(LPVOID lpThreadParameter)
{
	while ( TRUE )
	{
		gCustomPing.PingSend();

		SOCKET m_socket;

		m_socket = socket(PF_INET,SOCK_STREAM,0);

		if(m_socket == INVALID_SOCKET)
		{
			return;
		}

		SOCKADDR_IN target;

		target.sin_family = AF_INET;
		target.sin_port = htons(gProtect.m_MainInfo.IpAddressPort);
		target.sin_addr.s_addr = inet_addr(gProtect.m_MainInfo.IpAddress);

		if(target.sin_addr.s_addr == INADDR_NONE)
		{
			HOSTENT* host = gethostbyname(gProtect.m_MainInfo.IpAddress);

			if(host != 0)
			{
				memcpy(&target.sin_addr.s_addr,(*host->h_addr_list),host->h_length);
			}
		}

		gCustomPing.PingDelaySend = GetTickCount();

		if(connect(m_socket,(SOCKADDR*)&target,sizeof(target)) != SOCKET_ERROR)
		{
			gCustomPing.PingDelayRecv = GetTickCount()-gCustomPing.PingDelaySend+1;

			Sleep(100);

			closesocket(m_socket);
			m_socket == INVALID_SOCKET;
		}

		Sleep(5000);
			//char* msg = "C1";
			//int result = send(m_socket, msg, strlen(msg), 0);
	}
}

void CCustomPing::StartPing()
{
	if( this->PingStart == 1)
		return;

	if(gProtect.m_MainInfo.PingTest == 1)
	{
		if(DisablePing != 1)
		{
			CreateThread(0, 0, (LPTHREAD_START_ROUTINE)PingTest, 0, 0, 0);
		}
	}
	this->PingStart = 1;
}
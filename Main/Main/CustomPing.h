#pragma once
// -------------------------------------------------------------------------------

#include "Protocol.h"
#include <Ipexport.h>
// -------------------------------------------------------------------------------

struct PMSG_PING_SEND
{
	PSBMSG_HEAD header; // C1:F3:F1
	DWORD time;
};
// -------------------------------------------------------------------------------

class CCustomPing
{
public:
	CCustomPing();
	~CCustomPing();
	void ShowPing();
	void PingRecv(); 
	void PingSend();
	void StartPing();
public:
	DWORD PingDelay;
	DWORD PingDelaySend;
	DWORD PingDelayRecv;
	DWORD RealPingDelaySend;
	DWORD RealPingDelayRecv;
private:
	unsigned int m_fps;
    unsigned int m_fpscount;
	DWORD TickCount;
	int PingStart;
	// ----
}; extern CCustomPing gCustomPing;
// -------------------------------------------------------------------------------
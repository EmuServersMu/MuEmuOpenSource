#include "stdafx.h"
#include "DSProtocol.h"
#include "Util.h"
#include "Message.h"
#include "User.h"
#include "Path.h"
#include "ServerInfo.h"
#include "MemScript.h"
#include "RuneEffect.h"
#include "Notice.h"

RuneEffect gRuneEffect;

void RuneEffect::GCRuneEffect(int aIndex, int aTargetIndex)
{
	if (gObjIsConnected(aIndex) == false || gObj[aTargetIndex].IsBot >= 1)
	{
		return;
	}
	// ---
	PMSG_CUSTOM_RUNEEFFECT pMsg = { 0 };
	// ---
	pMsg.h.set(0xF3, 0xEF, sizeof(pMsg));
	// ---
	// ---
	pMsg.iReset = gObj[aTargetIndex].Reset;
	pMsg.iMReset = gObj[aTargetIndex].MasterReset;
	pMsg.iLevel = gObj[aTargetIndex].Level;
	pMsg.iIndex = aTargetIndex;
	pMsg.cVip = gObj[aTargetIndex].AccountLevel;
	pMsg.cGM = gObj[aTargetIndex].Authority;
	pMsg.cPK = gObj[aTargetIndex].PKLevel;
	// ---
	DataSend(aIndex, (LPBYTE)&pMsg, pMsg.h.size);
	DataSend(aTargetIndex, (LPBYTE)&pMsg, pMsg.h.size); 
}
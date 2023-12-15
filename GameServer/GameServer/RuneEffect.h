#pragma once

#include "Protocol.h"

struct PMSG_CUSTOM_RUNEEFFECT
{
	PSBMSG_HEAD h;
	int iIndex;
	int iLevel;
	int iReset;
	int iMReset;
	int cVip;
	int cGM;
	int cPK;
};
// ---
class RuneEffect
{
public:
	//void Load(char* path);
	void GCRuneEffect(int aIndex, int aTargetIndex);

private:
	int m_count;
};
extern RuneEffect gRuneEffect;
// ---
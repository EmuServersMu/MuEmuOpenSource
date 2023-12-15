#include "StdAfx.h"
#if MENSAGE_ERROR
#include "Util.h"
#include "MessageBox.h"

MessageBoxPopUp gMessageBoxPopUp;

void PopUpErrorCheckMsgBox(const char* szErrorMsg, bool bForceDestroy)
{
	MessageBox(NULL, szErrorMsg, NULL,MB_OK);
	SendMessage(NULL, WM_DESTROY, 0, 0);
}

void MessageBoxPopUp::InitPopUp()
{
	
	SetCompleteHook(0xE8, 0x00614AEF, &PopUpErrorCheckMsgBox);//-- open texture model
	SetCompleteHook(0xE8, 0x00772460, &PopUpErrorCheckMsgBox);//-- open texture
}
#endif
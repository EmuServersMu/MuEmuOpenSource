#pragma once

typedef unsigned __int64 QWORD;

#define WIN32_LEAN_AND_MEAN

#define _WIN32_WINNT _WIN32_WINNT_WINXP

// System Include
#include <windows.h>
#include <iostream>
#include <map>
#include <math.h>
#include <stdlib.h>
#include <winsock2.h>
#include <Mmsystem.h>
#include <time.h>
#include <gl\GL.h>
#include "detours.h"

#pragma comment(lib,"ws2_32.lib")
#pragma comment(lib,"Winmm.lib")
#pragma comment(lib,"Opengl32.lib")
#pragma comment(lib,"detours.lib")

#ifndef GAMESERVER_PREMIUM
#define GAMESERVER_PREMIUM 1
#endif

#if(GAMESERVER_PREMIUM==1)
#define MAX_CUSTOM_WING 100
#define MAX_DYNAMIC_WING_EFFECT 3000
#define MAX_CUSTOM_WING_EFFECT 3000
#else
#define MAX_CUSTOM_WING 20
#define MAX_DYNAMIC_WING_EFFECT 50
#define MAX_CUSTOM_WING_EFFECT 300
#endif

/*==========================================================================================================================*/

#define MU_ERROR                1 // 1 - ON | 0 - OFF
#define CTRL_FREEZE				1 // 1 - ON | 0 - OFF
#define FIX_1                   1 // 1 - ON | 0 - OFF
#define COPY_RIGHT              1 // 1 - ON | 0 - OFF
#define ANTI_CRACK_MAIN         1 // 1 - ON | 0 - OFF
#define FIX_LAG                 1 // 1 - ON | 0 - OFF
#define FIX_MONTER_TRABE		1 // 1 - ON | 0 - OFF
#define SERVER_NAME             1 // 1 - ON | 0 - OFF
#define REDUCE_MEMORY           1 // 1 - ON | 0 - OFF
#define REMOVE_CLASS            1 // 1 - ON | 0 - OFF
#define ANTIHACK                1 // 1 - ON | 0 - OFF

/*==========================================================================================================================*/

#define LIMITE_FPS              1 // 1 - ON | 0 - OFF
#define SELEC_CHAR_X700         1 // 1 - ON | 0 - OFF
#define DISABLE_BOTON           1 // 1 - ON | 0 - OFF
#define CHATATEC_ANIMATE        1 // 1 - ON | 0 - OFF
#define MENSAGE_ERROR           1 // 1 - ON | 0 - OFF
#define SKYBOX                  1 // 1 - ON | 0 - OFF
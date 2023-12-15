#pragma once

void InitCommon();
BOOL CheckIsLuckyItem(int ItemID);
BOOL CheckGensBattleMap(int map);
BOOL CheckGensMoveIndex(int idx);
void LoginTab();
void CheckMasterLevel();
void CompareGensMoveIndex();
void DrawEffectsPic(int &EffectID, float StartX, float StartY, float StartWidth, float StartHeight );

#if COPY_RIGHT
void Copyright();           
#endif

extern BYTE GensBattleMapCount;
extern BYTE GensMoveIndexCount;
extern BYTE GensBattleMap[120];
extern BYTE GensMoveIndex[120];

extern int DisableStaticEffect;
extern int DisableDynamicEffect;
extern int DisableSkillEffect;
extern int DisableGlowEffect;
extern int Anisotropy;
extern int MaxAnisotropy;
extern int Linear;
extern int GMT;
extern int Fog;
extern int Tron;
extern int MiniMap;
extern int MiniMapActive;
extern int DisablePing;

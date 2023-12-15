#pragma once

#define MAX_CUSTOM_GLOVES	20

struct CUSTOM_RF_GLOVES
{
	int Index;
	int ItemIndex;
	char ModelName[32];
	int TextureLeftIndex;
	char TextureLeftName[32];
	int TextureRightIndex;
	char TextureRightName[32];
	int ColorR;
	int ColorG;
	int ColorB;
};

class cCustomGloves
{
public:
	cCustomGloves();
	virtual ~cCustomGloves();
	void Init();
	void Load();
	void Load(CUSTOM_RF_GLOVES* info);
	void SetInfo(CUSTOM_RF_GLOVES info);
	CUSTOM_RF_GLOVES* GetInfoByItem(int index);
	CUSTOM_RF_GLOVES* GetInfoByRD(int index);
	bool GetCustomItemColor(int ItemIndex,float* ItemColor);
	void AssocGloves(char* This);
	bool CheckGloves(int ItemID);
	static void GlovesAssoc(char *This);
	static void BattleGloveGlow();
	static void BattleGlovePos();
	static void BattleGloveSize();
	static void DrawItemModel(float PosX, float PosY, float Width, float Height, int ItemID, int Level, int Excl, int Anc, bool OnMouse);
public:
	CUSTOM_RF_GLOVES m_CustomGlovesInfo[MAX_CUSTOM_GLOVES];
}; extern cCustomGloves gCustomGloves;
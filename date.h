#pragma once

#include "game.h"

#define CSV_LOAD_ERR_TITLE TEXT("CSV読み込みエラー")
#define CSV_DATANUM_ERR_TITLE TEXT("CSVデータ数エラー")

#define CSV_PATH  TEXT(".\\date\\enemy.csv")

#define CSV_CHARA_FORMAT TEXT("%d,%[^,],%d,%d,%d,%d,%d,%d")

#define ENEMY_MAX 5

struct CHARA_DATA
{
	int No;
	char Name[STR_MAX];

	int HP;
	int ATK;
	int DEF;

	int MAX_HP;
	int MAX_ATK;
	int MAX_DEF;
};

extern CHARA_DATA enemy[ENEMY_MAX];

extern BOOL LoadCSVChara(const char* path, CHARA_DATA* chara, int DataMox, BOOL IsHeader);

#include"game.h"
#include"date.h"
#include"shape.h"

CHARA_DATA enemy[ENEMY_MAX];

BOOL LoadCSVChara(const char* path, CHARA_DATA* chara, int DataMax, BOOL IsHeader = FALSE)
{
	FILE = fp;
	char GetChar = '\0';
	int LoopCnt = 0;
	errno_t FileErr = NULL;
	int IsEOF = NULL;

	FileErr = fopen_s(&fp, path, "r");
	if (FileErr != NULL)
	{
		MessageBox(GetMainWindowHandle(), path, CSV_LOAD_ERR_TITLE, MB_OK);
		return FALSE;
	}

	if (IsHeader == TRUE)
	{
		while (GetChar != '\n') { GetChar = fgetc(fp); }
	}

	while (IsEOF != EOF)
	{
		IsEOF = fscanf_s(
			fp,
			CSV_CHARA_FORMAT,
			&(chara + LoopCnt)->No,
			&(chara + LoopCnt)->Name[0], STR_MAX,
			&(chara + LoopCnt)->HP,
			&(chara + LoopCnt)->ATK,
			&(chara + LoopCnt)->DEF,
			&(chara + LoopCnt)->MAX_HP,
			&(chara + LoopCnt)->MAX_ATK,
			&(chara + LoopCnt)->MAX_DEF
		);

		LoopCnt++;
	}

	if (LoopCnt - 1 != DataMax)
	{
		MessageBox(GetMainWindowHandle(), path, CSV_DATANUM_ERR_TITLE, MB_OK);
		return FALSE;
	}
	fclose(fp);

	return TRUE;
}
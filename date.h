//◎Data系のヘッダファイル
#pragma once

//########## ヘッダーファイル読み込み ##########

//ゲームのメインヘッダファイル
#include	"game.h"

//########## マクロ定義 ##########

//エラーメッセージ
#define CSV_LOAD_ERR_TITLE		TEXT("CSV読み込みエラー")
#define CSV_DATANUM_ERR_TITLE	TEXT("CSVデータ数エラー")

//キャラデータのパス
#define CSV_PATH_ENEMY		TEXT(".\\date\\enemy.csv")	//ANSIの文字コードでファイル保存

//データの書式指定子
//キャラクタの書式指定子（%[^,]は文字列）
#define CSV_CHARA_FORMAT	TEXT("%d,%[^,],%d,%d,%d,%d,%d,%d")

//敵データ
#define ENEMY_MAX	5

//エラーメッセージ
#define SCORE_CREATE_ERR_TITLE	TEXT("スコアデータ作成エラー")
#define SCORE_LOAD_ERR_TITLE	TEXT("スコアデータ読込エラー")
#define SCORE_CREATE_TITLE		TEXT("スコアデータ作成OK!!")
#define SCORE_SAVE_TITLE		TEXT("スコアデータ保存OK!!")
#define SCORE_DELETE_TITLE		TEXT("スコアデータ削除OK!!")
#define SCORE_DELETE_ERR_TITLE	TEXT("スコアデータ削除エラー")

//スコアデータのパス（あえて拡張子をヘンなのにすることで、スコアデータと思われにくい！？）
#define SCORE_DATA_PATH		TEXT(".\\date\\gm.asd")	//ANSIの文字コードでファイル保存

//データの書式指定子
#define SCORE_DATA_FORMAT	TEXT("%[^,],%d,%[^,],%d,%[^,],%d")	//スコアデータの書式指定子（%[^,]は文字列）

//キャラデータ構造体(あくまでサンプル)
struct CHARA_DATA
{
	int No;					//No
	char Name[STR_MAX];		//名前

	//実際に使う値
	int HP;					//HP
	int ATK;				//攻撃力
	int DEF;				//防御力

	//最大値
	int MAX_HP;				//HP
	int MAX_ATK;			//攻撃力
	int MAX_DEF;			//防御力
};

//スコアデータ構造体(あくまでサンプル)
struct SCORE_DATA
{
	char path[PATH_MAX];	//パス
	char Name1[STR_MAX];	//名前１
	int Score1;				//スコア１
	char Name2[STR_MAX];	//名前２
	int Score2;				//スコア２
	char Name3[STR_MAX];	//名前３
	int Score3;				//スコア３
};

//########## 外部のグローバル変数 ##########
extern CHARA_DATA enemy[ENEMY_MAX];		//敵データ
extern SCORE_DATA score_data;			//スコアデータ
extern SCORE_DATA score_dataInit;		//スコアデータ(初期化用)

//########## プロトタイプ宣言 ##########
//※extern は、外部に関数がありますよ！という目印でつけています。

extern BOOL LoadCSVChara(const char* path, CHARA_DATA* chara, int DataMax, BOOL IsHeader);
extern BOOL LoadScoreData(const char* path, SCORE_DATA* score, BOOL IsHeader);

extern BOOL CreateScoreData(VOID);
extern BOOL SaveScoreData(VOID);
extern BOOL DeleteScoreData(VOID);
extern const char* GetScoreDataPath(VOID);
extern VOID SetScoreDataPath(const char* path);
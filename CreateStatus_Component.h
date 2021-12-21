#pragma once
#include"pch.h"
#include"Input.h"
#include"Component.h"
#include"Status.h"

class CreateStatus:public Component
{
public:
	CreateStatus();
	~CreateStatus();
	void Start();
	void Update();
	void Draw(DblBuffer& db);
	void setStatusMap(Status TmpS);
	void Initialize_Variable();
	bool Get_IsCreateData() { return  isCreateData; };
	enum ChoiseState
	{
		choiseStatus,//選択
		InputStatus,//割り振り
		Confimation,//確認
	};
private:
	ChoiseState mState;			  //状態
	Status mStatus[3] = { {"1",1,1,1,1,1,1,} ,
						  {"2",1,1,1,1,1,1,},
						  {"3",1,1,1,1,1,1,} };				  //割り振り後渡すステータス
	Party_Status Party_s;
	int CursolPosY = 0;			  //カーソルの位置
	int CursolPosX = 0;			  //カーソルの位置
	Input input;				  //入力用
	map<int, int> CursolAndStatus;//選択した際の確認用マップ
	map<int, string> CursolAndStatusName;//選択した際の確認用マップ
	int BeforeState=NULL ;

	//残りポイント
	int StatusPoint = 100;
	const int StatusPointMax = 100;

	int _1stNum=0;
	int _2stNum = 0;
	int StatusPointTest = 0;

	int party_s_num = 0;
	bool isCreateData=false;
};


#pragma once
#include"pch.h"
#include"Input.h"
#include"Component.h"
#include"Status_Component.h"
class CreateStatus:public Component
{
public:
	CreateStatus();
	~CreateStatus();
	void Start();
	void Update();
	void Draw(DblBuffer& db);
	Status PathStatus();
	enum ChoiseState
	{
		choiseStatus,//選択
		InputStatus,//割り振り
		Confimation,//確認
	};
private:
	ChoiseState mState;			  //状態
	Status mStatus;				  //割り振り後渡すステータス
	int CursolPosY = 0;			  //カーソルの位置
	Input input;				  //入力用
	map<int, int> CursolAndStatus;//選択した際の確認用マップ
	map<int, string> CursolAndStatusName;//選択した際の確認用マップ
	int BeforeState=NULL ;

	//残りポイント
	int StatusPoint = 100;
	const int StatusPointMax = 100;
};


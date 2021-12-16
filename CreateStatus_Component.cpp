#include "pch.h"
#include "CreateStatus_Component.h"


CreateStatus::CreateStatus()
	:BeforeState(choiseStatus)
	,mState(choiseStatus)
{
	CursolAndStatus[0] = mStatus.HP ;
	CursolAndStatus[1] = mStatus.MP ;
	CursolAndStatus[2] = mStatus.ATK;
	CursolAndStatus[3] = mStatus.DFP;
	CursolAndStatus[4] = mStatus.AGI;
	CursolAndStatusName[0] = "HP ";
	CursolAndStatusName[1] = "MP ";
	CursolAndStatusName[2] = "ATK";
	CursolAndStatusName[3] = "DFP";
	CursolAndStatusName[4] = "AGI";

}

CreateStatus::~CreateStatus()
{

}

void CreateStatus::Start()
{

}

void CreateStatus::Update()
{
	BeforeState = mState;
	if (mState==ChoiseState::choiseStatus)
	{
		if (input.isKeyPressed(VK_UP))
		{
			CursolPosY--;
			if (CursolPosY < 0)
			{
				CursolPosY = 0;
			}
		}
		if (input.isKeyPressed(VK_DOWN))
		{
			CursolPosY++;
			if (CursolPosY > 4)
			{
				CursolPosY = 4;
			}
		}
		if (input.isKeyPressed(VK_RETURN))
		{
			mState = InputStatus;
		}
		Sleep(50);
	}
	if (mState == ChoiseState::InputStatus)
	{

	}
	if (mState == ChoiseState::Confimation)
	{

	}
}

void CreateStatus::Draw(DblBuffer& db)
{
	if (BeforeState!=mState)
	{
		db.Clear();
	}
	if (mState == ChoiseState::choiseStatus)
	{
		db.SetAndWrite(0, 0, "ステータスを作成してください");
		db.SetAndWrite(0, 15, CursolPosY);
		db.SetAndWriteAndNum(0, 2, "HP  :",&mStatus.HP);
		db.SetAndWriteAndNum(0, 3, "MP  :", &mStatus.MP);
		db.SetAndWriteAndNum(0, 4, "ATK :",&mStatus.ATK);
		db.SetAndWriteAndNum(0, 5, "DFP :",&mStatus.DFP);
		db.SetAndWriteAndNum(0, 6, "AGI :",&mStatus.AGI);
		for (int i = 0; i < 5; i++)
		{
			if (CursolPosY == i)
			{
				continue;
			}
			db.SetAndWrite(6, i + 2, " ");
		}
		db.SetAndWrite(6, CursolPosY + 2, "<");
	}
	if (mState == ChoiseState::InputStatus)
	{
		string str = CursolAndStatusName[CursolPosY]+"  :";
		db.SetAndWrite(0, 0, "割り振るポイントを入力して下さい");
		db.SetAndWriteAndNum(0, 2, str, &CursolAndStatus[CursolPosY]);
		
		db.SetAndWriteAndNum(0, 5, "残りポイント  :" ,&StatusPoint);
		db.setCursorPos(0, 6);
		int tmpPoint;
		cin >> tmpPoint;


	}
	if (mState == ChoiseState::Confimation)
	{

	}
}

Status CreateStatus::PathStatus()
{
	return mStatus;
}

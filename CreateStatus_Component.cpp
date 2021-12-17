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
			if (CursolPosY > 6)
			{
				CursolPosY = 6;
			}
		}
		if (input.isKeyPressed(VK_RETURN))
		{
			if (CursolPosY < 5)
			{
				mState = InputStatus;
				return;
			}
			
		}
		Sleep(50);
	}
	if (mState == ChoiseState::InputStatus)
	{
		if (input.isKeyPressed(VK_UP))
		{
			if (CursolPosX==1)
			{
				_2stNum++;
				if (_2stNum >9)
				{
					_2stNum = 0;
				}
			}
			if (CursolPosX == 0)
			{
				_1stNum++;
				if (_1stNum > 9)
				{
					_1stNum = 0;
				}
			}

			StatusPointTest = ((_2stNum * 10) + _1stNum);
		}
		if (input.isKeyPressed(VK_DOWN))
		{
			if (CursolPosX == 1)
			{
				_2stNum--;
				if (_2stNum<0)
				{
					_2stNum = 9;
				}
			}
			if (CursolPosX == 0)
			{
				_1stNum--;
				if (_1stNum < 0)
				{
					_1stNum = 9;
				}
			}

			StatusPointTest = ((_2stNum * 10) + _1stNum);
			
		}
		if (input.isKeyPressed(VK_RIGHT))
		{
			CursolPosX--;
			if (CursolPosX < 0)
			{
				CursolPosX = 0;
			}
		}
		if (input.isKeyPressed(VK_LEFT))
		{
			CursolPosX++;
			if (CursolPosX > 1)
			{
				CursolPosX = 1;
			}
		}
		if (input.isKeyPressed(VK_RETURN)&&(StatusPoint -StatusPointTest)>=0)
		{
			CursolAndStatus[CursolPosY] += StatusPointTest;
			StatusPoint -= StatusPointTest;
			mState = choiseStatus;
			_1stNum = 0;
			_2stNum = 0;
			StatusPointTest = 0;
		}
		
		Sleep(50);
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
		db.SetAndWriteAndNum(0, 2, "HP  :",&CursolAndStatus[0]);
		db.SetAndWriteAndNum(0, 3, "MP  :", &CursolAndStatus[1]);
		db.SetAndWriteAndNum(0, 4, "ATK :", &CursolAndStatus[2]);
		db.SetAndWriteAndNum(0, 5, "DFP :", &CursolAndStatus[3]);
		db.SetAndWriteAndNum(0, 6, "AGI :", &CursolAndStatus[4]);
		db.SetAndWrite(0, 8, "決定");
		for (int i = 0; i < 8; i++)
		{
			if (CursolPosY == i)
			{
				continue;
			}
			db.SetAndWrite(8, i + 2, " ");
		}
		db.SetAndWrite(8, CursolPosY + 2, "<");
	}
	if (mState == ChoiseState::InputStatus)
	{
		int x_1st = 0;
		int x_2st = 1;
		
		
		
		string str = CursolAndStatusName[CursolPosY]+"  :";
		db.SetAndWrite(0, 0, "割り振るポイントを入力して下さい");
		db.SetAndWriteAndNum(0, 2, str,& CursolAndStatus[CursolPosY]);
		int tmp = StatusPoint - StatusPointTest;
		db.SetAndWrite(0, 4, "                   ");
		db.SetAndWriteAndNum(0, 4, "残りポイント  :" ,&tmp);
		
		if (CursolPosX!=x_1st)
		{
			db.SetAndWrite(x_1st, 6, "∧");
			db.SetAndWrite(x_1st, 8, "∨");
		}
		if (CursolPosX != x_2st)
		{
			db.SetAndWrite(x_2st, 6, "∧");
			db.SetAndWrite(x_2st, 8, "∨");
		}
		
		db.SetAndWrite(CursolPosX, 6, "　");
		db.SetAndWrite(CursolPosX, 8, "　");
		
		if(input.isKeyPressed(VK_RETURN)&& (StatusPoint - StatusPointTest) < 0)
		{
			db.SetAndWrite(0,10,"割り振るポイントが超過しています");
		}


		db.SetAndWrite(1, 7,_2stNum);
		db.SetAndWrite(3, 7,_1stNum);



	}
	if (mState == ChoiseState::Confimation)
	{

	}
}

Status CreateStatus::PathStatus()
{
	return mStatus;
}

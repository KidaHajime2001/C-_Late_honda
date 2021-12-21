#include "pch.h"
#include "CreateStatus_Component.h"

CreateStatus::CreateStatus()
	:BeforeState(choiseStatus)
	,mState(choiseStatus)
{
	//mapでカーソル位置からステータスを見つける
	setStatusMap(mStatus[0]);
	//mapでカーソル位置からステータス名を見つける
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
	//前フレームと入力状態をすり合わせる
	BeforeState = mState;

	//入力ステータスの選択画面
	if (mState==ChoiseState::choiseStatus)
	{
		//↑を推されたとき
		if (input.isKeyPressed(VK_UP))
		{
			//選択カーソルの位置を上に、カーソルの位置が最上だったら変化なし
			CursolPosY--;
			if (CursolPosY < 0)
			{
				CursolPosY = 0;
			}
		}
		if (input.isKeyPressed(VK_DOWN))
		{
			//選択カーソルの位置を下に、カーソルの位置が最低だったら変化なし
			CursolPosY++;
			if (CursolPosY > 6)
			{
				CursolPosY = 6;
			}
		}
		if (input.isKeyPressed(VK_RETURN))
		{
			//決定キーにカーソルがあっているとき
			if (CursolPosY==6)
			{
				if (party_s_num < 2)
				{
					party_s_num++;
					setStatusMap(mStatus[party_s_num]);
					Initialize_Variable();
					mState = Confimation;
					return;
				}
				else
				{
					for (int i = 0; i < MAX_PARTY_MENBER_NUM; i++)
					{
						Party_s.player[i] = mStatus[i];
					}
					FILE* fp = fopen("PartyData.dat", "wb");//バイナリファイルを開く
					if (fp!=NULL)
					{
						fwrite(&Party_s, sizeof(Party_Status), 1, fp); // SaveData_t構造体の中身を出力
					}
					
					fclose(fp);//ファイルを閉じる
					isCreateData = true;
				}
			}
			//カーソル位置がステータスにあっているときに状態遷移
			if (CursolPosY < 5)
			{
				
				mState = InputStatus;
				return;
			}
			
			
		}
		//ちょっと入力遅延
		Sleep(75);
	}
	//割りフルステータス選択
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
		//ちょっと入力遅延
		Sleep(75);
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

		db.SetAndWrite(0, 1, "name:");
		db.SetAndWrite(5, 1, mStatus[party_s_num].name);
		db.SetAndWriteAndNum(0, 2, "HP  :", &CursolAndStatus[0]);
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
		db.Clear();
		mState = choiseStatus;

	}
}

void CreateStatus::setStatusMap(Status TmpS)
{
		CursolAndStatus[0] = TmpS.HP;
		CursolAndStatus[1] = TmpS.MP;
		CursolAndStatus[2] = TmpS.ATK;
		CursolAndStatus[3] = TmpS.DFP;
		CursolAndStatus[4] = TmpS.AGI;
	
}

void CreateStatus::Initialize_Variable()
{
	StatusPoint = 100;

	_1stNum = 0;
	_2stNum = 0;
	StatusPointTest = 0;

	BeforeState = choiseStatus;
	mState = choiseStatus;
	
}


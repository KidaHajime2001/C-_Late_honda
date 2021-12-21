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
		choiseStatus,//�I��
		InputStatus,//����U��
		Confimation,//�m�F
	};
private:
	ChoiseState mState;			  //���
	Status mStatus[3] = { {"1",1,1,1,1,1,1,} ,
						  {"2",1,1,1,1,1,1,},
						  {"3",1,1,1,1,1,1,} };				  //����U���n���X�e�[�^�X
	Party_Status Party_s;
	int CursolPosY = 0;			  //�J�[�\���̈ʒu
	int CursolPosX = 0;			  //�J�[�\���̈ʒu
	Input input;				  //���͗p
	map<int, int> CursolAndStatus;//�I�������ۂ̊m�F�p�}�b�v
	map<int, string> CursolAndStatusName;//�I�������ۂ̊m�F�p�}�b�v
	int BeforeState=NULL ;

	//�c��|�C���g
	int StatusPoint = 100;
	const int StatusPointMax = 100;

	int _1stNum=0;
	int _2stNum = 0;
	int StatusPointTest = 0;

	int party_s_num = 0;
	bool isCreateData=false;
};


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
		choiseStatus,//�I��
		InputStatus,//����U��
		Confimation,//�m�F
	};
private:
	ChoiseState mState;			  //���
	Status mStatus;				  //����U���n���X�e�[�^�X
	int CursolPosY = 0;			  //�J�[�\���̈ʒu
	Input input;				  //���͗p
	map<int, int> CursolAndStatus;//�I�������ۂ̊m�F�p�}�b�v
	map<int, string> CursolAndStatusName;//�I�������ۂ̊m�F�p�}�b�v
	int BeforeState=NULL ;

	//�c��|�C���g
	int StatusPoint = 100;
	const int StatusPointMax = 100;
};


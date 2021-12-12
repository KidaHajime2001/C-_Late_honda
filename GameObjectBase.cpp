#include"pch.h"
#include "GameObjectBase.h"
GameObjectBase::GameObjectBase()
{
}

GameObjectBase::~GameObjectBase()
{
	//�R���|�[�l���g�̃|�C���^�S�Ă̊J��
	for (auto com : componentList)
	{
		delete com;
	}
}

void GameObjectBase::Update()
{
	//�R���|�[�l���g��Update��S�ĉ�
	
	for (auto com : componentList)
	{
		com->Update();
	}
}
void GameObjectBase::Draw()
{
	//�R���|�[�l���g��Draw��S�ĉ�
	for (auto com : componentList)
	{
		com->Draw();
	}

}





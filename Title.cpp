#include"pch.h"
#include "Title.h"

Title::Title()
{
	GameObjectBase* obj=new GameObjectBase;
	SelectEnter* mSelectEnter = obj->AddComponent<SelectEnter>();
	objects_List.push_back(obj);

	mSelectEnter->AddText("�Q�[�����n�߂�");
	mSelectEnter->AddText("�Q�[�����I���");
	

}

Title::~Title()
{
	for (auto obj : objects_List)
		delete obj;
	objects_List.clear();
}

SceneBase* Title::Update()
{
	for (auto obj : objects_List)
	{
		obj->Update();
	}
    return this;
}

void Title::Draw()
{
	
	for (auto obj : objects_List)
	{
		obj->Draw();
	}
}

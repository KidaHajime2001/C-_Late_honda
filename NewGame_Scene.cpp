#include"pch.h"
#include"NewGame_Scene.h"
#include"Game.h"
#include"Title.h"
#include"Status.h"
#include"CreateStatus_Component.h"
#include"Scenario_Scene.h"
NewGame::NewGame()
{
	Object* obj = new Object;
	Cs=obj->AddComponent<CreateStatus>();

	object_List.push_back(obj);

}

NewGame::~NewGame()
{

	for (auto obj : object_List)
		delete obj;
	object_List.clear();
}

SceneBase* NewGame::Update()
{
	
	for (auto obj : object_List)
	{
		obj->Update();
	}
	if (input.isKeyPressed(0x30)||Cs->Get_IsCreateData())
	{
		return new Scenario;
	}
	return this;
}

void NewGame::Draw()
{
	db.setCursorPos(0, 0);/*
	db.write("NEW GAME CREATE SCENE");*/
	for (auto obj : object_List)
	{
		obj->Draw(db);
	}
}

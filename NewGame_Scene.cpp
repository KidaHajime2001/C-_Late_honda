#include"pch.h"
#include"NewGame_Scene.h"
#include"Game.h"
#include"Title.h"
NewGame::NewGame()
{
}

NewGame::~NewGame()
{
	for (auto obj : object_List)
		delete obj;
	object_List.clear();
}

SceneBase* NewGame::Update()
{
	if (input.isKeyPressed(0x30))
	{
		return new Title;
	}
	return this;
}

void NewGame::Draw()
{
	db.setCursorPos(0, 0);
	db.write("NEW GAME CREATE SCENE");
	for (auto obj : object_List)
	{
		obj->Draw(db);
	}
}

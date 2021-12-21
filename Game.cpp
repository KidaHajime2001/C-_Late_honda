#include"pch.h"
#include "Game.h"
#include "Title.h"
#include"Status.h"
Game::Game()
{
	
	FILE* fp = fopen("PartyData.dat", "rb");
	if (fp == NULL) {
		return;
	}
	fread(&ps, sizeof(Party_Status), 1, fp);
	fclose(fp);
}

Game::~Game()
{
	for (auto obj : object_List)
		delete obj;
	object_List.clear();
}

SceneBase* Game::Update()
{
	for (auto obj : object_List)
	{
		obj->Update();
	}
	//0キー
	if (input.isKeyPressed(VK_DOWN))
	{
		return new Title;
	}
	return this;
}

void Game::Draw()
{
	
	db.SetAndWrite(0,1,"gamescne");
	db.setCursorPos(0, 0);/*
	db.write("NEW GAME CREATE SCENE");*/
	for (auto obj : object_List)
	{
		obj->Draw(db);
	}
	//savedata確認
	

	for (int i = 0; i < 2; i++)
	{
		db.SetAndWrite(0, 2+i, ps.player[i].name);

	}
	
}

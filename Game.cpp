#include"pch.h"
#include "Game.h"
#include "Title.h"
#include"Status.h"
#include"Scenario_Scene.h"
Game::Game()
{
	
	//if ((fp = fopen(name, "rb")) == NULL) {
	//	//printf("ファイルオープンエラー\n");
	//}
	//else
	//{
	//	fread(&ps, sizeof(Party_Status), 1, fp);
	//	fclose(fp);
	//}
	//for (int i = 0; i < MAX_PARTY_MENBER_NUM; i++)
	//{
	//	status[i] = ps.player[i];
	//}
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
		return new Scenario;
	}
	return this;
}

void Game::Draw()
{
	
	db.SetAndWrite(0,1,"gamescne");
	for (auto obj : object_List)
	{
		obj->Draw(db);
	}
	//savedata確認
	

	//for (int i = 0; i < 3; i++)
	//{
	//	db.SetAndWrite(0, 2+i,status[i].name);

	//}
	
}

#include"pch.h"
#include "Game.h"
#include "Title.h"
Game::Game()
{
}

Game::~Game()
{
	for (auto obj : object_List)
		delete obj;
	object_List.clear();
}

SceneBase* Game::Update()
{
	if (input.isKeyPressed(0x30))
	{
		return new Title;
	}
	return this;
}

void Game::Draw()
{
	db.setCursorPos(0, 0);
	db.write("GAME SCENE");
}

#include"pch.h"
#include "Game.h"

Game::Game()
{
}

Game::~Game()
{
	for (auto obj : objects_List)
		delete obj;
	objects_List.clear();
}

SceneBase* Game::Update()
{
	return this;
}

void Game::Draw()
{
}

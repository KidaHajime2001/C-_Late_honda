#include "pch.h"
#include "Title.h"
#include"Game.h"
Title::Title()
{
}

Title::~Title()
{
	for (auto obj : object_List)
		delete obj;
	object_List.clear();
}

SceneBase* Title::Update()
{
	if (input.isKeyPressed(0x30))
	{	
		return new Game;
	}
	return this;
}

void Title::Draw()
{
}

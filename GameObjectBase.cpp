#include"pch.h"
#include "GameObjectBase.h"
GameObjectBase::GameObjectBase()
{
}

GameObjectBase::~GameObjectBase()
{
	//コンポーネントのポインタ全ての開放
	for (auto com : componentList)
	{
		delete com;
	}
}

void GameObjectBase::Update()
{
	//コンポーネントのUpdateを全て回す
	
	for (auto com : componentList)
	{
		com->Update();
	}
}
void GameObjectBase::Draw()
{
	//コンポーネントのDrawを全て回す
	for (auto com : componentList)
	{
		com->Draw();
	}

}





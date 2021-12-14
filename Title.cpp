#include "pch.h"
#include "Title.h"
#include"Game.h"
#include"GameObject.h"
#include "Title_Component.h"
#include "NewGame_Scene.h"
Title::Title()
{
	Object* obj = new Object;
	tc=obj->AddComponent<TitleComponent>();
	object_List.push_back(obj);
}

Title::~Title()
{
	for (auto obj : object_List)
		delete obj;
	object_List.clear();
}

SceneBase* Title::Update()
{
	for (auto obj : object_List)
	{
		obj->Update();


	}
	if (tc!=nullptr&&input.isKeyPressed(VK_RETURN))
	{
		if (tc->GetStartSelectFlag())
		{
			return new Game;
		}
		else
		{
			return new NewGame;
		}
		
	}
	return this;
}

void Title::Draw()
{
	for (auto obj: object_List)
	{
		obj->Draw(db);
	}
	db.swap();

	Sleep(100);
}
//if (80 * 23 < i)
//{
//    i = 0;
//}
//db.setCursorPos(0, 0);
//db.write("using DblBuffer");
//db.setCursorPos(0, 1);
//for (int k = 0; k < 80 * 23; ++k) {
//    char text[256];
//    sprintf(text, "%d", k);
//    db.write(".");     //  ”wŒi•`‰æ
//}
//db.setCursorPos(i % 80, i / 80 + 1);
//if (input.isKeyPressed(VK_UP))
//{
//    db.write("ª");   //  Ž©‹@•`‰æ
//}
//else if (input.isKeyPressed(VK_RIGHT))
//{
//    db.write("¨");   //  Ž©‹@•`‰æ
//}
//else if (input.isKeyPressed(VK_DOWN))
//{
//    db.write("«");   //  Ž©‹@•`‰æ
//}
//else if (input.isKeyPressed(VK_LEFT))
//{
//    db.write("©");   //  Ž©‹@•`‰æ
//}
//else
//{
//    db.write("‚O");
//}
//db.swap();
//
//Sleep(100);
//i++;
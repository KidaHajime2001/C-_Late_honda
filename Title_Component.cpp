#include"pch.h"
#include "Title_Component.h"

TitleComponent::TitleComponent()
{
}

TitleComponent::~TitleComponent()
{
}

void TitleComponent::Start()
{
}

void TitleComponent::Update()
{
	if (input.isKeyPressed(VK_DOWN))
	{
		CursorTextY = NewGameTextY;
		StartSelectFlag = true;
	}
	if (input.isKeyPressed(VK_UP))
	{
		CursorTextY = ContinueTextY;
		StartSelectFlag = false;
	}
	
}

void TitleComponent::Draw(DblBuffer& db)
{
	db.setCursorPos(TitleTextX, TitleTextY);
	db.write("タイトルだよ");


	db.setCursorPos(NewGameTextX, NewGameTextY);
	db.write("新しく始める");

	db.setCursorPos(ContinueTextX, ContinueTextY);
	db.write("コンティニュー");

	db.setCursorPos(CursorTextX,NewGameTextY);
	db.write("<");

	db.setCursorPos(CursorTextX, ContinueTextY);
	db.write("<");

	db.setCursorPos(CursorTextX, CursorTextY);
	db.write(" ");
}

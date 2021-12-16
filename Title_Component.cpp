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
	
	db.SetAndWrite(TitleTextX, TitleTextY,"�^�C�g������");

	db.SetAndWrite(NewGameTextX, NewGameTextY, "�V�����n�߂�");

	db.SetAndWrite(ContinueTextX, ContinueTextY, "�R���e�B�j���[");

	db.SetAndWrite(CursorTextX, NewGameTextY, "<");

	db.SetAndWrite(CursorTextX, ContinueTextY, "<");

	db.SetAndWrite(CursorTextX, CursorTextY ," ");
}

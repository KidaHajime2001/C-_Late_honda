#pragma once
#include"pch.h"
#include"Component.h"
#include"Input.h"
class TitleComponent:public Component
{
public:
	TitleComponent();
	~TitleComponent();
	void Start();
	void Update();
	void Draw(DblBuffer& db);
	bool GetStartSelectFlag() { return StartSelectFlag; };
private:
	Input input;
	bool StartSelectFlag = false;//falseÇ™è„f

	const int TitleTextX=0;
	const int TitleTextY = 0;

	const int NewGameTextX = 0;
	const int NewGameTextY = 2;

	const int ContinueTextX = 0;
	const int ContinueTextY = 3;

	int CursorTextX = 20;
	int CursorTextY = ContinueTextY;
};

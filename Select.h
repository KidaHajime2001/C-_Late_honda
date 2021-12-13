#pragma once
#include"pch.h"
#include"Component.h"
#include"InputData.h"
class  SelectEnter:public Component
{
public:
	 SelectEnter();
	 ~SelectEnter();
	 void Start();
	 void Update();
	 bool UpdateBool();
	 void Draw();
	 void OnceDraw();
	 void AddText(string text);
	 int GetNowCursorNumber();
	 
private:
	list<string> text_list;
	int NowCursorNumber;
};

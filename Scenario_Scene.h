#pragma once
#include"pch.h"
#include"SceneBase.h"
#include"DblBuffer.h"

class Scenario :public SceneBase
{
public:
	Scenario();
	~Scenario();
	SceneBase* Update();
	void Draw();
	int getStrFromText(string filename, vector<string>& vstr);
	void Outputtext(vector<string> vstr_stage);
private:
	list<Object*> object_List;
	DblBuffer db;
	Input input;
};
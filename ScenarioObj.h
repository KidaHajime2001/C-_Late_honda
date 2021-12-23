#pragma once
#include"pch.h"
#include"GameObject.h"
#include"Input.h"

class ScenarioObj:public Object
{
public:
	ScenarioObj();
	~ScenarioObj();
	void Start();
	void Update();
	void Draw(DblBuffer& db);
	int getStrFromText(string filename, vector<string>& vstr);
	void Outputtext(vector<string> vstr_stage,DblBuffer db);
private:
	list<Component*> ComponentList;
	Input input;
	vector<string> vstr_stage1;
};

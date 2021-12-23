#pragma once
#include"pch.h"
#include"SceneBase.h"
#include"DblBuffer.h"
#include"ScenarioObj.h"
class Scenario :public SceneBase
{
public:
	Scenario();
	~Scenario();
	SceneBase* Update();
	void Draw();
	
private:
	list<Object*> object_List;
	DblBuffer db;
	Input input;
	
};
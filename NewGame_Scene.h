#pragma once
#include"pch.h"
#include"SceneBase.h"
#include"DblBuffer.h"
class NewGame:public SceneBase
{
public:
	NewGame();
	~NewGame();
	SceneBase* Update()override;
	void Draw()override;
private:
	list<Object*> object_List;
	Input input;
	DblBuffer db;

	
};


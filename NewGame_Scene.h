#pragma once
#include"pch.h"
#include"SceneBase.h"
#include"DblBuffer.h"
#include"CreateStatus_Component.h"
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
	class DblBuffer db;
	class CreateStatus* Cs;
	
};


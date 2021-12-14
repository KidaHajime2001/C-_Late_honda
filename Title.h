#pragma once
#include"pch.h"
#include"SceneBase.h"
#include"GameObject.h"
#include"Input.h"
class Title:public SceneBase
{
public:
	Title();
	~Title();
	SceneBase* Update()override;
	void Draw()override;
private:
	list<Object*> object_List;
	Input input;
};

#pragma once
#include"pch.h"
#include"GameObjectBase.h"
class SceneBase
{
public:
	SceneBase();
	virtual ~SceneBase();
	virtual SceneBase* Update();
	virtual void Draw();
	
private:
	
};



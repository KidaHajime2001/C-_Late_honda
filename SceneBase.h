#pragma once
#include"Input.h"
#include "GameObject.h"
class SceneBase
{
public:
	SceneBase();
	virtual ~SceneBase();
	virtual SceneBase* Update();
	virtual void Draw();
private:

};
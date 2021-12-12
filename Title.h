#pragma once
#include"pch.h"
#include"SceneBase.h"

class Title :public SceneBase
{
public:
	Title();
	~Title();
	SceneBase* Update()override;
	void Draw()override;

private:

};


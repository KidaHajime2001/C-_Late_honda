#pragma once
#include"pch.h"
#include "SceneBase.h"
class Game:public SceneBase
{
public:
	Game();
	~Game();
	SceneBase* Update()override;
	void Draw()override;
private:
	list<GameObjectBase*> objects_List;
};


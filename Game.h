#pragma once
#include"GameObject.h"
#include"SceneBase.h"
#include"Input.h"
class Game:public SceneBase
{
public:
	Game();
	~Game();
	SceneBase* Update()override;
	void Draw()override;
private:
	list<Object*> object_List;
	Input input;
};
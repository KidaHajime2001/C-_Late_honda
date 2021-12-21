#pragma once
#include"GameObject.h"
#include"SceneBase.h"
#include"Input.h"
#include"Status.h"
class Game:public SceneBase
{
public:
	Game();
	~Game();
	SceneBase* Update()override;
	void Draw()override;
private:
	list<Object*> object_List;
	DblBuffer db;
	Input input;
	Party_Status ps;
};
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
	Status status[MAX_PARTY_MENBER_NUM];
	FILE* fp;
	const char* name = "PartyData.dat";
};
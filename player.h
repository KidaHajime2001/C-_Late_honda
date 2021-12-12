#pragma once
#include"Component.h"
class Player:public Component
{
public:
	Player ();
	~Player();
	void Start();
	void Update();
	void Draw();
	void LoadStatus(string dataPath);

private:

};

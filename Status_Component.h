#pragma once
#include"Input.h"
#include"Component.h"
#include"DblBuffer.h"
class Status:public Component
{
public:
	Status();
	~Status();
	void Update();
	void Draw(DblBuffer& db);

	int HP = 1;
	int MP = 1;
	int ATK = 1;
	int DFP = 1;
	int AGI = 1;
private:
	Input input;
};
#pragma once
#include"pch.h"
#include"DblBuffer.h"
class Object;
class Player;
class Component
{
protected:
public:
	Component() {};
	virtual ~Component() {};
	Object* Parent=nullptr;
	virtual void Start() {};
	virtual void Update() {};
	virtual void Draw(DblBuffer& db) {};
};
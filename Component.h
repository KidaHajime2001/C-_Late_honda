#pragma once
#include"pch.h"
class Object;
class Player;
class Component
{
protected:
public:
	Component() {};
	virtual ~Component() {};
	Object* Parent;
	virtual void Start() {};
	virtual void Update() {};
	virtual void Draw() {};
};
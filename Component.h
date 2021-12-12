#pragma once
#include"pch.h"
#include "GameObjectBase.h"
class Component
{
protected:
public:
	Component() {};
	virtual ~Component() {};
	virtual void Start() {};
	virtual void Update() {};
	virtual void Draw() {};
};



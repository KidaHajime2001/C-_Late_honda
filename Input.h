#pragma once
#include"pch.h"
class Input
{
public:
	Input();
	~Input();
	bool isKeyPressed(int vKey);
private:

};

Input::Input()
{
}

Input::~Input()
{
}
inline bool Input::isKeyPressed(int vKey)
{
	return (GetAsyncKeyState(vKey) & 0x8000) != 0;
}

#include"pch.h"
#include"Input.h"

Input::Input()
{
}

Input::~Input()
{
}

bool Input::isKeyPressed(int vKey)
{
	return (GetAsyncKeyState(vKey) & 0x8000) != 0;
}

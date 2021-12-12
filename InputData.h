#pragma once
#include"pch.h"
class InputData
{
    static char Buffer;
public:
    static void Update()
    {
        if (_kbhit()) {
            Buffer = _getch();
            cout << "a";
        }
    }
    static bool KeyCheck(char key)
    {
        if (Buffer == key)
            return true;
        return false;
    }
};
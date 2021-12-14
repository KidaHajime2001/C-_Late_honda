#include"pch.h"
#include "DblBuffer.h"
#include"Input.h"
int main()
{
    DblBuffer db;
    Input input;
    for (int i = 0; i < 80 * 23; ++i) {
        db.setCursorPos(0, 0);
        db.write("using DblBuffer");
        db.setCursorPos(0, 1);
        for (int k = 0; k < 80 * 23; ++k) {
            db.write(".");     //  ”wŒi•`‰æ
        }
        db.setCursorPos(i % 80, i / 80 + 1);
        if (input.isKeyPressed(VK_UP))
        {
            db.write("ª");   //  Ž©‹@•`‰æ
        }
        else if (input.isKeyPressed(VK_RIGHT))
        {
            db.write("¨");   //  Ž©‹@•`‰æ
        }
        else if (input.isKeyPressed(VK_DOWN))
        {
            db.write("«");   //  Ž©‹@•`‰æ
        }
        else if (input.isKeyPressed(VK_LEFT))
        {
            db.write("©");   //  Ž©‹@•`‰æ
        }
        else
        {
            db.write("‚O");
        }
        db.swap();
        
        Sleep(100);
    }
}
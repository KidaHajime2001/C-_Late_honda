#include"pch.h"
#pragma once
typedef struct {
    string name;
    int HP;         //HP
    int MP;         //MP
    int ATK;
    int DFP;
    int AGI;
    

    //int Money;      //所持金
    int Exp;        //経験値
}Status;
typedef struct {
    Status player[3];
}Party_Status;

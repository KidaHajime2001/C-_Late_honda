#include"pch.h"
#pragma once
typedef struct {
    string name;
    int HP;         //HP
    int MP;         //MP
    int ATK;
    int DFP;
    int AGI;
    

    //int Money;      //������
    int Exp;        //�o���l
}Status;
typedef struct {
    Status player[3];
}Party_Status;

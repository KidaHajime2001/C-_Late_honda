#include"pch.h"
#include "DblBuffer.h"
#include"Input.h"
#include"SceneBase.h"
#include"Title.h"
#include"DblBuffer.h"
int main()
{
    Input input;
    DblBuffer db;
    SceneBase* scene = new Title;
    while (!input.isKeyPressed(VK_ESCAPE))
    {
        SceneBase* tmp ;
        tmp=scene->Update();
        scene->Draw();
        if (scene!=tmp)
        {
            delete scene;
            scene = tmp;
        }

        
    }
    
    delete scene;
}
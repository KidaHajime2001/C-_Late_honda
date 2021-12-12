#include"pch.h"
#include"Title.h"
#include"Game.h"
#include"InputData.h"
char InputData::Buffer = 0;
int main()
{

	SceneBase* scene = new Title();
	

	while (!InputData::KeyCheck('p'))
	{
		InputData::Update();
		SceneBase* TMPScene;

		TMPScene = scene->Update();
		scene->Draw();

		if (TMPScene != scene)
		{
			delete scene;
			scene = TMPScene;

		}
	}

	if (scene)
	{
		delete scene;
	}
	return 0;
}
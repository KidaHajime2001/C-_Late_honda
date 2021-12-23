#include"pch.h"
#include "Scenario_Scene.h"
#include"Title.h"

Scenario::Scenario()
{
	Object* obj = new ScenarioObj;
	object_List.push_back(obj);

}
Scenario::~Scenario()
{
}



SceneBase* Scenario::Update()
{
	for (auto obj : object_List)
	{
		obj->Update();
	}
	if (input.isKeyPressed(0x30))
	{
		return new Title;
	}
	return this;
}

void Scenario::Draw()
{
	db.setCursorPos(0, 0);/*
	db.write("NEW GAME CREATE SCENE");*/
	for (auto obj : object_List)
	{
		obj->Draw(db);
	}
}


//#include"conversation.h"
//
//Conversation::Conversation(string name1, string name2, string name3)
//{
//	getStrFromText("Textfile/Text1.txt", vstr_stage1);
//	getStrFromText("Textfile/Text2.txt", vstr_stage2);
//	getStrFromText("Textfile/Text3.txt", vstr_stage3);
//	getStrFromText("Textfile/Text4.txt", vstr_stage4);
//	getStrFromText("Textfile/Text5.txt", vstr_stage5);
//	name[1] = name1;
//	name[2] = name2;
//	name[3] = name3;
//	name[0] = "";
//	name[4] = "???";
//	name[5] = "Kraken";
//}
//
//Conversation::Conversation()
//{
//}
//
//Conversation::~Conversation()
//{
//}
//
//int Conversation::getStrFromText(string filename, vector<string>& vstr)
//{
//	ifstream ifs(filename);
//
//	if (!ifs)
//	{
//		cout << "error :>> failed to open the text file." << endl;
//		return 1;
//	}
//
//	string tmp;
//	while (getline(ifs, tmp))
//		vstr.push_back(tmp);
//
//	return 0;
//}
//
//void Conversation::Outputtext(vector<string> vstr_stage)
//{
//
//	string beforeName;
//
//	for (int i = 0; i < vstr_stage.size(); i++)
//	{
//		string nameNum = &vstr_stage[i][0];
//
//		cout << left << setw(7) << name[atoi(nameNum.c_str())];
//		vstr_stage[i].erase(vstr_stage[i].begin());
//		cout << vstr_stage[i] << endl;
//		while (getchar() != '\n');
//	}
//}
//
//void Conversation::OutputtextAuto(vector<string> vstr_stage)
//{
//	for (int i = 0; i < vstr_stage.size(); i++)
//	{
//		cout << vstr_stage[i] << endl;
//	}
//}
//
//void Conversation::Selecttext(int stageNum)
//{
//	switch (stageNum)
//	{
//	case 1:
//		Outputtext(vstr_stage1);
//		break;
//	case 2:
//
//		Outputtext(vstr_stage2);
//		break;
//	case 3:
//
//		Outputtext(vstr_stage3);
//		break;
//	case 4:
//
//		Outputtext(vstr_stage4);
//		break;
//	case 5:
//
//		Outputtext(vstr_stage5);
//		break;
//
//	default:
//		break;
//	}
//}

#include"pch.h"
#include"ScenarioObj.h"

ScenarioObj::ScenarioObj()
{
	getStrFromText("Textfile/Text1.txt", vstr_stage1);
}

ScenarioObj::~ScenarioObj()
{
	for (auto com : ComponentList)
		delete com;
}

void ScenarioObj::Start()
{
	
}

void ScenarioObj::Update()
{
	auto buff = ComponentList;
	for (auto com : buff)
		com->Update();
}

void ScenarioObj::Draw(DblBuffer& db)
{
	Outputtext(vstr_stage1,db);
	for (auto com : ComponentList)
		com->Draw(db);
}
int ScenarioObj::getStrFromText(string filename, vector<string>& vstr)
{
	ifstream ifs(filename);

	if (!ifs)
	{
		cout << "error :>> failed to open the text file." << endl;
		return 1;
	}

	string tmp;
	while (getline(ifs, tmp))
		vstr.push_back(tmp);

	return 0;
}
void ScenarioObj::Outputtext(vector<string> vstr_stage,DblBuffer db)
{

	string beforeName;

	for (int i = 0; i < vstr_stage.size(); i++)
	{
		string nameNum = &vstr_stage[i][0];

		/*cout << left << setw(7) << name[atoi(nameNum.c_str())];*/
		db.SetAndWrite(0,i,vstr_stage[0][i]);
		cout << vstr_stage[i] << endl;
		while (getchar() != '\n');
	}
}
#include "pch.h"
#include "Select.h"

SelectEnter::SelectEnter()
	:NowCursorNumber(0)
{
}

SelectEnter::~SelectEnter()
{
}

void SelectEnter::Start()
{
}

void SelectEnter::Update()
{

	OnceDraw();
	UpdateBool();
}

bool SelectEnter::UpdateBool()
{
	while (1)
	{
		InputData::Update();
		if (InputData::KeyCheck('w'))
		{
			NowCursorNumber--;
			system("cls");
			break;
		}
		if (InputData::KeyCheck('s'))
		{
			NowCursorNumber++;
			system("cls");
			break;
		}
		if (NowCursorNumber < 0)
		{
			NowCursorNumber = 0;
		}
		if (NowCursorNumber > (int)text_list.size())
		{
			NowCursorNumber = (int)text_list.size();
		}
		if (InputData::KeyCheck('a'))
		{
			return true;
			break;
		}
	}
	
}

void SelectEnter::Draw()
{
	

	/*int i=0;
	for (auto text : text_list)
	{
		cout << setw(10) << text;
		if (NowCursorNumber==i)
		{
			cout << " <";
		}
		cout << endl;
		i++;
	}*/
}

void SelectEnter::OnceDraw()
{
	int i = 0;
	for (auto text : text_list)
	{
		cout << setw(10) << text;
		if (NowCursorNumber == i)
		{
			cout << " <";
		}
		cout << endl;
		i++;
	}
}

void SelectEnter::AddText(string text)
{
	text_list.push_back(text);
}

int SelectEnter::GetNowCursorNumber()
{
	return NowCursorNumber;
}

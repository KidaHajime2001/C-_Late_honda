#include "pch.h"
#include "DblBuffer.h"
//----------------------------------------------------------------------
//			DblBuffer ver 0.001
//			Copyright (C) 2014 by N.Tsuda
//			Description: 画面チラツキを無くすためのダブルバッファクラス
//			License: CDDL 1.0 (http://opensource.org/licenses/CDDL-1.0)
//----------------------------------------------------------------------


DblBuffer::DblBuffer()
	: m_swapped(false)
{
	//m_hCons = GetStdHandle( STD_OUTPUT_HANDLE );
	m_hCons1 = CreateConsoleScreenBuffer(
		GENERIC_READ | GENERIC_WRITE,
		0, NULL, CONSOLE_TEXTMODE_BUFFER, NULL);
	m_hCons2 = CreateConsoleScreenBuffer(
		GENERIC_READ | GENERIC_WRITE,
		0, NULL, CONSOLE_TEXTMODE_BUFFER, NULL);
	SetConsoleActiveScreenBuffer(m_hCons1);
	CONSOLE_CURSOR_INFO info;
	info.dwSize = 1;
	info.bVisible = FALSE;
	SetConsoleCursorInfo(m_hCons1, &info);
	SetConsoleCursorInfo(m_hCons2, &info);
}
DblBuffer::~DblBuffer()
{
	CloseHandle(m_hCons1);
	CloseHandle(m_hCons2);
}
void DblBuffer::setColor(int col)
{
	WORD attr = 0;
	if (col & INTENSITY)
		attr |= FOREGROUND_INTENSITY;
	if (col & RED_MASK)
		attr |= FOREGROUND_RED;
	if (col & GREEN_MASK)
		attr |= FOREGROUND_GREEN;
	if (col & BLUE_MASK)
		attr |= FOREGROUND_BLUE;
	SetConsoleTextAttribute(m_swapped ? m_hCons1 : m_hCons2, attr);
}
void DblBuffer::setColor(int fg, int bg)
{
	WORD attr = 0;
	if (fg & INTENSITY)
		attr |= FOREGROUND_INTENSITY;
	if (fg & RED_MASK)
		attr |= FOREGROUND_RED;
	if (fg & GREEN_MASK)
		attr |= FOREGROUND_GREEN;
	if (fg & BLUE_MASK)
		attr |= FOREGROUND_BLUE;

	if (bg & INTENSITY)
		attr |= BACKGROUND_INTENSITY;
	if (bg & RED_MASK)
		attr |= BACKGROUND_RED;
	if (bg & GREEN_MASK)
		attr |= BACKGROUND_GREEN;
	if (bg & BLUE_MASK)
		attr |= BACKGROUND_BLUE;
	SetConsoleTextAttribute(m_swapped ? m_hCons1 : m_hCons2, attr);
}
void DblBuffer::setCursorPos(int x, int y)
{
	COORD pos;
	pos.X = x;
	pos.Y = y;
	SetConsoleCursorPosition(m_swapped ? m_hCons1 : m_hCons2, pos);
}
void DblBuffer::write(const char* ptr)
{
	DWORD len = (DWORD)strlen(ptr);
	WriteConsoleA(m_swapped ? m_hCons1 : m_hCons2, ptr, len, &len, 0);
}
void DblBuffer::write(const wchar_t* ptr)
{
	DWORD len = (DWORD)wcslen(ptr);
	WriteConsoleW(m_swapped ? m_hCons1 : m_hCons2, ptr, len, &len, 0);
}
void DblBuffer::write(const std::string& str)
{
	DWORD len = (DWORD)str.size();
	WriteConsoleA(m_swapped ? m_hCons1 : m_hCons2, str.c_str(), len, &len, 0);
}
void DblBuffer::write(const std::wstring& str)
{
	DWORD len = (DWORD)str.size();
	WriteConsoleA(m_swapped ? m_hCons1 : m_hCons2, str.c_str(), len, &len, 0);
}
void DblBuffer::swap()
{
	if ((m_swapped = !m_swapped)) {
		SetConsoleActiveScreenBuffer(m_hCons2);
	}
	else {
		SetConsoleActiveScreenBuffer(m_hCons1);
	}
}

void DblBuffer::SetAndWrite(int x, int y, const char* str)
{
	setCursorPos(x,y);
	write(str);
}

void DblBuffer::SetAndWrite(int x, int y, const wchar_t* str)
{
	setCursorPos(x, y);
	write(str);
}

void DblBuffer::SetAndWrite(int x, int y, const std::string& str)
{
	setCursorPos(x, y);
	write(str);
}

void DblBuffer::SetAndWrite(int x, int y, const std::wstring& str)
{
	setCursorPos(x, y);
	write(str);
}

void DblBuffer::SetAndWrite(int x, int y, int z)
{
	setCursorPos(x, y);
	write(std::to_string(z));
}

void DblBuffer::SetAndWriteAndNum(int x, int y, const char* str, const int* num)
{
	string textSum=str;
	textSum = textSum + std::to_string(*num);
	setCursorPos(x, y);
	write(textSum);
}


void DblBuffer::SetAndWriteAndNum(int x, int y, const std::string& str, const int* num)
{
	string textSum = str;
	textSum += std::to_string(*num);
	setCursorPos(x, y);
	write(textSum);
}

void DblBuffer::Clear()
{
	for (int  i = 0; i < 100; i++)
	{
		for (int  j = 0; j < 100; j++)
		{
			setCursorPos(i, j);
			write(" ");
		}
	}
}



#ifndef PRINTC
#define PRINTC

#include <Windows.h>
#include <iostream>

enum class TextColor { white, blue, green, red };

void PrintC(std::string string, TextColor color) {
	HANDLE hConsole = GetStdHandle(STD_OUTPUT_HANDLE);
	switch (color) {
	case TextColor::white:
		SetConsoleTextAttribute(hConsole, FOREGROUND_BLUE | FOREGROUND_GREEN | FOREGROUND_RED);
		break;
	case TextColor::blue:
		SetConsoleTextAttribute(hConsole, FOREGROUND_BLUE);
		break;
	case TextColor::green:
		SetConsoleTextAttribute(hConsole, FOREGROUND_GREEN);
		break;
	case TextColor::red:
		SetConsoleTextAttribute(hConsole, FOREGROUND_RED);
		break;
	}

	std::cout << string;

	SetConsoleTextAttribute(hConsole, FOREGROUND_BLUE | FOREGROUND_GREEN | FOREGROUND_RED);
}

void PrintC(std::string string) {
	HANDLE hConsole = GetStdHandle(STD_OUTPUT_HANDLE);
	SetConsoleTextAttribute(hConsole, FOREGROUND_BLUE | FOREGROUND_GREEN | FOREGROUND_RED);
	std::cout << string;
}

#endif
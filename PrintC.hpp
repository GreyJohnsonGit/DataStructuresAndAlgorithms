#ifndef PRINTC
#define PRINTC

#include <Windows.h>
#include <stdio.h>

enum class TextColor { white, blue, green, red };

void PrintC(const char* string, TextColor color) {
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

	printf(string);

	SetConsoleTextAttribute(hConsole, FOREGROUND_BLUE | FOREGROUND_GREEN | FOREGROUND_RED);
}

#endif
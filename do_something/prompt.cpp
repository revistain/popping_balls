#include "prompt.h"
#define col 80
#define row 30

void text_color(int color_number) {
	SetConsoleTextAttribute(GetStdHandle(STD_OUTPUT_HANDLE), color_number);
}

void hide_cursor() {
	CONSOLE_CURSOR_INFO cursorInfo = { 0, };
	cursorInfo.bVisible = 0;
	cursorInfo.dwSize = 1;
	SetConsoleCursorInfo(GetStdHandle(STD_OUTPUT_HANDLE), &cursorInfo);
}

void prompt_main() {
	hide_cursor();
	system("mode con cols=80 lines=30 | title Popping");
}


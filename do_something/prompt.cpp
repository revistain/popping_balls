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

// https://cplusplus.com/forum/beginner/100115/
// faster cls
// the previous system('cls'); was too too too slow
void cls()
{
    HANDLE console = ::GetStdHandle(STD_OUTPUT_HANDLE);
    CONSOLE_SCREEN_BUFFER_INFO csbi;
    ::GetConsoleScreenBufferInfo(console, &csbi);
    COORD origin = { 0, 0 };
    DWORD written;
    ::FillConsoleOutputCharacterA(console, ' ', csbi.dwSize.X * csbi.dwSize.Y,
        origin, &written);
    ::FillConsoleOutputAttribute(console, csbi.wAttributes, csbi.dwSize.X * csbi.dwSize.Y,
        origin, &written);
    ::SetConsoleCursorPosition(console, origin);
}

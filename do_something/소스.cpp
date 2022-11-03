#include <iostream>
#include <time.h>
#include <windows.h>
#include "object.h"

void set_gravity() {

}

int main() {
	srand(time(NULL));

	circle circle1(3, 3, 3);
	circle circle2(4, 5, 3);
	

	while (1) {
		system("cls");
		circle1.printObj();
		circle2.printObj();
		Sleep(100);
	}
}
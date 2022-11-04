#include "object.h"
#include "loop.h"
#include "prompt.h"
#include <time.h>
#include <windows.h>


int main() {
	srand(time(NULL));
	prompt_main();

	circle circle1(8, 5, 3);
	circle circle2(30, 5, 10);
	circle circle3(50, 5, 1);

	int i = 0;
	while (1) {
		system("cls");
		main_loop();

		if(i % 100 == 0) new circle(rand()%80, rand()%30, rand()%5);
		i++;
	}
}
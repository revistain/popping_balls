#include "object.h"
#include "loop.h"
#include "prompt.h"
#include "fps.h"
#include <time.h>
#include <windows.h>


int main() {
	srand(time(NULL));
	prompt_main();
	Fps fps;

	circle circle1(8, 5, 3);

	int i = 0;
	while (1) {
		main_loop();

		if(i % 30 == 0) new circle(rand()%80, rand()%30, rand()%5+1);
		fps.update(); text_color(6);
		gotoxy(0, 0); std::cout << "Fps: " << fps.get() << '\n';
		i++;
	}
}
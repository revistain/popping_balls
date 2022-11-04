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

	new circle(8, 5, 3);

	int i = 0;
	while (1) {
		fps.update();
		main_loop();

		if(i % 300 == 0) new circle(rand()%80, rand()%20, rand()%5+1);
		text_color(6);
		Sleep(1);
		cls();

		gotoxy(0, 0); std::cout << "Fps: " << fps.get() << "\n  ";// << i % 100 << std::endl;
		i++;
	}
}
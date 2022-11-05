#include "object.h"
#include "loop.h"
#include "prompt.h"
#include "fps.h"
#include <time.h>
#include <windows.h>

void traverseLinkedList() {
	object* listptr = static_cast<object*>(ObjList.ptr);
	if (listptr == nullptr) return;
	int cnt = 0;
	do {
		cnt++;
	} while ((listptr = listptr->getPrev()) != nullptr);
	gotoxy(0, 1);
	std::cout << "ball count: " << cnt;
}

int main() {
	srand(time(NULL));
	prompt_main();
	Fps fps;

	int i = 0;
	while (1) {
		traverseLinkedList();
		fps.update();
		main_loop();

		if(i % 5 == 0) new circle(rand()%80, rand()%20, rand()%5+1);

		text_color(6);
		Sleep(1);
		cls();

		gotoxy(0, 0); std::cout << "Fps: " << fps.get() << "(MAX 70)\n  ";// << i % 100 << std::endl;
		i++;
	}
}
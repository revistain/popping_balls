#include "loop.h"
#include "prompt.h"
#define GRAVITY 0.02
#define col 80
#define row 30

void gotoxy(int x, int y)
{
	COORD Cur;
	Cur.X = x;
	Cur.Y = y;
	SetConsoleCursorPosition(GetStdHandle(STD_OUTPUT_HANDLE), Cur);
}

void set_gravity(object* obj) {
	obj->add_vec(0, GRAVITY*obj->getW());
}

void set_obj_collision(object* obj) {
	object* ptr = static_cast<object*>(ObjList.ptr);

	do {
		if (obj != ptr && *obj == ptr) {
			delete ptr;
			break;
		}
	} while ((ptr = ptr->getPrev()) != nullptr);
}

void set_box_collision(object* obj) {
	if (obj->getY()+obj->getYvec() >= row) {
		obj->reverseX_vec();
	}
	else if (obj->getX() + obj->getXvec() < 0 || obj->getX() + obj->getXvec() > col-1) {
		obj->reverseY_vec();
	}
}

void renderer(object* obj) {
	gotoxy(static_cast<int>(obj->getX()), static_cast<int>(obj->getY()));
	text_color(obj->getColor());
	std::cout << "¡Ü";
}

void main_loop() {
	object* ptr = static_cast<object*>(ObjList.ptr);

	do {
		// do loop
		set_gravity(ptr);
		set_box_collision(ptr);
		set_obj_collision(ptr);
		ptr->apply_vec();
		renderer(ptr);

	} while ((ptr = ptr->getPrev()) != nullptr);

}

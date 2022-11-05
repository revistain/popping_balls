#include "loop.h"
#include "prompt.h"
#define GRAVITY 0.02
#define col 120
#define row 60

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

object* set_obj_collision(object* obj) {
	object* ptr = static_cast<object*>(ObjList.ptr);

	do {
		if (obj != ptr && *obj == ptr) {
			obj->elastic_collision(ptr);

			if (ptr->getHitCount() == 0) {
				ptr->add_hitCount();
			}
			else if (ptr->getHitCount() == 1) {
				delete ptr;
			}

			if (obj->getHitCount() == 0) {
				obj->add_hitCount();
			}
			else if (obj->getHitCount() == 1) {
				object* temp = obj->getNext();
				delete obj;
				return temp;
			}

			break;
		}
	} while ((ptr = ptr->getPrev()) != nullptr);

	return obj;
}

void set_box_collision(object* obj) {
	if (obj->getY() + obj->getYvec() < 0 || obj->getY() + obj->getYvec() >= row) {
		obj->reverseX_vec();
	}
	else if (obj->getX() + obj->getXvec() < 0 || obj->getX() + obj->getXvec() > col-2) {
		obj->reverseY_vec();
	}
}

void renderer(object* obj) {
	gotoxy(static_cast<int>(obj->getX()), static_cast<int>(obj->getY()));
	text_color(obj->getColor());
	if (obj->getHitCount() == 0) std::cout << "¡Ü";
	else if(obj->getHitCount() == 1) std::cout << "¡Û";
}

void main_loop() {
	object* ptr = static_cast<object*>(ObjList.ptr);
	object* temp = nullptr;

	if (ptr == nullptr) return;
	do {
		// do loop
		set_gravity(ptr);
		set_box_collision(ptr);
		if ((temp = set_obj_collision(ptr)) != ptr) {
			if (temp == nullptr) break;
			ptr = temp;
			continue;
		}
		
		ptr->apply_vec();
		renderer(ptr);

	} while ((ptr = ptr->getPrev()) != nullptr);

}

#include "object.h"
#define DAMPINGCOF 0.92

void* ObjList::ptr = nullptr;
object::object(float x, float y, int _weight) : weight(_weight) {
	pos.x = x;
	pos.y = y;
	color = rand() % 14 + 1;

	int tempX = rand();
	if ((tempX / 10) % 2) tempX = ~tempX + 1;
	vec.x = static_cast<float>(tempX % 5) / 3;
	//vec.y = 0; pass

	if (ObjList.ptr == nullptr) {
		prev = nullptr;
		next = nullptr;
	}
	else {
		prev = static_cast<object*>(ObjList.ptr);
		prev->next = this;
		next = nullptr;
	}

	ObjList.ptr = static_cast<void*>(this);
};
float object::get_length_between(object* obj) const {
	float temp1, temp2;
	temp1 = getX() - obj->getX();
	temp1 = temp1 * temp1;
	temp2 = getY() - obj->getY();
	temp2 = temp2 * temp2;

	return temp1 + temp2;
}
void object::reverseX_vec() {
	vec.y = -vec.y * DAMPINGCOF;
}
void object::reverseY_vec() {
	vec.x = -vec.x * DAMPINGCOF;
}
void object::elastic_collision(object* obj) {
	Vec2D temp1Vec(obj->getX() - getX(), obj->getY() - getY());
	temp1Vec.normallize();
	temp1Vec.scalar_multiply(DAMPINGCOF);
	Vec2D temp2Vec(temp1Vec);

	float v1 = getX() * getX() + getY() + getY();
	v1 = sqrt(v1);
	float v2 = obj->getX() * obj->getX() + obj->getY() * obj->getY();
	v2 = sqrt(v2);

	float w1 = getW(), w2 = obj->getW();
	temp1Vec.scalar_multiply(-(((w1 - w2)/(w1 + w2))*v1 +(2 * w2/(w1 + w2))*v2)/v1);
	temp2Vec.scalar_multiply(((2 * w1/(w1 + w2))*v1 + ((w2 - w1)/(w1 + w2))*v2)/v2);

	vec = temp1Vec;
	obj->vec = temp2Vec;
}
void object::apply_vec() {
	pos.x += vec.x;
	pos.y += vec.y;
}
void object::printObj() const {
	std::cout << "prev : " << prev << ", pos : " << pos.x << ", " << pos.y << ", vec : " << vec.x << ", " << vec.y << ", weight : " << weight << ", speed : " << speed << std::endl;
}
object::~object() {
	if (this->prev == nullptr && this->next == nullptr) {
		ObjList.ptr = nullptr;
	}
	else if (this->prev == nullptr) {
		this->next->prev = nullptr;
	}
	else if (this->next == nullptr) {
		this->prev->next = nullptr;
		ObjList.ptr = this->prev;
	}
	else {
		this->next->prev = this->prev;
		this->prev->next = this->next;
	}
}

bool circle::operator==(object* obj) const  {
	if (this->getX() + 1 < obj->getX() ||
		this->getX() - 1 > obj->getX() ||
		this->getY() + 1 < obj->getY() ||
		this->getY() - 1 > obj->getY()) {
		return false;
	}

	return get_length_between(obj) < r ? true : false;
}
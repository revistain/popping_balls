#include "object.h"
#define DAMPINGCOF 0.92

void* ObjList::ptr = nullptr;
object::object(float x, float y, int _weight) : weight(_weight) {
	pos.x = x;
	pos.y = y;
	color = rand() % 14 + 1;

	int tempX = rand();
	if ((tempX / 10) % 2) tempX = ~tempX + 1;
	vec.x = static_cast<float>(tempX % 5) / 10;
	//vec.y = 0; pass

	if (ObjList.ptr == nullptr) { prev = nullptr; }
	else { prev = static_cast<object*>(ObjList.ptr); }

	ObjList.ptr = static_cast<void*>(this);
};
float object::get_length_between(object& obj) const {
	float temp1, temp2;
	temp1 = getX() - obj.getX();
	temp1 = temp1 * temp1;
	temp2 = getY() - obj.getY();
	temp2 = temp2 * temp2;

	return temp1 + temp2;
}
void object::reverseX_vec() {
	vec.y = -vec.y * DAMPINGCOF;
}
void object::reverseY_vec() {
	vec.x = -vec.x * DAMPINGCOF;
}
void object::apply_vec() {
	pos.x += vec.x;
	pos.y += vec.y;
}
void object::printObj() const {
	std::cout << "prev : " << prev << ", pos : " << pos.x << ", " << pos.y << ", vec : " << vec.x << ", " << vec.y << ", weight : " << weight << ", speed : " << speed << std::endl;
}

bool circle::operator==(object& obj) const {
	// �� �� ���� basecase ~~
	return get_length_between(obj) > r ? false : true;
}
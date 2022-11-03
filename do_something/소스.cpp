#include <iostream>
#include <time.h>

typedef struct {
	float x, y;
}Pos;

typedef struct {
	float x, y = 0;
}Vec2D;

static struct {
	static void* ptr;
}ObjList;

class object {
private:
	object* prev;
	Pos pos;
	Vec2D vec;
	float weight;
	float speed = 0;

public:
	object(int x, int y, int _weight);

	virtual void is_collision_with(object& obj) const = 0;

	float get_length_between(object& obj) const;

	// loop
	void apply_vec();

	// 캡술화
	__inline float getX() const { return pos.x; }
	__inline float getY() const { return pos.y; }
	__inline float getW() const { return weight; }
	__inline float getS() const { return speed; }
	void add_vec(const float x, const float y) { vec.x += x; vec.y += y; }
};
object::object(int x, int y, int _weight) : weight(_weight) {
	srand(time(NULL));
	pos.x = x;
	pos.y = y;

	int tempX = rand();
	if ((tempX / 10) % 2) tempX = ~tempX + 1;
	vec.x = tempX % 10;
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
void object::apply_vec() {
	pos.x += vec.x;
	pos.y += vec.y;
}

class circle : public object {
private:
	float r = 1;
public:
	bool operator==(object& obj)const; // 충돌 감지
};
bool circle::operator==(object& obj) const {
	// 좀 더 빠른 basecase ~~
	return get_length_between(obj) > r ? false : true;
}

void init() {
	ObjList.ptr = nullptr;
}
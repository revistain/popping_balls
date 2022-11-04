#pragma once
#include <iostream>

typedef struct {
	float x, y;
}Pos;

typedef struct Vec2D {
	float x = 0, y = 0;
}Vec2D;

static struct ObjList {
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
	object(float x, float y, int _weight);

	//virtual void is_collision_with(object& obj) const = 0;

	float get_length_between(object& obj) const;
	void printObj() const;
	void reverseX_vec();
	void reverseY_vec();

	// loop
	void apply_vec();

	// 캡술화
	__inline float getX() const { return pos.x; }
	__inline float getY() const { return pos.y; }
	__inline float getW() const { return weight; }
	__inline float getS() const { return speed; }
	__inline object* getPrev() const { return prev; }
	__inline float getXvec() { return vec.x; }
	__inline float getYvec() { return vec.y; }
	__inline void add_vec(const float x, const float y) { vec.x += x; vec.y += y; }
};

class circle : public object {
private:
	float r = 1;
public:
	circle(float x, float y, int _weight) :object(x, y, _weight) {}
	bool operator==(object& obj)const; // 충돌 감지
};
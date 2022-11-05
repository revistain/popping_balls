#pragma once
#include <iostream>

typedef struct {
	float x, y;
}Pos;

class Vec2D {
public:
	float x = 0, y = 0;
	Vec2D() = default;
	Vec2D(float x, float y) : x(x), y(y) {}
	Vec2D(const Vec2D& vec) : x(vec.x), y(vec.y) {}

	Vec2D&& proj(const Vec2D& vec) const;
	float inner_product(const Vec2D& vec) const;
	void scalar_multiply(float scalar);
	void normallize();

	void operator=(const Vec2D& vec) {
		x = vec.x;
		y = vec.y;
	}
};

static struct ObjList {
	static void* ptr;
}ObjList;

class object {
private:
	object* prev;
	object* next;
	Pos pos;
	Vec2D vec;
	short color;
	float weight;
	float speed = 0;
	short hitCount = 0;

public:
	object(float x, float y, int _weight);

	//virtual void is_collision_with(object& obj) const = 0;

	float get_length_between(object* obj) const;
	void printObj() const;
	void reverseX_vec();
	void reverseY_vec();
	void elastic_collision(object* obj);


	// loop
	void apply_vec();

	// 캡술화
	__inline float getX() const { return pos.x; }
	__inline float getY() const { return pos.y; }
	__inline float getW() const { return weight; }
	__inline float getS() const { return speed; }
	__inline short getColor() const { return color; }
	__inline object* getPrev() const { return prev; }
	__inline object* getNext() const { return next; }
	__inline float getXvec() { return vec.x; }
	__inline float getYvec() { return vec.y; }
	__inline float getHitCount() { return hitCount; }
	__inline void add_hitCount() { hitCount++; }
	__inline void add_vec(const float x, const float y) { vec.x += x; vec.y += y; }
	__inline void set_vec(const float x, const float y) { vec.x = x; vec.y = y; }

	// operator override
	virtual bool operator==(object* obj) const = 0;

	virtual ~object();
};

class circle : public object {
private:
	float r = 5;
public:
	circle(float x, float y, int _weight) :object(x, y, _weight) {}
	bool operator==(object* obj) const; // 충돌 감지

	~circle() {}
};
#include "object.h"

float Vec2D::inner_product(const Vec2D& vec) const {
	return this->x * vec.x + this->y * vec.y;
}

void Vec2D::scalar_multiply(float scalar) {
	x = x * scalar;
	y = y * scalar;
}

void Vec2D::normallize() {
	float norm = sqrt(x * x + y * y);
	x = x / norm;
	y = y / norm;
}

Vec2D&& Vec2D::proj(const Vec2D& vec) const {
	float temp = inner_product(vec) / (x * x + y * y);
	return std::move(Vec2D(temp * x, temp * y));
}
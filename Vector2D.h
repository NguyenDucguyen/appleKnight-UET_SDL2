#ifndef VECTOR2D_H_
#define VECTOR2D_H_
#include "CommonFunc.h"
// struct tọa độ 1 điểm
class Vector2D
{
public:
	float x;
	float y;

	Vector2D()
	{
		x = 0.0f;
		y = 0.0f;
	}

	Vector2D(float a, float b)
	{
		x = a;
		y = b;
	}
	Vector2D operator+(Vector2D other) {
		return Vector2D(x + other.x, y + other.y);
	}
	Vector2D operator-(Vector2D other) {
		return Vector2D(x - other.x, y - other.y);
	}
	Vector2D operator*(float t) {
		return Vector2D(x*t, y*t);
	}
	Vector2D& operator+=(const Vector2D& other) {
		x += other.x;
		y += other.y;
		return *this;
	}
};
#endif 
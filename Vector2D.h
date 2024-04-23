#ifndef VECTOR2D_H_
#define VECTOR2D_H_
#include "CommonFunc.h"


class Vector2D
{
public:
    float x;
    float y;

    Vector2D();
    Vector2D(float a, float b);
    Vector2D operator+(const Vector2D& other) const;
    Vector2D operator-(const Vector2D& other) const;
    Vector2D operator*(float t) const;
    Vector2D& operator+=(const Vector2D& other);
};
#endif 
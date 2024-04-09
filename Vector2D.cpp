#include "Vector2D.h"

Vector2D::Vector2D()
{
    x = 0.0f;
    y = 0.0f;
}

Vector2D::Vector2D(float a, float b)
{
    x = a;
    y = b;
}

Vector2D Vector2D::operator+(const Vector2D& other) const
{
    return Vector2D(x + other.x, y + other.y);
}

Vector2D Vector2D::operator-(const Vector2D& other) const
{
    return Vector2D(x - other.x, y - other.y);
}

Vector2D Vector2D::operator*(float t) const
{
    return Vector2D(x * t, y * t);
}

Vector2D& Vector2D::operator+=(const Vector2D& other)
{
    x += other.x;
    y += other.y;
    return *this;
}
#include "Vector2.h"

#include "Math.h"

Vector2::Vector2(float x, float y)
{
	this->x = x;
	this->y = y;
}

Vector2 Vector2::operator+(const Vector2& other) const
{
	return Vector2(x + other.x, y + other.y);
}

Vector2 Vector2::operator-(const Vector2& other) const
{
	return Vector2(x - other.x, y - other.y);
}

Vector2 Vector2::operator*(float other) const
{
	return Vector2(x * other, y * other);
}

Vector2 Vector2::operator*(Vector2 other) const
{
	return Vector2(x * other.x, y * other.y);
}

Vector2 Vector2::operator/(float other) const
{
	return Vector2(x / other, y / other);
}

bool Vector2::operator==(const Vector2& other) const
{
	return x == other.x && y == other.y;
}

const float Vector2::Length()
{
	return sqrt(pow(x, 2) + pow(y, 2));
}

const Vector2 Vector2::Normalized()
{
	float length = Length();
	if (length == 0)
		return Vector2(0, 0);

	return Vector2(x / length, y / length);
}

const float Vector2::SquaredDistance(Vector2 a, Vector2 b)
{
	return pow(b.x - a.x, 2) + pow(b.y - a.y, 2);
}

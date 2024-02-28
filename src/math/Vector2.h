#pragma once
class Vector2
{
public:
	Vector2(float x, float y);

	float x;
	float y;

	Vector2 operator+(const Vector2& other) const;
	Vector2 operator-(const Vector2& other) const;
	Vector2 operator*(float other) const;
	Vector2 operator*(Vector2 other) const;
	Vector2 operator/(float other) const;
	bool operator==(const Vector2& other) const;


	const float Length();
	const Vector2 Normalized();
	static const float SquaredDistance(Vector2 a, Vector2 b);
};


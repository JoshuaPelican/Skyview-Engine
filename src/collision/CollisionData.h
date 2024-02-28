#pragma once

#include "../core/Math.h"

class Collider2D;

class CollisionData {
public:
	CollisionData() {};
	CollisionData(Collider2D* other, Vector2 hitPoint, Vector2 hitNormal, float separation);

	Collider2D* other = 0;
	Vector2 hitPoint = Vector2(0, 0);
	Vector2 hitNormal = Vector2(0, 0);
	float separation = 0;
};
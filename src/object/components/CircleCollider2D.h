#pragma once

#include "../../collision/Collider2D.h"
#include "../../core/Math.h"

class CircleCollider2D : public Collider2D
{
public:
	CircleCollider2D(Object* object);

	bool IsColliding(Collider2D* other) override;
	CollisionData GetCollision(Collider2D* other) override;

	Vector2 center = Vector2(0, 0);
	float radius = 64;
};


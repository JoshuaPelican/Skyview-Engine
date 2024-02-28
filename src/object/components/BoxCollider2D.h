#pragma once

#include "../../collision/Collider2D.h"
#include "../../core/Math.h"

class BoxCollider2D : public Collider2D
{
public:
	BoxCollider2D(Object* object);

	bool IsColliding(Collider2D* other) override;
	CollisionData GetCollision(Collider2D* other) override;

	Vector2 center = Vector2(0, 0);
	Vector2 scale = Vector2(1, 1);
};


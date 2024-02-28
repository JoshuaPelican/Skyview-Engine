#pragma once

#include "../object/Component.h"
#include "../collision/CollisionData.h"

class Collider2D : public Component
{
public:
	Collider2D(Object* object);

	// Inherited via Component
	void Update() override {};
	void Enable() override {};
	void Disable() override {};
	void OnCollision(CollisionData collision) override {};

	virtual bool IsColliding(Collider2D* other) = 0;
	virtual CollisionData GetCollision(Collider2D* other) = 0;

	bool isTrigger = false;
};


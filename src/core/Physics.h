#pragma once

#include "Module.h"
#include "../collision/CollisionData.h"

class Physics2D : public Module
{
public:
	void Update() override {};

	static CollisionData Raycast(Vector2 direction);
};


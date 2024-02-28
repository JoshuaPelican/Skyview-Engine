#pragma once

#include "Module.h"
#include "../collision/Collider2D.h"
#include "../object/components/BoxCollider2D.h"
#include "../object/components/CircleCollider2D.h"
#include "Math.h"

class Collision : public Module
{
public:
	void Update() override;

	void CheckForCollisions(Collider2D* collider);
};

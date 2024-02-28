#pragma once

#include "../../src/SkyviewEngine.h"

class HurtZone : public Component
{
public:
	HurtZone(Object* object);

	void Update() override;
	void Enable() override;
	void Disable() override;
	void OnCollision(CollisionData collision) override;

	float zoneDamage = 0;
};


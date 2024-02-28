#pragma once

#include "../../src/SkyviewEngine.h"

class Damageable : public Component
{
public:
	Damageable(Object* object) : Component(object) {};

	void Update() override;
	void Enable() override;
	void Disable() override;
	void OnCollision(CollisionData collision) override {};
	
	void TakeDamage(float damage);

	float maxHealth = 0;
	float currentHealth = 0;
	bool isDead = false;
};


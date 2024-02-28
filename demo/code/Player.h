#pragma once

#include "../../src/SkyviewEngine.h"

class Player : public Component
{
public:
	Player(Object* object) : Component(object) {};
	void Enable() override;
	void Update() override;
	void Disable() override;
	void OnCollision(CollisionData data) override;
};
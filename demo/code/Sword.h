#pragma once

#include "../../src/SkyviewEngine.h"

class Sword : public Component
{
public:
	Sword(Object* object) : Component(object) {};
	void Update() override;
	void Enable() override;
	void Disable() override;
	void OnCollision(CollisionData collision) override;

	Transform2D* pivot = 0;
};


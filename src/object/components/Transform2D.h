#pragma once

#include <SDL.h>

#include "../Component.h"
#include "../../core/Math.h"

class Object;

class Transform2D : public Component
{
public:
	Transform2D(Object* object);
	void Enable() override {};
	void Update() override;
	void Disable() override {};
	void OnCollision(CollisionData data) override {};

	void Move(float x, float y);
	void Move(Vector2 movement);
	void SetPosition(Vector2 position);
	void Rotate(float angle);
	void Scale(float x, float y);

	void RecalculateCenter();

	Vector2 position = Vector2(0, 0);
	Vector2 scale = Vector2(1, 1);
	float angle = 0;
	Vector2 center = Vector2(0, 0);
	Vector2 pivot = Vector2(0, 0);

	bool movedThisFrame = false;
};


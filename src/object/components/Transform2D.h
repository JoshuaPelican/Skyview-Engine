#pragma once

#include <SDL.h>

#include "../Component.h"

class Object;

class Transform2D : Component
{
public:
	Transform2D(Object* object);
	void Enable() override {};
	void Update() override {};
	void Disable() override {};

	void Move(float x, float y);
	void Rotate(float angle);
	void Scale(float x, float y);


	SDL_FPoint* position = 0;
	SDL_FPoint* scale = 0;
	float angle = 0;
	SDL_FPoint* center = 0;
	SDL_FPoint* pivot = 0;
};


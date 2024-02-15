#pragma once

#include <SDL.h>

class Object;

class Transform2D
{
public:
	Transform2D(Object* obj);
	~Transform2D();

	void Move(float x, float y);
	void Rotate(float angle);
	void Scale(float x, float y);

	Object* object;

	SDL_FPoint* position = 0;
	SDL_FPoint* scale = 0;
	float angle = 0;
	SDL_FPoint* center = 0;
	SDL_FPoint* pivot = 0;
};


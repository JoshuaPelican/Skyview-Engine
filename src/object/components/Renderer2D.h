#pragma once

#include <SDL.h>
#include <SDL_image.h>
#include <string>
using namespace std;

#include "../../rendering/Sprite.h"

class Object;

class Renderer2D
{
public:
	Renderer2D(Object* object);
	~Renderer2D();

	Object* object;
	Sprite* sprite = 0;

	SDL_Rect* rect = 0;

	bool flipX = false, flipY = false; // TODO: Currently unused, need to use these
};


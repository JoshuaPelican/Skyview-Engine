#pragma once

#include <SDL.h>
#include <SDL_image.h>
#include <string>
using namespace std;

#include "../../rendering/Sprite.h"
#include "../Component.h"

class Object;

class Renderer2D : Component
{
public:
	Renderer2D(Object* object) : Component(object) {};
	void Enable() override {};
	void Update() override {};
	void Disable() override {};

	Sprite* sprite = 0;

	bool flipX = false, flipY = false; // TODO: Currently unused, need to use these
};


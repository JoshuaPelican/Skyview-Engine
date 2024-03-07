#pragma once

#include "Module.h"

#include <SDL.h>

class Object;
class Window;

class Rendering : public Module
{
public:
	Rendering();
	~Rendering();
	void Update() override;

	void RenderObject(Object* obj);
	void DrawRectOutline(SDL_FRect rect, int r, int g, int b);

	Window* window;
};
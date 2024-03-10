#pragma once

#include <SDL.h>

#include "Module.h"
#include "Math.h"

class Input : public Module
{
public:
	void Update() override;

	static int GetKeyDown(SDL_Scancode keyCode);

	static Vector2 mousePosition;
	static bool leftMouseDown;

private:
	static const Uint8* keyStates;
};


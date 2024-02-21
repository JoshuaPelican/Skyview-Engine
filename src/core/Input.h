#pragma once

#include <SDL.h>

#include "Module.h"

class Input : public Module
{
public:
	void Update() override;

	static bool GetKeyDown(SDL_Scancode keyCode);

private:
	static const Uint8* keyStates;
};


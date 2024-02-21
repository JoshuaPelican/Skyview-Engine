#pragma once

#include <SDL.h>

#include "Module.h"

class Time : public Module
{
public:
	void Update() override;

	static float deltaTime;
	static float fixedDeltaTime;
	static Uint64 time;
};


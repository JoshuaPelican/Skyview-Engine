#include "Time.h"

float Time::deltaTime = 0;
float Time::fixedDeltaTime = 1 / 60;
Uint64 Time::time = 0;

void Time::Update()
{
	Uint64 ticks = SDL_GetTicks64();
	Time::deltaTime = (ticks - time) * 0.001f;
	Time::time = ticks;
}

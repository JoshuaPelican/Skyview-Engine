#pragma once

#include <SDL.h>

class Renderer2D
{
public:
	Renderer2D();
	~Renderer2D();
	bool LoadMedia(char* filePath);

	SDL_Surface* surface = NULL;
};


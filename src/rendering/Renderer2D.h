#pragma once

#include <SDL.h>
#include <string>
using namespace std;

class Renderer2D
{
public:
	Renderer2D() {};
	Renderer2D(string mediaPath);
	~Renderer2D();
	void SetMedia(string mediaPath);
	bool LoadSurface(const SDL_PixelFormat* format);

	string mediaPath = "";
	SDL_Surface* surface = NULL;

	bool isLoaded = false;
};


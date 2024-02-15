#pragma once

#include <SDL.h>
#include <SDL_image.h>
#include <string>
using namespace std;

class Sprite
{
public:
	Sprite() {};
	Sprite(string mediaPath);
	~Sprite();
	void SetMedia(string mediaPath);
	bool LoadMedia(SDL_Renderer* renderer);

	SDL_Texture* texture = 0;
	bool isLoaded = false;

	int width = 0, height = 0;

private:
	string mediaPath = "";
};


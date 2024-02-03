#pragma once

#include <SDL.h>
#include <stdio.h>

class Window
{
	public:
		Window(char* name, int x, int y, int width, int height);
		~Window();
		void Draw();

	private:
		SDL_Surface* screenSurface = NULL;
		SDL_Window* window = NULL;
};
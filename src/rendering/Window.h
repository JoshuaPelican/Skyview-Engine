#pragma once

#include <SDL.h>

class Window
{
	public:
		Window(char* name, int x, int y, int width, int height);
		~Window();
		void Clear();
		void Draw();
		void Blit(SDL_Surface* surface);

		SDL_Surface* screenSurface = NULL;
		SDL_Window* window = NULL;
	private:

};
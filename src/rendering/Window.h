#pragma once

#include <SDL.h>
#include <stdio.h>

class Window
{
	public:
		Window(char* name, int x, int y, int width, int height);
		~Window();
		void Clear();
		void Draw();

		SDL_Window* window = NULL;
		SDL_Renderer* renderer = NULL;
		SDL_Rect* viewport = NULL;

		int width = 0, height = 0;
};
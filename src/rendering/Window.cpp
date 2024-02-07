#include "Window.h"
#include <stdio.h>

Window::Window(char* name, int x, int y, int width, int height)
{
	//Create window
	window = SDL_CreateWindow(name, SDL_WINDOWPOS_CENTERED, SDL_WINDOWPOS_CENTERED, width, height, SDL_WINDOW_SHOWN);
	if (window == NULL)
	{
		printf("Window could not be created! SDL_Error: %s\n", SDL_GetError());
		return;
	}

	//Get window surface
	screenSurface = SDL_GetWindowSurface(window);
}

Window::~Window()
{
	SDL_DestroyWindow(this->window);
}

void Window::Clear()
{
	//Fill the surface white
	SDL_FillRect(screenSurface, NULL, SDL_MapRGB(screenSurface->format, 255, 255, 100));
}

void Window::Draw()
{
	//Update the surface
	SDL_UpdateWindowSurface(window);
}

void Window::Blit(SDL_Surface* surface)
{
	SDL_BlitSurface(surface, NULL, screenSurface, NULL);
}
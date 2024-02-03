#include "Window.h"

Window::Window(char* name, int x, int y, int width, int height)
{
	//Initialize SDL
	if (SDL_Init(SDL_INIT_VIDEO) < 0)
	{
		printf("SDL could not initialize! SDL_Error: %s\n", SDL_GetError());
		return;
	}

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

void Window::Draw()
{
	//Fill the surface white
	SDL_FillRect(screenSurface, NULL, SDL_MapRGB(screenSurface->format, 255, 255, 100));

	//Update the surface
	SDL_UpdateWindowSurface(window);
}
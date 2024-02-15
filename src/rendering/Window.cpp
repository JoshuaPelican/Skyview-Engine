#include "Window.h"

Window::Window(char* name, int x, int y, int width, int height)
{
	this->width = width;
	this->height = height;

	// Create window
	window = SDL_CreateWindow(name, SDL_WINDOWPOS_CENTERED, SDL_WINDOWPOS_CENTERED, width, height, SDL_WINDOW_SHOWN | SDL_WINDOW_RESIZABLE);
	if (window == NULL)
	{
		printf("Window could not be created! SDL_Error: %s\n", SDL_GetError());
		return;
	}

	// Create renderer
	renderer = SDL_CreateRenderer(window, -1, SDL_RENDERER_ACCELERATED);
	if (renderer == NULL)
	{
		printf("Renderer could not be created! SDL Error: %s\n", SDL_GetError());
		return;
	}

	// Initialize renderer color
	SDL_SetRenderDrawColor(renderer, 255, 255, 255, 255);

	// Initialize the viewport
	viewport = new SDL_Rect();
	viewport->x = 0;
	viewport->y = 0;
	viewport->w = width;
	viewport->h = height;
	SDL_RenderSetViewport(renderer, viewport);
}

Window::~Window()
{
	SDL_DestroyWindow(this->window);
}

void Window::Clear()
{
	// Clear screen
	SDL_RenderClear(renderer);
}

void Window::Draw()
{
	// Update screen
	SDL_RenderPresent(renderer);
}
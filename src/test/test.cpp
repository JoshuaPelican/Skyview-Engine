#include <SDL.h>
#include <stdio.h>
#include "../core.h"

//Screen dimension constants
const int SCREEN_WIDTH = 640;
const int SCREEN_HEIGHT = 480;

int main(int argc, char* args[])
{
	Window* window = new Window("Window Name", 0, 0, SCREEN_WIDTH, SCREEN_HEIGHT);

	SDL_Event e;

	bool quit = false;
	while (!quit)
	{
		//Handle events on queue
		while (SDL_PollEvent(&e) != 0)
		{
			//User requests quit
			if (e.type == SDL_QUIT)
			{
				quit = true;
			}

			window->Draw();
		}
	}

	//Destroy window
	delete window;

	//Quit SDL subsystems
	SDL_Quit();

	return 0;
}

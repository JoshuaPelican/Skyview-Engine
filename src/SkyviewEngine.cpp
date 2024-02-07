#include "SkyviewEngine.h"
#include <SDL.h>

SkyviewEngine::SkyviewEngine()
{
	Enable();
}

SkyviewEngine::~SkyviewEngine()
{
	Disable();
}

void SkyviewEngine::Enable()
{
	printf("Skyview Engine Starting...\n\n");

	//Initialize SDL
	if (SDL_Init(SDL_INIT_EVERYTHING) < 0)
	{
		printf("SDL could not initialize! SDL_Error: %s\n", SDL_GetError());
		return;
	}

	gameState = new GameState();

	renderModule = new Rendering();
	renderModule->SetState(gameState);

	CreateObject("Test Object 1", "./src/_demo/images/test.bmp");

	GameLoop();
}

void SkyviewEngine::Update()
{
	renderModule->Update();
}

void SkyviewEngine::Disable()
{
	delete gameState;
	delete renderModule;
	SDL_Quit();
}

void SkyviewEngine::GameLoop()
{
	SDL_Event e;

	bool quit = false;
	while (!quit)
	{
		//Handle events on queue
		while (SDL_PollEvent(&e) != 0)
		{
			//User requests quit
			if (e.type == SDL_QUIT)
				quit = true;

			Update();
		}
	}
}

Object* SkyviewEngine::CreateObject(char* name, char* imgPath)
{
	Object* newObject = new Object(name, imgPath);
	printf("New Object Created: %s\n", name);

	gameState->objects.push_back(newObject);

	return newObject;
}
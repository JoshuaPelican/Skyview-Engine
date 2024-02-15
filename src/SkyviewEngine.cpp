#include "SkyviewEngine.h"

#include "core/Rendering.h"
#include "core/GameState.h"

SkyviewEngine* SkyviewEngine::instance = 0;

SkyviewEngine::SkyviewEngine(Application* app)
{
	Enable();
	app->Load();
	GameLoop();
}

SkyviewEngine::~SkyviewEngine()
{
	Disable();
}

void SkyviewEngine::Enable()
{
	printf("Skyview Engine Starting...\n\n");

	if (instance != NULL)
		delete instance;

	instance = this;

	//Initialize SDL
	if (SDL_Init(SDL_INIT_EVERYTHING) < 0)
	{
		printf("SDL could not initialize! SDL_Error: %s\n", SDL_GetError());
		return;
	}

	//Initialize IMG loading
	int imgFlags = IMG_INIT_PNG | IMG_INIT_JPG;
	if (!(IMG_Init(imgFlags) & imgFlags))
	{
		printf("SDL_image could not initialize! SDL_image Error: %s\n", IMG_GetError());
		return;
	}

	gameState = new GameState();

	renderModule = new Rendering();
	renderModule->SetState(gameState);
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

Object* SkyviewEngine::CreateObject(string name, string imgPath)
{
	Object* newObject = new Object(name, imgPath);
	printf("New Object Created: %s\n", name.c_str());

	gameState->objects.push_back(newObject);

	return newObject;
}
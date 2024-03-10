#include "SkyviewEngine.h"

#include "core/GameState.h"

SkyviewEngine* SkyviewEngine::instance = 0;

SkyviewEngine::SkyviewEngine(Application* app)
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

	debugModule = new Debug();
	debugModule->SetState(gameState);
	debugModule->SetRenderer(renderModule);

	collisionModule = new Collision();
	collisionModule->SetState(gameState);

	timeModule = new Time();
	inputModule = new Input();

	app->Load();

	GameLoop();
}

SkyviewEngine::~SkyviewEngine()
{
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
		}

		Update();
	}
}

void SkyviewEngine::Update()
{
	timeModule->Update();

	inputModule->Update();
	debugModule->Update();
	collisionModule->Update();

	renderModule->Update();

	gameState->Update();
}

Object* SkyviewEngine::CreateObject(string name, string mediaPath)
{
	Object* newObject = new Object(name);
	newObject->renderer.SetSprite(mediaPath);

	gameState->AddObject(newObject);

	printf("New Object Created: %s\n", name.c_str());

	return newObject;
}

void SkyviewEngine::DestroyObject(Object* object)
{
	gameState->RemoveObject(object);

	printf("Object Destroyed: %s\n", object->name.c_str());
}

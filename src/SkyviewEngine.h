#pragma once

#include <SDL.h>
#include <SDL_image.h>
#include <string>
using namespace std;

#include "core/Application.h"
#include "core/Module.h"
#include "object/object.h"

class Rendering;
class GameState;

#define SE SkyviewEngine::instance

class SkyviewEngine : Module
{
public:
	SkyviewEngine(Application* app);
	~SkyviewEngine();

	void Enable() override;
	void Disable() override;
	void Update() override;

	void GameLoop();
	Object* CreateObject(string name, string imgPath);

	static SkyviewEngine* instance;

	Rendering* renderModule = 0;
	GameState* gameState = 0;
};
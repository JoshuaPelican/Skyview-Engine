#pragma once

#include <SDL.h>
#include <SDL_image.h>
#include <string>
using namespace std;

#include "core/Application.h"
#include "core/Module.h"
#include "core/Time.h"
#include "core/Input.h"

#include "object/object.h"

class Rendering;
class GameState;

#define SE SkyviewEngine::instance

class SkyviewEngine : Module
{
public:
	SkyviewEngine(Application* app);
	~SkyviewEngine();
	void Update() override;

	void GameLoop();
	Object* CreateObject(string name, string imgPath);

	static SkyviewEngine* instance;

private:
	GameState* gameState = 0;

	Rendering* renderModule = 0;
	Time* timeModule = 0;
	Input* inputModule = 0;
};
#pragma once

#include <SDL.h>
#include <SDL_image.h>
#include <string>
using namespace std;

#include "core/Application.h"
#include "core/Module.h"
#include "core/Rendering.h"
#include "core/Collision.h"
#include "core/Time.h"
#include "core/Input.h"
#include "core/Debug.h"
#include "core/math.h"

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
	void DestroyObject(Object* object);

	static SkyviewEngine* instance;

private:
	GameState* gameState = 0;

	Rendering* renderModule = 0;
	Collision* collisionModule = 0;
	Time* timeModule = 0;
	Input* inputModule = 0;
	Debug* debugModule = 0;
};
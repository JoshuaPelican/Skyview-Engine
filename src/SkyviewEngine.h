#pragma once

#include <string>
using namespace std;

#include "core/Module.h"
#include "core/Rendering.h"
#include "core/GameState.h"
#include "core/Application.h"

#define SE SkyviewEngine::instance

class Object;

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
#pragma once

#include "core/Module.h"
#include "core/Rendering.h"
#include "core/GameState.h"

class GameState;
class Rendering;
class Object;

class SkyviewEngine : Module
{
public:
	SkyviewEngine();
	~SkyviewEngine();

	virtual void Enable() override;
	virtual void Disable() override;
	virtual void Update() override;

	void GameLoop();
	Object* CreateObject(char* name, char* imgPath);

	Rendering* renderModule = 0;
	GameState* gameState = 0;
};
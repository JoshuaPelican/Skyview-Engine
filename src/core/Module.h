#pragma once

class GameState;

class Module
{
public:
	virtual void Update() = 0;

	void SetState(GameState* state);

	GameState* gameState = 0;
};


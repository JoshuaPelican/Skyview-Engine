#pragma once

class GameState;

class Module
{
public:
	virtual void Update() = 0;
	void SetState(GameState* state);
	GameState* gameState = 0;

private:
	virtual void Enable() = 0;
	virtual void Disable() = 0;

};


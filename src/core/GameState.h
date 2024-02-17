#pragma once

#include <list>
using namespace std;

#include "Module.h"

class Object;

class GameState : public Module
{
public:
	GameState();
	~GameState();
	void Update() override;

	void AddObject(Object* object);

	list<Object*> objects;
};


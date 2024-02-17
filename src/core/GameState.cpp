#include "GameState.h"

#include "../object/Object.h"

GameState::GameState()
{

}

GameState::~GameState()
{

}

void GameState::Update()
{
	for each (Object* object in objects)
	{
		object->renderer->Update();
		object->transform->Update();
		for each (Component* component in object->components)
		{
			component->Update();
		}
	}
}

void GameState::AddObject(Object* object)
{
	objects.push_back(object);

	object->renderer->Enable();
	object->transform->Enable();
	/*
	for each (Component * component in object->components)
	{
		component->Enable();
	}
	*/
}

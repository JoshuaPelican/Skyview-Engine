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
	for (Object* object : objects)
	{
		object->renderer.Update();
		object->transform.Update();
		if(object->collider != NULL)
			object->collider->Update();
		for (Component* component : object->components)
		{
			component->Update();
		}
	}
}

void GameState::AddObject(Object* object)
{
	objects.push_back(object);

	object->renderer.Enable();
	object->transform.Enable();
	/*
	for each (Component * component in object->components)
	{
		component->Enable();
	}
	*/
}

void GameState::RemoveObject(Object* object)
{
	//objects.remove(object);
	for each (Component * component in object->components)
	{
		component->Disable();
	}
	object->renderer.Disable();
	object->transform.Disable();
}

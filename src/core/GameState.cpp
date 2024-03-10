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

	for (list<Object*>::const_iterator it = objects.begin(); it != objects.end(); it++)
	{
		Object* object = *it;

		if (object->isDestroyed)
		{
			it = objects.erase(it);
			delete object;
		}
		else
		{
			object->renderer.Update();
			object->transform.Update();
			if (object->collider != NULL)
				object->collider->Update();
			for (Component* component : object->components)
			{
				component->Update();
			}
		}

		if (it == objects.end())
			break;
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
	for each (Component * component in object->components)
	{
		component->Disable();
	}
	object->renderer.Disable();
	object->transform.Disable();
	object->isDestroyed = true;
}

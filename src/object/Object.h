#pragma once

#include <string>
#include <list>
using namespace std;

#include "Component.h"
#include "components/Renderer2D.h"
#include "components/Transform2D.h"
#include "../collision/Collider2D.h"

class Object
{
public:
	Object(string name);
	~Object();

	SDL_FRect* GetRect() const;

	template <typename ComponentType>
	inline ComponentType* AddComponent()
	{
		ComponentType* component = new ComponentType(this);
		components.push_back(component);
		component->Enable();
		return component;
	}
	template <typename ComponentType>
	inline ComponentType* GetComponent()
	{
		ComponentType* result = nullptr;
		for each (Component * currComp in components)
		{
			result = dynamic_cast<ComponentType*>(currComp);
			if (result)
				break;
		}
		return result;
	}

	string name = "New Object";
	Renderer2D renderer = 0;
	Transform2D transform = 0;
	Collider2D* collider = 0;
	list<Component*> components;
};
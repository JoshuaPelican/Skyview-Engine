#pragma once

#include <string>
#include <list>
using namespace std;

#include "Component.h"
#include "components/Renderer2D.h"
#include "components/Transform2D.h"

class Object
{
public:
	Object(string name, string imgPath);
	~Object();

	SDL_FRect* GetRect() const;

	void AddComponent(Component* component);

	string name = "New Object";
	Renderer2D* renderer = 0;
	Transform2D* transform = 0;
	list<Component*> components;
};
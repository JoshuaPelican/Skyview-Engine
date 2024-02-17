#include "Object.h"

#include <typeinfo>

#include "../rendering/Sprite.h"

Object::Object(string name)
{
	this->name = name;
	renderer = new Renderer2D(this);
	transform = new Transform2D(this);
}

Object::~Object()
{
	delete renderer;
	delete transform;
	for each (Component* component in components)
	{
		delete component;
	}
}

SDL_FRect* Object::GetRect() const
{
	SDL_FRect* rect = new SDL_FRect();
	rect->x = transform->position->x;
	rect->y = transform->position->y;
	rect->w = renderer->sprite->width * transform->scale->x;
	rect->h = renderer->sprite->height * transform->scale->y;

	return rect;
}

void Object::AddComponent(Component* component)
{
	components.push_back(component);
	component->Enable();
}

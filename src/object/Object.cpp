#include "Object.h"

#include "../rendering/Sprite.h"

Object::Object(string name, string mediaPath)
{
	this->name = name;
	renderer = new Renderer2D(this);
	renderer->sprite = new Sprite(mediaPath);
	transform = new Transform2D(this);
}

Object::~Object()
{
	delete renderer;
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
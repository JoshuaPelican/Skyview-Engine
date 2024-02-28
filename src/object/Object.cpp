#include "Object.h"

#include <typeinfo>

#include "../rendering/Sprite.h"
#include "../collision/CollisionData.h"

Object::Object(string name)
{
	this->name = name;
	renderer = Renderer2D(this);
	transform = Transform2D(this);
}

Object::~Object()
{

}

SDL_FRect* Object::GetRect() const
{
	SDL_FRect* rect = new SDL_FRect();
	rect->x = transform.position.x;
	rect->y = transform.position.y;
	rect->w = renderer.sprite->width * transform.scale.x;
	rect->h = renderer.sprite->height * transform.scale.y;

	return rect;
}
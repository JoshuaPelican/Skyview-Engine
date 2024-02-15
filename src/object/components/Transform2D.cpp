#include "Transform2D.h"

#include "../Object.h"

Transform2D::Transform2D(Object* obj)
{
	object = obj;

	position = new SDL_FPoint();
	position->x = 0;
	position->y = 0;

	scale = new SDL_FPoint();
	scale->x = 1;
	scale->y = 1;

	angle = 0;

	center = new SDL_FPoint();
	center->x = obj->renderer->sprite->width;
	center->y = obj->renderer->sprite->height;
	pivot = new SDL_FPoint();
	pivot->x = center->x; // TEMP: Make this configurable
	pivot->y = center->y; // TEMP: Make this configurable
}

Transform2D::~Transform2D()
{

}

void Transform2D::Move(float x, float y)
{
	position->x += x;
	position->y += y;
}

void Transform2D::Rotate(float angle)
{
	this->angle += angle;
}

void Transform2D::Scale(float x, float y)
{
	scale->x *= x;
	scale->y *= y;
}
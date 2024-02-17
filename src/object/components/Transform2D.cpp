#include "Transform2D.h"

#include "../Object.h"

Transform2D::Transform2D(Object* object) : Component(object)
{
	position = new SDL_FPoint();
	position->x = 0;
	position->y = 0;

	scale = new SDL_FPoint();
	scale->x = 1;
	scale->y = 1;

	angle = 0;

	center = new SDL_FPoint();
	pivot = center; // TODO: Make this configurable
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

void Transform2D::RecalculateCenter()
{
	center->x = object->renderer->sprite->width * scale->x / 2;
	center->y = object->renderer->sprite->height * scale->y / 2;
}
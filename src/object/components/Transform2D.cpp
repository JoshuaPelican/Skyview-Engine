#include "Transform2D.h"

#include "../Object.h"

Transform2D::Transform2D(Object* object) : Component(object)
{

}

void Transform2D::Update()
{
	movedThisFrame = false;
}

void Transform2D::Move(float x, float y)
{
	position.x += x;
	position.y += y;

	movedThisFrame = true;
}
void Transform2D::Move(Vector2 movement)
{
	position.x += movement.x;
	position.y += movement.y;

	movedThisFrame = true;
}

void Transform2D::SetPosition(Vector2 position)
{
	this->position = position;
	movedThisFrame = true;
}


void Transform2D::Rotate(float angle)
{
	this->angle += angle;
}

void Transform2D::Scale(float x, float y)
{
	scale.x *= x;
	scale.y *= y;
}

void Transform2D::RecalculateCenter()
{
	if (object->renderer.sprite == NULL)
	{
		center.x = 0;
		center.y = 0;
	}
	else
	{
		center.x = object->renderer.sprite->width / 2.0f * scale.x;
		center.y = object->renderer.sprite->height / 2.0f * scale.y;
	}
}
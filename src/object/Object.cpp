#include "Object.h"

Object::Object(string name, string mediaPath)
{
	this->name = name;
	renderer = new Renderer2D(mediaPath);
}

Object::~Object()
{
	delete renderer;
}
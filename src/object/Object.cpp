#include "Object.h"

Object::Object(char* name, char* imgPath)
{
	this->name = name;
	renderer = new Renderer2D();
	renderer->LoadMedia(imgPath);
}

Object::~Object()
{
	delete renderer;
}
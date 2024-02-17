#pragma once

class Object;

class Component
{
public:
	Component(Object* object);

	virtual void Update() = 0;
	virtual void Enable() = 0;
	virtual void Disable() = 0;

	Object* object;
};


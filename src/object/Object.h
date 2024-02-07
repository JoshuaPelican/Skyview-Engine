#pragma once

#include "../rendering/Renderer2D.h"

class Object
{
public:
	Object(char* name, char* imgPath);
	~Object();
	//void Enable();
	//void Disable();
	//void Update();

	char* name = "";
	Renderer2D* renderer = 0;
};
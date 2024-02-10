#pragma once

#include <string>
using namespace std;

#include "../rendering/Renderer2D.h"

class Object
{
public:
	Object(string name, string imgPath);
	~Object();
	//void Enable();
	//void Disable();
	//void Update();

	string name = "New Object";
	Renderer2D* renderer = 0;
};
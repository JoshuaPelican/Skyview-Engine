#pragma once

#include <string>
using namespace std;

#include "../object/components/Renderer2D.h"
#include "../object/components/Transform2D.h"

class Object
{
public:
	Object(string name, string imgPath);
	~Object();
	//void Enable();
	//void Disable();
	//void Update();

	SDL_FRect* GetRect() const;

	string name = "New Object";
	Renderer2D* renderer = 0;
	Transform2D* transform = 0;
};
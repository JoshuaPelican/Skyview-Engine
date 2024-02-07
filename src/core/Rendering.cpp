#include "Rendering.h"

Rendering::Rendering()
{
	Enable();
}

Rendering::~Rendering()
{
	Disable();
}

void Rendering::Enable()
{
	window = new Window("Window Name", 0, 0, 500, 500);
}

void Rendering::Update()
{
	window->Clear();

	for each (Object* obj in gameState->objects)
	{
		if (obj->renderer->surface == NULL)
			continue;

		window->Blit(obj->renderer->surface);
	}

	window->Draw();
}

void Rendering::Disable()
{
	delete window;
}
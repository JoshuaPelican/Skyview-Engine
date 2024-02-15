#include "Rendering.h"

#include "../rendering/Window.h"
#include "../object/components/Renderer2D.h"
#include "../object/Object.h"
#include "GameState.h"

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
		RenderObject(obj);
	}

	window->Draw();
}

void Rendering::Disable()
{
	delete window;
}

void Rendering::RenderObject(Object* obj)
{
	if (obj->renderer->sprite == NULL)
		return;

	if (!obj->renderer->sprite->isLoaded)
		if (!obj->renderer->sprite->LoadMedia(window->renderer))
			return;

	SDL_RenderCopyExF(window->renderer, obj->renderer->sprite->texture, NULL, obj->GetRect(), obj->transform->angle, obj->transform->pivot, SDL_FLIP_NONE);
}
#include "Rendering.h"

#include "../rendering/Window.h"
#include "../object/components/Renderer2D.h"
#include "../object/Object.h"
#include "GameState.h"

Rendering::Rendering()
{
	window = new Window("Window Name", 0, 0, 500, 500);
}

Rendering::~Rendering()
{
	delete window;
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

void Rendering::RenderObject(Object* obj)
{
	if (obj->renderer.sprite == NULL)
		return;

	if (!obj->renderer.sprite->isLoaded)
		if (!obj->renderer.LoadMedia(window->renderer))
			return;

	SDL_FPoint* pivot = new SDL_FPoint();
	pivot->x = obj->transform.pivot.x;
	pivot->y = obj->transform.pivot.y;

	SDL_RenderCopyExF(window->renderer, obj->renderer.sprite->texture, NULL, obj->GetRect(), obj->transform.angle, pivot, SDL_FLIP_NONE);
}

void Rendering::DrawRectOutline(SDL_FRect rect, int r, int g, int b)
{
	SDL_SetRenderDrawColor(window->renderer, r, g, b, 1);
	SDL_RenderDrawRectF(window->renderer, &rect);
	window->Draw();
}
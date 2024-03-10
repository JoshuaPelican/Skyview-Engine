#include "Debug.h"

#include "../object/Object.h"
#include "GameState.h"
#include "../object/components/BoxCollider2D.h"
#include "../object/components/CircleCollider2D.h"
#include "../rendering/Window.h"

bool Debug::drawColliders = true;

void Debug::Update()
{
	for (list<Object*>::const_iterator it = gameState->objects.begin(); it != gameState->objects.end(); it++)
	{
		Object* object = *it;

		if (object->collider == 0)
			continue;

		SDL_FRect objRect = *object->GetRect();
		SDL_FRect rect;

		CircleCollider2D* circle = dynamic_cast<CircleCollider2D*>(object->collider);
		if (circle != 0)
		{
			rect = { objRect.x, objRect.y, circle->radius * 2 * circle->object->transform.scale.x, circle->radius * 2 * circle->object->transform.scale.x };
		}


		BoxCollider2D* box = dynamic_cast<BoxCollider2D*>(object->collider);
		if (box != 0)
		{
			rect = { objRect.x, objRect.y, box->size.x * box->object->transform.scale.x, box->size.y * box->object->transform.scale.y };
		}

		renderModule->DrawRectOutline(rect, 0, 255, 0);

		if (it == gameState->objects.end())
			break;
	}

	renderModule->window->Draw();
}

void Debug::SetRenderer(Rendering* renderModule)
{
	this->renderModule = renderModule;
}



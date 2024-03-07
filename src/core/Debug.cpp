#include "Debug.h"

#include "../object/Object.h"
#include "GameState.h"
#include "../object/components/BoxCollider2D.h"

void Debug::Update()
{
	for (list<Object*>::const_iterator it = gameState->objects.begin(); it != gameState->objects.end(); it++)
	{
		Object* object = *it;

		if (object->collider == 0)
			continue;

		BoxCollider2D* box = dynamic_cast<BoxCollider2D*>(object->collider);

		if (box == 0)
			continue;

		/*
		SDL_FRect objRect = *object->GetRect();
		SDL_FRect rect = {objRect.x, objRect.y, box->size.x, box->size.y};
		renderModule->DrawRectOutline(rect, 0, 255, 0);
		*/
	}
}

void Debug::SetRenderer(Rendering* renderModule)
{
	this->renderModule = renderModule;
}



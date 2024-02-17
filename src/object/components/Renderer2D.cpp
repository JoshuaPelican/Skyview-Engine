#include "Renderer2D.h"

#include "../Object.h"

void Renderer2D::SetSprite(string mediaPath)
{
	if (!sprite)
		sprite = new Sprite();

	sprite->SetMedia(mediaPath);
}

bool Renderer2D::LoadMedia(SDL_Renderer* renderer)
{
	if (sprite->LoadMedia(renderer))
	{
		object->transform->RecalculateCenter();
		return true;
	}
	return false;
}

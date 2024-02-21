#include "Player.h"

void Player::Enable()
{
}

void Player::Update()
{
	float speed = 100;
	float x = 0, y = 0;

	if (Input::GetKeyDown(SDL_SCANCODE_RIGHT))
	{
		x += 1;
	}
	if (Input::GetKeyDown(SDL_SCANCODE_LEFT))
	{
		x -= 1;
	}
	if (Input::GetKeyDown(SDL_SCANCODE_UP))
	{
		y -= 1;
	}
	if (Input::GetKeyDown(SDL_SCANCODE_DOWN))
	{
		y += 1;
	}

	x *= speed;
	y *= speed;
	x *= Time::deltaTime;
	y *= Time::deltaTime;

	object->transform->Move(x, y);
}

void Player::Disable()
{
}

#include "Player.h"

#include <cmath>

void Player::Enable()
{
}

void Player::Update()
{
	float speed = 100;
	Vector2 movement = Vector2(Input::GetKeyDown(SDL_SCANCODE_RIGHT) + -Input::GetKeyDown(SDL_SCANCODE_LEFT), -Input::GetKeyDown(SDL_SCANCODE_UP) + Input::GetKeyDown(SDL_SCANCODE_DOWN));

	// Speed & Framerate Independence
	movement = movement.Normalized() * speed * Time::deltaTime;

	if (movement == Vector2(0, 0))
		return;

	object->transform.Move(movement.x, movement.y);
}

void Player::Disable()
{
}

void Player::OnCollision(CollisionData data)
{
	
}
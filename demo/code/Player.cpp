#include "Player.h"

void Player::Enable()
{
}

void Player::Update()
{
	object->transform->Move(0.01f, 0);
}

void Player::Disable()
{
}

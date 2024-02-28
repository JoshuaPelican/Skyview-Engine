#include "Input.h"

const Uint8* Input::keyStates = NULL;

void Input::Update()
{
	Input::keyStates = SDL_GetKeyboardState(NULL);
}

int Input::GetKeyDown(SDL_Scancode keyCode)
{
	return Input::keyStates[keyCode];
}
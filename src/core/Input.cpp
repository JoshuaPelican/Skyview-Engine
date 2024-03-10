#include "Input.h"

const Uint8* Input::keyStates = NULL;
Vector2 Input::mousePosition = Vector2(0, 0);
bool Input::leftMouseDown = false;

void Input::Update()
{
	Input::keyStates = SDL_GetKeyboardState(NULL);

	int mouseX = 0;
	int mouseY = 0;

	Uint32 mouseState = SDL_GetMouseState(&mouseX, &mouseY);

	Input::mousePosition = Vector2(mouseX, mouseY);
	Input::leftMouseDown = SDL_BUTTON(1) == mouseState;
}

int Input::GetKeyDown(SDL_Scancode keyCode)
{
	return Input::keyStates[keyCode];
}
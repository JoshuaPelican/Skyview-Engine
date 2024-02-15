#pragma once

#include "Module.h"

class Object;
class Window;

class Rendering : public Module
{
	public:
		Rendering();
		~Rendering();
		void Update() override;

		void RenderObject(Object* obj);

		Window* window;

	private:
		void Enable() override;
		void Disable() override;
};
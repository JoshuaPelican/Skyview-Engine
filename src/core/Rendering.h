#pragma once

#include "Module.h"
#include "../rendering/Window.h"
#include "../rendering/Renderer2D.h"

class Rendering : public Module
{
	public:
		Rendering();
		~Rendering();
		void Update() override;
		Window* window;

	private:
		void Enable() override;
		void Disable() override;
};
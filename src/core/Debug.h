#pragma once

#include "Module.h"
#include "Rendering.h"

class Debug : public Module
{
public:
	void Update() override;

	void SetRenderer(Rendering* renderModule);

	Rendering* renderModule = 0;
};


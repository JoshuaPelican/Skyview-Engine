#pragma once

#include "../src/SkyviewEngine.h"
#include "../src/core/Application.h"

class DemoApp : public Application
{
public:
	DemoApp(string name) : Application(name) {};
	void Load() override;
};
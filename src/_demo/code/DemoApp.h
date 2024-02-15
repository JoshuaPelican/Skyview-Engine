#pragma once

#include "../../SkyviewEngine.h"
#include "../../core/Application.h"

class DemoApp : public Application
{
public:
	DemoApp(string name) : Application(name) {};
	void Load() override;
};
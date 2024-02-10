#pragma once

#include "../../SkyviewEngine.h"

class DemoApp : public Application
{
public:
	DemoApp(string name) : Application(name) {};
	void Load() override;
};
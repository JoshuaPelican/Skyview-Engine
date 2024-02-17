#pragma once

#include <string>
using namespace std;

class Application
{
public:
	Application(string name);
	~Application();
	virtual void Load() = 0;

	string name;
};


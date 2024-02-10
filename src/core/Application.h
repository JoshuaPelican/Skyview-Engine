#pragma once

#include <string>
using namespace std;

class Application
{
public:
	Application(string appName);
	~Application();
	virtual void Load() = 0;

	string appName;
};


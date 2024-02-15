#pragma once

#include <list>
using namespace std;

class Object;

class GameState
{
public:
	std::list<Object*> objects;
};


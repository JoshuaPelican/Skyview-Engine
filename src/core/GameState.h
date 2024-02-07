#pragma once

#include <list>
#include "../object/Object.h"

using namespace std;

class GameState
{
public:
	std::list<Object*> objects;
};


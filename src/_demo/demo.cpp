#include <SDL.h>
#include <stdio.h>
#include "../SkyviewEngine.h"

//Screen dimension constants
const int SCREEN_WIDTH = 640;
const int SCREEN_HEIGHT = 480;

int main(int argc, char* args[])
{
	SkyviewEngine* engine = new SkyviewEngine();
	
	//Destroy window
	delete engine;

	return 0;
}
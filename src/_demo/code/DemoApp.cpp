#include "DemoApp.h"

int main(int argc, char* args[])
{
	DemoApp* app = new DemoApp("App Name");
	SkyviewEngine* engine = new SkyviewEngine(app);
	delete app;
	delete engine;

	return 0;
}

void DemoApp::Load()
{
	SE->CreateObject("Test Object 1", "./src/_demo/images/test.bmp");
}
#include "DemoApp.h"

#include "Player.h"

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
	Object* obj = SE->CreateObject("Player", "./demo/images/test.bmp");
	obj->AddComponent(new Player(obj));
	obj->transform->Move(100, 100);
	obj->transform->Scale(0.5f, 0.5f);
}
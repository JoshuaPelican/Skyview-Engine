#include "DemoApp.h"

#include "Player.h"

int main(int argc, char* args[])
{
	DemoApp app = DemoApp("App Name");
	SkyviewEngine engine = SkyviewEngine(&app);

	return 0;
}

void DemoApp::Load()
{
	Object* obj = SE->CreateObject("Player", "./demo/images/circle.png");
	obj->AddComponent(new Player(obj));
	obj->transform->Move(100, 100);
	obj->transform->Scale(0.5f, 0.5f);
}
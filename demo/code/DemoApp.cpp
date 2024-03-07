#include "DemoApp.h"

#include "Player.h"
#include "Damageable.h"
#include "HurtZone.h"

int main(int argc, char* args[])
{
	DemoApp app = DemoApp("App Name");
	SkyviewEngine engine = SkyviewEngine(&app);

	return 0;
}

void DemoApp::Load()
{
	Object* player = SE->CreateObject("Player", "./demo/images/circle.png");
	player->collider = new CircleCollider2D(player);
	player->AddComponent<Player>();
	Damageable* d = player->AddComponent<Damageable>();
	d->maxHealth = 100;
	player->transform.Scale(0.5f, 0.5f);
	player->transform.Move(250, 250);


	Object* wall = SE->CreateObject("Wall R", "./demo/images/square.png");
	wall->collider = new BoxCollider2D(wall);
	wall->transform.Move(500, 250);
	wall->transform.Scale(0.5f, 2.5f);

	wall = SE->CreateObject("Wall L", "./demo/images/square.png");
	wall->collider = new BoxCollider2D(wall);
	wall->transform.Move(0, 250);
	wall->transform.Scale(0.5f, 2.5f);

	wall = SE->CreateObject("Wall T", "./demo/images/square.png");
	wall->collider = new BoxCollider2D(wall);
	wall->transform.Move(250, 0);
	wall->transform.Scale(2.5f, 0.5f);

	wall = SE->CreateObject("Wall B", "./demo/images/square.png");
	wall->collider = new BoxCollider2D(wall);
	wall->transform.Move(250, 500);
	wall->transform.Scale(2.5f, 0.5f);

	/*
	Object* ball = SE->CreateObject("Circle", "./demo/images/circle.png");
	ball->collider = new CircleCollider2D(ball);
	ball->collider->isTrigger = true;
	HurtZone* h = ball->AddComponent<HurtZone>();
	h->zoneDamage = 20;
	ball->transform.Move(300, 300);
	ball->transform.Scale(0.5f, 0.5f);
	*/
}
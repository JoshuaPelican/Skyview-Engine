#include "DemoApp.h"

#include "code/Player.h"
#include "code/Damageable.h"
#include "code/HurtZone.h"
#include "code/Sword.h"

int main(int argc, char* args[])
{
	DemoApp app = DemoApp("App Name");
	SkyviewEngine engine = SkyviewEngine(&app);

	return 0;
}

void DemoApp::Load()
{
	Object* sword = SE->CreateObject("Sword", "./demo/images/weapon_dagger.png");
	Sword* s = sword->AddComponent<Sword>();
	auto cSword = new CircleCollider2D(sword);
	sword->collider = cSword;
	cSword->radius = 16;
	sword->collider->isTrigger = true;

	Object* player = SE->CreateObject("Player", "./demo/images/green_character.png");
	auto cPlayer = new CircleCollider2D(player);
	player->collider = cPlayer;
	cPlayer->radius = 32;
	player->AddComponent<Player>();
	Damageable* dPlayer = player->AddComponent<Damageable>();
	dPlayer->maxHealth = 100;
	player->transform.Move(250, 250);

	s->pivot = &player->transform;

	Object* wall = SE->CreateObject("Wall R", "./demo/images/tile.png");
	wall->collider = new BoxCollider2D(wall);
	wall->transform.Move(500, 250);
	wall->transform.Scale(0.5f, 9);
	wall->transform.Rotate(0);

	wall = SE->CreateObject("Wall L", "./demo/images/tile.png");
	wall->collider = new BoxCollider2D(wall);
	wall->transform.Move(0, 250);
	wall->transform.Scale(0.5, 9);

	wall = SE->CreateObject("Wall T", "./demo/images/tile.png");
	wall->collider = new BoxCollider2D(wall);
	wall->transform.Move(250, 0);
	wall->transform.Scale(9, 0.5f);

	wall = SE->CreateObject("Wall B", "./demo/images/tile.png");
	wall->collider = new BoxCollider2D(wall);
	wall->transform.Move(250, 500);
	wall->transform.Scale(9, 0.5f);

	for (size_t i = 0; i < 6; i++)
	{
		Object* enemy = SE->CreateObject("Enemy", "./demo/images/red_character.png");
		auto cEnemy = new CircleCollider2D(enemy);
		enemy->collider = cEnemy;
		cEnemy->radius = 32;
		Damageable* dEnemy = enemy->AddComponent<Damageable>();
		dEnemy->currentHealth = 100;
		enemy->transform.Move(100 + 64 * i, 350);
		HurtZone* hEnemy = enemy->AddComponent<HurtZone>();
		hEnemy->zoneDamage = 1;
	}
}
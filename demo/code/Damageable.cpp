#include "Damageable.h"

void Damageable::Update()
{
}

void Damageable::Enable()
{
}

void Damageable::Disable()
{
}

void Damageable::TakeDamage(float damage)
{
	currentHealth -= damage;

	printf("Ouch!");

	if (currentHealth <= 0)
		isDead = true;

	SE->DestroyObject(this->object);
}
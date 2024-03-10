#include "Damageable.h"

void Damageable::Update()
{
}

void Damageable::Enable()
{
	currentHealth = maxHealth;
}

void Damageable::Disable()
{
}

void Damageable::TakeDamage(float damage)
{
	currentHealth -= damage;

	printf("Ouch! {%f} health\n", currentHealth);

	if (currentHealth <= 0)
	{
		isDead = true;
		SE->DestroyObject(this->object);
	}
}
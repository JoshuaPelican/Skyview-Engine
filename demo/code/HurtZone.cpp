#include "HurtZone.h"

#include "Damageable.h"

HurtZone::HurtZone(Object* object) : Component(object)
{

}

void HurtZone::Update()
{
}

void HurtZone::Enable()
{
}

void HurtZone::Disable()
{
}

void HurtZone::OnCollision(CollisionData collision)
{
	Damageable* d = collision.other->object->GetComponent<Damageable>();

	if (!d)
		return;

	d->TakeDamage(zoneDamage * Time::deltaTime);

	printf("{%f}", Time::deltaTime);
}

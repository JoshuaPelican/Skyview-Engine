#include "Sword.h"

#include "Damageable.h"

void Sword::Update()
{
	object->transform.SetPosition((Input::mousePosition - pivot->object->transform.position).Normalized() * 50 + pivot->position + object->transform.center - Vector2(16, 16));
	object->transform.pivot = pivot->center - Vector2(8, 8);
	object->transform.angle = Math::AngleAwayFromPoint(object->transform.position + object->transform.center, pivot->position + pivot->center) - 90;
}

void Sword::Enable()
{
}

void Sword::Disable()
{
}

void Sword::OnCollision(CollisionData collision)
{
	if (collision.other == pivot->object->collider)
		return;

	printf("Collision with Sword!\n");

	Damageable* d = collision.other->object->GetComponent<Damageable>();

	if (!d)
		return;

	d->TakeDamage(1);
}

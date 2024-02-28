#include "Collision.h"

#include "GameState.h"
#include "../core/Math.h"
#include "../core/Time.h"
#include "../object/Object.h"
#include "../collision/Collider2D.h"

void Collision::Update()
{
	for each (Object * obj in gameState->objects)
	{
		if (obj->collider == NULL)
			continue;

		if (obj->transform.movedThisFrame == false)
			continue;

		CheckForCollisions(obj->collider);
	}
}

void Collision::CheckForCollisions(Collider2D* collider)
{
	for each (Object * other in gameState->objects)
	{
		if (other == collider->object) // Object is self; ignore
			continue;

		if (other->collider == NULL) // Object has no collider; ignore
			continue;

		if (collider->IsColliding(other->collider) == false) // Object is not colliding with anything; ignore
			continue;


		CollisionData data = collider->GetCollision(other->collider);

		if(collider->isTrigger == false && other->collider->isTrigger == false)
			collider->object->transform.Move(data.hitNormal * data.separation);
		
		for each (Component* component in collider->object->components)
			component->OnCollision(data);

		CollisionData otherData = other->collider->GetCollision(collider);

		for each (Component * component in other->components)
			component->OnCollision(otherData);
	}
}

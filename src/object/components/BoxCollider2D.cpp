#include "BoxCollider2D.h"

#include "../Object.h"
#include "CircleCollider2D.h"

BoxCollider2D::BoxCollider2D(Object* object) : Collider2D (object)
{

}

bool BoxCollider2D::IsColliding(Collider2D* other)
{
	CircleCollider2D* otherCircle = dynamic_cast<CircleCollider2D*>(other);
	if (otherCircle != 0)
	{

	}

	return false;
}

CollisionData BoxCollider2D::GetCollision(Collider2D* other)
{
	return CollisionData(other, Vector2(0, 0), Vector2(0, 0), 0);
}

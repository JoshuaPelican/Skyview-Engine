#include "CircleCollider2D.h"

#include "../Object.h"

CircleCollider2D::CircleCollider2D(Object* object) : Collider2D(object)
{

}

bool CircleCollider2D::IsColliding(Collider2D* other)
{
	CircleCollider2D* otherCircle = dynamic_cast<CircleCollider2D*>(other);
	if (otherCircle != 0)
	{
		return sqrt(Vector2::SquaredDistance(this->center + this->object->transform.position, otherCircle->center + otherCircle->object->transform.position)) 
			< this->radius + otherCircle->radius;
	}

	return false;
}

CollisionData CircleCollider2D::GetCollision(Collider2D* other)
{
	CircleCollider2D* otherCircle = dynamic_cast<CircleCollider2D*>(other);
	if (otherCircle != 0)
	{
		Vector2 otherPos = otherCircle->center + otherCircle->object->transform.position;
		Vector2 thisPos = this->center + this->object->transform.position;
		float totalRadius = this->radius + otherCircle->radius;
		float collisionDistance = sqrt(Vector2::SquaredDistance(thisPos, otherPos));
		float intersectionAmount = totalRadius - collisionDistance;
		Vector2 normal = (thisPos - otherPos) / collisionDistance;
		Vector2 hitPoint = otherPos + (normal * radius);

		return CollisionData(other, hitPoint, normal, intersectionAmount);
	}

	return CollisionData(other, Vector2(0, 0), Vector2(0, 0), 0);
}

#include "CircleCollider2D.h"

#include "../Object.h"
#include "BoxCollider2D.h"

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

	BoxCollider2D* otherBox = dynamic_cast<BoxCollider2D*>(other);
	if (otherBox != 0)
	{
		Vector2 otherPos = otherBox->center + otherBox->object->transform.position;
		Vector2 thisPos = this->center + this->object->transform.position;

		float leftEdge = otherPos.x - otherBox->size.x * otherBox->object->transform.scale.x / 2;
		float rightEdge = otherPos.x + otherBox->size.x * otherBox->object->transform.scale.x / 2;
		float topEdge = otherPos.y - otherBox->size.y * otherBox->object->transform.scale.y / 2;
		float bottomEdge = otherPos.y + otherBox->size.y * otherBox->object->transform.scale.y / 2;

		float testX = thisPos.x;
		float testY = thisPos.y;

		//Find closest x offset
		if (thisPos.x < leftEdge)		 testX = leftEdge;
		else if (thisPos.x > rightEdge)  testX = rightEdge;

		//Find closest y offset
		if (thisPos.y < topEdge)		 testY = topEdge;
		else if (thisPos.y > bottomEdge) testY = bottomEdge;

		float squaredDistance = Vector2::SquaredDistance(thisPos, Vector2(testX, testY));
		
		// if the distance is less than the radius, collision!
		return squaredDistance <= this->radius * this->object->transform.scale.Length() * this->radius * this->object->transform.scale.Length();
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

	BoxCollider2D* otherBox = dynamic_cast<BoxCollider2D*>(other);
	if (otherBox != 0)
	{
		Vector2 otherPos = otherBox->center + otherBox->object->transform.position;
		Vector2 thisPos = this->center + this->object->transform.position;

		float leftEdge = otherPos.x - otherBox->size.x * otherBox->object->transform.scale.x / 2;
		float rightEdge = otherPos.x + otherBox->size.x * otherBox->object->transform.scale.x / 2;
		float topEdge = otherPos.y - otherBox->size.y * otherBox->object->transform.scale.y / 2;
		float bottomEdge = otherPos.y + otherBox->size.y * otherBox->object->transform.scale.y / 2;

		float testX = thisPos.x;
		float testY = thisPos.y;

		//Find closest x offset
		if (thisPos.x < leftEdge)		 testX = leftEdge;
		else if (thisPos.x > rightEdge)  testX = rightEdge;

		//Find closest y offset
		if (thisPos.y < topEdge)		 testY = topEdge;
		else if (thisPos.y > bottomEdge) testY = bottomEdge;

		Vector2 closestPoint = Vector2(testX, testY);

		float squaredDistance = Vector2::SquaredDistance(thisPos, closestPoint);

		Vector2 hitNormal = (thisPos - closestPoint).Normalized();
		float separation = this->radius * this->object->transform.scale.Length() - sqrt(squaredDistance);

		return CollisionData(other, closestPoint, hitNormal, separation);
	}

	return CollisionData(other, Vector2(0, 0), Vector2(0, 0), 0);
}

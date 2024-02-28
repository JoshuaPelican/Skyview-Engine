#include "CollisionData.h"

CollisionData::CollisionData(Collider2D* other, Vector2 hitPoint, Vector2 hitNormal, float separation)
{
	this->other = other;
	this->separation = separation;
	this->hitPoint = hitPoint;
	this->hitNormal = hitNormal;
}

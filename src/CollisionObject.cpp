#include "CollisionObject.h"
#include "BoundingObject.h"

CollisionObject::CollisionObject(const BoundingObject &boundingObject, const Vector2 position) 
		: _boundingObject(boundingObject), position(position), velocity(Vector2(0.0f, 0.0f)), acceleration(Vector2(0.0f, 0.0f)) {
}

int CollisionObject::getCollisionSystemHandle() const {
	return _handle;
}

void CollisionObject::setCollisionSystemHandle(int handle) {
	_handle = handle;
}

bool CollisionObject::collidesWith(float millis, const CollisionObject &object) const {
	return _boundingObject.intersects(object._boundingObject);
}

const BoundingObject& CollisionObject::getBoundingObject() const {
	return _boundingObject;
}

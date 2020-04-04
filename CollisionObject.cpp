#include "CollisionObject.h"

CollisionObject::CollisionObject(const Vector2 position) 
    : position(position), velocity(Vector2(0.0f, 0.0f)), acceleration(Vector2(0.0f, 0.0f)) {
}

int CollisionObject::getCollisionSystemHandle() const {
  return _handle;
}

void CollisionObject::setCollisionSystemHandle(int handle) {
  _handle = handle;
}

bool CollisionObject::collidesWith(float millis, const CollisionObject &object) const {
  return false;
}

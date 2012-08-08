#include "Collision.h"

using namespace std;

Collision::Collision(float millis, CollisionObject &obj1, CollisionObject &obj2) : millis(millis), obj1(obj1), obj2(obj2) {
}

float Collision::getMillis() const {
	return millis;
}

CollisionObject& Collision::getObject1() {
	return obj1;
}

CollisionObject& Collision::getObject2() {
	return obj2;
}

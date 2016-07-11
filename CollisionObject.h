#ifndef COLLISION_OBJECT_H
#define COLLISION_OBJECT_H

#include "Vector2.h"

class CollisionObject {
	int _handle;

	public:
		CollisionObject(const Vector2 position);

		int getCollisionSystemHandle() const;
		void setCollisionSystemHandle(int handle);
		bool collidesWith(float millis, const CollisionObject &object) const;
		void update(float millis);

		Vector2 position, velocity, acceleration;

};

#endif

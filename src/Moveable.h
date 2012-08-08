#ifndef MOVEABLE_H
#define MOVEABLE_H

#include "CollisionObject.h"
#include "BoundingObject.h"

class Moveable : public CollisionObject {
	public:
		Moveable(Vector2 position, BoundingObject boundingObject);

		Vector2 getPosition() const;
		Vector2 getVelocity() const;
		Vector2 getAcceleration() const;

		void setPosition(Vector2 position);
		void setVelocity(Vector2 velocity);
		void setAcceleration(Vector2 acceleration);
		
		void update(float millis);

	private:
		Vector2 position, velocity, acceleration;

};

#endif

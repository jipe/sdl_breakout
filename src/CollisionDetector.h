#ifndef COLLISION_DETECTOR_H
#define COLLISION_DETECTOR_H

#include "CollisionObject.h"
#include "Collision.h"

#include <vector>

using namespace std;

class CollisionDetector {
	public:
		CollisionDetector();

		void add(CollisionObject &obj);
		void remove(CollisionObject &obj);

		vector<Collision> update(float millis);

	private:
    /* TODO: Use a more elaborate container like a grid or something like that
             so only objects that are actually close to each other are tested
             for collision.
     */
		vector<CollisionObject*> objects;
		
};

#endif

#ifndef COLLISION_DETECTOR_H
#define COLLISION_DETECTOR_H

#include "CollisionObject.h"
#include "Collision.h"

#include <vector>

using namespace std;

class CollisionDetector {
  vector<CollisionObject*> _objects;

  public:
    CollisionDetector();

    void add(CollisionObject &obj);
    void remove(CollisionObject &obj);

    vector<Collision> update(float millis);

};

#endif

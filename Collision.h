#ifndef COLLISION_H
#define COLLISION_H

#include "CollisionObject.h"

class Collision {
  float millis;
  CollisionObject &obj1, &obj2;

  public:
    Collision(float millis, CollisionObject& obj1, CollisionObject& obj2);

    float getMillis() const;
    CollisionObject& getObject1();
    CollisionObject& getObject2();

};

#endif

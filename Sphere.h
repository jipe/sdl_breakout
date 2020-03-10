#ifndef SPHERE_H
#define SPHERE_H

#include "Geometry.h"
#include "vector.h"

class Sphere : public Geometry {
  Vector2 &_center;
  float _radius;
  
  public:
    Sphere(float x0, float y0, float radius);
    Sphere(Vector2 center, float radius);

    float radius() const { return _radius; }

    virtual Vector2 center() const { return Vector2(_center); }

};

#endif

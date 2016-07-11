#ifndef GEOMETRY_H
#define GEOMETRY_H

#include "Vector2.h"

class Sphere;
class Box;

class Geometry {

  bool _intersects(const Geometry *g1, const Geometry *g2) const;
  bool _intersects(const Sphere &sphere1, const Sphere &sphere2) const;
  bool _intersects(const Sphere &sphere, const Box &box) const;
  bool _intersects(const Box &box1, const Box &box2) const;

  public:

    virtual Vector2 center() const = 0;
    bool intersects(const Geometry *geometry) const;

};

#endif

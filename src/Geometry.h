#ifndef GEOMETRY_H
#define GEOMETRY_H

#include "Vector2.h"

class Geometry {

  virtual const Vector2& center() const = 0;
  virtual bool intersects(Geometry &geometry) const = 0;

};

#endif

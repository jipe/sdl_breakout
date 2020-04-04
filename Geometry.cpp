#include "Geometry.h"
#include "vector.h"
#include "Edge.h"
#include "Sphere.h"
#include "Box.h"

bool Geometry::intersects(const Geometry *geometry) const {
  return false;
}

bool Geometry::_intersects(const Geometry *g1, const Geometry *g2) const {
  const Sphere *sphere1, *sphere2;
  const Box *box1, *box2;

  if ((sphere1 = dynamic_cast<const Sphere*>(g1)) != 0) {
    if ((sphere2 = dynamic_cast<const Sphere*>(g2)) != 0) {
      return _intersects(*sphere1, *sphere2);
    } else if ((box2 = dynamic_cast<const Box*>(g2)) != 0) {
      return _intersects(*sphere1, *box2);
    }
  } else if ((box1 = dynamic_cast<const Box*>(g1)) != 0) {
    if ((sphere2 = dynamic_cast<const Sphere*>(g2)) != 0) {
      return _intersects(*sphere2, *box1);
    } else if ((box2 = dynamic_cast<const Box*>(g2)) != 0) {
      return _intersects(*box1, *box2);
    }
  }
  return false;
}

bool Geometry::_intersects(const Sphere &sphere1, const Sphere &sphere2) const {
  return false;
}

bool Geometry::_intersects(const Sphere &sphere, const Box &box) const {
  return false;
}

bool Geometry::_intersects(const Box &box1, const Box &box2) const {
  return false;
}

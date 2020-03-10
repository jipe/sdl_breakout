#ifndef BOX_H
#define BOX_H

#include "vector.h"
#include "Edge.h"
#include "Geometry.h"

class Box : public Geometry {
  Vector2 _p1, _p2, _p3, _p4;
  Edge _e1, _e2, _e3, _e4;

  public:
    Box(float x0, float y0, float x1, float y1);
    Box(Vector2 &p1, Vector2 &p2, Vector2 &p3, Vector2 &p4);

    const Vector2& p1() const { return _p1; }
    const Vector2& p2() const { return _p2; }
    const Vector2& p3() const { return _p3; }
    const Vector2& p4() const { return _p4; }

    const Edge& e1() const { return _e1; }
    const Edge& e2() const { return _e2; }
    const Edge& e3() const { return _e3; }
    const Edge& e4() const { return _e4; }

    virtual Vector2 center() const;
};

#endif

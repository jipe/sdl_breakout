#include "Box.h"
#include "vector.h"
#include "Edge.h"

Box::Box(float x0, float y0, float x1, float y1) : _p1(x0,y0), _p2(x1,y0), _p3(x1,y1), _p4(x0,y1),
    _e1(_p1, _p2), _e2(_p2, _p3), _e3(_p3, _p4), _e4(_p4, _p1) {
}

Box::Box(Vector2 &p1, Vector2 &p2, Vector2 &p3, Vector2 &p4) :
    _p1(p1), _p2(p2), _p3(p3), _p4(p4), 
    _e1(_p1, _p2), _e2(_p2, _p3), _e3(_p3, _p4), _e4(_p4, _p1) {
}

Vector2 Box::center() const {
  float x = (_p1.x + _p2.x + _p3.x + _p4.x) / 4.0f;
  float y = (_p1.y + _p2.y + _p3.y + _p4.y) / 4.0f;
  return Vector2(x, y);
}

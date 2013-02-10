#include "Edge.h"
#include "Vector2.h"
#include "Matrix2x2.h"
#include "Screen.h"

#include "math.h"

Edge::Edge(const Vector2 &p1, const Vector2 &p2) : _p1(p1), _p2(p2) {
}

bool Edge::intersects(const Edge &edge) const {
  Vector2 e1(p1(), p2());
  Vector2 v1(p1(), edge.p1());
  Vector2 v2(p1(), edge.p2());
  float sign = sgn(Matrix2x2(e1.x, e1.y, v1.x, v1.y).det());
  sign *= Matrix2x2(e1.x, e1.y, v2.x, v2.y).det();

  if (sign > 0) {
    return false;
  }

  Vector2 e2(edge.p1(), edge.p2());
  v1 = Vector2(edge.p1(), p1());
  v2 = Vector2(edge.p1(), p2());

  sign = sgn(Matrix2x2(e2.x, e2.y, v1.x, v1.y).det());
  sign *= Matrix2x2(e2.x, e2.y, v2.x, v2.y).det();
  return sign < 0;
}

void Edge::render(Screen &screen) const {
  screen.drawLine(p1().x, p1().y, p2().x, p2().y);
}

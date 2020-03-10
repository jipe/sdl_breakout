#ifndef EDGE_H
#define EDGE_H

#include "vector.h"
#include "Screen.h"

class Edge {
  Vector2 &_p1, &_p2;
  
  public:
    Edge(Vector2 &p1, Vector2 &p2);

    const Vector2& p1() const { return _p1; }
    const Vector2& p2() const { return _p2; }

    bool intersects(const Edge &edge) const;
    void render(Screen &screen) const;

    Edge& operator=(const Edge &edge);
};

#endif

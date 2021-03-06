#ifndef VERTEX_H
#define VERTEX_H

#include "vector.h"
#include "Color.h"

struct Vertex {
  Vector3 point;
  Vector3 normal;
  Vector3 color;
  Vector2 texture_coord;

  Vertex(Vector3& point, Vector3& normal, Color& color, Vector2& texture_coord);
  Vertex(Vector3& point, Vector3& normal, Vector3& color, Vector2& texture_coord);
};
#endif

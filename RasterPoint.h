#ifndef RASTER_POINT_H
#define RASTER_POINT_H

#include "Vector2.h"
#include "Vector3.h"
#include "Vertex.h"

struct RasterPoint {
  int x, y;
  Vector3 color;
  Vector3 normal;
  Vector2 texture_coord;

  RasterPoint(const Vertex &v);
};

#endif

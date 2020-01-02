#ifndef RASTER_EDGE_H
#define RASTER_EDGE_H

#include "RasterPoint.h"
#include "Vector2.h"
#include "Vector3.h"

struct RasterEdge {
  int y, y_max;
  int dx, dy;
  int floor_dx_dy;
  int f;
  int df;
  int x;
  float interpolation_factor;
  Vector3 color;
  Vector3 d_color;
  Vector3 normal;
  Vector3 d_normal;
  Vector2 texture_coord;
  Vector2 d_texture_coord;

  RasterEdge(const RasterPoint& p1, const RasterPoint& p2);
  void nextLine();
};

#endif

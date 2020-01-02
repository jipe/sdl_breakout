#include "RasterEdge.h"
#include "RasterPoint.h"
#include "Vector3.h"
#include "math.h"

#include <cmath>

RasterEdge::RasterEdge(const RasterPoint& p1, const RasterPoint& p2)
  : y(p1.y),
    y_max(p2.y),
    dx(p2.x - p1.x),
    dy(p2.y - p1.y),
    floor_dx_dy(static_cast<int>(floor(static_cast<float>(dx) / static_cast<float>(dy)))),
    f(0),
    df(dy * floor_dx_dy - dx),
    x(p1.x),
    interpolation_factor(1.0f / static_cast<float>(abs(dy))),
    color(p1.color),
    normal(p1.normal),
    texture_coord(p1.texture_coord),
    d_color(interpolation_factor * (p2.color - p1.color)),
    d_normal(interpolation_factor * (p2.normal - p1.normal)),
    d_texture_coord(interpolation_factor * (p2.texture_coord - p1.texture_coord)) {
  
}

void RasterEdge::nextLine() {
  y++;
  x += floor_dx_dy;
  f += df;
  if (f < 0) {
    f += dy;
    x++;
  } 
  color += d_color;
  normal += d_normal;
  texture_coord += d_texture_coord;
}

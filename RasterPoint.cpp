#include "RasterPoint.h"
#include "Vertex.h"

RasterPoint::RasterPoint(const Vertex &v)
  : x(static_cast<int>(v.point.x)),
    y(static_cast<int>(v.point.y)),
    color(v.color),
    normal(v.normal),
    texture_coord(v.texture_coord) {
}

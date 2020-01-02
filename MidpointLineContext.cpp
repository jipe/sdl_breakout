#include "MidpointLineContext.h"
#include "RasterPoint.h"
#include "math.h"

MidpointLineContext::MidpointLineContext(const RasterPoint& p1, const RasterPoint& p2)
  : dx(p2.x - p1.x),
    dy(p2.y - p1.y),
    x(p1.x),
    y(p1.y) {
  if (abs(dx) < abs(dy)) {
  } else {
  }
}

#ifndef MIDPOINT_LINE_CONTEXT_H
#define MIDPOINT_LINE_CONTEXT_H

#include "RasterPoint.h"

struct MidpointLineContext {
  int dx, dy; 
  int f;
  int df_y, df_xy;
  int x, y;

  MidpointLineContext(const RasterPoint& p0, const RasterPoint& p1);
};

#endif

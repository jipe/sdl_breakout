#ifndef BRICK_H
#define BRICK_H

#include "Screen.h"

class Brick {
  int _x, _y;

	public:
    Brick(int x, int y);

    int x() const { return _x; }
    int y() const { return _y; }

    void render(Screen &screen) const;
};

#endif

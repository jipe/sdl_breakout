#include "Brick.h"
#include "Screen.h"

#include <iostream>

using namespace std;

Brick::Brick(int x, int y) : _x(x), _y(y) {
}

void Brick::render(Screen &screen) const {
  screen.setColor(Color(175, 175, 175));
  screen.fillRect(_x - 50, _y - 25, _x + 50, _y + 25, false);
  screen.setColor(Color(225, 225, 225));
  screen.drawRect(_x - 50, _y - 25, _x + 50, _y + 25, false);
}

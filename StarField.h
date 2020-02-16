#ifndef STARFIELD_H
#define STARFIELD_H

#include <vector>

#include "Screen.h"
#include "Color.h"

typedef struct {
  float x, y, z;
} Star;

class StarField {
  int   _number_of_stars, _width, _height;
  float _near, _far;
  Color _color, _background;
  std::vector<Star> _stars;

  public:
    StarField(int width, int height, int number_of_stars);

    void render(Screen &screen, int x, int y, bool lock = true);
    void update(float deltaZ);
    void setColor(Color c);
    void setBackground(Color c);

};

#endif

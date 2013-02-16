#ifndef STARFIELD_H
#define STARFIELD_H

#include "Screen.h"
#include "Color.h"

typedef struct {
	float x, y, z;
} Star;

class StarField {
  int _number_of_stars, _width, _height;
  float _near, _far;
  Color _color, _background;
  Star* _stars;

  void init();

	public:
		StarField(int width, int height, int _number_of_stars);
		~StarField();

		void render(Screen &screen, int x, int y, bool lock = true);
		void update(float deltaZ);
		void setColor(Color c);
		void setBackground(Color c);

};

#endif

#ifndef STARFIELD_H
#define STARFIELD_H

#include "Screen.h"
#include "Color.h"

typedef struct {
	float x, y, z;
} Star;

class StarField {
	public:
		StarField(int width, int height, int numberOfStars);
		~StarField();

		void render(Screen &screen, int x, int y, bool lock = true);
		void update(float deltaZ);
		void setColor(Color c);
		void setBackground(Color c);

	private:
		int numberOfStars, width, height;
		float near, far;
		Color color, background;
		Star* stars;

		void init();
};

#endif

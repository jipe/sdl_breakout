#ifndef FIREEFFECT_H
#define FIREEFFECT_H

#include "Animation.h"
#include "Screen.h"

#include <SDL/SDL.h>

class FireAnimation : public Animation {

	int _width, _height;
	int _ignitionPoints;

	public:
		FireAnimation(int width, int height, int ignitionPoints, int fps);
		~FireAnimation();

		void render(Screen &screen, int x, int y);
		bool nextFrame();

};

#endif

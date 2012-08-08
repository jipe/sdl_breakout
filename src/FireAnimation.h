#ifndef FIREEFFECT_H
#define FIREEFFECT_H

#include "Screen.h"

#include <SDL/SDL.h>

class FireAnimation {

	SDL_Surface *_surface;
	int _width, _height;
	int _origins;

	public:
		FireAnimation(Screen &screen, int width, int height, int origins, int fps);
		~FireAnimation();

		void render(Screen &screen, int x, int y);
		bool nextFrame();

};

#endif

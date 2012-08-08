#ifndef SURFACE_H
#define SURFACE_H

#include <SDL/SDL.h>

using namespace std;

class Surface {
	shared_ptr<SDL_Surface> _surface;

	public:
		Surface(Screen &screen, unsigned int width, unsigned int height);

		SDL_Surface* getRawSurface() const;
};

#endif

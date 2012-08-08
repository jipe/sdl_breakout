#include "FireAnimation.h"
#include "Screen.h"

#include <SDL/SDL.h>

FireAnimation::FireAnimation(Screen &screen, int width, int height, int origins, int fps) :
		Animation(fps),
		_width(width),
		_height(height),
		_origins(origins) {
	_surface = screen.getSurface(width, height);
}

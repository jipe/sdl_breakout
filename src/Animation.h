#ifndef ANIMATION_H
#define ANIMATION_H

#include "Screen.h"

class Animation {
	float _millisPerFrame, _deltaMillis;

	public:
		Animation(unsigned int fps);
		virtual ~Animation();

		virtual void render(Screen &screen, int x, int y) const = 0;
		virtual bool nextFrame() = 0;

		virtual void update(float millis);

};

#endif

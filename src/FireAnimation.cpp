#include "Animation.h"
#include "FireAnimation.h"
#include "Screen.h"

FireAnimation::FireAnimation(int width, int height, int ignitionPoints, int fps) :
		Animation(fps), 
    _width(width), 
    _height(height), 
    _ignitionPoints(ignitionPoints) {
}

FireAnimation::~FireAnimation() {
}

void FireAnimation::render(Screen &screen, int x, int y) {
}

bool FireAnimation::nextFrame() {
  return false;
}

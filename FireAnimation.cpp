#include "Animation.h"
#include "FireAnimation.h"
#include "Screen.h"

FireAnimation::FireAnimation(int width, int height, int ignition_points, int fps) :
		Animation(fps), 
    _width(width), 
    _height(height), 
    _ignition_points(ignition_points) {
}

FireAnimation::~FireAnimation() {
}

void FireAnimation::render(Screen &screen, int x, int y) {
}

bool FireAnimation::nextFrame() {
  return false;
}

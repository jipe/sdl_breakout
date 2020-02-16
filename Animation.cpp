#include "Animation.h"
#include "Screen.h"

Animation::Animation(unsigned int fps)
: _millis_per_frame(1000.0f / static_cast<float>(fps)),
  _delta_millis(0.0f) {
}

Animation::~Animation() {
}

void Animation::update(float millis) {
  _delta_millis += millis;
  if (_delta_millis > _millis_per_frame) {
    nextFrame();
    _delta_millis -= _millis_per_frame;
  }
}


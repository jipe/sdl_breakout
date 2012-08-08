#include "Animation.h"
#include "Screen.h"

Animation::Animation(unsigned int fps) :
		_millisPerFrame(1000.0f / static_cast<float>(fps)),
		_deltaMillis(0.0f) {
}

Animation::~Animation() {
}

void Animation::update(float millis) {
	_deltaMillis += millis;
	if (_deltaMillis > _millisPerFrame) {
		nextFrame();
		_deltaMillis -= _millisPerFrame;
	}
}


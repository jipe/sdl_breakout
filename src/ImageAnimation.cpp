#include "ImageAnimation.h"
#include "Screen.h"

#include <string>
#include <iostream>

using namespace std;

ImageAnimation::ImageAnimation(Screen &screen, int imageHandle, int frameWidth, int fps) : 
		Animation(fps),
		_imageHandle(imageHandle), 
		_framePtr(0),
		_frameWidth(frameWidth),
		_numberOfFrames(screen.getImageInfo(imageHandle).width / frameWidth),
		_imageWidth(screen.getImageInfo(imageHandle).width),
		_imageHeight(screen.getImageInfo(imageHandle).height) {
}

bool ImageAnimation::nextFrame() {
	if (++_framePtr < _numberOfFrames) {
		return true;
	} else {
		_framePtr = 0;
		return false;
	}
}

void ImageAnimation::setFrame(int frame) {
	_framePtr = frame;
}

void ImageAnimation::render(Screen &screen, int x, int y) const {
	SDL_Rect rect;
	rect.x = _framePtr * _frameWidth;
	rect.y = 0;
	rect.w = _frameWidth;
	rect.h = _imageHeight;
	screen.drawImage(_imageHandle, x, y, rect);
}

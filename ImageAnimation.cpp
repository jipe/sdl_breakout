#include "ImageAnimation.h"
#include "Screen.h"

#include <string>
#include <iostream>

using namespace std;

ImageAnimation::ImageAnimation(Screen &screen, int image_handle, int frame_width, int fps) : 
		Animation(fps),
		_image_handle(image_handle), 
		_frame_ptr(0),
		_frame_width(frame_width),
		_number_of_frames(0),//screen.getImageInfo(image_handle).width / frame_width),
		_image_width(0),//screen.getImageInfo(image_handle).width),
		_image_height(0) {//screen.getImageInfo(image_handle).height) {
}

bool ImageAnimation::nextFrame() {
	if (++_frame_ptr < _number_of_frames) {
		return true;
	} else {
		_frame_ptr = 0;
		return false;
	}
}

void ImageAnimation::setFrame(int frame) {
	_frame_ptr = frame;
}

void ImageAnimation::render(Screen &screen, int x, int y) const {
	SDL_Rect rect;
	rect.x = _frame_ptr * _frame_width;
	rect.y = 0;
	rect.w = _frame_width;
	rect.h = _image_height;
//	screen.drawImage(_image_handle, x, y, rect);
}

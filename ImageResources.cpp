#include "ImageResources.h"
#include "Screen.h"

#include <string>
#include <iostream>

ImageResources::ImageResources(Screen &screen) {
	_bat_image_info = screen.loadImage("images/bat.png");
	_ball_image_info = screen.loadImage("images/ball.png");
	_red_brick_image_info = screen.loadImage("images/brick_red.png");
	_green_brick_image_info = screen.loadImage("images/brick_green.png");
	_blue_brick_image_info = screen.loadImage("images/brick_blue.png");
	_grey_brick_image_info = screen.loadImage("images/brick_grey.png");
	_border_image_info = screen.loadImage("images/background.png");
	_grey_slate_image_info = screen.loadImage("images/grey_slate.png");
}

void ImageResources::init(Screen &screen) {
}

ImageInfo ImageResources::getBatImageInfo() const {
	return _bat_image_info;
}

ImageInfo ImageResources::getBallImageInfo() const {
	return _ball_image_info;
}

ImageInfo ImageResources::getRedBrickImageInfo() const {
	return _red_brick_image_info;
}

ImageInfo ImageResources::getGreenBrickImageInfo() const {
	return _green_brick_image_info;
}

ImageInfo ImageResources::getBlueBrickImageInfo() const {
	return _blue_brick_image_info;
}

ImageInfo ImageResources::getGreyBrickImageInfo() const {
	return _grey_brick_image_info;
}

ImageInfo ImageResources::getBorderImageInfo() const {
	return _border_image_info;
}

ImageInfo ImageResources::getGreySlateImageInfo() const {
	return _grey_slate_image_info;
}

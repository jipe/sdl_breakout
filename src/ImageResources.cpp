#include "ImageResources.h"
#include "Screen.h"

#include <string>
#include <iostream>

ImageResources::ImageResources(Screen &screen) {
	_batImageInfo = screen.loadImage("images/bat.png");
	_ballImageInfo = screen.loadImage("images/ball.png");
	_redBrickImageInfo = screen.loadImage("images/brick_red.png");
	_greenBrickImageInfo = screen.loadImage("images/brick_green.png");
	_blueBrickImageInfo = screen.loadImage("images/brick_blue.png");
	_greyBrickImageInfo = screen.loadImage("images/brick_grey.png");
	_borderImageInfo = screen.loadImage("images/background.png");
	_greySlateImageInfo = screen.loadImage("images/grey_slate.png");
}

void ImageResources::init(Screen &screen) {
}

ImageInfo ImageResources::getBatImageInfo() const {
	return _batImageInfo;
}

ImageInfo ImageResources::getBallImageInfo() const {
	return _ballImageInfo;
}

ImageInfo ImageResources::getRedBrickImageInfo() const {
	return _redBrickImageInfo;
}

ImageInfo ImageResources::getGreenBrickImageInfo() const {
	return _greenBrickImageInfo;
}

ImageInfo ImageResources::getBlueBrickImageInfo() const {
	return _blueBrickImageInfo;
}

ImageInfo ImageResources::getGreyBrickImageInfo() const {
	return _greyBrickImageInfo;
}

ImageInfo ImageResources::getBorderImageInfo() const {
	return _borderImageInfo;
}

ImageInfo ImageResources::getGreySlateImageInfo() const {
	return _greySlateImageInfo;
}

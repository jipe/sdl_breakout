#include "StarField.h"
#include "Screen.h"
#include "Color.h"
#include "ColorConstants.h"

#include <cstdlib>

StarField::StarField(int width, int height, int number_of_stars) : 
		_width(width), 
		_height(height), 
		_number_of_stars(number_of_stars), 
		_near(0.1f), 
		_far(2.0f), 
		_color(ColorConstants::WHITE), 
		_background(ColorConstants::BLACK) {
	init();
}

StarField::~StarField() {
	delete _stars;
}

void StarField::init() {
	_stars = new Star[_number_of_stars];
	for (int i = 0; i < _number_of_stars; i++) {
		_stars[i].x = (rand() % (2*_width)) - _width;
		_stars[i].y = (rand() % (2*_height)) - _height;
		_stars[i].z = (_far - _near) * static_cast<float>(rand()) / static_cast<float>(RAND_MAX) + _near;
	}
}

void StarField::render(Screen &screen, int x, int y, bool lock) {
	float half_width = static_cast<float>(_width) / 2.0f;
	float half_height = static_cast<float>(_height) / 2.0f;
	if (lock) {
		screen.lockSurface();
	}
	for (int i = 0; i < _number_of_stars; i++) {
		int pos_x = static_cast<int>(half_width + (_stars[i].x - half_width) / _stars[i].z);
		int pos_y = static_cast<int>(half_height + (_stars[i].y - half_height) / _stars[i].z);
		if (pos_x >= x && pos_x < _width+x && pos_y >= y && pos_y < _height+y) {
			int r = static_cast<int>((_far - _near - (_stars[i].z - _near)) * (_color.getR() - _background.getR()) + _background.getR());
			int g = static_cast<int>((_far - _near - (_stars[i].z - _near)) * (_color.getG() - _background.getG()) + _background.getG());
			int b = static_cast<int>((_far - _near - (_stars[i].z - _near)) * (_color.getB() - _background.getB()) + _background.getB());
			if (r > 255) { r = 255; }
			if (g > 255) { g = 255; }
			if (b > 255) { b = 255; }
			screen.setColor(Color(r, g, b));
			screen.setPixel(pos_x, pos_y, false);
		}
	}
	if (lock) {
		screen.unlockSurface();
	}
}

void StarField::update(float dz) {
	for (int i = 0; i < _number_of_stars; i++) {
		_stars[i].z += dz;
		if (_stars[i].z > _far) {
			_stars[i].z -= _far - _near;
		} else if (_stars[i].z < _near) {
			_stars[i].z += _far - _near;
		}
	}
}

void StarField::setColor(Color color) {
  _color = color;
}

void StarField::setBackground(Color color) {
	_background = color;
}

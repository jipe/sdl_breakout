#include "StarField.h"
#include "Screen.h"
#include "Color.h"
#include "ColorConstants.h"

#include <cstdlib>

StarField::StarField(int width, int height, int numberOfStars) : 
		width(width), 
		height(height), 
		numberOfStars(numberOfStars), 
		near(0.1f), 
		far(2.0f), 
		color(ColorConstants::WHITE), 
		background(ColorConstants::BLACK) {
	init();
}

StarField::~StarField() {
	delete stars;
}

void StarField::init() {
	stars = new Star[numberOfStars];
	for (int i = 0; i < numberOfStars; i++) {
		stars[i].x = (rand() % (2*width)) - width;
		stars[i].y = (rand() % (2*height)) - height;
		stars[i].z = (far - near) * static_cast<float>(rand()) / static_cast<float>(RAND_MAX) + near;
	}
}

void StarField::render(Screen &screen, int x, int y, bool lock) {
	float halfWidth = static_cast<float>(width) / 2.0f;
	float halfHeight = static_cast<float>(height) / 2.0f;
	if (lock) {
		screen.lockSurface();
	}
	for (int i = 0; i < numberOfStars; i++) {
		int posx = static_cast<int>(halfWidth + (stars[i].x - halfWidth) / stars[i].z);
		int posy = static_cast<int>(halfHeight + (stars[i].y - halfHeight) / stars[i].z);
		if (posx >= x && posx < width+x && posy >= y && posy < height+y) {
			int r = static_cast<int>((far - near - (stars[i].z - near)) * (color.getR() - background.getR()) + background.getR());
			int g = static_cast<int>((far - near - (stars[i].z - near)) * (color.getG() - background.getG()) + background.getG());
			int b = static_cast<int>((far - near - (stars[i].z - near)) * (color.getB() - background.getB()) + background.getB());
			if (r > 255) { r = 255; }
			if (g > 255) { g = 255; }
			if (b > 255) { b = 255; }
			screen.setColor(Color(r, g, b));
			screen.setPixel(posx, posy, false);
		}
	}
	if (lock) {
		screen.unlockSurface();
	}
}

void StarField::update(float deltaZ) {
	for (int i = 0; i < numberOfStars; i++) {
		stars[i].z += deltaZ;
		if (stars[i].z > far) {
			stars[i].z -= far - near;
		} else if (stars[i].z < near) {
			stars[i].z += far - near;
		}
	}
}

void StarField::setColor(Color color) {
	StarField::color = color;
}

void StarField::setBackground(Color color) {
	background = color;
}

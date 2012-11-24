#include "BreakOut.h"
#include "Application.h"
#include "ColorConstants.h"
#include "Screen.h"
#include "StarField.h"
#include "Animation.h"
#include "ImageAnimation.h"

#include <iostream>
#include <cstdlib>

using namespace std;

enum BrickIndex { RED = 0, GREEN = 1, BLUE = 2, GREY = 3 };

BreakOut::BreakOut(int width, int height, int fps) : 
		Application(width, height, fps), 
		_starField(width - 54, height - 120, 750) {
}

BreakOut::~BreakOut() {
	cout << "Thank you for playing. Take care!" << endl;
}

void BreakOut::init(Screen &screen) {
	_imageResources.init(screen);
	_batAnimation = new ImageAnimation(screen, _imageResources.getBatImageInfo().imageHandle, 100, 10);
}

void BreakOut::handleEvent(SDL_Event &event) {
	switch (event.type) {
		case SDL_MOUSEMOTION:
			//bat.dx = event.motion.xrel;
			break;
		default:
			Application::handleEvent(event);
			break;
	}

}

void BreakOut::updateModel(float millis) {
	_starField.update(-0.005f);
	_batAnimation->update(millis);
}

void BreakOut::render(Screen &screen) {
	Color bg = ColorConstants::BLACK;
	Color fg = ColorConstants::WHITE;
	screen.setBackground(bg);
	screen.setColor(fg);
	_starField.setColor(fg);
	_starField.setBackground(bg);
	screen.drawImage(_imageResources.getBorderImageInfo().imageHandle, 0, 0);
	screen.lockSurface();
	screen.setColor(bg);
	screen.fillRect(27, 100, 573, 780, false);
	screen.setColor(fg);
	_starField.render(screen, 27, 100, false);
	screen.unlockSurface();
	_batAnimation->render(screen, 350, 500);
	screen.flush();
}

void BreakOut::shutDown() {
	delete _batAnimation;
}


#include "BreakOut.h"
#include "Application.h"
#include "ColorConstants.h"
#include "Screen.h"
#include "StarField.h"
#include "Animation.h"
#include "ImageAnimation.h"
#include "Brick.h"

#include <iostream>
#include <cstdlib>

using namespace std;

enum BrickIndex { RED = 0, GREEN = 1, BLUE = 2, GREY = 3 };

BreakOut::BreakOut(int width, int height, int fps) : 
		Application(width, height, fps), 
		_starField(width, height, 5750) {
  _gameObjects.push_back(new Brick(500,300));
  _gameObjects.push_back(new Brick(150,300));
}

BreakOut::~BreakOut() {
  vector<Brick*>::iterator iter = _gameObjects.begin();
  while (iter != _gameObjects.end()) {
    delete *iter;
    iter++;
  }
}

void BreakOut::init(Screen &screen) {
	_imageResources.init(screen);
}

void BreakOut::handleEvent(SDL_Event &event) {
	switch (event.type) {
		case SDL_MOUSEMOTION:
			break;
		default:
			Application::handleEvent(event);
			break;
	}

}

void BreakOut::updateModel(float millis) {
	_starField.update(-0.005f);
}

void BreakOut::render(Screen &screen) {
	Color bg = ColorConstants::BLACK;
	Color fg = ColorConstants::WHITE;
	screen.setBackground(bg);
	screen.setColor(fg);
  screen.lockSurface();
  /*
	_starField.setColor(fg);
	_starField.setBackground(bg);
	//screen.drawImage(_imageResources.getBorderImageInfo().imageHandle, 0, 0);
	screen.lockSurface();
	screen.setColor(bg);
	screen.fillRect(0, 0, getWidth(), getHeight(), false);
	screen.setColor(fg);
	//_starField.render(screen, 0, 0, false);
  // Draw bricks
  vector<Brick*>::iterator iter = _gameObjects.begin();
  while (iter != _gameObjects.end()) {
    (*iter)->render(screen);
    iter++;
  }
  */
  int delta = 20;
  for (int x = 0; x < getWidth(); x += delta) {
    screen.drawLine(getWidth() / 2, getHeight() / 2, x, 0);
  }
  for (int y = 0; y < getHeight(); y += delta) {
    screen.drawLine(getWidth() / 2, getHeight() / 2, getWidth()-1, y);
  }
  for (int x = getWidth()-1; x >= 0; x -= delta) {
    screen.drawLine(getWidth() / 2, getHeight() / 2, x, getHeight()-1);
  }
  for (int y = getHeight()-1; y >= 0; y -= delta) {
    screen.drawLine(getWidth() / 2, getHeight() / 2, 0, y);
  }
	screen.unlockSurface();
	screen.flush();
}

void BreakOut::shutDown() {
}


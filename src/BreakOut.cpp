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
		_starField(width, height, 5750),
    _imageResources(getScreen()),
    _lineDelta(40), _lineOffset(0) {
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

void BreakOut::render() {
  Screen &screen = getScreen();
	Color bg = ColorConstants::BLACK;
	Color fg = ColorConstants::WHITE;
	screen.setBackground(bg);
	screen.setColor(fg);
  screen.lockSurface();
  screen.clear();
  /*
  // 1st octant
  screen.drawLine(400,400, 799, 405);
  screen.drawLine(400,400, 799, 700);
  // 2nd octant
  screen.drawLine(400,400, 700, 799);
  screen.drawLine(400,400, 405, 799);
  // 3rd octant
  screen.drawLine(400,400, 395, 799);
  screen.drawLine(400,400, 100, 799);
  // 4th octant
  screen.drawLine(400,400, 0, 700);
  screen.drawLine(400,400, 0, 405);
  // 5th octant
  screen.drawLine(400,400, 0, 395);
  screen.drawLine(400,400, 0, 100);
  // 6th octant
  screen.drawLine(400,400, 100, 0);
  screen.drawLine(400,400, 395, 0);
  // 7th octant
  screen.drawLine(400,400, 405, 0);
  screen.drawLine(400,400, 700, 0);
  // 8th octant
  screen.drawLine(400,400, 799, 100);
  screen.drawLine(400,400, 799, 395);

  // Octant boundaries 
  screen.drawLine(400, 0, 400, 799);
  screen.drawLine(0, 400, 799, 400);
  screen.drawLine(0, 0, 799, 799);
  screen.drawLine(0, 799, 799, 0);
  */
  screen.setColor(ColorConstants::DARK_BLUE);
  renderCircle(screen, 380, 400, false);
  renderCircle(screen, 420, 400, true);
  renderCircle(screen, 400, 380, false);
  renderCircle(screen, 400, 420, true);
  screen.setColor(ColorConstants::BLUE);
  renderCircle(screen, 0, 0, true);
  renderCircle(screen, 799, 0, true);
  renderCircle(screen, 799, 799, true);
  renderCircle(screen, 0, 799, true);
  screen.setColor(ColorConstants::MAGENTA);
  renderCircle(screen, 200, 200, true);
  renderCircle(screen, 600, 200, false);
  renderCircle(screen, 0, 600, false);
  renderCircle(screen, 800, 600, true);
  screen.setColor(ColorConstants::WHITE);
  renderCircle(screen, 400, 400, true);
  _lineOffset += 2;
  _lineOffset %= _lineDelta;
	screen.unlockSurface();
	screen.flush();
}

void BreakOut::renderCircle(Screen &screen, int x0, int y0, bool ccw) {
  if (ccw) {
    for (int x = getWidth()-1-_lineOffset; x >= 0; x -= _lineDelta) {
      screen.drawLine(x0, y0, x, 0);
    }
    for (int y = _lineOffset; y < getHeight(); y += _lineDelta) {
      screen.drawLine(x0, y0, 0, y);
    }
    for (int x = _lineOffset; x < getWidth(); x += _lineDelta) {
      screen.drawLine(x0, y0, x, getHeight()-1);
    }
    for (int y = getHeight()-1-_lineOffset; y >= 0; y -= _lineDelta) {
      screen.drawLine(x0, y0, getWidth()-1, y);
    }
  } else {
    for (int x = _lineOffset; x < getWidth(); x += _lineDelta) {
      screen.drawLine(x0, y0, x, 0);
    }
    for (int y = _lineOffset; y < getHeight(); y += _lineDelta) {
      screen.drawLine(x0, y0, getWidth()-1, y);
    }
    for (int x = getWidth()-1-_lineOffset; x >= 0; x -= _lineDelta) {
      screen.drawLine(x0, y0, x, getHeight()-1);
    }
    for (int y = getHeight()-1-_lineOffset; y >= 0; y -= _lineDelta) {
      screen.drawLine(x0, y0, 0, y);
    }
  }
}

/*
void BreakOut::shutDown() {
}
*/

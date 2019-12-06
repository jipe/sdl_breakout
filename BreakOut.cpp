#include "BreakOut.h"
#include "Application.h"
#include "Screen.h"
#include "StarField.h"
#include "Animation.h"
#include "ImageAnimation.h"
#include "Brick.h"
#include "Edge.h"
#include "Color.h"

#include <iostream>
#include <cstdlib>

using namespace std;

enum BrickIndex { RED = 0, GREEN = 1, BLUE = 2, GREY = 3 };

BreakOut::BreakOut(int width, int height, int fps) : 
		Application(width, height, fps), 
		_star_field(width, height, 5000),
    _image_resources(getScreen()) {

  for (int i = 0; i < 10; i++) {
    float x = (width-1) * (static_cast<float>(rand()) / static_cast<float>(RAND_MAX));
    float y = (height-1) * (static_cast<float>(rand()) / static_cast<float>(RAND_MAX));
    _points.push_back(Vector2(x,y));
  }
  for (int i = 0, j = 5; i < 5; i++, j++) {
    _edges.push_back(Edge(_points[i], _points[j]));
  }
}

BreakOut::~BreakOut() {
  vector<Brick*>::iterator iter = _game_objects.begin();
  while (iter != _game_objects.end()) {
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
	_star_field.update(-0.007f);
}

void BreakOut::render() {
  Screen &screen = getScreen();
	Color bg = Color::BLACK;
	Color fg = Color::RED;
	screen.setBackground(bg);
	screen.setColor(fg);
  screen.clear();
  _star_field.render(screen, 0, 0, false);

  for (int i = 0; i < _edges.size(); i++) {
    bool intersects = false;
    for (int j = 0; j < _edges.size(); j++) {
      if (_edges[i].intersects(_edges[j])) {
        intersects = true;
        break;
      }
    }
    screen.setColor(intersects ? Color::RED : Color::GREEN);
    _edges[i].render(screen);
  }

	screen.flush();
}

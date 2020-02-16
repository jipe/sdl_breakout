#include "BreakOut.h"
#include "Application.h"
#include "Screen.h"
#include "StarField.h"
#include "Animation.h"
#include "ImageAnimation.h"
#include "Brick.h"
#include "Edge.h"
#include "Color.h"
#include "Vertex.h"

#include <iostream>
#include <cstdlib>
#include <cmath>

using namespace std;

enum BrickIndex { RED = 0, GREEN = 1, BLUE = 2, GREY = 3 };

BreakOut::BreakOut(int width, int height, int fps) : 
    Application(width, height, fps),
    _star_field(width, height, 5000),
    _texture(getScreen().loadImage("images/pigs.png")),
    _image_resources(getScreen()),
    _p1(static_cast<float>(width) / 5.0f, 4.0f * static_cast<float>(height) / 5.0f, 1),
    _p2(4.0f * static_cast<float>(width) / 5.0f, 4.0f * static_cast<float>(height) / 5.0f, 1),
    _p3(static_cast<float>(width) / 2.0f, static_cast<float>(height) / 5.0f, 1),
    _theta(0.0f) {

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
  _theta += .02f;
  if (_theta > 360.0f) {
    _theta = 0.0f;
  }
}

void BreakOut::render() {
  Screen &screen = getScreen();
  Color bg = Color::BLACK;
  Color fg = Color::RED;
  screen.setBackground(bg);
  screen.setColor(fg);
  screen.clear();
  _star_field.render(screen, 0, 0, false);

  /*
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
  */

  float cos_theta   = cos(_theta);
  float sin_theta   = sin(_theta);
  float half_width  = static_cast<float>(getWidth()) / 2.0f;
  float half_height = static_cast<float>(getHeight()) / 2.0f;

  float p1x = _p1.x - half_width;
  float p1y = _p1.y - half_height;
  float p2x = _p2.x - half_width;
  float p2y = _p2.y - half_height;
  float p3x = _p3.x - half_width;
  float p3y = _p3.y - half_height;

  Vector3 p1(half_width + (p1x * cos_theta - p1y * sin_theta), half_height + (p1x * sin_theta + p1y * cos_theta), 1),
          p2(half_width + (p2x * cos_theta - p2y * sin_theta), half_height + (p2x * sin_theta + p2y * cos_theta), 1),
          p3(half_width + (p3x * cos_theta - p3y * sin_theta), half_height + (p3x * sin_theta + p3y * cos_theta), 1);

  Vector3 n1(0,0,1),
          n2(0,0.5f,0.5f),
          n3(0,0,1);

  Vector2 tc1(0,1),
          tc2(1,0),
          tc3(1,1);

  Vertex v1(p1, n1, Color::RED, tc1),
         v2(p2, n2, Color::GREEN, tc2),
         v3(p3, n3, Color::BLUE, tc3);

  screen.fillTriangle(v1, v2, v3, _texture.image_handle);
  screen.flush();
}

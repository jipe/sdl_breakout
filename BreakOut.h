#ifndef BREAKOUT_H
#define BREAKOUT_H

#include <vector>

#include "StarField.h"
#include "application.h"
#include "collision.h"
#include "ImageResources.h"
#include "Animation.h"
#include "GameObject.h"
#include "Brick.h"
#include "Edge.h"

class BreakOut : public Application, public CollisionResolver {
  StarField _star_field;
  CollisionDetector _collision_detector;
  ImageResources _image_resources;
  std::vector<Brick*> _game_objects;
  std::vector<Vector2> _points;
  std::vector<Edge> _edges;
  ImageInfo _texture;
  Vector3 _p1, _p2, _p3, _p4;
  float _theta;

  void handleEvent(SDL_Event &event);
  void updateModel(float millis);
  void render();

  void resolve(Collision collision);

  public:
    BreakOut(int width, int height, int fps);
    ~BreakOut();

};

#endif

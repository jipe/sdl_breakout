#ifndef ANIMATED_GAME_OBJECT_H
#define ANIMATED_GAME_OBJECT_H

#include "Screen.h"
#include "Vector2.h"
#include "GameObject.h"
#include "Animation.h"

#include <vector>

using namespace std;

class AnimatedGameObject {
  vector<Animation*> _animations;
  int _animation_ptr;
  Vector2 _position;

public:
  AnimatedGameObject(const Vector2 position);

  int add(Animation *animation);
  void setCurrentAnimation(int handle);

  void render(Screen &screen) const;
};

#endif

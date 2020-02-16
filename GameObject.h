#ifndef GAME_OBJECT_H
#define GAME_OBJECT_H

#include "Screen.h"
#include "Vector2.h"

#include <vector>

using namespace std;

class GameObject {
  Vector2 _position, _speed, _acceleration;

  public:
    GameObject(const Vector2 position);

    const Vector2& position() const { return _position; }
    const Vector2& speed() const { return _speed; }
    const Vector2& acceleration() const { return _acceleration; }

    virtual void render(Screen &screen) const;
};

#endif

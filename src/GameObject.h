#ifndef GAME_OBJECT_H
#define GAME_OBJECT_H

#include "Screen.h"
#include "CollisionObject.h"
#include "BoundingObject.h"
#include "Vector2.h"
#include "Animation.h"

#include <vector>

using namespace std;

class GameObject : public CollisionObject {
	vector<Animation*> _animations;
	int _animationPtr;

	public:
		GameObject(const BoundingObject &boundingObject, const Vector2 position);

		int add(Animation *animation);
		void setCurrentAnimation(int handle);

		void render(Screen &screen) const;
};

#endif

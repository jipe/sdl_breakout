#include "GameObject.h"
#include "Animation.h"
#include "BoundingObject.h"
#include "CollisionObject.h"
#include "Screen.h"

#include <vector>

using namespace std;

GameObject::GameObject(const BoundingObject &boundingObject, const Vector2 position) 
		: CollisionObject(boundingObject, position) {
}

int GameObject::add(Animation *animation) {
	int index = _animations.size();
	_animations.push_back(animation);
	return index;
}

void GameObject::setCurrentAnimation(int handle) {
	_animationPtr = handle;
}

void GameObject::render(Screen &screen) const {
	_animations[_animationPtr]->render(screen, static_cast<int>(position.x), static_cast<int>(position.y));
}

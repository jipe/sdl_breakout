#include "AnimatedGameObject.h"
#include "Animation.h"
#include "CollisionObject.h"
#include "Screen.h"

#include <vector>

using namespace std;

AnimatedGameObject::AnimatedGameObject(const Vector2 position) {
}

int AnimatedGameObject::add(Animation *animation) {
	int index = _animations.size();
	_animations.push_back(animation);
	return index;
}

void AnimatedGameObject::setCurrentAnimation(int handle) {
	_animationPtr = handle;
}

void AnimatedGameObject::render(Screen &screen) const {
	//_animations[_animationPtr]->render(screen, static_cast<int>(_position.x), static_cast<int>(_position.y));
}

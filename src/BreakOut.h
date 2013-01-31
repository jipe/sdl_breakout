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

class BreakOut : public Application, public CollisionResolver {
	StarField _starField;
	CollisionDetector _collisionDetector;
	ImageResources _imageResources;
  std::vector<Brick*> _gameObjects;

	void init(Screen &screen);
	void handleEvent(SDL_Event &event);
	void updateModel(float millis);
	void render(Screen &screen);
	void shutDown();

	void resolve(Collision collision);
	
	public:
		BreakOut(int width, int height, int fps);
		~BreakOut();

};

#endif

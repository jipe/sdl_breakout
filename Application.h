#ifndef APPLICATION_H
#define APPLICATION_H

#include "Screen.h"

class Application {
	int _width, _height;
	bool _running, _paused;
	float _ticks_per_frame;
  Screen *_screen;
	
	void _processEvents();

	public:
		Application(int width, int height, int fps);
		virtual ~Application();

		void run();
		void stop();
		void pause();
		void resume();
		
		inline int getWidth() { 
			return _width;
		}

		inline int getHeight() {
			return _height;
		}

	protected:
		virtual void updateModel(float millis) = 0;
		virtual void render() = 0;

		virtual void handleEvent(SDL_Event& event);

		void hideCursor();
    Screen& getScreen() { return *_screen; }

};

#endif

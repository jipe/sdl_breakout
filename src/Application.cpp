#include "Application.h"
#include <SDL/SDL.h>
#include <unistd.h>
#include <cstdlib>
#include <iostream>

using namespace std;

Application::Application(int width, int height, int fps) 
    : _width(width), _height(height), _paused(false), _running(false), _ticksPerFrame(1000.0f / static_cast<float>(fps)) {
}

Application::~Application() {
}

void Application::run() {
  putenv((char*)"SDL_VIDEO_CENTERED=1");
  Screen screen(_width, _height);
  SDL_ShowCursor(0);
  //SDL_WM_GrabInput(SDL_GRAB_ON);
  init(screen);
  unsigned int t0, deltaTicks;
  _running = true;
  while (_running) {
    t0 = SDL_GetTicks();
    if (_paused) {
      _processEvents();
      usleep(100000);
    } else {
      _processEvents();
      updateModel(_ticksPerFrame);
      render(screen);
      deltaTicks = SDL_GetTicks() - t0;
      if (deltaTicks < _ticksPerFrame) {
        usleep((_ticksPerFrame - deltaTicks) * 1000);
      }
    }
  }
  shutDown();
}

void Application::stop() {
  _running = false;
}

void Application::pause() {
  _paused = true;
}

void Application::resume() {
  _paused = false;
}

void Application::_processEvents() {
  SDL_Event event;
  while (SDL_PollEvent(&event)) {
    handleEvent(event);
  }
}

void Application::handleEvent(SDL_Event &event) {
  switch (event.type) {
    case SDL_QUIT:
      stop();
      break;
    case SDL_KEYDOWN:
      switch (event.key.keysym.sym) {
        case SDLK_ESCAPE:
          stop();
          break;
        case SDLK_LALT:
          //SDL_WM_GrabInput(SDL_GRAB_OFF);
          SDL_ShowCursor(1);
          break;
        default:
          break;
      }
      break;
    case SDL_KEYUP:
      switch (event.key.keysym.sym) {
        case SDLK_LALT:
          //SDL_WM_GrabInput(SDL_GRAB_ON);
          SDL_ShowCursor(0);
          break;
        default:
          break;
      }
      break;
    case SDL_ACTIVEEVENT:
      if (event.active.gain) {
        //SDL_WM_GrabInput(SDL_GRAB_ON);
        SDL_ShowCursor(0);
        resume();
      } else {
        //SDL_WM_GrabInput(SDL_GRAB_OFF);
        SDL_ShowCursor(1);
        pause();
      }
      break;
    default:
      break;
  }
}

void Application::hideCursor() {
  SDL_ShowCursor(0);
}

void Application::shutDown() {
}

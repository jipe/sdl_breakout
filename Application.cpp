#include "Application.h"
#include <SDL2/SDL.h>
#include <unistd.h>
#include <cstdlib>
#include <iostream>

using namespace std;

Application::Application(int width, int height, int fps) :
  _width(width),
  _height(height),
  _paused(false),
  _running(false),
  _ticks_per_frame(1000.0f / static_cast<float>(fps))
{
  _screen = new Screen(_width, _height);
}

Application::~Application() {
  delete _screen;
}

void Application::run() {
  //SDL_ShowCursor(0);
  //SDL_WM_GrabInput(SDL_GRAB_ON);
  unsigned int t0, delta_ticks;
  _running = true;
  while (_running) {
    t0 = SDL_GetTicks();
    if (_paused) {
      _processEvents();
      usleep(100000);
    } else {
      _processEvents();
      updateModel(_ticks_per_frame);
      render();
      delta_ticks = SDL_GetTicks() - t0;
      if (delta_ticks < _ticks_per_frame) {
        usleep((_ticks_per_frame - delta_ticks) * 1000);
      }
    }
  }
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
  default:
    break;
  }
}

void Application::hideCursor() {
  SDL_ShowCursor(0);
}


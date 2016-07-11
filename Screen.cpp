#include "Screen.h"
#include "Color.h"
#include "ScreenException.h"
#include "math.h"

#include <SDL/SDL.h>
#include <SDL/SDL_image.h>
#include <string>
#include <iostream>
#include <vector>

using namespace std;

Screen::Screen(int width, int height) : _width(width), _height(height), _color(255, 255, 255, 0), _background(0, 0, 0, 0) {
	if (SDL_Init(SDL_INIT_VIDEO) == -1) {
		throw ScreenException("Error initialising SDL");
	}
	_surface = SDL_SetVideoMode(width, height, 32, SDL_ANYFORMAT|SDL_DOUBLEBUF);
	if (!_surface) {
		throw ScreenException("Error setting video mode");
	}
	const SDL_VideoInfo* video_info = SDL_GetVideoInfo();
	if (video_info) {
		std::cout << "HW available? " << video_info->hw_available << std::endl;
	} else {
		std::cout << "Video info was null" << std::endl;
	}
	std::cout << "width: " << _surface->w << std::endl;
	std::cout << "height: " << _surface->h << std::endl;
	std::cout << "pitch: " << _surface->pitch << std::endl;
	std::cout << "BPP: " << (int) _surface->format->BytesPerPixel << std::endl;
	std::cout << "HW: " << (_surface->flags & SDL_HWSURFACE) << std::endl;
}

Screen::~Screen() {
  for (vector<SDL_Surface*>::iterator iter = _image_store.begin(); iter != _image_store.end(); iter++) {
    SDL_FreeSurface(*iter);
  }
	SDL_Quit();
}

void Screen::lockSurface() {
	SDL_LockSurface(_surface);
}

void Screen::unlockSurface() {
	SDL_UnlockSurface(_surface);
}

void Screen::setPixel(int x, int y, bool lock) {
	if (lock) {
		if (SDL_LockSurface(_surface) == 0) {
      _drawPixel(x, y);
			SDL_UnlockSurface(_surface);
		}
	} else {
    _drawPixel(x, y);
	}
}

Color Screen::getPixel(int x, int y) const {
  Uint32* pixels = static_cast<Uint32*>(_surface->pixels);
	Uint8 r, g, b, a;
	SDL_GetRGBA(pixels[y*_surface->w + x], _surface->format, &r, &g, &b, &a);
	return Color(r, g, b, a);
}

void Screen::setColor(Color c) {
	_color_pixel = SDL_MapRGBA(_surface->format, c.getR(), c.getG(), c.getB(), c.getA());
}

void Screen::setBackground(Color c) {
	_background_pixel = SDL_MapRGBA(_surface->format, c.getR(), c.getG(), c.getB(), c.getA());
}

void Screen::clear() {
	if (SDL_LockSurface(_surface) == 0) {;
		Uint32* pixels = (Uint32*) _surface->pixels;
		for (int i = 0; i < _surface->h*_surface->w; i++) {
			pixels[i] = _background_pixel;
		}
		SDL_UnlockSurface(_surface);
	}
}

void Screen::drawLine(int x0, int y0, int x1, int y1, bool antialias) {
  int dx = x1 - x0;
  int dy = y1 - y0;

  if (abs(dx) < abs(dy)) {
    if (dx > 0 && dy > 0) {
      // 2nd octant - normal is (-dy, dx)
      int f = dy - 2*dx;
      int df_y = -2*dx;
      int df_xy = 2*(dy - dx);
      int x = x0;
      for (int y = y0; y <= y1; y++) {
        _drawPixel(x, y);
        if (f < 0) {
          x++;
          f += df_xy;
        } else {
          f += df_y;
        }
      }
    } else if (dx < 0 && dy > 0) {
      // 3rd octant - normal is (-dy, dx)
      int f = 2*dx + dy;
      int df_y = 2*dx;
      int df_xy = 2*(dx + dy);
      int x = x0;

      for (int y = y0; y <= y1; y++) {
        _drawPixel(x, y);
        if (f < 0) {
          x--;
          f += df_xy;
        } else {
          f += df_y;
        }
      }
    } else if (dx < 0 && dy < 0) {
      // 6th octant - normal is (dy, -dx)
      int f = -dy + 2*dx;
      int df_y = 2*dx;
      int df_xy = -2*(dy - dx);
      int x = x0;
      for (int y = y0; y >= y1; y--) {
        _drawPixel(x,y);
        if (f < 0) {
          x--;
          f += df_xy;
        } else {
          f += df_y;
        }
      }
    } else if (dx > 0 && dy < 0) {
      // 7th octant - normal is (-dy, dx)
      int f = -dy -2*dx;
      int df_y = -2*dx;
      int df_xy = -2*(dx + dy);
      int x = x0;

      for (int y = y0; y >= y1; y--) {
        _drawPixel(x, y);
        if (f < 0) {
          x++;
          f += df_xy;
        } else {
          f += df_y;
        }
      }
    } else if (dx == 0) {
      // Vertical line
      if (dy > 0) {
        for (int y = y0; y <= y1; y++) {
          _drawPixel(x0, y);
        }
      } else {
        for (int y = y0; y >= y1; y--) {
          _drawPixel(x0, y);
        }
      }
    }
  } else {
    if (dx > 0 && dy > 0) {
      // 1st octant - normal is (-dy, dx)
      int f = -2*dy + dx;
      int df_x = -2*dy;
      int df_xy = 2*(dx - dy);
      int y = y0;

      for (int x = x0; x <= x1; x++) {
        _drawPixel(x, y);
        if (f < 0) {
          y++;
          f += df_xy;
        } else {
          f += df_x;
        }
      }
    } else if (dx < 0 && dy > 0) {
      // 4th octant - normal is (dy, -dx)
      int f = -2*dy - dx;
      int df_x = -2*dy;
      int df_xy = -2*(dy + dx);
      int y = y0;

      for (int x = x0; x >= x1; x--) {
        _drawPixel(x, y);
        if (f < 0) {
          y++;
          f += df_xy;
        } else {
          f += df_x;
        }
      }
    } else if (dx < 0 && dy < 0) {
      // 5th octant - normal is (-dy, dx)
      int f = 2*dy - dx;
      int df_x = 2*dy;
      int df_xy = -2*(dx - dy);
      int y = y0;

      for (int x = x0; x >= x1; x--) {
        _drawPixel(x, y);
        if (f < 0) {
          y--;
          f += df_xy;
        } else {
          f += df_x;
        }
      }
    } else if (dx > 0 && dy < 0) {
      // 8th octant - normal is (dy, -dx)
      int f = 2*dy + dx;
      int df_x = 2*dy;
      int df_xy = 2*(dy + dx);
      int y = y0;
      for (int x = x0; x <= x1; x++) {
        _drawPixel(x, y);
        if (f < 0) {
          y--;
          f += df_xy;
        } else {
          f += df_x;
        }
      }
    } else if (dy == 0) {
      // Horizontal line
      if (dx > 0) {
        for (int x = x0; x <= x1; x++) {
          _drawPixel(x, y0);
        }
      } else {
        for (int x = x0; x >= x1; x--) {
          _drawPixel(x, y0);
        }
      }
    }
  }
}

void Screen::_drawRect(int x0, int y0, int x1, int y1) {
	Uint32 *pixels = static_cast<Uint32*>(_surface->pixels);
	std::size_t line_offset = y0*_surface->w;
	// Top line
	for (int x = x0; x <= x1; x++) {
		pixels[line_offset + x] = _color_pixel;
	}
	// Side lines
	for (int y = y0+1; y < y1; y++) {
		pixels[y*_surface->w + x0] = _color_pixel;
		pixels[y*_surface->w + x1] = _color_pixel;
	}
	// Bottom line
	line_offset = y1*_surface->w;
	for (int x = x0; x <= x1; x++) {
		pixels[line_offset + x] = _color_pixel;
	}
	SDL_UnlockSurface(_surface);
}

void Screen::drawRect(int x0, int y0, int x1, int y1, bool lock) {
	if (lock) {
		if (SDL_LockSurface(_surface) == 0) {
			_drawRect(x0, y0, x1, y1);
		}
	} else {
		_drawRect(x0, y0, x1, y1);
	}
}

void Screen::_fillRect(int x0, int y0, int x1, int y1) {
	Uint32* pixels = static_cast<Uint32*>(_surface->pixels);
	for (int y = y0; y < y1; y++) {
		int line_offset = y*_surface->w;
		for (int x = x0; x < x1; x++) {
			pixels[line_offset + x] = _color_pixel;
		}
	}
}

void Screen::fillRect(int x0, int y0, int x1, int y1, bool lock) {
	if (lock) {
		if (SDL_LockSurface(_surface) == 0) {
			_fillRect(x0, y0, x1, y1);
			SDL_UnlockSurface(_surface);
		}
	} else {
		_fillRect(x0, y0, x1, y1);
	}
}

void Screen::drawCircle(int x, int y, int radius) {
}

void Screen::fillCircle(int x, int y, int radius) {
}

void Screen::drawImage(int image_handle, int x, int y) {
	if (image_handle >= 0 && image_handle < _image_store.size()) {
		SDL_Surface* image = _image_store[image_handle];
		SDL_Rect dest;
		dest.x = x;
		dest.y = y;
		SDL_BlitSurface(image, 0, _surface, &dest);
	}
}

void Screen::drawImage(int image_handle, int x, int y, const SDL_Rect &src) {
	if (image_handle >= 0 && image_handle < _image_store.size()) {
		drawSurface(_image_store[image_handle], x, y, src);
	}
}

void Screen::drawSurface(SDL_Surface* s, int x, int y, const SDL_Rect &src) {
	SDL_Rect dest;
	dest.x = x;
	dest.y = y;
	SDL_BlitSurface(s, const_cast<SDL_Rect*>(&src), _surface, &dest);
}

void Screen::drawSurface(SDL_Surface* s, int x, int y, int rotate_degrees, const SDL_Rect &src) {
}

void Screen::flush() const {
	SDL_Flip(_surface);
}

const ImageInfo Screen::loadImage(std::string filename) {
  SDL_Surface* loaded_surface = IMG_Load(filename.c_str());
  if (loaded_surface) {
    SDL_Surface* converted_surface = SDL_DisplayFormatAlpha(loaded_surface);
    if (converted_surface) {
      _image_store.push_back(converted_surface);
    }
    SDL_FreeSurface(loaded_surface);
    return ImageInfo(_image_store.size()-1, converted_surface->w, converted_surface->h);
  }
	return ImageInfo(-1, 0, 0);
}

const ImageInfo Screen::getImageInfo(int image_handle) const {
	if (image_handle >= 0 && image_handle < _image_store.size()) {
		SDL_Surface *image = _image_store[image_handle];
		return ImageInfo(image_handle, image->w, image->h);
	} else {
		return ImageInfo(-1, 0, 0);
	}
}

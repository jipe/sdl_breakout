#ifndef SCREEN_H
#define SCREEN_H

#include "Color.h"
#include "ImageInfo.h"

#include <SDL/SDL.h>
#include <string>
#include <vector>

class Screen {
  int _width, _height;
  SDL_Surface* _surface;
  Color _color, _background;
  unsigned int _color_pixel, _background_pixel;
  std::vector<SDL_Surface*> _image_store;

  void _drawRect(int x0, int y0, int x1, int y1);
  void _fillRect(int x0, int y0, int x1, int y1);
  inline void _drawPixel(int x, int y) { static_cast<Uint32*>(_surface->pixels)[y*_surface->w + x] = _color_pixel; }

  Screen& operator = (const Screen &screen) { return *this; }

	public:
		Screen(int width, int height);
		~Screen();

		void lockSurface();
		void unlockSurface();
		void setPixel(int x, int y, bool lock = true);
		Color getPixel(int x, int y) const;
		void setColor(Color c);
		void setBackground(Color c);
		void clear();

		void drawLine(int x0, int y0, int x1, int y1, bool antialias = false);
		void drawRect(int x0, int y0, int x1, int y1, bool lock = true);
		void fillRect(int x0, int y0, int x1, int y1, bool lock = true);
    void drawCircle(int x, int y, int radius);
    void fillCircle(int x, int y, int radius);

		void drawImage(int image_handle, int x, int y);
		void drawImage(int image_handle, int x, int y, const SDL_Rect &src);
		void drawSurface(SDL_Surface *s, int x, int y, const SDL_Rect &src);
		void drawSurface(SDL_Surface *s, int x, int y, int rotate_degrees, const SDL_Rect &src);

		void flush() const;

		const ImageInfo loadImage(std::string filename);
		const ImageInfo getImageInfo(int image_handle) const;

		inline int getHeight() { 
			return _height; 
		}

		inline int getWidth() { 
			return _width; 
		}

};

#endif

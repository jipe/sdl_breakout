#ifndef SCREEN_H
#define SCREEN_H

#include "Color.h"
#include "ImageInfo.h"

#include <SDL/SDL.h>
#include <string>
#include <vector>

class Screen {
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
		void drawImage(int imageHandle, int x, int y);
		void drawImage(int imageHandle, int x, int y, const SDL_Rect &src);
		void drawSurface(SDL_Surface *s, int x, int y, const SDL_Rect &src);
		void drawSurface(SDL_Surface *s, int x, int y, int rotateDegrees, const SDL_Rect &src);

		void flush() const;

		const ImageInfo loadImage(std::string fileName);
		const ImageInfo getImageInfo(int imageHandle) const;

		inline int getHeight() { 
			return height; 
		}

		inline int getWidth() { 
			return width; 
		}


	private:
		int width, height;
		SDL_Surface* surface;
		Color color, background;
		unsigned int colorPixel, backgroundPixel;
    std::vector<SDL_Surface*> _imageStore;

		void _drawRect(int x0, int y0, int x1, int y1);
		void _fillRect(int x0, int y0, int x1, int y1);
    inline void _drawPixel(int x, int y) { static_cast<Uint32*>(surface->pixels)[y*surface->w + x] = colorPixel; }

    Screen& operator = (const Screen &screen) { return *this; }
};

#endif

#include "Screen.h"
#include "Color.h"
#include "ScreenException.h"

#include <SDL/SDL.h>
#include <SDL/SDL_image.h>
#include <string>
#include <iostream>

const int IMAGE_STORE_SIZE = 128;

using namespace std;

Screen::Screen(int width, int height) : width(width), height(height), color(255, 255, 255, 0), background(0, 0, 0, 0) {
	if (SDL_Init(SDL_INIT_VIDEO) == -1) {
		throw ScreenException("Error initialising SDL");
	}
	surface = SDL_SetVideoMode(width, height, 32, SDL_ANYFORMAT);
	if (!surface) {
		throw ScreenException("Error setting video mode");
	}
	const SDL_VideoInfo* videoInfo = SDL_GetVideoInfo();
	if (videoInfo) {
		std::cout << "HW available? " << videoInfo->hw_available << std::endl;
	} else {
		std::cout << "Video info was null" << std::endl;
	}
	imageStore = new SDL_Surface*[IMAGE_STORE_SIZE];
	memset(imageStore, 0, IMAGE_STORE_SIZE * sizeof(SDL_Surface*));
	std::cout << "width: " << surface->w << std::endl;
	std::cout << "height: " << surface->h << std::endl;
	std::cout << "pitch: " << surface->pitch << std::endl;
	std::cout << "BPP: " << (int) surface->format->BytesPerPixel << std::endl;
	std::cout << "HW: " << (surface->flags & SDL_HWSURFACE) << std::endl;
}

Screen::~Screen() {
	std::cout << "Shutting down SDL" << std::endl;
	for (int i = 0; i < IMAGE_STORE_SIZE; i++) {
		if (imageStore[i]) {
			SDL_FreeSurface(imageStore[i]);
		}
	}
	delete[] imageStore;
	cout << "Deleted image store" << endl;
	SDL_Quit();
}

void Screen::lockSurface() {
	SDL_LockSurface(surface);
}

void Screen::unlockSurface() {
	SDL_UnlockSurface(surface);
}

void Screen::setPixel(int x, int y, bool lock) {
	if (lock) {
		if (SDL_LockSurface(surface) == 0) {
			((Uint32*) surface->pixels)[y*surface->w + x] = colorPixel;
			SDL_UnlockSurface(surface);
		}
	} else {
		((Uint32*) surface->pixels)[y*surface->w + x] = colorPixel;
	}
}

Color Screen::getPixel(int x, int y) const {
	Uint8 r, g, b, a;
	SDL_GetRGBA(0, surface->format, &r, &g, &b, &a);
	return Color(r, g, b, a);
}

void Screen::setColor(Color c) {
	colorPixel = SDL_MapRGBA(surface->format, c.getR(), c.getG(), c.getB(), c.getA());
}

void Screen::setBackground(Color c) {
	backgroundPixel = SDL_MapRGBA(surface->format, c.getR(), c.getG(), c.getB(), c.getA());
}

void Screen::clear() {
	if (SDL_LockSurface(surface) == 0) {;
		Uint32* pixels = (Uint32*) surface->pixels;
		for (int i = 0; i < surface->h*surface->w; i++) {
			pixels[i] = backgroundPixel;
		}
		SDL_UnlockSurface(surface);
	}
}

void Screen::drawLine(int x0, int y0, int x1, int y1) {
	// TODO: Bresenham or MidPointLine
}

void Screen::_drawRect(int x0, int y0, int x1, int y1) {
	Uint32 *pixels = static_cast<Uint32*>(surface->pixels);
	std::size_t lineOffset = y0*surface->w;
	// Top line
	for (int x = x0; x <= x1; x++) {
		pixels[lineOffset + x] = colorPixel;
	}
	// Side lines
	for (int y = y0+1; y < y1; y++) {
		pixels[y*surface->w + x0] = colorPixel;
		pixels[y*surface->w + x1] = colorPixel;
	}
	// Bottom line
	lineOffset = y1*surface->w;
	for (int x = x0; x <= x1; x++) {
		pixels[lineOffset + x] = colorPixel;
	}
	SDL_UnlockSurface(surface);
}

void Screen::drawRect(int x0, int y0, int x1, int y1, bool lock) {
	if (lock) {
		if (SDL_LockSurface(surface) == 0) {
			_drawRect(x0, y0, x1, y1);
		}
	} else {
		_drawRect(x0, y0, x1, y1);
	}
}

void Screen::_fillRect(int x0, int y0, int x1, int y1) {
	Uint32* pixels = static_cast<Uint32*>(surface->pixels);
	for (int y = y0; y < y1; y++) {
		int lineOffset = y*surface->w;
		for (int x = x0; x < x1; x++) {
			pixels[lineOffset + x] = colorPixel;
		}
	}
}

void Screen::fillRect(int x0, int y0, int x1, int y1, bool lock) {
	if (lock) {
		if (SDL_LockSurface(surface) == 0) {
			_fillRect(x0, y0, x1, y1);
			SDL_UnlockSurface(surface);
		}
	} else {
		_fillRect(x0, y0, x1, y1);
	}
}

void Screen::drawImage(int imageHandle, int x, int y) {
	if (imageHandle >= 0 && imageHandle < IMAGE_STORE_SIZE) {
		SDL_Surface* image = imageStore[imageHandle];
		SDL_Rect dest;
		dest.x = x;
		dest.y = y;
		SDL_BlitSurface(image, 0, surface, &dest);
	}
}

void Screen::drawImage(int imageHandle, int x, int y, const SDL_Rect &src) {
	if (imageHandle >= 0 && imageHandle < IMAGE_STORE_SIZE) {
		drawSurface(imageStore[imageHandle], x, y, src);
	}
}

void Screen::drawSurface(SDL_Surface* s, int x, int y, const SDL_Rect &src) {
	SDL_Rect dest;
	dest.x = x;
	dest.y = y;
	SDL_BlitSurface(s, const_cast<SDL_Rect*>(&src), surface, &dest);
}

void Screen::drawSurface(SDL_Surface* s, int x, int y, int rotateDegrees, const SDL_Rect &src) {
}

void Screen::flush() const {
	SDL_Flip(surface);
}

const ImageInfo Screen::loadImage(std::string fileName) {
	int ptr = 0;
	while (ptr < IMAGE_STORE_SIZE && imageStore[ptr]) {
		ptr++;
	}
	if (ptr < IMAGE_STORE_SIZE) {
		SDL_Surface* loadedSurface = IMG_Load(fileName.c_str());
		if (loadedSurface) {
			SDL_Surface* convertedSurface = SDL_DisplayFormatAlpha(loadedSurface);
			if (convertedSurface) {
				imageStore[ptr] = convertedSurface;
			}
			SDL_FreeSurface(loadedSurface);
			return ImageInfo(ptr, convertedSurface->w, convertedSurface->h);
		}
	}
	return ImageInfo(-1, 0, 0);
}

const ImageInfo Screen::getImageInfo(int imageHandle) const {
	if (imageHandle >= 0 && imageHandle < IMAGE_STORE_SIZE) {
		SDL_Surface *image = imageStore[imageHandle];
		return ImageInfo(imageHandle, image->w, image->h);
	} else {
		return ImageInfo(-1, 0, 0);
	}
}

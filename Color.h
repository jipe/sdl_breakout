#ifndef COLOR_H
#define COLOR_H

#include <SDL2/SDL.h>

class Color {
	Uint8 _r, _g, _b, _a;

public:
	Color(Uint8 r, Uint8 g, Uint8 b, Uint8 a = 0);

	inline Uint8 getR() {
		return _r;
	}

	inline Uint8 getG() {
		return _g;
	}

	inline Uint8 getB() {
		return _b;
	}

	inline Uint8 getA() {
		return _a;
	}

	static Color RED, GREEN, BLUE,
	DARK_RED, DARK_GREEN, DARK_BLUE,
	LIGHT_RED, LIGHT_GREEN, LIGHT_BLUE,
	YELLOW, MAGENTA, CYAN,
	DARK_YELLOW, DARK_MAGENTA, DARK_CYAN,
	LIGHT_YELLOW, LIGHT_MAGENTA, LIGHT_CYAN,
	BLACK, DARK_GREY, GREY, LIGHT_GREY, WHITE,
	ORANGE, NEON, AQUA, PURPLE, SKY;
};

#endif

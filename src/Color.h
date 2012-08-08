#ifndef COLOR_H
#define COLOR_H

#include <SDL/SDL.h>

class Color {
	public:
		Color(Uint8 r, Uint8 g, Uint8 b, Uint8 a = 0);

		inline Uint8 getR() {
			return r;
		}

		inline Uint8 getG() {
			return g;
		}

		inline Uint8 getB() {
			return b;
		}

		inline Uint8 getA() {
			return a;
		}

	private:
		Uint8 r, g, b, a;
};

#endif

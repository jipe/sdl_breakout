#ifndef COLOR_H
#define COLOR_H

#include <SDL/SDL.h>

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

};

#endif

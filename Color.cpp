#include "Color.h"
#include "math.h"

#include <SDL2/SDL.h>

Color::Color(Uint8 r, Uint8 g, Uint8 b, Uint8 a) : _r(r), _g(g), _b(b), _a(a) {
}

Color::Color(Vector3& v)
  : _r(static_cast<Uint8>(255 < v.x ? 255 : v.x)),
    _g(static_cast<Uint8>(255 < v.y ? 255 : v.y)),
    _b(static_cast<Uint8>(255 < v.z ? 255 : v.z)) {
}

Color Color::RED           (255,0,0);
Color Color::GREEN         (0,255,0);
Color Color::BLUE          (0,0,255);
Color Color::DARK_RED      (128,0,0);
Color Color::DARK_GREEN    (0,128,0);
Color Color::DARK_BLUE     (0,0,128);
Color Color::LIGHT_RED     (255,128,128);
Color Color::LIGHT_GREEN   (128,255,128);
Color Color::LIGHT_BLUE    (128,128,255);

Color Color::YELLOW        (255,255,0);
Color Color::MAGENTA       (255,0,255);
Color Color::CYAN          (0,255,255);
Color Color::DARK_YELLOW   (128,128,0);
Color Color::DARK_MAGENTA  (128,0,128);
Color Color::DARK_CYAN     (0,128,128);
Color Color::LIGHT_YELLOW  (255,255,128);
Color Color::LIGHT_MAGENTA (255,128,255);
Color Color::LIGHT_CYAN    (128,255,255);

Color Color::BLACK         (0,0,0);
Color Color::DARK_GREY     (64,64,64);
Color Color::GREY          (128,128,128);
Color Color::LIGHT_GREY    (192,192,192);
Color Color::WHITE         (255,255,255);

Color Color::ORANGE        (255,128,0);
Color Color::NEON          (128,255,0);
Color Color::AQUA          (0,255,128);
Color Color::PURPLE        (128,0,255);
Color Color::SKY           (0,128,255);

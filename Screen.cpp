#include "Screen.h"
#include "Color.h"
#include "ScreenException.h"
#include "Vertex.h"
#include "Vector2.h"
#include "Vector3.h"
#include "Matrix2x2.h"
#include "math.h"
#include "RasterPoint.h"
#include "RasterEdge.h"
#include "MidpointLineContext.h"

#include <SDL2/SDL.h>
#include <SDL2/SDL_image.h>
#include <string>
#include <iostream>
#include <vector>
#include <utility>

using namespace std;

Screen::Screen(int width, int height)
  : _width(width),
    _height(height),
    _color(255, 255, 255, 0),
    _background(0, 0, 0, 0) {
  if (SDL_Init(SDL_INIT_VIDEO) != 0) {
    std::cout << "Error initializing SDL" << std::endl;
    throw ScreenException("Error initialising SDL");
  }

  _window      = SDL_CreateWindow("SDL BreakOut", SDL_WINDOWPOS_CENTERED, SDL_WINDOWPOS_CENTERED, _width, _height, SDL_WINDOW_RESIZABLE);
  _renderer    = SDL_CreateRenderer(_window, -1, 0);
  _texture     = SDL_CreateTexture(_renderer, SDL_PIXELFORMAT_ARGB8888, SDL_TEXTUREACCESS_STREAMING, _width, _height);
  _pixelFormat = SDL_AllocFormat(SDL_GetWindowPixelFormat(_window));

  SDL_RenderSetLogicalSize(_renderer, _width, _height);

  if (!_window || !_renderer || !_texture) {
    std::cout << "Error creating window, renderer or texture" << std::endl;
    throw ScreenException("Error creating window");
  }

  _pixels = new Uint32[_width*_height];
  _textures = new SDL_Surface[32];
}

Screen::~Screen() {
  SDL_FreeFormat(_pixelFormat);
  SDL_DestroyTexture(_texture);
  SDL_DestroyRenderer(_renderer);
  SDL_DestroyWindow(_window);
  SDL_Quit();
  delete[] _pixels;
  delete[] _textures;
}

void Screen::setPixel(int x, int y) {
  _drawPixel(x, y);
}

Color Screen::getPixel(int x, int y) const {
  Uint8 r, g, b, a;
  SDL_GetRGBA(_pixels[y*_width + x], _pixelFormat,& r,& g,& b,& a);
  return Color(r, g, b, a);
}

void Screen::setColor(Color c) {
  _color_pixel = SDL_MapRGBA(_pixelFormat, c.getR(), c.getG(), c.getB(), c.getA());
}

void Screen::setColor(Vector3 v) {
  _color_pixel = SDL_MapRGBA(_pixelFormat, static_cast<unsigned int>(255.0f * v.x), static_cast<unsigned int>(255.0f * v.y), static_cast<unsigned int>(255.0f * v.z), 255);
}

void Screen::setBackground(Color c) {
  _background_pixel = SDL_MapRGBA(_pixelFormat, c.getR(), c.getG(), c.getB(), c.getA());
}

void Screen::clear() {
  for (int i = 0; i < _height*_width; i++) {
    _pixels[i] = _background_pixel;
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
  std::size_t line_offset = y0*_width;
  // Top line
  for (int x = x0; x <= x1; x++) {
    _pixels[line_offset + x] = _color_pixel;
  }
  // Side lines
  for (int y = y0+1; y < y1; y++) {
    _pixels[y*_width + x0] = _color_pixel;
    _pixels[y*_width + x1] = _color_pixel;
  }
  // Bottom line
  line_offset = y1*_width;
  for (int x = x0; x <= x1; x++) {
    _pixels[line_offset + x] = _color_pixel;
  }
}

void Screen::drawRect(int x0, int y0, int x1, int y1) {
  _drawRect(x0, y0, x1, y1);
}

void Screen::_fillRect(int x0, int y0, int x1, int y1) {
  for (int y = y0; y < y1; y++) {
    int line_offset = y*_width;
    for (int x = x0; x < x1; x++) {
      _pixels[line_offset + x] = _color_pixel;
    }
  }
}

void Screen::fillRect(int x0, int y0, int x1, int y1) {
  _fillRect(x0, y0, x1, y1);
}

void Screen::drawCircle(int x, int y, int radius) {
}

void Screen::fillCircle(int x, int y, int radius) {
}

void Screen::drawTriangle(const Vertex& v1, const Vertex& v2, const Vertex& v3) {
}

void Screen::_scan_convert(RasterEdge& left_edge, RasterEdge& right_edge) {
  int y1 = min(left_edge.y, right_edge.y);
  int y2 = min(left_edge.y_max, right_edge.y_max);

  for (int y = y1; y < y2; y++) {
    if (right_edge.x - left_edge.x > 0) {
      // Values to be interpolated across scanline
      Vector3 color(left_edge.color);
      Vector3 d_color((right_edge.color - left_edge.color) / static_cast<float>(right_edge.x - left_edge.x));
      Vector3 normal(left_edge.normal);
      Vector3 d_normal((right_edge.normal - left_edge.normal) / static_cast<float>(right_edge.x - left_edge.x));
      Vector2 texture_coord(left_edge.texture_coord);
      Vector2 d_texture_coord((right_edge.texture_coord - left_edge.texture_coord) / static_cast<float>(right_edge.x - left_edge.x));

      for (int x = left_edge.x; x < right_edge.x; x++) {
        setColor(color);
        _drawPixel(x, y);
        color += d_color;
        normal += d_normal;
        texture_coord += d_texture_coord;
      }
    }
    left_edge.nextLine();
    right_edge.nextLine();
  }
}

void Screen::fillTriangle(const Vertex& v1, const Vertex& v2, const Vertex& v3) {
  RasterPoint p1(v1),
              p2(v2),
              p3(v3);

  // Sort p1, p2 and p3 so p1.y <= p2.y <= p3.y
  if (p3.y < p2.y) {
    std::swap(p3, p2);
  }
  if (p3.y < p1.y) {
    std::swap(p3, p1);
  }
  if (p2.y < p1.y) {
    std::swap(p1, p2);
  }

  // Sort p1 and p2 so p1.x <= p2.x if they're on the same scanline
  if (p1.y == p2.y && p1.x > p2.x) {
    std::swap(p1, p2);
  }

  if (p1.y < p2.y) {
    // p1p2 is non-horizontal
    RasterEdge p1p2(p1, p2),
               p1p3(p1, p3);

    /* Determinant of | p1p3.x p1p2.x |
     *                | p1p3.y p1p2.y | */
    float d = (p3.x - p1.x) * (p2.y - p1.y) - (p3.y - p1.y) * (p2.x - p1.x);

    if (d < 0) {
      // p1p3 is left edge
      _scan_convert(p1p3, p1p2);
    } else {
      // p1p2 is left edge
      _scan_convert(p1p2, p1p3);
    }

    if (p3.y > p2.y) {
      // p2p3 is non-horizontal right edge
      RasterEdge p2p3(p2, p3);
      if (d < 0) {
        // p1p3 is left edge
        _scan_convert(p1p3, p2p3);
      } else {
        // p2p3 is left edge
        _scan_convert(p2p3, p1p3);
      }
    }
  } else if (p2.y < p3.y) {
    // p2p3 is non-horizontal
    RasterEdge p1p3(p1, p3),
               p2p3(p2, p3);

    /* Determinant of | p1p3.x p2p3.x |
     *                | p1p3.y p2p3.y | */
    float d = (p3.x - p1.x) * (p3.y - p2.y) - (p3.y - p1.y) * (p3.x - p2.x);

    if (d < 0) {
      // p1p3 is left edge
      _scan_convert(p1p3, p2p3);
    } else {
      // p2p3 is left edge
      _scan_convert(p2p3, p1p3);
    }
  }
}

void Screen::drawSurface(SDL_Surface* s, int x, int y, const SDL_Rect& src) {
  SDL_Rect dest;
  dest.x = x;
  dest.y = y;
}

void Screen::drawSurface(SDL_Surface* s, int x, int y, int rotate_degrees, const SDL_Rect& src) {
}

void Screen::flush() const {
  SDL_UpdateTexture(_texture, NULL, _pixels, _width * sizeof(Uint32));
  SDL_RenderClear(_renderer);
  SDL_RenderCopy(_renderer, _texture, NULL, NULL);
  SDL_RenderPresent(_renderer);
}

#ifndef SCREEN_H
#define SCREEN_H

#include "Color.h"
#include "ImageInfo.h"
#include "Vertex.h"
#include "RasterEdge.h"
#include "vector.h"

#include <SDL2/SDL.h>
#include <SDL2/SDL_image.h>
#include <string>
#include <vector>

class Screen {
  SDL_Window *_window;
  SDL_Renderer *_renderer;
  SDL_Texture *_texture;
  SDL_PixelFormat *_pixelFormat;
  std::vector<SDL_Surface*> _images;

  int _width, _height;
  Color _color, _background;
  Uint32 *_pixels;
  Uint32 _color_pixel, _background_pixel;

  void _drawRect(int x0, int y0, int x1, int y1);
  void _fillRect(int x0, int y0, int x1, int y1);
  void _scan_convert(RasterEdge& left_edge, RasterEdge& right_edge);
  void _scan_convert_textured(RasterEdge& left_edge, RasterEdge& right_edge, int texture);
  inline void _drawPixel(int x, int y) { _pixels[y*_width + x] = _color_pixel; }

  Screen& operator = (const Screen& screen) { return *this; }

  public:
    Screen(int width, int height);
    ~Screen();

    void setPixel(int x, int y);
    Color getPixel(int x, int y) const;
    void setColor(Color c);
    void setColor(Vector3 v);
    void setBackground(Color c);
    void clear();

    void drawLine(int x0, int y0, int x1, int y1, bool antialias = false);
    void drawRect(int x0, int y0, int x1, int y1);
    void fillRect(int x0, int y0, int x1, int y1);
    void drawCircle(int x, int y, int radius);
    void fillCircle(int x, int y, int radius);
    void drawTriangle(const Vertex& v1, const Vertex& v2, const Vertex& v3);
    void fillTriangle(const Vertex& v1, const Vertex& v2, const Vertex& v3, int texture = -1);

    /*
    void drawImage(int image_handle, int x, int y); 
    void drawImage(int image_handle, int x, int y, const SDL_Rect &src);
    */

    const ImageInfo loadImage(std::string filename);
    const ImageInfo getImageInfo(int image_handle) const;

    void flush() const;

    inline int getHeight() {
      return _height;
    }

    inline int getWidth() {
      return _width;
    }
};

#endif

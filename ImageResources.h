#ifndef IMAGE_RESOURCES_H
#define IMAGE_RESOURCES_H

#include "Screen.h"

class ImageResources {
  ImageInfo _bat_image_info, _ball_image_info, _red_brick_image_info, _green_brick_image_info, 
    _blue_brick_image_info, _grey_brick_image_info, _border_image_info, _grey_slate_image_info;

  public:
    ImageResources(Screen &screen);

    void init(Screen &screen);

    ImageInfo getBatImageInfo() const;
    ImageInfo getBallImageInfo() const;
    ImageInfo getRedBrickImageInfo() const;
    ImageInfo getGreenBrickImageInfo() const;
    ImageInfo getBlueBrickImageInfo() const;
    ImageInfo getGreyBrickImageInfo() const;
    ImageInfo getBorderImageInfo() const;
    ImageInfo getGreySlateImageInfo() const;
};

#endif

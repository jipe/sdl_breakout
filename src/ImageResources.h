#ifndef IMAGE_RESOURCES_H
#define IMAGE_RESOURCES_H

#include "Screen.h"

class ImageResources {
	ImageInfo _batImageInfo, _ballImageInfo, _redBrickImageInfo, _greenBrickImageInfo, 
		_blueBrickImageInfo, _greyBrickImageInfo, _borderImageInfo, _greySlateImageInfo;

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

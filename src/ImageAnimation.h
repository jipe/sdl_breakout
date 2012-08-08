#ifndef IMAGE_ANIMATION_H
#define IMAGE_ANIMATION_H

#include "Screen.h"
#include "Animation.h"

#include <string>

using namespace std;

class ImageAnimation : public Animation {
	int _imageHandle, _frameWidth, _imageWidth, _imageHeight;
	int _framePtr, _numberOfFrames;

	public:
		ImageAnimation(Screen &screen, int imageHandle, int frameWidth, int fps);
		virtual ~ImageAnimation() { }

		bool nextFrame();
		void setFrame(int frame);
		void render(Screen &screen, int x, int y) const;
};

#endif

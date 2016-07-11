#ifndef IMAGE_ANIMATION_H
#define IMAGE_ANIMATION_H

#include "Screen.h"
#include "Animation.h"

#include <string>

using namespace std;

class ImageAnimation : public Animation {
	int _image_handle, _frame_width, _image_width, _image_height;
	int _frame_ptr, _number_of_frames;

	public:
		ImageAnimation(Screen &screen, int image_handle, int frame_width, int fps);
		virtual ~ImageAnimation() { }

		bool nextFrame();
		void setFrame(int frame);
		void render(Screen &screen, int x, int y) const;
};

#endif

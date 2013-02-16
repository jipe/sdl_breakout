#ifndef IMAGE_INFO_H
#define IMAGE_INFO_H

struct ImageInfo {
	int image_handle;
	int width, height;

	ImageInfo();
	ImageInfo(int image_handle, int width, int height);
};

#endif

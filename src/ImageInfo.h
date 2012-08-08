#ifndef IMAGE_INFO_H
#define IMAGE_INFO_H

struct ImageInfo {
	int imageHandle;
	int width, height;

	ImageInfo();
	ImageInfo(int imageHandle, int width, int height);
};

#endif

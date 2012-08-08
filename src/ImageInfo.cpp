#include "ImageInfo.h"

ImageInfo::ImageInfo() 
		: imageHandle(-1), width(0), height(0) {
}

ImageInfo::ImageInfo(int imageHandle, int width, int height) 
		: imageHandle(imageHandle), width(width), height(height) {
}

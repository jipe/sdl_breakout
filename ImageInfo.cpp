#include "ImageInfo.h"

ImageInfo::ImageInfo() 
    : image_handle(-1), width(0), height(0) {
}

ImageInfo::ImageInfo(int image_handle, int width, int height) 
    : image_handle(image_handle), width(width), height(height) {
}

//
// Created by MatGod on 05.09.2020.
//

#include <png.h>
#include "Image.h"

void Image::loadImage(std::string imagePath) {
    FILE* file;
    fopen_s(&file, imagePath.data(), "rb");

    png_structp png = png_create_read_struct(PNG_LIBPNG_VER_STRING, NULL, NULL, NULL);
}

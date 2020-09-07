//
// Created by MatGod on 05.09.2020.
//

#include <iostream>
#include <sys/stat.h>

#include "Image.h"

Image::Image(const std::string &imagePath) {
    load(imagePath);
}

void Image::load(const std::string& imagePath) {
    path = imagePath;
    struct stat buffer{};
    if (stat(imagePath.c_str(), &buffer) != 0) {
        std::cout << "File " << imagePath << " not found. Exit";
        exit(1);
    }
    image<rgba_pixel> img(imagePath);
    width = img.get_width();
    height = img.get_height();
    data.reserve(width * height * 4);
    for (int i = 0; i != height; ++i) {
        for (int j = 0; j != width; ++j) {
            data[(i * width + j) * 4] = img.get_pixel(j, i).red;
            data[(i * width + j) * 4 + 1] = img.get_pixel(j, i).green;
            data[(i * width + j) * 4 + 2] = img.get_pixel(j, i).blue;
            data[(i * width + j) * 4 + 3] = img.get_pixel(j, i).alpha;
        }
    }
}

void Image::update(const std::string& imagePath) {
    clear();
    load(imagePath);
}

void Image::clear() {
    path = "";
    width = 0;
    height = 0;
}

std::string Image::getPath() {
    return path;
}

uint8_t* Image::getData() {
    return data.data();
}

int Image::getWidth() const {
    return width;
}

int Image::getHeight() const {
    return height;
}

Image::~Image() {
    clear();
}

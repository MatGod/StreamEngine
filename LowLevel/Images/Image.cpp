//
// Created by MatGod on 05.09.2020.
//

#include <iostream>

#include "Image.h"

Image::Image(const std::string &imagePath) {
    load(imagePath);
}

void Image::load(const std::string& imagePath) {
    path = imagePath;

    image<rgba_pixel> img(imagePath);
    data = img.get_pixbuf();
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

imageBuffer Image::getData() const {
    return data;
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

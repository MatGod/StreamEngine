//
// Created by MatGod on 05.09.2020.
//

#ifndef STREAMENGINE_IMAGE_H
#define STREAMENGINE_IMAGE_H

#include <vector>
#include <string>
#include "../../pngpp/png.hpp"

using namespace png;

typedef pixel_buffer<basic_rgba_pixel<unsigned char>> imageBuffer;

class Image {
private:
    std::string path;
    imageBuffer data;
    int width = 0;
    int height = 0;

public:
    explicit Image(const std::string& imagePath);
    void load(const std::string& imagePath);
    void update(const std::string& imagePath);
    void clear();
    std::string getPath();
    imageBuffer getData() const;
    int getWidth() const;
    int getHeight() const;
    ~Image();
};


#endif //STREAMENGINE_IMAGE_H

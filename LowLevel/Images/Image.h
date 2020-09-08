//
// Created by MatGod on 05.09.2020.
//

#ifndef STREAMENGINE_IMAGE_H
#define STREAMENGINE_IMAGE_H

#include <vector>
#include <string>
#include "../../pngpp/png.hpp"
#include "Drawable.h"

using namespace png;

class Image : public Drawable, public std::enable_shared_from_this<Image> {
private:
    std::string path;
    std::vector<uint8_t> data;
    int width = 0;
    int height = 0;

public:
    explicit Image(const std::string& imagePath);
    std::shared_ptr<Image> getImage(clock_t) override;
    void load(const std::string& imagePath);
    void update(const std::string& imagePath);
    void clear();
    std::string getPath();
    uint8_t* getData();
    int getWidth() const;
    int getHeight() const;
    ~Image();
};


#endif //STREAMENGINE_IMAGE_H

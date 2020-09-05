//
// Created by MatGod on 05.09.2020.
//

#ifndef STREAMENGINE_IMAGE_H
#define STREAMENGINE_IMAGE_H

#include <vector>
#include <xstring>

class Image {
private:
    unsigned char** data;
    int width;
    int height;

public:
    void loadImage(std::string imagePath);

};


#endif //STREAMENGINE_IMAGE_H

//
// Created by matgod on 07.09.2020.
//

#ifndef STREAMENGINE_DRAWABLE_H
#define STREAMENGINE_DRAWABLE_H


#include <memory>

class Image;

class Drawable {
public:
    virtual std::shared_ptr<Image> getImage(clock_t) = 0;
};


#endif //STREAMENGINE_DRAWABLE_H

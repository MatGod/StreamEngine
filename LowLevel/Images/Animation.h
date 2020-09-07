//
// Created by matgod on 07.09.2020.
//

#ifndef STREAMENGINE_ANIMATION_H
#define STREAMENGINE_ANIMATION_H


#include <list>
#include <memory>
#include "Drawable.h"
#include "Image.h"

class Animation : public Drawable {
private:
    std::vector<std::shared_ptr<Image>> animList;
    float playTime = 0;

public:
    explicit Animation(std::vector<std::shared_ptr<Image>>);
    std::shared_ptr<Image> getFrame(float time);
};


#endif //STREAMENGINE_ANIMATION_H

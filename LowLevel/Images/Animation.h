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
    float playTime = 5;

public:
    explicit Animation(std::vector<std::shared_ptr<Image>>, float);
    std::shared_ptr<Image> getImage(clock_t time) override;
};


#endif //STREAMENGINE_ANIMATION_H

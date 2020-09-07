//
// Created by matgod on 07.09.2020.
//

#include "Animation.h"

#include <utility>

Animation::Animation(std::vector<std::shared_ptr<Image>> images) {
    animList = std::move(images);
}

std::shared_ptr<Image> Animation::getFrame(float time) {
    return animList[static_cast<int>(time / playTime * animList.size()) % static_cast<int>(animList.size())];
}

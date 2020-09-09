//
// Created by matgod on 07.09.2020.
//

#include "Animation.h"

#include <utility>

Animation::Animation(std::vector<std::shared_ptr<Image>> images, float playTime) {
    this->playTime = playTime;
    animList = std::move(images);
}

std::shared_ptr<Image> Animation::getImage(clock_t time) {
    if (animList.empty()) {
        std::cout << "Error! Trying to getImage from empty Animation. Exiting";
        exit(3);
    }
    return animList[static_cast<int>(time / (playTime * 100 * animList.size())) % static_cast<int>(animList.size())];
}

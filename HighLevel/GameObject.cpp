//
// Created by matgod on 07.09.2020.
//

#include "GameObject.h"
#include "../LowLevel/Images/Animation.h"

#include <utility>

GameObject::GameObject(std::shared_ptr<Drawable> drawable) {
    pic = std::move(drawable);
}

void GameObject::setPosition(float x, float y) {
    this->x = x;
    this->y = y;
}

void GameObject::setSize(float width, float height) {
    this->width = width;
    this->height = height;
}

void GameObject::setSpeed(float speed) {
    this->speed = speed;
}

float GameObject::getXPos() const {
    return x;
}

float GameObject::getYPos() const {
    return y;
}

float GameObject::getWidth() const {
    return width;
}

float GameObject::getHeight() const {
    return height;
}

float GameObject::getSpeed() const {
    return speed;
}

std::shared_ptr<Image> GameObject::getImage() {
    if (std::is_same<decltype(pic), class Image>::value) {
        Image* img = static_cast<Image*>(pic.get());
        return std::shared_ptr<Image>();
    } else {
        auto* anim = static_cast<Animation*>(pic.get());
        return static_cast<Animation*>(pic.get())->getFrame(lifeTime);
    }
}

//
// Created by matgod on 07.09.2020.
//

#include "GameObject.h"
#include "../LowLevel/Images/Animation.h"

#include <utility>

GameObject::GameObject(const std::string &name, std::shared_ptr<Drawable> drawable) {
    this->name = name;
    pic = std::move(drawable);
    bornTime = clock();
}

GameObject::GameObject(const std::string &name, const std::vector<std::shared_ptr<Image>>& animImages, float playTime) {
    this->name = name;
    pic = std::make_shared<Animation>(animImages, playTime);
}

std::string GameObject::GetName() {
    return name;
}

void GameObject::SetPosition(float x, float y) {
    this->x = x;
    this->y = y;
}

void GameObject::SetSize(float w, float h) {
    width = w;
    height = h;
}

void GameObject::SetSpeed(float s) {
    speed = s;
}

float GameObject::GetXPos() const {
    return x;
}

float GameObject::GetYPos() const {
    return y;
}

float GameObject::GetWidth() const {
    return width;
}

float GameObject::GetHeight() const {
    return height;
}

float GameObject::GetSpeed() const {
    return speed;
}

std::shared_ptr<Image> GameObject::GetImage() {
    return pic->getImage(clock() - bornTime);
}

void GameObject::Move(Direction dir) {
    switch (dir) {
        case UP: {
            y += speed;
            break;
        }
        case DOWN: {
            y -= speed;
            break;
        }
        case LEFT: {
            x -= speed;
            break;
        }
        case RIGHT: {
            x += speed;
            break;
        }
    }
}

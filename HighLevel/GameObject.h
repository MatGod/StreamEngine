//
// Created by matgod on 07.09.2020.
//

#ifndef STREAMENGINE_GAMEOBJECT_H
#define STREAMENGINE_GAMEOBJECT_H


#include <memory>
#include "../LowLevel/Images/Drawable.h"

class GameObject {
private:
    std::shared_ptr<Drawable> pic;
    float x = 0;
    float y = 0;
    float width = 0;
    float height = 0;
    float speed = 0;
    float bornTime = 0;
    float lifeTime = 0;

public:
    explicit GameObject(std::shared_ptr<Drawable> drawable);
    std::shared_ptr<Image> getImage();
    void setPosition(float x, float y);
    void setSize(float width, float height);
    void setSpeed(float speed);
    float getXPos() const;
    float getYPos() const;
    float getWidth() const;
    float getHeight() const;
    float getSpeed() const;
};


#endif //STREAMENGINE_GAMEOBJECT_H

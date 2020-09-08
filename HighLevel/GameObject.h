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
    clock_t bornTime = 0;
    clock_t lifeTime = 0;

public:
    explicit GameObject(std::shared_ptr<Drawable> drawable);
    std::shared_ptr<Image> GetImage();
    void SetPosition(float x, float y);
    void SetSize(float w, float h);
    void SetSpeed(float s);
    float GetXPos() const;
    float GetYPos() const;
    float GetWidth() const;
    float GetHeight() const;
    float GetSpeed() const;
    void Move();
};


#endif //STREAMENGINE_GAMEOBJECT_H

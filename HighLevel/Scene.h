//
// Created by matgod on 07.09.2020.
//

#ifndef STREAMENGINE_SCENE_H
#define STREAMENGINE_SCENE_H


#include <list>
#include "../LowLevel/Render/Render.h"
#include "GameObject.h"

class Scene {
private:
    std::shared_ptr<Render> render;
    std::map<int, GameObject> objects;

public:
    explicit Scene(std::shared_ptr<Render>);
    void Draw();
};


#endif //STREAMENGINE_SCENE_H

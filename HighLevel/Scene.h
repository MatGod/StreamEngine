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
    std::map<int, std::shared_ptr<GameObject>> objects;
    int nextID = 0;

public:
    explicit Scene(std::shared_ptr<Render>);
    int AddObject(std::shared_ptr<GameObject> object);
    void DeleteObject(int id);
    void Draw();
};


#endif //STREAMENGINE_SCENE_H

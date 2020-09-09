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
    std::map<std::string, std::shared_ptr<GameObject>> objects;
    int nextID = 0;

public:
    explicit Scene(std::shared_ptr<Render>);
    void AddObject(std::shared_ptr<GameObject> object);
    void DeleteObject(const std::string &name);
    std::shared_ptr<GameObject> GetObject(const std::string &name);
    void Draw();
};


#endif //STREAMENGINE_SCENE_H

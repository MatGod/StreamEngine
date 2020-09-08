//
// Created by matgod on 07.09.2020.
//

#include "Scene.h"

#include <utility>

Scene::Scene(std::shared_ptr<Render> r) {
    render = std::move(r);
}

void Scene::Draw() {
    render->clearFrame();
    for (const auto &obj : objects) {
        auto gameObject = obj.second;
        render->drawImage(gameObject->GetImage(),
                          gameObject->GetXPos(), gameObject->GetYPos(),
                          gameObject->GetWidth(), gameObject->GetHeight());
    }
    render->updateFrame();
}

int Scene::AddObject(std::shared_ptr<GameObject> object) {
    objects[nextID] = std::move(object);
    return nextID++;
}

void Scene::DeleteObject(int id) {
    objects.erase(id);
}

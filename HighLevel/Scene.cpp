//
// Created by matgod on 07.09.2020.
//

#include "Scene.h"

#include <utility>

Scene::Scene(std::shared_ptr<Render> r) {
    render = std::move(r);
}

void Scene::AddObject(std::shared_ptr<GameObject> object) {
    objects[object->GetName()] = std::move(object);
}

void Scene::DeleteObject(const std::string &name) {
    objects.erase(name);
}

std::shared_ptr<GameObject> Scene::GetObject(const std::string &name) {
    return objects[name];
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

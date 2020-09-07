//
// Created by matgod on 07.09.2020.
//

#include "Scene.h"

#include <utility>

Scene::Scene(std::shared_ptr<Render> r) {
    render = std::move(r);
}

void Scene::Draw() {
    for (const auto &obj : objects) {
        auto gameObject = obj.second;
        render->DrawImage(gameObject.getImage(),
                          gameObject.getXPos(), gameObject.getYPos(),
                          gameObject.getWidth(),gameObject.getHeight());
    }

}

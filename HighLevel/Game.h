//
// Created by matgod on 07.09.2020.
//

#ifndef STREAMENGINE_GAME_H
#define STREAMENGINE_GAME_H


#include "../LowLevel/Render/Render.h"
#include "Scene.h"

class Game {
private:
    std::shared_ptr<Render> render;
    std::unique_ptr<Scene> scene;

    bool running = true;
public:
    explicit Game(int width = 1366, int height = 768);
    void Draw();
    int AddObject(std::shared_ptr<GameObject> obj);
    std::shared_ptr<Image> LoadImage(const std::string& imgPath);
    void addKeyAction(Key, Action);
    void StopPlay();
    bool IsRunning() const;
};


#endif //STREAMENGINE_GAME_H

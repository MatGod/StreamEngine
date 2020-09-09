//
// Created by matgod on 07.09.2020.
//

#ifndef STREAMENGINE_GAME_H
#define STREAMENGINE_GAME_H


#include "../LowLevel/Render/Render.h"
#include "Scene.h"
#include "../XMLParser/LibraryXML.h"
#include "../XMLParser/SceneLoaderXML.h"

class Game {
private:
    std::shared_ptr<Render> render;
    std::shared_ptr<Scene> scene;
    std::shared_ptr<LibraryXML> lib;
    std::shared_ptr<SceneLoaderXML> sceneLoader;

    bool running = true;
public:
    explicit Game(int width = 1366, int height = 768);
    void Draw();
    void AddObject(std::shared_ptr<GameObject> obj);
    std::shared_ptr<GameObject> GetObject(const std::string &name);
    void DeleteObject(const std::string &name);
    std::shared_ptr<Image> LoadImage(const std::string& imgPath);
    void AddKeyAction(Key, Action);
    void StopPlay();
    bool IsRunning() const;
    void LoadLib(const std::string& libPathXML);
    std::shared_ptr<Drawable> GetDrawable(const std::string& key);
    void LoadScene(const std::string& scenePathXML);
};


#endif //STREAMENGINE_GAME_H

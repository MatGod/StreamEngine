//
// Created by matgod on 07.09.2020.
//

#include "Game.h"

#include <utility>

Game::Game(int width, int height) {
    render = std::make_shared<Render>(width, height);
    scene = std::make_unique<Scene>(render);
    lib = std::make_unique<LibraryXML>(render);
    sceneLoader = std::make_shared<SceneLoaderXML>(lib, render);
}

bool Game::IsRunning() const {
    return running;
}

void Game::Draw() {
    scene->Draw();
}

std::shared_ptr<Image> Game::LoadImage(const std::string& imgPath) {
    return render->loadImage(imgPath);
}

void Game::AddObject(std::shared_ptr<GameObject> obj) {
    scene->AddObject(std::move(obj));
}

std::shared_ptr<GameObject> Game::GetObject(const std::string &name) {
    return scene->GetObject(name);
}

void Game::DeleteObject(const std::string &name) {
    scene->DeleteObject(name);
}

void Game::AddKeyAction(Key key, Action action) {
    render->addKeyAction(key, std::move(action));
}

void Game::StopPlay() {
    running = false;
    render->close();
}

void Game::LoadLib(const std::string& libPathXML) {
    lib->LoadLibrary(libPathXML);
}

std::shared_ptr<Drawable> Game::GetDrawable(const std::string& key) {
    return lib->GetDrawable(key);
}

void Game::LoadScene(const std::string &scenePathXML) {
    scene = sceneLoader->LoadScene(scenePathXML);
}

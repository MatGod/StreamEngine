//
// Created by matgod on 07.09.2020.
//

#include "Game.h"

#include <utility>

Game::Game(int width, int height) {
    render = std::make_shared<Render>(width, height);
    scene = std::make_unique<Scene>(render);
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

int Game::AddObject(std::shared_ptr<GameObject> obj) {
    return scene->AddObject(std::move(obj));
}

void Game::addKeyAction(Key key, Action action) {
    render->addKeyAction(key, std::move(action));
}

void Game::StopPlay() {
    running = false;
    render->close();
}

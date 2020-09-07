//
// Created by matgod on 07.09.2020.
//

#include "Game.h"

Game::Game(int width, int height) {
    render = std::make_shared<Render>(width, height);
    scene = std::make_unique<Scene>(render);
}

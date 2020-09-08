//
// Created by matgod on 08.09.2020.
//

#include "KeyMapper.h"

#include <utility>

KeyMapper* KeyMapper::instance = nullptr;
KeyMapperDestroyer KeyMapper::destroyer;

KeyMapperDestroyer::~KeyMapperDestroyer() {
    delete instance;
}

void KeyMapperDestroyer::initialize(KeyMapper* p) {
    instance = p;
}

KeyMapper* KeyMapper::getMapper() {
    if (!instance) {
        instance = new KeyMapper;
        destroyer.initialize(instance);
    }
    return instance;
}

void KeyMapper::addKeyAction(Key key, Action action) {
    actions[key] = std::move(action);
}

void KeyMapper::doAction(int key) {
    if (actions[key]) {
        actions[key]();
    }
}
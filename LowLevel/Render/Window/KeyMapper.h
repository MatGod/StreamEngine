//
// Created by matgod on 08.09.2020.
//

#ifndef STREAMENGINE_KEYMAPPER_H
#define STREAMENGINE_KEYMAPPER_H


#include <unordered_map>
#include <functional>
#include <GLFW/glfw3.h>

using Action = std::function<void()>;

enum Key {
    ESC = GLFW_KEY_ESCAPE,
    ARROW_UP = GLFW_KEY_UP,
    ARROW_DOWN = GLFW_KEY_DOWN,
    ARROW_LEFT = GLFW_KEY_LEFT,
    ARROW_RIGHT = GLFW_KEY_RIGHT,
    DELETE = GLFW_KEY_DELETE,
    INSERT = GLFW_KEY_INSERT
};

class KeyMapper;

class KeyMapperDestroyer {
private:
    KeyMapper* instance;

public:
    ~KeyMapperDestroyer();
    void initialize(KeyMapper*);
};

class KeyMapper {
private:
    static KeyMapper* instance;
    static KeyMapperDestroyer destroyer;

    std::unordered_map<int, Action> actions;

protected:
    KeyMapper() = default;;
    KeyMapper(const KeyMapper&){}
    KeyMapper& operator=(KeyMapper const&){ return *this; }
    ~KeyMapper() = default;;
    friend class KeyMapperDestroyer;

public:
    static KeyMapper* getMapper();
    void addKeyAction(Key, Action);
    void doAction(int);
};


#endif //STREAMENGINE_KEYMAPPER_H

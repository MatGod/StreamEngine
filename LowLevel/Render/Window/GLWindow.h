//
// Created by MatGod on 05.09.2020.
//

#ifndef STREAMENGINE_GLWINDOW_H
#define STREAMENGINE_GLWINDOW_H

#include <GL/glew.h>
#include <GLFW/glfw3.h>
#include <functional>
#include "KeyMapper.h"

enum FullscreenMode {
    WINDOWED = 0,
    FULLSCREEN = 1
};

class GLWindow;

class GLWindowDestroyer {
private:
    GLWindow* instance;
public:
    ~GLWindowDestroyer();
    void initialize(GLWindow* p);
};

class GLWindow {
private:
    static GLWindow* instance;
    static GLWindowDestroyer destroyer;
    int width = 0;
    int height = 0;
    int bufferWidth = 0;
    int bufferHeight = 0;
    GLFWwindow* window;
    static KeyMapper* mapper;
    static void keyCallback(GLFWwindow*, int, int, int, int);

protected:
    GLWindow(int&, int&);
    GLWindow(const GLWindow&) = default;
    GLWindow& operator=(GLWindow const&){ return *this; }
    ~GLWindow() = default;
    friend class GLWindowDestroyer;

public:
    static GLWindow* getWindow(int = 1366, int = 768);
    int getWidth() const;
    int getHeight() const;
    void addKeyAction(Key, Action);
    void update();
    void close();
};


#endif //STREAMENGINE_GLWINDOW_H

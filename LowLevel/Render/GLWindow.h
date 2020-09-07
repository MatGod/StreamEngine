//
// Created by MatGod on 05.09.2020.
//

#ifndef STREAMENGINE_GLWINDOW_H
#define STREAMENGINE_GLWINDOW_H

#include <GL/glew.h>
#include <GLFW/glfw3.h>
#include <iostream>
#include <functional>

class GLWindow {
private:
    GLFWwindow* window;
    int width = 0;
    int height = 0;
    int bufferWidth = 0;
    int bufferHeight = 0;

public:
    explicit GLWindow(int windowWidth = 1366, int windowHeight = 768);
    GLFWwindow* getGLFWWindow() {return window;}
    void execute(const std::function<void(void)>& drawFunc);
    int getWidth() const;
    int getHeight() const;

};


#endif //STREAMENGINE_GLWINDOW_H

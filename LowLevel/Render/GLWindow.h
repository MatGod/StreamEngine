//
// Created by MatGod on 05.09.2020.
//

#ifndef STREAMENGINE_GLWINDOW_H
#define STREAMENGINE_GLWINDOW_H


#include <GLFW/glfw3.h>

class GLWindow {
private:
    GLFWwindow* window;
    int width;
    int height;
    int bufferWidth;
    int bufferHeight;

public:
    explicit GLWindow(int windowWidth = 1366, int windowHeight = 768);
    GLFWwindow* getGLFWWindow() {return window;}
    void execute();

};


#endif //STREAMENGINE_GLWINDOW_H

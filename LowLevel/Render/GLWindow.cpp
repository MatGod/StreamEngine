//
// Created by MatGod on 05.09.2020.
//


#include "GLWindow.h"

GLWindow::GLWindow(int windowWidth, int windowHeight) : width(windowWidth), height(windowHeight) {
    glfwInit();

    glfwWindowHint(GLFW_CONTEXT_VERSION_MAJOR, 3);
    glfwWindowHint(GLFW_CONTEXT_VERSION_MINOR, 3);
    glfwWindowHint(GLFW_OPENGL_PROFILE, GLFW_OPENGL_CORE_PROFILE);
    glfwWindowHint(GLFW_RESIZABLE, GL_FALSE);
    glfwWindowHint(GLFW_SAMPLES, 4);

    window = glfwCreateWindow(width, height, "StreamEngine Test", nullptr, nullptr);
    if (window == nullptr) {
        std::cout << "Failed to create GLWindow. Terminate";
        glfwTerminate();
        exit(2);
    }
    glfwMakeContextCurrent(window);
    if (glewInit() != GLEW_OK) {
        std::cout << "Failed to init GLEW\n";
        exit(2);
    }
    glfwSwapInterval(1);

    glfwGetFramebufferSize(window, &bufferWidth, &bufferHeight);

    glDepthFunc(GL_LESS);

    glViewport(0, 0, bufferWidth, bufferHeight);
    glEnable(GL_MULTISAMPLE);

    glClearColor(1, 1, 1, 1);
}

void GLWindow::execute(const std::function<void(void)>& drawFunc) {
    glClear(GL_COLOR_BUFFER_BIT);

    //Insert Rendering code;
    drawFunc();

    glfwSwapBuffers(window);
    glfwPollEvents();
}

int GLWindow::getWidth() const {
    return bufferWidth;
}

int GLWindow::getHeight() const {
    return bufferHeight;
}

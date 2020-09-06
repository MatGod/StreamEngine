//
// Created by MatGod on 05.09.2020.
//

#include <iostream>
#include "GLWindow.h"

GLWindow::GLWindow(int windowWidth, int windowHeight) : width(windowWidth), height(windowHeight) {
    glfwInit();

    glfwWindowHint(GLFW_CONTEXT_VERSION_MAJOR, 3);
    glfwWindowHint(GLFW_CONTEXT_VERSION_MINOR, 3);
    glfwWindowHint(GLFW_OPENGL_PROFILE, GLFW_OPENGL_CORE_PROFILE);
    glfwWindowHint(GLFW_RESIZABLE, GL_FALSE);

    window = glfwCreateWindow(width, height, "StreamEngine Test", nullptr, nullptr);

    if (window == nullptr) {
        std::cout << "Failed to create GLWindow. Terminate";
        glfwTerminate();
    }
    glfwMakeContextCurrent(window);
    glfwSwapInterval(1);

    glfwGetFramebufferSize(window, &bufferWidth, &bufferHeight);

    glEnable(GL_DEPTH_TEST);
    glEnable(GL_DOUBLEBUFFER);
    glDepthFunc(GL_LESS);

    glViewport(0, 0, bufferWidth, bufferHeight);

    glClearColor(0, 0, 0, 1);
    glOrtho(0, 0, bufferWidth, bufferHeight, 1, 0);
    glEnable(GL_BLEND);
    glEnable(GL_ALPHA_TEST);
    glBlendFunc(GL_SRC_ALPHA, GL_ONE_MINUS_SRC_ALPHA);
}

void GLWindow::execute() {
    while (!glfwWindowShouldClose(window)) {
        glClear(GL_COLOR_BUFFER_BIT | GL_STENCIL_BUFFER_BIT);

        //Insert Rendering code;


        glfwSwapBuffers(window);
        glfwPollEvents();
    }
}

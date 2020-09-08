//
// Created by MatGod on 05.09.2020.
//


#include "GLWindow.h"

#include <iostream>
#include <utility>

GLWindow* GLWindow::instance = nullptr;
GLWindowDestroyer GLWindow::destroyer;
KeyMapper* GLWindow::mapper = nullptr;

GLWindowDestroyer::~GLWindowDestroyer() {
    delete instance;
}

void GLWindowDestroyer::initialize(GLWindow *p) {
    instance = p;
}

GLWindow* GLWindow::getWindow(int windowWidth, int windowHeight) {
    if (!instance) {
        instance = new GLWindow(windowWidth, windowHeight);
        destroyer.initialize(instance);
    }
    return instance;
}

GLWindow::GLWindow(int& width, int& height) : width(width), height(height) {
    mapper = KeyMapper::getMapper();
    glfwInit();
    //Настройка GLFW
    //Задается минимальная требуемая версия OpenGL.
    //Мажорная
    glfwWindowHint(GLFW_CONTEXT_VERSION_MAJOR, 3);
    //Минорная
    glfwWindowHint(GLFW_CONTEXT_VERSION_MINOR, 3);
    //Установка профайла для которого создается контекст
    glfwWindowHint(GLFW_OPENGL_PROFILE, GLFW_OPENGL_CORE_PROFILE);
    //Выключение возможности изменения размера окна
    glfwWindowHint(GLFW_RESIZABLE, GL_FALSE);

    glfwWindowHint(GLFW_DECORATED, GLFW_FALSE);

    glfwWindowHint(GLFW_SAMPLES, 4);

    window = glfwCreateWindow(width, height, "tests", nullptr, nullptr);
    if (window == nullptr) {
        std::cout << "Failed to create GLFW window\n";
        glfwTerminate();
        exit(1);
    }

    glfwMakeContextCurrent(window);
    glewExperimental = GL_TRUE;
    if (glewInit() != GLEW_OK) {
        std::cout << "Failed to init GLEW\n";
        exit(1);
    }

    glfwGetFramebufferSize(window, &bufferWidth, &bufferHeight);

    glfwSetKeyCallback(window, keyCallback);
}

int GLWindow::getWidth() const {
    return bufferWidth;
}

int GLWindow::getHeight() const {
    return bufferHeight;
}

void GLWindow::keyCallback(GLFWwindow *w, int key, int scancode, int action, int mode) {
    if (action == GLFW_REPEAT || action == GLFW_PRESS) {
        mapper->doAction(key);
    }
}

void GLWindow::close() {
    glfwSetWindowShouldClose(window, GL_TRUE);
}

void GLWindow::addKeyAction(Key key, Action action) {
    mapper->addKeyAction(key, std::move(action));
}

void GLWindow::update() {
    glfwSwapBuffers(window);
    glfwPollEvents();
}

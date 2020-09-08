//
// Created by matgod on 05.09.2020.
//

#ifndef STREAMENGINE_RENDER_H
#define STREAMENGINE_RENDER_H

#include <map>
#include <memory>
#include <GL/glew.h>
#include <GLFW/glfw3.h>
#include "../Images/Image.h"
#include "Window/GLWindow.h"
#include "Shaders/Shader.h"

class Render {
private:
    std::map<std::string, std::pair<std::shared_ptr<Image>, GLuint>> texIDs;
    GLWindow* window;
    std::unique_ptr<Shader> shaderProg;

    GLuint VBO = 0;
    GLuint VAO = 0;

public:
    explicit Render(int width = 1366, int height = 768);
    std::shared_ptr<Image> loadImage(const std::string& imgPath);
    void drawImage(const std::shared_ptr<Image>& img, float x, float y, float width, float height);
    void clearFrame();
    void updateFrame();
    void close();
    void addKeyAction(Key, Action);
};


#endif //STREAMENGINE_RENDER_H

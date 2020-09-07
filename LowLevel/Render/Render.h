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
#include "GLWindow.h"
#include "Shader.h"

struct DrawCoords {
    float x0, y0, x1, y1;
};

class Render {
private:
    std::map<std::string, std::pair<std::shared_ptr<Image>, GLuint>> texIDs;
    std::unique_ptr<GLWindow> window;
    std::unique_ptr<Shader> shaderProg;
    std::vector<std::pair<GLuint, DrawCoords>> imagesToDraw;

    GLuint VBO = 0;
    GLuint VAO = 0;

    void drawAll();

public:
    Render();
    std::shared_ptr<Image> LoadImage(const std::string& imgPath);
    void DrawImage(const std::shared_ptr<Image>& img, float x, float y, float width, float height);
    void StartRender();
};


#endif //STREAMENGINE_RENDER_H

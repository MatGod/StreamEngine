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

class Render {
private:
    std::map<std::string, std::pair<std::shared_ptr<Image>, GLuint>> texIDs;
    GLWindow window;
public:
    Render();
    std::shared_ptr<Image> LoadImage(const std::string& imgPath);
    void DrawImage(const std::shared_ptr<Image>& img, int x, int y, int width, int height);
    void render();
};


#endif //STREAMENGINE_RENDER_H

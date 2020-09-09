//
// Created by matgod on 05.09.2020.
//

#include "Render.h"

#include <memory>
#include <utility>

Render::Render(int width, int height) {
    window = GLWindow::getWindow();
    shaderProg = std::make_unique<Shader>("Resource/Shaders/VertexShader.glsl",
                                          "Resource/Shaders/FragmentShader.glsl");
    glEnable(GL_BLEND);
    glBlendFunc(GL_SRC_ALPHA, GL_ONE_MINUS_SRC_ALPHA);

    glClearColor(1, 0, 0, 1);

    glGenVertexArrays(1, &VAO);
    glGenBuffers(1, &VBO);

    glBindVertexArray(VAO);
    glBindBuffer(GL_ARRAY_BUFFER, VBO);

    glVertexAttribPointer(0, 3, GL_FLOAT, GL_FALSE, 8 * sizeof(GLfloat), (GLvoid*) 0);
    glEnableVertexAttribArray(0);

    glVertexAttribPointer(1, 3, GL_FLOAT, GL_FALSE, 8 * sizeof(GLfloat), (GLvoid*) (3 * sizeof(GLfloat)));
    glEnableVertexAttribArray(1);

    glVertexAttribPointer(2, 2, GL_FLOAT, GL_FALSE, 8 * sizeof(GLfloat), (GLvoid*) (6 * sizeof(GLfloat)));
    glEnableVertexAttribArray(2);

    glBindBuffer(GL_ARRAY_BUFFER, 0);
    glBindVertexArray(0);

    shaderProg->use();
    glUniform2f(glGetUniformLocation(shaderProg->getProgram(), "windowSize"), window->getWidth(), window->getHeight());
}

std::shared_ptr<Image> Render::loadImage(const std::string &imgPath) {
    if (texIDs.find(imgPath) != texIDs.end() && !texIDs.empty()) {
        return texIDs[imgPath].first;
    }
    auto img = std::make_shared<Image>(imgPath);

    GLuint texID;
    glGenTextures(1, &texID);

    glBindTexture(GL_TEXTURE_2D, texID);
    glPixelStorei(GL_UNPACK_ALIGNMENT, 1);
    glTexImage2D(GL_TEXTURE_2D,
                 0,
                 GL_RGBA,
                 img->getWidth(),
                 img->getHeight(),
                 0,
                 GL_RGBA,
                 GL_UNSIGNED_BYTE,
                 img->getData());
    glTexParameteri(GL_TEXTURE_2D, GL_TEXTURE_MAG_FILTER, GL_NEAREST);
    glTexParameteri(GL_TEXTURE_2D, GL_TEXTURE_MIN_FILTER, GL_NEAREST);

    texIDs.insert(std::make_pair(imgPath, std::make_pair(img, texID)));

    glBindTexture(GL_TEXTURE_2D, 0);

    return img;
}

void Render::drawImage(const std::shared_ptr<Image> &img, float x, float y, float width, float height) {
    GLfloat coords[] = {
            // Позиции             // Цвета          // Текстурные координаты
            x + width, y + height, 0.0f, 0.0f, 0.0f, 0.0f, 1.0f, 0.0f,   // Верхний правый
            x + width, y,          0.0f, 0.0f, 0.0f, 0.0f, 1.0f, 1.0f,   // Нижний правый
            x,         y,          0.0f, 0.0f, 0.0f, 0.0f, 0.0f, 1.0f,   // Нижний левый
            x,         y + height, 0.0f, 0.0f, 0.0f, 0.0f, 0.0f, 0.0f    // Верхний левый
    };
    glBindVertexArray(VAO);
    glBindBuffer(GL_ARRAY_BUFFER, VBO);
    glBufferData(GL_ARRAY_BUFFER, sizeof(coords), coords, GL_STATIC_DRAW);
    glBindBuffer(GL_ARRAY_BUFFER, 0);

    glBindTexture(GL_TEXTURE_2D, texIDs[img->getPath()].second);
    glDrawArrays(GL_TRIANGLE_FAN, 0, 4);
    glBindVertexArray(0);
}

void Render::clearFrame() {
    glClear(GL_COLOR_BUFFER_BIT);
}

void Render::updateFrame() {
    window->update();
}

void Render::addKeyAction(Key key, Action action) {
    window->addKeyAction(key, std::move(action));
}

void Render::close() {
    window->close();
}

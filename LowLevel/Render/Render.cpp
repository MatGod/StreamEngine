//
// Created by matgod on 05.09.2020.
//

#include "Render.h"

#include <memory>

Render::Render(int width, int height) {
    window = std::make_unique<GLWindow>(width, height);
    shaderProg = std::make_unique<Shader>("LowLevel/Render/Shaders/VertexShader.glsl",
                                          "LowLevel/Render/Shaders/FragmentShader.glsl");

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

    shaderProg->Use();
    glUniform2f(glGetUniformLocation(shaderProg->GetProgram(), "windowSize"), window->getWidth(), window->getHeight());
}

std::shared_ptr<Image> Render::LoadImage(const std::string &imgPath) {
    if (texIDs.find(imgPath) != texIDs.end()) {
        return texIDs[imgPath].first;
    }
    auto img = std::make_shared<Image>(imgPath);

    GLuint texID;
    glGenTextures(1, &texID);

    glBindTexture(GL_TEXTURE_2D, texID);
    glPixelStorei(GL_UNPACK_ALIGNMENT, 1);
    glTexImage2D(GL_TEXTURE_2D,
                 0,
                 GL_RGB,
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

void Render::DrawImage(const std::shared_ptr<Image> &img, float x, float y, float width, float height) {
    DrawCoords coords = {x, y, x + width, y + height};
    imagesToDraw.emplace_back(texIDs[img->getPath()].second, coords);
}

void Render::StartRender() {
    window->execute([this]() {
        this->drawAll();
    });
}

void Render::drawAll() {
    for (auto img : imagesToDraw) {
        GLfloat coords[] = {
                // Позиции                            // Цвета            // Текстурные координаты
                img.second.x1, img.second.y1, 0.0f, 0.0f, 0.0f, 0.0f, 1.0f, 0.0f,   // Верхний правый
                img.second.x1, img.second.y0, 0.0f, 0.0f, 0.0f, 0.0f, 1.0f, 1.0f,   // Нижний правый
                img.second.x0, img.second.y0, 0.0f, 0.0f, 0.0f, 0.0f, 0.0f, 1.0f,   // Нижний левый
                img.second.x0, img.second.y1, 0.0f, 0.0f, 0.0f, 0.0f, 0.0f, 0.0f    // Верхний левый
        };
        glBindVertexArray(VAO);
        glBindBuffer(GL_ARRAY_BUFFER, VBO);
        glBufferData(GL_ARRAY_BUFFER, sizeof(coords), coords, GL_STATIC_DRAW);
        glBindBuffer(GL_ARRAY_BUFFER, 0);

        glBindTexture(GL_TEXTURE_2D, img.first);
        glDrawArrays(GL_TRIANGLE_FAN, 0, 4);
        glBindVertexArray(0);
    }
    imagesToDraw.clear();
}

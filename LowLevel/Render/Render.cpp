//
// Created by matgod on 05.09.2020.
//

#include "Render.h"

Render::Render() {
    glEnable(GL_TEXTURE_2D);
}

std::shared_ptr<Image> Render::LoadImage(const std::string &imgPath) {
    if (texIDs.find(imgPath) != texIDs.end()) {
        return texIDs[imgPath].first;
    }
    auto img = std::make_shared<Image>(Image(imgPath));

    GLuint texID;
    glGenTextures(1, &texID);

    glBindTexture(GL_TEXTURE_2D, texID);
    glPixelStorei( GL_UNPACK_ALIGNMENT, 1 );
    glTexImage2D(GL_TEXTURE_2D,
                 0,
                 GL_RGB,
                 img->getWidth(),
                 img->getHeight(),
                 0,
                 GL_RGB,
                 GL_UNSIGNED_BYTE,
                 img->getData().get_row(0).data());
    glTexParameteri(GL_TEXTURE_2D, GL_TEXTURE_MAG_FILTER, GL_NEAREST);
    glTexParameteri(GL_TEXTURE_2D, GL_TEXTURE_MIN_FILTER, GL_NEAREST);

    texIDs.insert(std::make_pair(imgPath, std::make_pair(img, texID)));

    return img;
}

void Render::DrawImage(const std::shared_ptr<Image> &img, int x, int y, int width, int height) {
    GLfloat vertices[] = {
            static_cast<GLfloat>(x), static_cast<GLfloat>(y), 0.0f,
            static_cast<GLfloat>(x), static_cast<GLfloat>(y + height), 0.0f,
            static_cast<GLfloat>(x + width), static_cast<GLfloat>(y + height), 0.0f,
            static_cast<GLfloat>(x + width), static_cast<GLfloat>(y), 0.0f
    };

    GLuint VBO, VAO;
    glGenBuffers(1, &VBO);
    glGenVertexArrays(1, &VAO);

    glBindVertexArray(VAO);
    glBindBuffer(GL_ARRAY_BUFFER, VBO);
    glBufferData(GL_ARRAY_BUFFER, sizeof(vertices), vertices, GL_STREAM_DRAW);

    GLint successCompile;
    std::string infoLog;
    infoLog.reserve(512);

    GLuint vertexShader = glCreateShader(GL_VERTEX_SHADER);
    glShaderSource(vertexShader, 1, reinterpret_cast<const GLchar *const *>("Shaders/VertexShader.glsl"), nullptr);
    glCompileShader(vertexShader);
    glGetShaderiv(vertexShader, GL_COMPILE_STATUS, &successCompile);
    if (!successCompile) {
        glGetShaderInfoLog(vertexShader, 512, nullptr, const_cast<GLchar *>(infoLog.data()));
        std::cout << "ERROR::SHADER::VERTEX::COMPILATION_FAILED\n" << infoLog << std::endl;
    }

    GLuint fragmentShader;
    fragmentShader = glCreateShader(GL_FRAGMENT_SHADER);
    glShaderSource(fragmentShader, 1, reinterpret_cast<const GLchar *const *>("Shaders/FragmentShader.glsl"), nullptr);
    glCompileShader(fragmentShader);
    glGetShaderiv(fragmentShader, GL_COMPILE_STATUS, &successCompile);
    if (!successCompile) {
        glGetShaderInfoLog(fragmentShader, 512, nullptr, const_cast<GLchar *>(infoLog.data()));
        std::cout << "ERROR::SHADER::FRAGMENT::COMPILATION_FAILED\n" << infoLog << std::endl;
    }

    GLuint shaderProgram = glCreateProgram();
    glAttachShader(shaderProgram, vertexShader);
    glAttachShader(shaderProgram, fragmentShader);
    glLinkProgram(shaderProgram);

    glUseProgram(shaderProgram);

    glDeleteShader(vertexShader);
    glDeleteShader(fragmentShader);

    glVertexAttribPointer(0, 3, GL_FLOAT, GL_FALSE, 3 * sizeof(GLfloat), nullptr);
    glEnableVertexAttribArray(0);
    glBindVertexArray(0);
}

void Render::render() {
    window.execute();
}

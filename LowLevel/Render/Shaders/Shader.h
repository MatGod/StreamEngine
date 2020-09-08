//
// Created by matgod on 17.07.2020.
//

#ifndef WINDOWDEFORMER_SHADER_H
#define WINDOWDEFORMER_SHADER_H


#include <GL/gl.h>
#include <string>
#include <fstream>
#include <sstream>
#include <iostream>

class Shader {
private:
    GLuint program;
public:
    Shader(const char*, const char*);
    void use() const;
    GLuint getProgram() const;
};


#endif //WINDOWDEFORMER_SHADER_H

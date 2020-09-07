#version 330 core

layout (location = 0) in vec3 position;
layout (location = 1) in vec3 color;
layout (location = 2) in vec2 texCoord;

out vec3 ourColor;
out vec2 TexCoord;

uniform vec2 windowSize;

void main() {
    gl_Position = vec4(position.x / windowSize.x * 2.f, position.y / windowSize.y * 2.f, position.z, 1.0f);
    ourColor = color;
    TexCoord = texCoord;
}
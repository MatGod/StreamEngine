#version 330

in vec3 ourColor;
in vec2 TexCoord;

out vec4 color;

uniform sampler2D ourTexture;

void main() {
    color = texture(ourTexture, TexCoord);
    //color = vec4(1, 0, 0, 1);
}

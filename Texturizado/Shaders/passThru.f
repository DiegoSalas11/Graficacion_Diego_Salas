#version 430 core

out vec4 fColor;
//in vec4 color;
in vec2 texturePos;
uniform sampler2D imgTextura;

void main()
{
    fColor =  texture(imgTextura,texturePos);
}

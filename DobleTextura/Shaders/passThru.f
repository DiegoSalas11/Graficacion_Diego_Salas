
#version 430 core

out vec4 fColor;
//in vec4 color;
in vec2 texturePos;

uniform sampler2D imgTextura;
uniform sampler2D imgTextura2;

vec4 gabriel;
vec4 mancera;


void main()
{

     gabriel =texture(imgTextura,texturePos);
	 mancera =texture(imgTextura2,texturePos);

    fColor =  mix(gabriel,mancera,0.5);
}
#version 430 core

layout (location = 0) in vec4 vPosition;
layout (location = 1) in vec2 vTexturePos;

uniform sampler2D imgTextura;
vec4 newVec;
uniform mat4 mTransform;
out vec2 texturePos;

float HeightMap(vec3 color)
{

return(0.40*color.r+ 0.51*color.g + 0.14*color.b);

}

void main()
{

	newVec=vPosition;
	
	newVec.y= 15.0*HeightMap(texture(imgTextura,vTexturePos).rgb);
	texturePos= vTexturePos;
	gl_Position = mTransform*newVec;

}

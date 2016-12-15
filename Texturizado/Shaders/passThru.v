#version 430 core

layout (location = 0) in vec4 vPosition;
layout (location = 1) in vec2 vTexturePos;
vec4 newVec;
uniform mat4 mTransform;
out vec2 texturePos;



void main()
{

	newVec=vPosition;
	texturePos= vTexturePos;
	//color = vec4(0.0, 0.0, 0.9, 1.0);

	gl_Position = mTransform*newVec;



}

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
	

	gl_Position = mTransform*newVec;



}

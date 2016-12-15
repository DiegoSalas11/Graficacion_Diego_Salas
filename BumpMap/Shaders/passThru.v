#version 430 core

layout (location = 0) in vec4 vPosition;
layout (location = 1) in vec2 vTexturePos;


uniform mat4 mTransform;
uniform vec3 LightPos;
out vec2 texturePos;
out vec3 light;
out vec4 newVec;

void main()
{

	newVec=vPosition;
	light=normalize(lightPos-vPosition);
	texturePos= vTexturePos;
	gl_Position = mTransform*newVec;

}

#version 430 core

layout (location = 0) in vec4 vPosition;
layout (location = 1) in vec2 vTexturePos;

out vec4 outPosition;
out vec2 outTexturePos;
out vec3 light;


uniform mat4 mTransform;
uniform vec3 myLightPosition;
uniform vec3 vEye;

void main()
{
	 outTexturePos=vTexturePos;
     outPosition= vPosition;
	 light=normalize(myLightPosition-outPosition.xyz);
	 vec4 vNewVec = vPosition;
	 gl_Position = mTransform * vNewVec;
}
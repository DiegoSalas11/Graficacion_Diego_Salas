#version 430 core
layout (location = 0) in vec4 vPosition;

uniform mat4 mTransform;
uniform float tiempo;
vec4 newVec;
out vec4 color;

void main()
{
	newVec=vPosition;

	color = vec4(0.0, 0.0, 0.9, 1.0);

	newVec.y=2*sin((tiempo*newVec.x*newVec.x+newVec.z*newVec.z*tiempo));
	

	gl_Position = mTransform*newVec;

}

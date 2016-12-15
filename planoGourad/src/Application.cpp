
#include "Application.h"
#include <iostream>
#include <vector>
#include "GL\glew.h"
#include <gl/GL.h>
#include <gl/GLU.h>
#include "glm/vec3.hpp"
//#include "GL/freeglut.h
#include "ShaderFuncs.h"

using namespace std;




Application::Application() :plane()
{

	
}

Application::~Application() 
{}

void Application::update()
{
	time = time + 0.005f;

}

void Application::setup()
{
	

	eye = glm::vec3(0.0f,70.0f,70.0f);
	target = glm::vec3(0, 0, 0);
	up = glm::vec3(0,1.0f,0);
	plane.createPlane(60);
	std::string strVertexShader = loadTextFile("Shaders/gouradPlane.v");
	std::string strFragmentShader   = loadTextFile("Shaders/passThru.f");
	
	InitializeProgram(plane.shader, strVertexShader,strFragmentShader);

	plane.uEye[0] = glGetUniformLocation(plane.shader, "vEye");
	plane.uTime[0] = glGetUniformLocation(plane.shader,"fTime");
	plane.uTransform[0] = glGetUniformLocation(plane.shader,"mTransform");

	//plane.uTransform[0] = glGetUniformLocation(plane.shader, "mTransform");

	
	//plane.uniform = glGetUniformLocation(plane.shader, "transform");


	//plane.numVertex = 36;

	glGenVertexArrays(1, &plane.vao);
	glBindVertexArray(plane.vao);
	glGenBuffers(1, &plane.vbo);
	glBindBuffer(GL_ARRAY_BUFFER, plane.vbo);

	glBufferData(GL_ARRAY_BUFFER, plane.getVertexSizeInBytes() + plane.getTextureCoordsSizeInBytes(), NULL, GL_STATIC_DRAW);
	glBufferSubData(GL_ARRAY_BUFFER, 0,plane.getVertexSizeInBytes(), plane.plane);
	glBufferSubData(GL_ARRAY_BUFFER, plane.getVertexSizeInBytes(), plane.getTextureCoordsSizeInBytes(),plane.textureCoords);
	plane.cleanMemory();

	glVertexAttribPointer(0, 4, GL_FLOAT, GL_FALSE, 0, 0);
	glVertexAttribPointer(1, 4, GL_FLOAT, GL_FALSE, 0, (void*)sizeof(GL_TRIANGLES, 0, plane.getNumVertex()));

	glEnableVertexAttribArray(0);
	glEnableVertexAttribArray(1);


}


void Application::display()
{
	
	glClearColor(0.0f, 0.0f, 0.0f, 0.0f);
	glClear(GL_COLOR_BUFFER_BIT|GL_DEPTH_BUFFER_BIT);
	glPolygonMode(GL_FRONT_AND_BACK,GL_LINE);
//	glPolygonMode(GL_FRONT_AND_BACK, GL_FILL);
	glUseProgram(plane.shader);
	glBindVertexArray(plane.vao);
	lookAt = glm::lookAt(eye, target, up);
	perspective = glm::perspective(80.0f/180.0f*3.1416f,800.0f/600.0f, 0.1f, 200.0f);
	Transform = perspective*lookAt;
	
	glUniform3fv(plane.uEye[0], 1, glm::value_ptr(eye));
	glUniform1f(plane.uTime[0],time);
	glUniformMatrix4fv(plane.uTransform[0], 1, GL_FALSE, glm::value_ptr(Transform));
	glDrawArrays(GL_TRIANGLES,0,plane.getNumVertex());
}

void Application::reshape(int w, int h)
{
	glViewport(0, 0, (GLsizei)w, (GLsizei)h);
}

void Application::keyboard(int key, int scanCode, int action, int mods)
{
	if (key == GLFW_KEY_ESCAPE && action == GLFW_PRESS)
	{
		exit(0);
	}
}



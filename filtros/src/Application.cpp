
#include "Application.h"
#include <iostream>
#include <vector>
#include "GL\glew.h"
#include <gl/GL.h>
#include <gl/GLU.h>
#include "glm/vec3.hpp"
//#include "GL/freeglut.h
#include "ShaderFuncs.h"
#include "SOIL.h" 
using namespace std;

void Application::initTexture()
{
	int x, y, n;
	//int force_channels = 4;
	unsigned char *image_data = SOIL_load_image("Lenna.png", &x, &y, &n, 0);
	//GLuint tex = 0;
	
	glGenTextures(1, &plane.texture_id[0]);//cuantas texturas
	glBindTexture(GL_TEXTURE_2D,plane.texture_id[0]);
	glActiveTexture(GL_TEXTURE0);

	glTexImage2D(GL_TEXTURE_2D, 0, GL_RGB, x, y, 0, GL_RGB, GL_UNSIGNED_BYTE, image_data);
	SOIL_free_image_data(image_data);


	glTexParameteri(GL_TEXTURE_2D, GL_TEXTURE_WRAP_S,GL_REPEAT);
	glTexParameteri(GL_TEXTURE_2D, GL_TEXTURE_WRAP_T, GL_REPEAT);

	glTexParameterf(GL_TEXTURE_2D, GL_TEXTURE_MAG_FILTER, GL_LINEAR);
	glTexParameterf(GL_TEXTURE_2D, GL_TEXTURE_MIN_FILTER, GL_LINEAR);
	glBindTexture(GL_TEXTURE_2D, 0);
	

}

void Application::initSecondTexture()
{

	int x, y, n;
	//int force_channels = 4;
	unsigned char *image_data = SOIL_load_image("HAG.png", &x, &y, &n, 0);
	//GLuint tex = 0;

	glGenTextures(1, &plane.texture_id[1]);//cuantas texturas
	glBindTexture(GL_TEXTURE_2D, plane.texture_id[1]);
	glActiveTexture(GL_TEXTURE0);

	glTexImage2D(GL_TEXTURE_2D, 0, GL_RGB, x, y, 0, GL_RGB, GL_UNSIGNED_BYTE, image_data);
	SOIL_free_image_data(image_data);


	glTexParameteri(GL_TEXTURE_2D, GL_TEXTURE_WRAP_S, GL_REPEAT);
	glTexParameteri(GL_TEXTURE_2D, GL_TEXTURE_WRAP_T, GL_REPEAT);

	glTexParameterf(GL_TEXTURE_2D, GL_TEXTURE_MAG_FILTER, GL_LINEAR);
	glTexParameterf(GL_TEXTURE_2D, GL_TEXTURE_MIN_FILTER, GL_LINEAR);
	glBindTexture(GL_TEXTURE_2D, 0);
}

Application::Application() :plane()
{

	
}

Application::~Application() 
{}

void Application::update()
{
	

}

void Application::setup()
{
	
	time = 0;
	eye = glm::vec3(0.0f,70.0f,70.0f);
	target = glm::vec3(0, 0, 0);
	up = glm::vec3(0,1.0f,0);
	plane.createPlane(1);

	std::string strVertexShader = loadTextFile("Shaders/passThru.v");
	std::string strFragmentShader = loadTextFile("Shaders/passThru.f");

	initTexture();
	initSecondTexture();

	InitializeProgram(plane.shader, strVertexShader,strFragmentShader);
	
	plane.uEye[0] = glGetUniformLocation(plane.shader, "vEye");
	plane.uTime[0] = glGetUniformLocation(plane.shader,"fTime");
	plane.uTransform[0] = glGetUniformLocation(plane.shader,"mTransform");

	plane.uTexture[0] = glGetUniformLocation(plane.shader, "imgTextura");
	plane.uTexture[1] = glGetUniformLocation(plane.shader, "imgTextura2");

	//plane.numVertex = 36;

	glGenVertexArrays(1, &plane.vao);
	glBindVertexArray(plane.vao);
	glGenBuffers(1, &plane.vbo);
	glBindBuffer(GL_ARRAY_BUFFER, plane.vbo);

	glBufferData(GL_ARRAY_BUFFER, plane.getVertexSizeInBytes() + plane.getTextureCoordsSizeInBytes(), NULL, GL_STATIC_DRAW);
	glBufferSubData(GL_ARRAY_BUFFER, 0,plane.getVertexSizeInBytes(), plane.plane);
	glBufferSubData(GL_ARRAY_BUFFER, plane.getVertexSizeInBytes(), plane.getTextureCoordsSizeInBytes(),plane.textureCoords);
	plane.cleanMemory();

	glVertexAttribPointer(0, 4, GL_FLOAT, GL_FALSE, 0, 0); // canal y numero de caoordenadas
	glVertexAttribPointer(1, 2, GL_FLOAT, GL_FALSE, 0, (void*)plane.getVertexSizeInBytes());

	glEnableVertexAttribArray(0);
	glEnableVertexAttribArray(1);

}


void Application::display()
{
	
	glClearColor(0.0f, 0.0f, 0.0f, 0.0f);
	glClear(GL_COLOR_BUFFER_BIT|GL_DEPTH_BUFFER_BIT);
	//glPolygonMode(GL_FRONT_AND_BACK,GL_LINE);
	glPolygonMode(GL_FRONT_AND_BACK, GL_FILL);
	glUseProgram(plane.shader);
	glBindVertexArray(plane.vao);

	lookAt = glm::lookAt(eye, target, up);
	perspective = glm::perspective(80.0f/180.0f*3.1416f,800.0f/600.0f, 0.1f, 200.0f);
	Transform = perspective*lookAt;
	

	glUniform3fv(plane.uEye[0], 1, glm::value_ptr(eye));
	glUniform1f(plane.uTime[0],time);
	glUniformMatrix4fv(plane.uTransform[0], 1, GL_FALSE, glm::value_ptr(Transform));

	glBindTexture(GL_TEXTURE_2D, plane.texture_id[0]);//------------
	glUniform1i(plane.uTexture[0], 0);
	glActiveTexture(GL_TEXTURE0);

	glBindTexture(GL_TEXTURE_2D, plane.texture_id[1]);
	glUniform1i(plane.uTexture[1], 1);
	glActiveTexture(GL_TEXTURE1);

	

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



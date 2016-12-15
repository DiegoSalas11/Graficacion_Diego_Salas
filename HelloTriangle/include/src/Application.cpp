
#include "Application.h"
#include <iostream>
#include <vector>

#include "GL\glew.h"
#include <gl/GL.h>
#include <gl/GLU.h>
#include "glm/vec3.hpp"


//#include "GL/freeglut.h"

#include "ShaderFuncs.h"

GLfloat vertexPositions[] = {
	

	/*0.75f, 0.75f,0.0f,1.0f,
	-0.75f,0.75f,0.0f,1.0f,
	-0.75f,-0.75f,0.0f,1.0f,
*/
	//0.75f, 0.75f, 0.0f, 1.0f,//a
	//0.75f, -0.75f, 0.0f, 1.0f,//b
 //  -0.75f, -0.75f, 0.0f, 1.0f,//c

   -0.75f, 0.75f, 0.75f, 1.0f,
   -0.75f,-0.75f, 0.75f, 1.0f,
   0.75f,  -0.75f, 0.75f, 1.0f,//t1

   -0.75f, 0.75f, 0.75f, 1.0f,      
    0.75f,-0.75f, 0.75f, 1.0f,
    0.75f,  0.75f, 0.75f, 1.0f,//t2

	0.75f, 0.75f, 0.75f, 1.0f,
	0.75f,-0.75f, 0.75f, 1.0f,
	0.75f, -0.75f, -0.75f, 1.0f,//t3

	0.75f, 0.75f, 0.75f, 1.0f,
	0.75f,-0.75f, -0.75f, 1.0f,
	0.75f, 0.75f, -0.75f, 1.0f,//t4

	0.75f, 0.75f, -0.75f, 1.0f,
	0.75f,-0.75f, -0.75f, 1.0f,
	-0.75f, -0.75f, -0.75f, 1.0f,//t5

	0.75f, 0.75f, -0.75f, 1.0f,
	-0.75f,-0.75f, -0.75f, 1.0f,
	-0.75f, 0.75f, -0.75f, 1.0f,//t6

	-0.75f, 0.75f, -0.75f, 1.0f,
	-0.75f,-0.75f, -0.75f, 1.0f,
	-0.75f, -0.75f, 0.75f, 1.0f,//t7

	-0.75f, 0.75f, -0.75f, 1.0f,
	-0.75f,-0.75f, 0.75f, 1.0f,
	-0.75f, 0.75f, 0.75f, 1.0f,//t8

	-0.75f, 0.75f, -0.75f, 1.0f,
	-0.75f, 0.75f, 0.75f, 1.0f,
	 0.75f, 0.75f, 0.75f, 1.0f,//t9

	 -0.75f, 0.75f, -0.75f, 1.0f,
	 0.75f, 0.75f, 0.75f, 1.0f,
	 0.75f, 0.75f, -0.75f, 1.0f,//t10


	 -0.75f, -0.75f, 0.75f, 1.0f,
	 -0.75f, -0.75f, -0.75f, 1.0f,
	 0.75f, -0.75f, -0.75f, 1.0f,//t11

	 -0.75f, -0.75f, 0.75f, 1.0f,
	 0.75f, -0.75f, -0.75f, 1.0f,
	 0.75f, -0.75f, 0.75f, 1.0f,//t12

};


GLfloat vertexColors[] = {


	1.0, 1.0, 1.0, 1.0,
	1.0, 1.0, 1.0, 1.0,
	1.0, 1.0, 1.0, 1.0,

	1.0, 1.0, 1.0, 1.0,
	1.0, 1.0, 1.0, 1.0,
	1.0, 1.0, 1.0, 1.0,// face 1


	1.0, 0.0, 0.0, 1.0,
	1.0, 0.0, 0.0, 1.0,
	1.0, 0.0, 0.0, 1.0,

	1.0, 0.0, 0.0, 1.0,
	1.0, 0.0, 0.0, 1.0,
	1.0, 0.0, 0.0, 1.0,// face 2

	0.0, 1.0, 0.0, 1.0,
	0.0, 1.0, 0.0, 1.0,
	0.0, 1.0, 0.0, 1.0,

	0.0, 1.0, 0.0, 1.0,
	0.0, 1.0, 0.0, 1.0,
	0.0, 1.0, 0.0, 1.0,// face 3

	0.0, 0.0, 1.0, 1.0,
	0.0, 0.0, 1.0, 1.0,
	0.0, 0.0, 1.0, 1.0,

	0.0, 0.0, 1.0, 1.0,
	0.0, 0.0, 1.0, 1.0,
	0.0, 0.0, 1.0, 1.0,// face 3

	1.0, 0.3, 1.0, 1.0,
	1.0, 0.3, 1.0, 1.0,
	1.0, 0.3, 1.0, 1.0,

	1.0, 0.3, 1.0, 1.0,
	1.0, 0.3, 1.0, 1.0,
	1.0, 0.3, 1.0, 1.0,// face 4


	1.0, 1.0, 0.0, 1.0,
	1.0, 1.0, 0.0, 1.0,
	1.0, 1.0, 0.0, 1.0,

	1.0, 1.0, 0.0, 1.0,
	1.0, 1.0, 0.0, 1.0,
	1.0, 1.0, 0.0, 1.0,// face 5

	1.0, 1.0, 0.0, 1.0,
	1.0, 0.0, 1.0, 1.0,
	1.0, 1.0, 0.0, 1.0,

	1.0, 1.0, 0.0, 1.0,
	1.0, 0.0, 1.0, 1.0,
	1.0, 1.0, 0.0, 1.0,// face 6

};



Application::Application() 
{}

Application::~Application() 
{}

void Application::update()
{
	
	triangle.fAngleX= triangle.fAngleX  + .0001;
	triangle.fAngleY = triangle.fAngleY + .0001;
	triangle.fAngleZ = triangle.fAngleZ + .0001;
	//------------

}

void Application::setup()
{
	


	eye = glm::vec3(0,15.0f,3.0f);
	target = glm::vec3(0, 0, 0);
	up = glm::vec3(0,1.0f,0);

	std::string strVertexShader = loadTextFile("Shaders/passThru.vs");
	std::string strFragmentShader = loadTextFile("Shaders/passThru.fs");
	InitializeProgram(triangle.shader, strVertexShader, strFragmentShader);
	triangle.fAngleX= 0.0;
	triangle.fAngleY = 0.0;
	triangle.fAngleZ = 0.0;

	
	triangle.uniform = glGetUniformLocation(triangle.shader, "transform");


	triangle.numVertex = 100;

	glGenVertexArrays(1, &triangle.vao);
	glBindVertexArray(triangle.vao);
	glGenBuffers(1, &triangle.vbo);
	glBindBuffer(GL_ARRAY_BUFFER, triangle.vbo);
	//glBufferData(GL_ARRAY_BUFFER, sizeof(vertexPositions), vertexPositions, GL_STATIC_DRAW);
	glBufferData(GL_ARRAY_BUFFER, sizeof(vertexPositions)+sizeof(vertexColors), NULL, GL_STATIC_DRAW);
	glBufferSubData(GL_ARRAY_BUFFER, 0/*offset*/, sizeof(vertexPositions), vertexPositions);
	glBufferSubData(GL_ARRAY_BUFFER, sizeof(vertexPositions), sizeof(vertexColors), vertexColors);

	glVertexAttribPointer(0, 4, GL_FLOAT, GL_FALSE, 0, 0);
	glVertexAttribPointer(1, 4, GL_FLOAT, GL_FALSE, 0, (void*)sizeof(vertexPositions));

	glEnableVertexAttribArray(0);
	glEnableVertexAttribArray(1);
}


void Application::display()
{
	//Borramos el buffer de color
	glClearColor(0.0f, 0.0f, 0.0f, 0.0f);
	glClear(GL_COLOR_BUFFER_BIT|GL_DEPTH_BUFFER_BIT);

	//Seleccionamos los shaders a usar
	//glUseProgram(triangle.shader);	
	
	//activamos el vertex array object y dibujamos
	//glBindVertexArray(triangle.vao);
	rotationZ = glm::rotate(glm::mat4(1.0f), triangle.fAngleZ, glm::vec3(0.0f, 0.0f, 1.0f));
	rotationX = glm::rotate(glm::mat4(1.0f),triangle.fAngleX,glm::vec3(1.0f,0.0f,0.0f));
	rotationY = glm::rotate(glm::mat4(1.0f), triangle.fAngleY, glm::vec3(0.0f, 1.0f, 0.0f));

	lookAt = glm::lookAt(eye, target, up);
	perspective = glm::perspective(80.0f/180.0f*3.1416f,800.0f/600.0f, 0.1f, 20.0f);

	
	//---------------

	//pasar avalores a variables uniform
	//glUniform1f(triangle.uniform,triangle.fAngle);
	//glUniformMatrix4fv(triangle.uniform,1,false,glm::value_ptr(Transform));
	glUseProgram(triangle.shader);
	glBindVertexArray(triangle.vao);

	for (int i = 0; i < 10; i++)
	{
		for (int j = 0; j < 10; j++)
		{
			if (mapa[i][j] == '1')
			{
				newPosition = glm::translate(glm::mat4(1.0f), glm::vec3(1.5f*i, 0.0f, 1.5f*j));
				Transform = perspective*lookAt*newPosition*rotationX*rotationY*rotationZ;
				// pasar al shader
				glUniformMatrix4fv(triangle.uniform, 1, GL_FALSE, glm::value_ptr(Transform));

				glDrawArrays(GL_TRIANGLES, 0, triangle.numVertex);
			}
			else
			{
				continue;
			}

		}
	}

	
	
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



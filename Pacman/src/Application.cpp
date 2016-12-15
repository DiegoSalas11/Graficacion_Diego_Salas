
#include "Application.h"
#include <iostream>
#include <vector>
#include "GL\glew.h"
#include <gl/GL.h>
#include <gl/GLU.h>
#include "glm/vec3.hpp"
#include "ShaderFuncs.h"
#define  PI 3.1416f


GLfloat vertexPositions[] = {
	

	//0.75f, 0.75f,0.0f,1.0f,
	//-0.75f,0.75f,0.0f,1.0f,
	//-0.75f,-0.75f,0.0f,1.0f,

	//0.75f, 0.75f, 0.0f, 1.0f,//a
	//0.75f, -0.75f, 0.0f, 1.0f,//b
 //  -0.75f, -0.75f, 0.0f, 1.0f,//c
   //------
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

	0.0, 0.0, 1.0, 1.0,
	0.0, 0.0, 1.0, 1.0,
	0.0, 0.0, 1.0, 1.0,

	0.0, 0.0, 1.0, 1.0,
	0.0, 0.0, 1.0, 1.0,
	0.0, 0.0, 1.0, 1.0,// face 1


	0.0, 0.0, 1.0, 1.0,
	0.0, 0.0, 1.0, 1.0,
	0.0, 0.0, 1.0, 1.0,

	0.0, 0.0, 1.0, 1.0,
	0.0, 0.0, 1.0, 1.0,
	0.0, 0.0, 1.0, 1.0,// face 2

	0.0, 0.0, 1.0, 1.0,
	0.0, 0.0, 1.0, 1.0,
	0.0, 0.0, 1.0, 1.0,

	0.0, 0.0, 1.0, 1.0,
	0.0, 0.0, 1.0, 1.0,
	0.0, 0.0, 1.0, 1.0,// face 3

	0.0, 0.0, 1.0, 1.0,
	0.0, 0.0, 1.0, 1.0,
	0.0, 0.0, 1.0, 1.0,

	0.0, 0.0, 1.0, 1.0,
	0.0, 0.0, 1.0, 1.0,
	0.0, 0.0, 1.0, 1.0,// face 3

	0.0, 0.0, 1.0, 1.0,
	0.0, 0.0, 1.0, 1.0,
	0.0, 0.0, 1.0, 1.0,

	0.0, 0.0, 1.0, 1.0,
	0.0, 0.0, 1.0, 1.0,
	0.0, 0.0, 1.0, 1.0,// face 4


	0.0, 0.0, 1.0, 1.0,
	0.0, 0.0, 1.0, 1.0,
	0.0, 0.0, 1.0, 1.0,

	0.0, 0.0, 1.0, 1.0,
	0.0, 0.0, 1.0, 1.0,
	0.0, 0.0, 1.0, 1.0,// face 5

	0.0, 0.0, 1.0, 1.0,
	0.0, 0.0, 1.0, 1.0,
	0.0, 0.0, 1.0, 1.0,

	0.0, 0.0, 1.0, 1.0,
	0.0, 0.0, 1.0, 1.0,
	0.0, 0.0, 1.0, 1.0,// face 6

};

GLfloat vertexPositionsPills[] = {

	-0.35f, 0.35f, 0.35f, 1.0f,
	-0.35f,-0.35f, 0.35f, 1.0f,
	0.35f,  -0.35f, 0.35f, 1.0f,//t1

	-0.35f, 0.35f, 0.35f, 1.0f,
	0.35f,-0.35f, 0.35f, 1.0f,
	0.35f,  0.35f, 0.35f, 1.0f,//t2

	0.35f, 0.35f, 0.35f, 1.0f,
	0.35f,-0.35f, 0.35f, 1.0f,
	0.35f, -0.35f, -0.35f, 1.0f,//t3

	0.35f, 0.35f, 0.35f, 1.0f,
	0.35f,-0.35f, -0.35f, 1.0f,
	0.35f, 0.35f, -0.35f, 1.0f,//t4

	0.35f, 0.35f, -0.35f, 1.0f,
	0.35f,-0.35f, -0.35f, 1.0f,
	-0.35f, -0.35f, -0.35f, 1.0f,//t5

	0.35f, 0.35f, -0.35f, 1.0f,
	-0.35f,-0.35f, -0.35f, 1.0f,
	-0.35f, 0.35f, -0.35f, 1.0f,//t6

	-0.35f, 0.35f, -0.35f, 1.0f,
	-0.35f,-0.35f, -0.35f, 1.0f,
	-0.35f, -0.35f, 0.35f, 1.0f,//t7

	-0.35f, 0.35f, -0.35f, 1.0f,
	-0.35f,-0.35f, 0.35f, 1.0f,
	-0.35f, 0.35f, 0.35f, 1.0f,//t8

	-0.35f, 0.35f, -0.35f, 1.0f,
	-0.35f, 0.35f, 0.35f, 1.0f,
	0.35f, 0.35f, 0.35f, 1.0f,//t9

	-0.35f, 0.35f, -0.35f, 1.0f,
	0.35f, 0.35f, 0.35f, 1.0f,
	0.35f, 0.35f, -0.35f, 1.0f,//t10


	-0.35f, -0.35f, 0.35f, 1.0f,
	-0.35f, -0.35f, -0.35f, 1.0f,
	0.35f, -0.35f, -0.35f, 1.0f,//t11

	-0.35f, -0.35f, 0.35f, 1.0f,
	0.35f, -0.35f, -0.35f, 1.0f,
	0.35f, -0.35f, 0.35f, 1.0f,//t12
	
};
GLfloat vertexColorsPills[] ={
	0.75, 1.0, 0.0, 1.0,
	0.75, 1.0, 0.0, 1.0,
	0.75, 1.0, 0.0, 1.0,

	0.75, 1.0, 0.0, 1.0,
	0.75, 1.0, 0.0, 1.0,
	0.75, 1.0, 0.0, 1.0,// face 1


	0.75, 1.0, 0.0, 1.0,
	0.75, 1.0, 0.0, 1.0,
	0.75, 1.0, 0.0, 1.0,

	0.75, 1.0, 0.0, 1.0,
	0.75, 1.0, 0.0, 1.0,
	0.75, 1.0, 0.0, 1.0,// face 2

	0.75, 1.0, 0.0, 1.0,
	0.75, 1.0, 0.0, 1.0,
	0.75, 1.0, 0.0, 1.0,

	0.75, 1.0, 0.0, 1.0,
	0.75, 1.0, 0.0, 1.0,
	0.75, 1.0, 0.0, 1.0,// face 3

	0.75, 1.0, 0.0, 1.0,
	0.75, 1.0, 0.0, 1.0,
	0.75, 1.0, 0.0, 1.0,

	0.75, 1.0, 0.0, 1.0,
	0.75, 1.0, 0.0, 1.0,
	0.75, 1.0, 0.0, 1.0,// face 3

	0.75, 1.0, 0.0, 1.0,
	0.75, 1.0, 0.0, 1.0,
	0.75, 1.0, 0.0, 1.0,

	0.75, 1.0, 0.0, 1.0,
	0.75, 1.0, 0.0, 1.0,
	0.75, 1.0, 0.0, 1.0,// face 4


	0.75, 1.0, 0.0, 1.0,
	0.75, 1.0, 0.0, 1.0,
	0.75, 1.0, 0.0, 1.0,

	0.75, 1.0, 0.0, 1.0,
	0.75, 1.0, 0.0, 1.0,
	0.75, 1.0, 0.0, 1.0,// face 5

	0.75, 1.0, 0.0, 1.0,
	0.75, 1.0, 0.0, 1.0,
	0.75, 1.0, 0.0, 1.0,

	0.75, 1.0, 0.0, 1.0,
	0.75, 1.0, 0.0, 1.0,
	0.75, 1.0, 0.0, 1.0,// face 6
};


Application::Application() 
{
	radius = 10.0f;
	angle = 270.0f;
	angleSum = 10.0f;
	posX = 0.0f;
	posY = 0.0f;
	columnaCol = 0;
	filaCol = 0;
	MarianaTorres = glm::vec3(0.0f,0.0f,0.0f);
}

Application::~Application() 
{}

void Application::update()
{
	triangle.fAngleX= triangle.fAngleX  + .0009;
	triangle.fAngleY = triangle.fAngleY + .0001;
	triangle.fAngleZ = triangle.fAngleZ + .0001;
	//------------
	pill.fAngleX = triangle.fAngleX + 1.0009;
	pill.fAngleY = triangle.fAngleY + .0001;
	pill.fAngleZ = triangle.fAngleZ + .0001;
	//mousePos(posX,posY);
	printf("CamPosX== %f CampPosZ== %f \n",eye.x,eye.z);
}

void Application::setup()
{

	switchView = false;
	eye = glm::vec3(1.0f,0.5f,1.5f);
	target = glm::vec3(1.0f, 0.5f, 2.5f);
	//target = eye + glm::vec3(1.0f,0.5f,-1.0f);
	up = glm::vec3(0, 1.0f, 0);
	eyeOrtho=glm::vec3(1.0f, 10.0f, 2.7f);
	

	rotateVec = target - eye;
	moveVec = target - eye;
	std::string strVertexShader = loadTextFile("Shaders/passThru.vs");
	std::string strFragmentShader = loadTextFile("Shaders/passThru.fs");

	//-------------------WALLS

	InitializeProgram(triangle.shader, strVertexShader, strFragmentShader);
	triangle.fAngleX = 0.0;
	triangle.fAngleY = 0.0;
	triangle.fAngleZ = 0.0;
	triangle.uniform = glGetUniformLocation(triangle.shader, "transform");
	
	triangle.numVertex = 36;
	glGenVertexArrays(1, &triangle.vao);
	glBindVertexArray(triangle.vao);
	glGenBuffers(1, &triangle.vbo);
	glBindBuffer(GL_ARRAY_BUFFER, triangle.vbo);

	glBufferData(GL_ARRAY_BUFFER, sizeof(vertexPositions) + sizeof(vertexColors), NULL, GL_STATIC_DRAW);
	glBufferSubData(GL_ARRAY_BUFFER, 0/*offset*/, sizeof(vertexPositions), vertexPositions);
	glBufferSubData(GL_ARRAY_BUFFER, sizeof(vertexPositions), sizeof(vertexColors), vertexColors);

	glVertexAttribPointer(0, 4, GL_FLOAT, GL_FALSE, 0, 0);
	glVertexAttribPointer(1, 4, GL_FLOAT, GL_FALSE, 0, (void*)sizeof(vertexPositions));

	glEnableVertexAttribArray(0);
	glEnableVertexAttribArray(1);

	//----------------END WALLS

	//----------------PILLSS
	InitializeProgram(pill.shader, strVertexShader, strFragmentShader);
	pill.fAngleX = 0.0;
	pill.fAngleY = 0.0;
	pill.fAngleZ = 0.0;
	pill.uniform = glGetUniformLocation(pill.shader, "transform");
	pill.numVertex = 36;

	glGenVertexArrays(1, &pill.vao);
	glBindVertexArray(pill.vao);
	glGenBuffers(1, &pill.vbo);

	glBindBuffer(GL_ARRAY_BUFFER, pill.vbo);
	glBufferData(GL_ARRAY_BUFFER, sizeof(vertexPositionsPills) + sizeof(vertexColorsPills), NULL, GL_STATIC_DRAW);
	glBufferSubData(GL_ARRAY_BUFFER, 0/*offset*/, sizeof(vertexPositionsPills), vertexPositionsPills);
	glBufferSubData(GL_ARRAY_BUFFER, sizeof(vertexPositionsPills), sizeof(vertexColorsPills), vertexColorsPills);

	glVertexAttribPointer(0, 4, GL_FLOAT, GL_FALSE, 0, 0);
	glVertexAttribPointer(1, 4, GL_FLOAT, GL_FALSE, 0, (void*)sizeof(vertexPositionsPills));
	
	glEnableVertexAttribArray(0);
	glEnableVertexAttribArray(1);
	
	//------------------------END PILLS
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
	
	lookAt = glm::lookAt(eye, target, up);
	perspective = glm::perspective(80.0f/180.0f*3.1416f,800.0f/600.0f, 0.1f, 20.0f);
	
	glUseProgram(triangle.shader);
	glBindVertexArray(triangle.vao);

	for (int i = 0; i < 10; i++)
	{
		for (int j = 0; j < 10; j++)
		{
			if (mapa[i][j] == '1')
			{
			
				newPosition = glm::translate(glm::mat4(1.0f), glm::vec3(1.5f*i, 0.0f, 1.5f*j));
				Transform = perspective*lookAt*newPosition;
				//Transform = ortho*lookAt*newPosition;

				//pasar al shader
				glUniformMatrix4fv(triangle.uniform, 1, GL_FALSE, glm::value_ptr(Transform));

				glDrawArrays(GL_TRIANGLES, 0, triangle.numVertex);
			}
		
		}
	}

	
	
}
void Application::displayPills()
{

	rotationZ = glm::rotate(glm::mat4(1.0f), triangle.fAngleZ, glm::vec3(0.0f, 0.0f, 1.0f));
	rotationX = glm::rotate(glm::mat4(1.0f), triangle.fAngleX, glm::vec3(1.0f, 0.0f, 0.0f));
	rotationY = glm::rotate(glm::mat4(1.0f), triangle.fAngleY, glm::vec3(0.0f, 1.0f, 0.0f));

	glUseProgram(pill.shader);
	glBindVertexArray(pill.vao);
	for (int i = 0; i < 10; i++)
	{
		for (int j = 0; j < 10; j++)
		{

			if (mapa[i][j] == '2')
			{
			
				newPosition = glm::translate(glm::mat4(1.0f), glm::vec3(1.5f*i, 0.0f, 1.5f*j));
				//Transform = ortho*lookAt*newPosition;
				Transform = perspective*lookAt*newPosition*rotationX*rotationY*rotationZ;
				// pasar al shader
				glUniformMatrix4fv(pill.uniform, 1, GL_FALSE, glm::value_ptr(Transform));
				glDrawArrays(GL_TRIANGLES, 0, pill.numVertex);

			}
		}
	}
}

void Application::displayOrtho()
{

	//Borramos el buffer de color
	glClearColor(0.0f, 0.0f, 0.0f, 0.0f);
	glClear(GL_COLOR_BUFFER_BIT | GL_DEPTH_BUFFER_BIT);

	//Seleccionamos los shaders a usar
	//glUseProgram(triangle.shader);	

	//activamos el vertex array object y dibujamos
	//glBindVertexArray(triangle.vao);

	lookAt = glm::lookAt(eyeOrtho, target, up);
	perspective = glm::perspective(80.0f / 180.0f*3.1416f, 800.0f / 600.0f, 0.1f, 20.0f);
	ortho = glm::ortho(-0.75f, 14.0f,14.0f,-0.75f);
	glUseProgram(triangle.shader);
	glBindVertexArray(triangle.vao);

	for (int i = 0; i < 10; i++)
	{
		for (int j = 0; j < 10; j++)
		{
			if (mapa[i][j] == '1')
			{

				newPosition = glm::translate(glm::mat4(1.0f), glm::vec3(1.5f*i, 1.5f*j, 0.0f));
				Transform = ortho*newPosition;
				//Transform = ortho*lookAt*newPosition;

				//pasar al shader
				glUniformMatrix4fv(triangle.uniform, 1, GL_FALSE, glm::value_ptr(Transform));

				glDrawArrays(GL_TRIANGLES, 0, triangle.numVertex);
			}

		}
	}
}

void Application::displayOrthoPills()
{
	rotationZ = glm::rotate(glm::mat4(1.0f), triangle.fAngleZ, glm::vec3(0.0f, 0.0f, 1.0f));
	rotationX = glm::rotate(glm::mat4(1.0f), triangle.fAngleX, glm::vec3(1.0f, 0.0f, 0.0f));
	rotationY = glm::rotate(glm::mat4(1.0f), triangle.fAngleY, glm::vec3(0.0f, 1.0f, 0.0f));

	glUseProgram(pill.shader);
	glBindVertexArray(pill.vao);
	for (int i = 0; i < 10; i++)
	{
		for (int j = 0; j < 10; j++)
		{

			if (mapa[i][j] == '2')
			{

				newPosition = glm::translate(glm::mat4(1.0f), glm::vec3(1.5f*i, 1.5f*j, 0.0f));
				//Transform = ortho*lookAt*newPosition;
				Transform = ortho*newPosition*rotationX*rotationY*rotationZ;
				// pasar al shader
				glUniformMatrix4fv(pill.uniform, 1, GL_FALSE, glm::value_ptr(Transform));
				glDrawArrays(GL_TRIANGLES, 0, pill.numVertex);

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
	//SWITCHCAM
	if (key == GLFW_KEY_2)
	{
		switchView = false;
	}
	if (key == GLFW_KEY_1)
	{
		switchView = true;
	}
	//ADELANTE
	if (key == GLFW_KEY_UP)
	{
		
			target = target + moveVec*0.1f;
			eye = eye + moveVec*0.1f;
	}
	//IZQUIERDA
	if (key == GLFW_KEY_LEFT)
	{

		angle = angle - angleSum;

		rotateVec.x = 0.1f*radius*cos(angle/180.0f*PI);
		rotateVec.z = 0.1f*radius*sin(angle/180.0f*PI);

		target = rotateVec + eye;
		moveVec = target - eye;
	
	}
	//DERECHA
	if (key == GLFW_KEY_RIGHT)
	{
		angle = angle + angleSum;

		rotateVec.x = 0.1f*radius*cos(angle / 180.0f*PI);
		rotateVec.z = 0.1f*radius*sin(angle / 180.0f*PI);
		target = rotateVec + eye;
		moveVec = target - eye;
	}

	if (key == GLFW_KEY_ESCAPE && action == GLFW_PRESS)
	{
		exit(0);
	}
}

void Application::mousePos(double  xpos, double  ypos)
{
	posX = xpos;
	posY = ypos;
}

void Application::mouseButton(int button,int action)
{
	int columna=0, fila=0;
	if(action==GLFW_PRESS)
	{
		printf("X==%f  Y==%f\n", posX, posY);
		//float posBackX, posBackY;
	
		posBackX = 0;
		posBackY = 0;
		//------------------------------------------------------------X
		for (int posTempX = 64; posTempX < 641; posTempX += 64)
		{
			posBackX = posTempX - 64;
			if (posX>=posBackX && posX<posTempX)
			{
				printf("columna== %d\n", columna);
				break;
			}
			else
			{
				columna++;
			}
			//---------------------------------------------Y
		}
		for (int posTempY = 48; posTempY < 481; posTempY += 48)
		{
			posBackY = posTempY - 48;
			if (posY>=posBackY && posY<posTempY)
			{
				printf("fila== %d\n", fila);
				break;
			}
			else
			{
				fila++;
			}
		}				
	}
						if (button == GLFW_MOUSE_BUTTON_LEFT && GLFW_PRESS)
						{
							mapa[columna][fila] = '0';
						}
							if (button == GLFW_MOUSE_BUTTON_RIGHT)
							{
								mapa[columna][fila] = '1';
							}
								if (button == GLFW_MOUSE_BUTTON_MIDDLE)
								{
									mapa[columna][fila] = '2';
								}
	}

void Application::checkCollision()
{
	columnaCol = 0;

	filaCol = 0;
	posColX = eye.x;
	posColZ = eye.z;

	

	//------------------------------------------------------------X
	for (float posTempX1 = 0.75f; posTempX1 < 14.25f; posTempX1 += 1.5f)
	{
		posBackColX = posTempX1 -1.5f;

		if (posColX >= posBackColX && posColX<posTempX1)
		{
			printf("columnaCOL== %d\n", columnaCol);
			break;
		}
		else
		{
			columnaCol++;
		}
		//---------------------------------------------Z
	}
	for (float posTempZ1 = 0.75f; posTempZ1 < 14.25f ; posTempZ1 += 1.5f)
	{
		posBackColZ = posTempZ1 - 1.5f;
		if (posColZ >= posBackColZ && posColZ<posTempZ1)
		{
			printf("fila== %d\n", filaCol);
			break;
		}
		else
		{
			filaCol++;
		}
	}
	if (mapa[columnaCol][filaCol]=='1')
	{
		printf("COLLISIOOOON PAREEED");
		eye = MarianaTorres;
		return;
	}
	if (mapa[columnaCol][filaCol] == '2')
	{
		printf("COLLISIOOOON PASTILLA");
		mapa[columnaCol][filaCol]='0';
	}
	MarianaTorres.x = eye.x;
	MarianaTorres.y = eye.y;
	MarianaTorres.z = eye.z;
}

		

		




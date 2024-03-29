
#include <string>
#include <vector>
#include <stdio.h>
#include <iostream>
#include "GL/glew.h"
#include "GLFW/glfw3.h"
#include "Application.h"

Application app;

//Se tiene que llamar despues de inicializar la ventana y el OpenGL, pero antes del main loop
void setup()
{
	app.setup();
}

//Se ejecuta siempre que se necesite actualizar la imagen
void display()
{
	if(app.switchView == true)
	{
		app.display();
		app.displayPills();
	}
	if (app.switchView == false)
	{
		app.displayOrtho();
		app.displayOrthoPills();
	}
	app.checkCollision();
}

//Se ejecuta cuando la ventana cambia de tama�o. Par�metros en pixeles.
//(ojo: En otros programas se debe ejecutar glViewport)
void reshape(int w, int h)
{
	app.reshape(w, h);
}
void keyboard(GLFWwindow* window, int key, int scancode, int action, int mods)
{
	app.keyboard(key,scancode,action,mods);
}

void GetMouseButton(GLFWwindow *window, int button, int action, int mods)
{
	app.mouseButton(button,action);
}
void GetCursorPos(GLFWwindow *window, double xpos, double ypos)
{
	app.mousePos(xpos,ypos);
}
int main(int argc, char *argv[])
{
	GLFWwindow* window;

	/* Initialize the library */
	if (!glfwInit())
		return -1;

	/* Create a windowed mode window and its OpenGL context */
	window = glfwCreateWindow(640, 480, "Hello World", NULL, NULL);
	if (!window)
	{
		glfwTerminate();
		return -1;
	}

	/* Make the window's context current */
	glfwMakeContextCurrent(window);

	glewExperimental = GL_TRUE; 
	glewInit();
	app.setup();

	// get version info 
	const GLubyte* renderer = glGetString (GL_RENDERER); 
	const GLubyte* version = glGetString (GL_VERSION); 
	printf (" Renderer: %s\ n", renderer); 
	printf (" OpenGL version supported %s\ n", version); 
	
	// tell GL to only draw onto a pixel if the shape is closer to the viewer 
	//glEnable (GL_DEPTH_TEST); // enable depth-testing 	
	//glDepthFunc (GL_LESS); // depth-testing interprets a smaller value as "closer" 

	glViewport(0, 0, (GLsizei)640, (GLsizei)480);
	glEnable(GL_DEPTH_TEST);

	glfwSetKeyCallback(window, keyboard);

	glfwSetMouseButtonCallback(window, GetMouseButton);

	glfwSetCursorPosCallback(window, GetCursorPos);


	while (!glfwWindowShouldClose(window))
	{

		/* update other events like input handling */
		glfwPollEvents();

		//update application
		app.update();
		/* put the stuff we've been drawing onto the display */
		display();
		
		glfwSwapBuffers(window);
	}
	
	/* close GL context and any other GLFW resources */
	glfwTerminate();
	return 0;

}

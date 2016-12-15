#pragma once

#include <iostream>
#include "Object3D.h"
#include "glm/mat4x4.hpp"
#include "glm/vec4.hpp"
#include  "glm/gtc/matrix_transform.hpp"
#include "glm/gtc/type_ptr.hpp"
#include "GLFW\glfw3.h"
#include "plane.h"

class Application {
public:
	GLFWwindow* window;
	void initTexture();
	void initSecondTexture();
	Application();
	~Application();
	void update();
	void setup();
	void display();
	void reshape(int w, int h);
	void keyboard(int key, int scanCode, int action, int mods);
	float time;


private:	
	Plane plane;

	glm::mat4 Transform;
	//--------------------------rotation
	glm::mat4 rotationX;
	glm::mat4 rotationY;
	glm::mat4 rotationZ;
	//-------------------------lookat
	glm::mat4 lookAt;
	glm::vec3 target;
	glm::vec3 eye;
	glm::vec3 up;
	//-------------------------perspectiva
	glm::mat4 perspective;
	//-------------------------translate
	glm::mat4 newPosition;
};


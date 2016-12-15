#pragma once

#include <iostream>
#include "Object3D.h"
#include "glm/mat4x4.hpp"
#include "glm/vec4.hpp"
#include  "glm/gtc/matrix_transform.hpp"
#include "glm/gtc/type_ptr.hpp"

class Application {
public:
	Application();
	~Application();
	void update();
	void setup();
	void display();
	void reshape(int w, int h);


private:	
	Object3D triangle;
	//--------------------------rotation
	glm::mat4 rotationX;
	glm::mat4 rotationY;
	glm::mat4 rotationZ;
	glm::mat4 rotationMult;
	//-------------------------lookat
	glm::mat4 lookAt;
	glm::vec3 target;
	glm::vec3 eye;
	glm::vec3 up;
	//-------------------------perspectiva
	glm::mat4 perspective;
};


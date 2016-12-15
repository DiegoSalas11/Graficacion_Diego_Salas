#pragma once

#include <iostream>
#include "Object3D.h"
#include "glm/mat4x4.hpp"
#include "glm/vec4.hpp"
#include  "glm/gtc/matrix_transform.hpp"
#include "glm/gtc/type_ptr.hpp"
#include "GLFW\glfw3.h"


class Application {
public:
	bool switchView;
	Application();
	~Application();
	double posX;
	double posY;
	float posBackX, posBackY;
	float posBackColX, posBackColZ;
	int columnaCol, filaCol;
	float posColZ, posColX;
	void update();
	void setup();
	void display();
	void displayPills();
	void displayOrtho();
	void displayOrthoPills();
	void reshape(int w, int h);
	void keyboard(int key, int scanCode, int action, int mods);
	void mousePos(double xpos, double ypos);
	void mouseButton(int button,int action);
	void checkCollision();

	char mapa[10][10] = {	
		'2','1','1','1','1','1','1','1','1','1',
		'2','2','2','2','2','2','2','2','2','1',
		'2','2','1','1','2','2','1','1','2','1',
		'2','2','1','0','0','0','0','1','2','1',
		'1','2','0','0','1','1','0','2','2','1',
		'1','2','2','2','1','1','0','2','2','1',
		'1','2','0','0','0','0','0','1','2','1',
		'1','2','1','1','2','2','1','1','2','1',
		'1','2','2','2','2','2','2','2','2','1',
		'1','1','1','1','1','1','1','1','1','1'
	};

private:	
	Object3D triangle;
	Object3D pill;
	glm::mat4 Transform;
	
	//--------------------------rotation
	glm::mat4 rotationX;
	glm::mat4 rotationY;
	glm::mat4 rotationZ;
	//-------------------------lookat
	glm::mat4 lookAt;
	glm::vec3 target;
	glm::vec3 eye;
	glm::vec3 eyeOrtho;
	glm::vec3 targetOrtho;
	glm::vec3 up;
	//-------------------------MOVEMENT
	glm::vec3 rotateVec;
	glm::vec3 moveVec;
	glm::vec3 MarianaTorres;
	float radius;
	float angleSum;
	float angle;
	
	
	//-------------------------perspectiva
	glm::mat4 perspective;
	glm::mat4 ortho;
	glm::mat4 rotateView;
	//-------------------------translate
	glm::mat4 newPosition;
};


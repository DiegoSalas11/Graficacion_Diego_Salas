	#version 430 core

	out vec4 fragmentColor;
	in vec4 color;
	void main()
	{
	    fragmentColor = vec4(color);
	}
#pragma once
#include <GLFW/include/glfw3.h>

class Input
{
public:
	Input();
	~Input();

	void SetCallback(GLFWwindow* window, GLFWkeyfun callbackFunction);
};


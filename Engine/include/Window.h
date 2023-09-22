#pragma once
#include <GLFW/include/glfw3.h>

class Window
{
public:
	Window();
	~Window();
public:
	void InitWindow();
	void CreateWindow(int width, int height, const char* title);

	GLFWwindow* GlfwWindow = nullptr;
};


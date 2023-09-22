#include <Window.h>
#include <GLFW/include/glfw3.h>
#include <iostream>

Window::Window()
{
}

Window::~Window()
{
}

void Window::InitWindow()
{
	glfwInit();
	glfwWindowHint(GLFW_CONTEXT_VERSION_MAJOR, 3);
	glfwWindowHint(GLFW_CONTEXT_VERSION_MINOR, 3);
	glfwWindowHint(GLFW_OPENGL_PROFILE, GLFW_OPENGL_CORE_PROFILE);
	std::cout << "GLFW init succesfull" << '\n';
}

void Window::CreateWindow(int width, int height, const char* title)
{
	GlfwWindow = glfwCreateWindow(width, height, title, NULL, NULL);
	if (GlfwWindow == NULL)
	{
		std::cout << "Failed to create GLFW window" << '\n';
		glfwTerminate();
		return;
	}

	glfwMakeContextCurrent(GlfwWindow);
	std::cout << "Created new window and set current GLFW context" << '\n';
}



#include <Window.h>
#include <GLFW/include/glfw3.h>
#include <iostream>

void framebuffer_size_callback(GLFWwindow* window, int width, int height);

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
	glfwSetFramebufferSizeCallback(GlfwWindow, framebuffer_size_callback);
}

void framebuffer_size_callback(GLFWwindow* window, int width, int height)
{
	std::cout << "Resized window" << '\n';
	glViewport(0, 0, width, height);
}



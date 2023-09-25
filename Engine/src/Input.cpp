#include <Input.h>

#include <GLFW/include/glfw3.h>

Input::Input()
{
}

Input::~Input()
{
}

void Input::SetCallback(GLFWwindow* window, GLFWkeyfun callbackFunction)
{
	glfwSetKeyCallback(window, callbackFunction);
}

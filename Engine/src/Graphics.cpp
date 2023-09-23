#include <Graphics.h>
#include <glad/glad.h>
#include <GLFW/include/glfw3.h>
#include <iostream>

Graphics::Graphics()
{
}

Graphics::~Graphics()
{
}

void Graphics::InitGraphics()
{
	if (!gladLoadGLLoader((GLADloadproc)glfwGetProcAddress))
	{
		std::cout << "Failed to initialize GLAD" << std::endl;
		return;
	}
	
	glViewport(0, 0, 800, 600);
}

void Graphics::SetOrthographicProjection(float left, float right, float bottom, float top, float near, float far)
{
	// orthographic projcetion https://en.wikipedia.org/wiki/Orthographic_projection
	float mat[4][4] = {
		{2.0f / (right - left), 0.0f, 0.0f, 0.0f},
		{0.0f, 2.0f / (top - bottom), 0.0f, 0.0f},
		{0.0f, 0.0f, -2.0f / (far - near), 0.0f},
		{-(right + left) / (right - left), -(top + bottom) / (top - bottom), -(far + near) / (far - near), 1.0f}
	};

	glUniformMatrix4fv(glGetUniformLocation(NULL, "projection"), 1, GL_FALSE, &mat[0][0]);
}

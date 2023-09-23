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
	
	//glViewport(0, 0, 1024, 512);
}

void Graphics::SetOrthographicProjection(unsigned int shaderProgram ,float left, float right, float bottom, float top, float nearr, float farr)
{
	// orthographic projcetion https://en.wikipedia.org/wiki/Orthographic_projection
	float mat[4][4] = {
		{2.0f / (right - left), 0.0f, 0.0f, 0.0f},
		{0.0f, 2.0f / (top - bottom), 0.0f, 0.0f},
		{0.0f, 0.0f, -2.0f / (farr - nearr), 0.0f},
		{-(right + left) / (right - left), -(top + bottom) / (top - bottom), -(farr + nearr) / (farr - nearr), 1.0f}
	};

	glUniformMatrix4fv(glGetUniformLocation(shaderProgram, "projection"), 1, GL_FALSE, &mat[0][0]);
}

#include <Graphics.h>
#include <glad/glad.h>
#include <glad/glad_wgl.h>
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


	// define the function's prototype
	typedef void (*GL_GENBUFFERS) (GLsizei, GLuint*);
	// find the function and assign it to a function pointer
	GL_GENBUFFERS glGenBuffers = (GL_GENBUFFERS)wglGetProcAddress("glGenBuffers");
	// function can now be called as normal
	unsigned int buffer;
	glGenBuffers(1, &buffer);
	
	glViewport(0, 0, 800, 600);
}

void Graphics::SetOrthographicProjection(float left, float right, float bottom, float top, float nearr, float farr)
{
	// orthographic projcetion https://en.wikipedia.org/wiki/Orthographic_projection
	float mat[4][4] = {
		{2.0f / (right - left), 0.0f, 0.0f, 0.0f},
		{0.0f, 2.0f / (top - bottom), 0.0f, 0.0f},
		{0.0f, 0.0f, -2.0f / (farr - nearr), 0.0f},
		{-(right + left) / (right - left), -(top + bottom) / (top - bottom), -(farr + nearr) / (farr - nearr), 1.0f}
	};

	glUniformMatrix4fv(glGetUniformLocation(NULL, "projection"), 1, GL_FALSE, &mat[0][0]);
}

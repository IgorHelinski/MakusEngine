#include <MakusEngine.h>
#include <glad/glad.h>
#include <GLFW/include/glfw3.h>
#include <Window.h>
#include <Graphics.h>
#include <iostream>

MakusEngine::MakusEngine()
{
}

MakusEngine::~MakusEngine()
{
}

void MakusEngine::StartMakus()
{
	Window window;
	window.InitWindow();
	window.CreateWindow(800, 600, "Makus Engine dev build");

	Graphics graphics;
	graphics.InitGraphics();

	graphics.SetOrthographicProjection(0, 800, 0, 600, 0.0f, 1.0f);

	OnCreate();

	while (!glfwWindowShouldClose(window.GlfwWindow))
	{
		OnUpdate();

		// this at the end
		glfwSwapBuffers(window.GlfwWindow);
		glfwPollEvents();
	}

	OnQuit();
}

void MakusEngine::OnCreate()
{
	HelloWorld();
}

void MakusEngine::OnUpdate()
{
	glClearColor(0.2f, 0.3f, 0.3f, 1.0f);
	glClear(GL_COLOR_BUFFER_BIT);

	float playerX = 10;
	float playerY = 10;

	glColor3f(1, 1, 0);
	glPointSize(8);
	glBegin(GL_POINTS);
	glVertex2i((GLint)playerX, (GLint)playerY);
	glEnd();

	playerX = 200;
	playerY = 200;
}

void MakusEngine::OnQuit()
{
	glfwTerminate();
}

void MakusEngine::HelloWorld()
{
	std::cout << "HelloWorld" << '\n';
}



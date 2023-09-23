#include <MakusEngine.h>
#include <glad/glad.h>
#include <GLFW/include/glfw3.h>
#include <Window.h>
#include <Graphics.h>
#include <iostream>

GLfloat pointVertex[] = { 1024 / 2, 512 / 2 };
float playerX;
float playerY;

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
	window.CreateWindow(1024, 512, "Makus Engine dev build");

	Graphics graphics;
	graphics.InitGraphics();
	//graphics.SetOrthographicProjection(0, 1024, 0, 512, 0.0f, 1.0f);

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

	glMatrixMode(GL_PROJECTION);
	glLoadIdentity();
	glOrtho(0, 1024, 0, 768, 0, 1);
	glMatrixMode(GL_MODELVIEW);
	glLoadIdentity();

	//glClearColor(0.2f, 0.3f, 0.3f, 1.0f);

	playerX = 300;
	playerY = 300;
}

void MakusEngine::OnUpdate()
{
	glClear(GL_COLOR_BUFFER_BIT | GL_DEPTH_BUFFER_BIT);

	glEnableClientState(GL_VERTEX_ARRAY);
	glPointSize(50);
	glVertexPointer(2, GL_FLOAT, 0, pointVertex);
	glDrawArrays(GL_POINT, 0, 1);
	glDisableClientState(GL_VERTEX_ARRAY);

}

void MakusEngine::OnQuit()
{
	glfwTerminate();
}

void MakusEngine::HelloWorld()
{
	std::cout << "HelloWorld" << '\n';
}



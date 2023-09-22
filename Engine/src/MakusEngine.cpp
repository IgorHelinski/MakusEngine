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
}

void MakusEngine::OnQuit()
{
	glfwTerminate();
}

void MakusEngine::HelloWorld()
{
	std::cout << "HelloWorld" << '\n';
}

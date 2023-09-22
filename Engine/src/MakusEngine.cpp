#include <MakusEngine.h>
#include <Window.h>
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

	OnCreate();

	while (!glfwWindowShouldClose(window.GlfwWindow))
	{
		OnUpdate();

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
	
}

void MakusEngine::OnQuit()
{
	glfwTerminate();
}

void MakusEngine::HelloWorld()
{
	std::cout << "HelloWorld" << '\n';
}

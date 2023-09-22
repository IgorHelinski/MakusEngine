#include <MakusEngine.h>
#include <glad/glad.h>
#include <GLFW/include/glfw3.h>
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

	if (!gladLoadGLLoader((GLADloadproc)glfwGetProcAddress))
	{
		std::cout << "Failed to initialize GLAD" << std::endl;
		return;
	}

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
	
}

void MakusEngine::OnQuit()
{
	glfwTerminate();
}

void MakusEngine::HelloWorld()
{
	std::cout << "HelloWorld" << '\n';
}

#include <glad/glad.h>
#include <GLFW/include/glfw3.h>

#include <MakusEngine.h>
#include <Window.h>
#include <Graphics.h>
#include <Input.h>

#include <iostream>
#include <math.h>
#define PI 3.1415926535

float px, py; // player position
int pDirX = 0, pDirY = 1;

float pSpeed = 10;

long time1, time2, dt;

void OnInput(GLFWwindow* window, int key, int scancode, int action, int mods);

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
	window.CreateWindow(windowWidth, windowHeight, "Makus Engine | Snake");

	Input input;
	input.SetCallback(window.GlfwWindow, OnInput);
	
	Graphics graphics;
	graphics.InitGraphics();

	std::cout << "OpenGL version - " << glGetString(GL_VERSION) << std::endl;

	OnCreate();

	while (!glfwWindowShouldClose(window.GlfwWindow))
	{
		OnUpdate();

		/* Swap front and back buffers */
		glfwSwapBuffers(window.GlfwWindow);
		/* Poll for and process events */
		glfwPollEvents();
	}

	glfwDestroyWindow(window.GlfwWindow);
	OnQuit();
}

void MakusEngine::OnCreate()
{
	px = 300;
	py = 300;
}

void MakusEngine::OnUpdate()
{
	glClear(GL_COLOR_BUFFER_BIT | GL_DEPTH_BUFFER_BIT);

	glClearColor(0.3, 0.3, 0.3, 0);

	glMatrixMode(GL_PROJECTION);
	glLoadIdentity();
	glOrtho(0, windowWidth, windowHeight, 0, 0, 1);

	//DrawMap2D();

	time1 = glfwGetTime();
	dt = time1 - time2;
	time2 = time1;

	px += (pDirX * pSpeed * dt);
	py += (pDirY * pSpeed * dt);

	// draw player
	glColor3f(1, 1, 0);
	glPointSize(8);
	glBegin(GL_POINTS);
	glVertex2i(px, py);
	glEnd();
}

void MakusEngine::OnQuit()
{
	glfwTerminate();
}

void MakusEngine::HelloWorld()
{
	std::cout << "HelloWorld" << '\n';
}

void MakusEngine::DrawMap2D() {
	/*int xo, yo;
	for (int y = 0; y < mapY; y++) {
		for (int x = 0; x < mapX; x++) {
			if (map[y * mapX + x] == 1)
				glColor3f(1, 1, 1);
			else
				glColor3f(0, 0, 0);

			xo = x * mapS;
			yo = y * mapS;
			glBegin(GL_QUADS);
			glVertex2i(xo +1, yo +1);
			glVertex2i(xo +1, yo+ mapS - 1);
			glVertex2i(xo + mapS - 1, yo + mapS - 1);
			glVertex2i(xo + mapS - 1, yo + 1);
			glEnd();
		}
	}*/
}

void OnInput(GLFWwindow* window, int key, int scancode, int action, int mods)
{
	if (key == GLFW_KEY_A && (action == GLFW_PRESS || action == GLFW_REPEAT)) 
	{
		// left
		pDirX = -1;
		pDirY = 0;
	}
	if (key == GLFW_KEY_D && (action == GLFW_PRESS || action == GLFW_REPEAT))
	{
		// right
		pDirX = 1;
		pDirY = 0;
	}
	if (key == GLFW_KEY_W && (action == GLFW_PRESS || action == GLFW_REPEAT)) 
	{
		// up
		pDirX = 0;
		pDirY = -1;
	}
	if (key == GLFW_KEY_S && (action == GLFW_PRESS || action == GLFW_REPEAT))
	{
		// down
		pDirX = 0;
		pDirY = 1;
	}
}



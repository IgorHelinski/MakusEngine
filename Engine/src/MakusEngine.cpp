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
float pdx, pdy; // player delta
float pa; // player angle

int mapX = 8, mapY = 8, mapS = 64;
int map[] = {
	1,1,1,1,1,1,1,1,
	1,0,0,0,0,0,0,1,
	1,0,0,0,0,0,0,1,
	1,0,0,0,0,0,0,1,
	1,0,0,0,0,0,0,1,
	1,0,0,0,0,0,0,1,
	1,0,0,0,0,0,0,1,
	1,1,1,1,1,1,1,1,
};

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

	pdx = cos(pa) * 5;
	pdy = sin(pa) * 5;
}

void MakusEngine::OnUpdate()
{
	glClear(GL_COLOR_BUFFER_BIT | GL_DEPTH_BUFFER_BIT);

	glClearColor(0.3, 0.3, 0.3, 0);

	glMatrixMode(GL_PROJECTION);
	glLoadIdentity();
	glOrtho(0, windowWidth, windowHeight, 0, 0, 1);

	DrawMap2D();

	// draw player
	glColor3f(1, 1, 0);
	glPointSize(8);
	glBegin(GL_POINTS);
	glVertex2i(px, py);
	glEnd();

	glLineWidth(3);
	glBegin(GL_LINES);
	glVertex2i(px, py);
	glVertex2i(px + pdx * 5, py + pdy * 5);
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

unsigned int MakusEngine::VertexShaderSetup() {
	const char* vertexShaderSource = "#version 330 core\n"
		"layout (location = 0) in vec3 aPos;\n"
		"void main()\n"
		"{\n"
		"   gl_Position = vec4(aPos.x, aPos.y, aPos.z, 1.0);\n"
		"}\0";

	unsigned int vertexShader = glCreateShader(GL_VERTEX_SHADER);

	glShaderSource(vertexShader, 1, &vertexShaderSource, NULL);
	glCompileShader(vertexShader);

	return vertexShader;
}

unsigned int MakusEngine::FragmentShaderSetup() {
	const char* fragmentShaderSource = "#version 330 core\n"
		"out vec4 FragColor;\n"
		"void main()\n"
		"{\n"
		"   FragColor = vec4(1.0f, 0.5f, 0.2f, 1.0f);\n"
		"}\n\0";

	unsigned int fragmentShader = glCreateShader(GL_FRAGMENT_SHADER);

	glShaderSource(fragmentShader, 1, &fragmentShaderSource, NULL);
	glCompileShader(fragmentShader);

	return fragmentShader;
}

unsigned int MakusEngine::LinkShaders(unsigned int vertexShader, unsigned int fragmentShader) {
	unsigned int shaderProgram = glCreateProgram();
	glAttachShader(shaderProgram, vertexShader);
	glAttachShader(shaderProgram, fragmentShader);
	glLinkProgram(shaderProgram);
	glUseProgram(shaderProgram);
	glDeleteShader(vertexShader);
	glDeleteShader(fragmentShader);

	return shaderProgram;
}

void MakusEngine::DrawMap2D() {
	int xo, yo;
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
	}
}

void OnInput(GLFWwindow* window, int key, int scancode, int action, int mods)
{
	if (key == GLFW_KEY_A && (action == GLFW_PRESS || action == GLFW_REPEAT)) 
	{
		pa -= 0.1;
		if (pa < 0)
			pa += 2 * PI;

		pdx = cos(pa) * 5;
		pdy = sin(pa) * 5;
	}
	if (key == GLFW_KEY_D && (action == GLFW_PRESS || action == GLFW_REPEAT))
	{
		pa += 0.1;
		if (pa > 2 * PI)
			pa = 0;

		pdx = cos(pa) * 5;
		pdy = sin(pa) * 5;
	}
	if (key == GLFW_KEY_W && (action == GLFW_PRESS || action == GLFW_REPEAT)) 
	{
		px += pdx;
		py += pdy;
	}
	if (key == GLFW_KEY_S && (action == GLFW_PRESS || action == GLFW_REPEAT))
	{
		px -= pdx;
		py -= pdy;
	}
}



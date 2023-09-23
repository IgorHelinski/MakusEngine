#include <MakusEngine.h>
#define GLFW_INCLUDE_NONE
#include <GLFW/include/glfw3.h>
#include <glad/glad.h>

#include <Window.h>
#include <Graphics.h>
#include <iostream>

#include <stdlib.h>
#include <stdio.h>

#include <math.h>

//GLfloat pointVertex[] = { 1024 / 2, 512 / 2 };
GLfloat pointVertex[] = { 1024 / 2, 512 / 2 };
GLfloat pointVertex2[] = { 1024 * 0.75, 512 / 2 };
float playerX;
float playerY;

static const char* vertex_shader_text =
"#version 110\n"
"uniform mat4 MVP;\n"
"attribute vec3 vCol;\n"
"attribute vec2 vPos;\n"
"varying vec3 color;\n"
"void main()\n"
"{\n"
"    gl_Position = MVP * vec4(vPos, 0.0, 1.0);\n"
"    color = vCol;\n"
"}\n";

static const char* fragment_shader_text =
"#version 110\n"
"varying vec3 color;\n"
"void main()\n"
"{\n"
"    gl_FragColor = vec4(color, 1.0);\n"
"}\n";

static const struct
{
	float x, y;
	float r, g, b;
} vertices[3] =
{
	{ -0.6f, -0.4f, 1.f, 0.f, 0.f },
	{  0.6f, -0.4f, 0.f, 1.f, 0.f },
	{   0.f,  0.6f, 0.f, 0.f, 1.f }
};

static void error_callback(int error, const char* description)
{
	fprintf(stderr, "Error: %s\n", description);
}

static void key_callback(GLFWwindow* window, int key, int scancode, int action, int mods)
{
	if (key == GLFW_KEY_ESCAPE && action == GLFW_PRESS)
		glfwSetWindowShouldClose(window, GLFW_TRUE);
}

MakusEngine::MakusEngine()
{
}

MakusEngine::~MakusEngine()
{
}

void MakusEngine::StartMakus()
{
	/*Window window;
	window.InitWindow();
	window.CreateWindow(1024, 512, "Makus Engine dev build");

	Graphics graphics;
	graphics.InitGraphics();

	glViewport(0.0f, 0.0f, 1024, 512);
	glMatrixMode(GL_PROJECTION);
	glLoadIdentity();
	glOrtho(0, 1024, 0, 512, 0, 1);
	glMatrixMode(GL_MODELVIEW);
	glLoadIdentity();*/

	//graphics.SetOrthographicProjection(0, 1024, 0, 512, 0.0f, 1.0f);

	//unsigned int vertexShader = VertexShaderSetup();
	//unsigned int fragmentShader = FragmentShaderSetup();
	//unsigned int shaderProgram = LinkShaders(vertexShader, fragmentShader);

	//graphics.SetOrthographicProjection(shaderProgram ,0, 1024, 0, 512, -1.0f, 1.0f);

	GLFWwindow* window;
	GLuint vertex_buffer, vertex_shader, fragment_shader, program;
	GLint mvp_location, vpos_location, vcol_location;

	glfwSetErrorCallback(error_callback);

	if (!glfwInit())
		exit(EXIT_FAILURE);

	glfwWindowHint(GLFW_CONTEXT_VERSION_MAJOR, 2);
	glfwWindowHint(GLFW_CONTEXT_VERSION_MINOR, 0);

	window = glfwCreateWindow(640, 480, "Simple example", NULL, NULL);
	if (!window)
	{
		glfwTerminate();
		exit(EXIT_FAILURE);
	}

	glfwSetKeyCallback(window, key_callback);

	glfwMakeContextCurrent(window);
	gladLoadGL();
	glfwSwapInterval(1);

	glGenBuffers(1, &vertex_buffer);
	glBindBuffer(GL_ARRAY_BUFFER, vertex_buffer);
	glBufferData(GL_ARRAY_BUFFER, sizeof(vertices), vertices, GL_STATIC_DRAW);

	vertex_shader = glCreateShader(GL_VERTEX_SHADER);
	glShaderSource(vertex_shader, 1, &vertex_shader_text, NULL);
	glCompileShader(vertex_shader);

	fragment_shader = glCreateShader(GL_FRAGMENT_SHADER);
	glShaderSource(fragment_shader, 1, &fragment_shader_text, NULL);
	glCompileShader(fragment_shader);

	program = glCreateProgram();
	glAttachShader(program, vertex_shader);
	glAttachShader(program, fragment_shader);
	glLinkProgram(program);

	mvp_location = glGetUniformLocation(program, "MVP");
	vpos_location = glGetAttribLocation(program, "vPos");
	vcol_location = glGetAttribLocation(program, "vCol");

	glEnableVertexAttribArray(vpos_location);
	glVertexAttribPointer(vpos_location, 2, GL_FLOAT, GL_FALSE,
		sizeof(vertices[0]), (void*)0);
	glEnableVertexAttribArray(vcol_location);
	glVertexAttribPointer(vcol_location, 3, GL_FLOAT, GL_FALSE,
		sizeof(vertices[0]), (void*)(sizeof(float) * 2));

	OnCreate();

	//while (!glfwWindowShouldClose(window.GlfwWindow))
	//{
	//	OnUpdate();

	//	// this at the end
	//	glfwSwapBuffers(window.GlfwWindow);
	//	glfwPollEvents();
	//}

	while (!glfwWindowShouldClose(window))
	{
		float ratio;
		int width, height;
		//mat4x4 m, p, mvp;

		glfwGetFramebufferSize(window, &width, &height);
		ratio = width / (float)height;

		glViewport(0, 0, width, height);
		glClear(GL_COLOR_BUFFER_BIT);

		/*mat4x4_identity(m);
		mat4x4_rotate_Z(m, m, (float)glfwGetTime());
		mat4x4_ortho(p, -ratio, ratio, -1.f, 1.f, 1.f, -1.f);
		mat4x4_mul(mvp, p, m);*/

		glUseProgram(program);
		//glUniformMatrix4fv(mvp_location, 1, GL_FALSE, (const GLfloat*)mvp);
		glDrawArrays(GL_TRIANGLES, 0, 3);

		glfwSwapBuffers(window);
		glfwPollEvents();
	}

	glfwDestroyWindow(window);

	glfwTerminate();
	exit(EXIT_SUCCESS);

	OnQuit();
}

void MakusEngine::OnCreate()
{
	HelloWorld();

	/*glMatrixMode(GL_PROJECTION);
	glLoadIdentity();
	glOrtho(0, 1024.0, 0, 768.0, -1.0, 1.0);
	glMatrixMode(GL_MODELVIEW);
	glLoadIdentity();*/

	//glClearColor(0.2f, 0.3f, 0.3f, 1.0f);

	//playerX = 300;
	//playerY = 300;
}

void MakusEngine::OnUpdate()
{
	glClear(GL_COLOR_BUFFER_BIT);

	// Render OpenGL here
	glEnable(GL_POINT_SMOOTH); // make the point circular
	glEnableClientState(GL_VERTEX_ARRAY); // tell OpenGL that you're using a vertex array for fixed-function attribute
	glPointSize(50); // must be added before glDrawArrays is called
	glVertexPointer(2, GL_FLOAT, 0, pointVertex); // point to the vertices to be used
	glDrawArrays(GL_POINTS, 0, 1); // draw the vertixes
	glDisableClientState(GL_VERTEX_ARRAY); // tell OpenGL that you're finished using the vertex arrayattribute
	glDisable(GL_POINT_SMOOTH); // stop the smoothing to make the points circular

	glEnableClientState(GL_VERTEX_ARRAY); // tell OpenGL that you're using a vertex array for fixed-function attribute
	glVertexPointer(2, GL_FLOAT, 0, pointVertex2); // point to the vertices to be used
	glPointSize(10); // must be added before glDrawArrays is called
	glDrawArrays(GL_POINTS, 0, 1); // draw the vertixes
	glDisableClientState(GL_VERTEX_ARRAY); // tell OpenGL that you're finished using the vertex arrayattribute
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



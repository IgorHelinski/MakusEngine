#include <glad/glad.h>
#include <GLFW/include/glfw3.h>
#include <iostream>

int main(void)
{
    GLFWwindow* window;

    /* Initialize the library */
    if (!glfwInit())
        return -1;

    /* Create a windowed mode window and its OpenGL context */
    window = glfwCreateWindow(1024, 512, "Hello World", NULL, NULL);
    if (!window)
    {
        glfwTerminate();
        return -1;
    }

    /* Make the window's context current */
    glfwMakeContextCurrent(window);

    if (!gladLoadGLLoader((GLADloadproc)glfwGetProcAddress))
    {
        std::cout << "Failed to initialize GLAD" << std::endl;
        return -1;
    }

    GLuint VertexArrayID;
    glGenVertexArrays(1, &VertexArrayID);
    glBindVertexArray(VertexArrayID);

    // data for the vertex buffer (array of 3 vectors, representing 3 vertecies(x, y, z))
    static const GLfloat g_vertex_buffer_data[] = {
        -1.0f, -1.0f, 0.0f,
        1.0f, -1.0f, 0.0f,
        0.0f, 1.0f, 0.0f,
    };

    GLuint vertexBuffer;
    glGenBuffers(1, &vertexBuffer);
    glBindBuffer(GL_ARRAY_BUFFER, vertexBuffer);
    glBufferData(GL_ARRAY_BUFFER, sizeof(g_vertex_buffer_data), g_vertex_buffer_data, GL_STATIC_DRAW);

    std::cout << glGetString(GL_VERSION) << std::endl;

    float px, py;
    px = 300;
    py = 300;

    /* Loop until the user closes the window */
    while (!glfwWindowShouldClose(window))
    {
        /* Render here */
        glClear(GL_COLOR_BUFFER_BIT | GL_DEPTH_BUFFER_BIT);

        glClearColor(0.3, 0.3, 0.3, 0);

        glMatrixMode(GL_PROJECTION);
        glLoadIdentity();
        glOrtho(0, 1024, 512, 0, 0, 1);

        //glEnableVertexAttribArray(0);
        //glBindBuffer(GL_ARRAY_BUFFER, vertexBuffer);
        //glVertexAttribPointer(
        //    0,                  // attribute 0. No particular reason for 0, but must match the layout in the shader.
        //    3,                  // size
        //    GL_FLOAT,           // type
        //    GL_FALSE,           // normalized?
        //    0,                  // stride
        //    (void*)0            // array buffer offset
        //);

        ////here we draw the motherfucker
        //glDrawArrays(GL_TRIANGLES, 0, 3);
        //glDisableVertexAttribArray(0);

        glColor3f(1, 1, 0);
        glPointSize(80);
        glBegin(GL_POINTS);
        glVertex2i(px, py);
        glEnd();

        /* Swap front and back buffers */
        glfwSwapBuffers(window);

        /* Poll for and process events */
        glfwPollEvents();
    }

    glfwTerminate();
    return 0;
}
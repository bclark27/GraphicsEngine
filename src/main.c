#include "bufferObjects/vec3d.h"
#include <GL/glew.h>
#include <GLFW/glfw3.h>
#include "comm/Common.h"

int main()
{
// Initialize GLFW
    if (!glfwInit()) {
        fprintf(stderr, "Failed to initialize GLFW\n");
        return -1;
    }

    // Optionally set the context to an older version if using immediate mode
    glfwWindowHint(GLFW_CONTEXT_VERSION_MAJOR, 2);
    glfwWindowHint(GLFW_CONTEXT_VERSION_MINOR, 1);

    // Create a windowed mode window and its OpenGL context
    GLFWwindow* window = glfwCreateWindow(640, 480, "OpenGL Triangle", NULL, NULL);
    if (!window) {
        glfwTerminate();
        return -1;
    }
    glfwMakeContextCurrent(window);

    // Initialize GLEW after making the context current
    if (glewInit() != GLEW_OK) {
        fprintf(stderr, "Failed to initialize GLEW\n");
        return -1;
    }

    // Main loop
    while (!glfwWindowShouldClose(window)) {
        // Clear the screen to a dark gray color
        glClearColor(0.1f, 0.1f, 0.1f, 1.0f);
        glClear(GL_COLOR_BUFFER_BIT);

        // Draw a triangle using immediate mode (deprecated in modern OpenGL)
        glBegin(GL_TRIANGLES);
            glColor3f(1.0f, 0.0f, 0.0f); // Red vertex
            glVertex2f(-0.6f, -0.4f);
            glColor3f(0.0f, 1.0f, 0.0f); // Green vertex
            glVertex2f(0.6f, -0.4f);
            glColor3f(0.0f, 0.0f, 1.0f); // Blue vertex
            glVertex2f(0.0f, 0.6f);
        glEnd();

        // Swap front and back buffers
        glfwSwapBuffers(window);
        // Poll for and process events
        glfwPollEvents();
    }

    // Clean up and exit
    glfwDestroyWindow(window);
    glfwTerminate();
    return 0;
}

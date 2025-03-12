#include <GL/glew.h>
#include <GLFW/glfw3.h>
#include "comm/Common.h"

#include "shader.h"
#include "VAO.h"
#include "VBO.h"
#include "EBO.h"



#define HEIGHT  (480)
#define WIDTH   (640)



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
  GLFWwindow* window = glfwCreateWindow(WIDTH, HEIGHT, "OpenGL Triangle", NULL, NULL);
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

  // Vertices coordinates
  GLfloat vertices[] =
  {
  	-0.5f, -0.5f * (float)(sqrt(3)) / 3, 0.0f, // Lower left corner
  	0.5f, -0.5f * (float)(sqrt(3)) / 3, 0.0f, // Lower right corner
  	0.0f, 0.5f * (float)(sqrt(3)) * 2 / 3, 0.0f, // Upper corner
  	-0.5f / 2, 0.5f * (float)(sqrt(3)) / 6, 0.0f, // Inner left
	  0.5f / 2, 0.5f * (float)(sqrt(3)) / 6, 0.0f, // Inner right
	  0.0f, -0.5f * (float)(sqrt(3)) / 3, 0.0f // Inner down
  };

  // Indices for vertices order
  GLuint indices[] =
  {
  	0, 3, 5, // Lower left triangle
  	3, 2, 4, // Lower right triangle
  	5, 4, 1 // Upper triangle
  };

  shader* shad = shader_init("shaders/default.vert", "shaders/default.frag");

  VAO* vao1 = VAO_create();
  VAO_bind(vao1);

  VBO* vbo1 = VBO_create(vertices, 18);
  EBO* ebo1 = EBO_create(indices, 9);

  VAO_link(vao1, vbo1, 0);

  VAO_unbind(vao1);
  VBO_unbind(vbo1);
  EBO_unbind(ebo1);


  while (!glfwWindowShouldClose(window))
  {
    glClearColor(0.07f, 0.13f, 0.17f, 1.0f);
    glClear(GL_COLOR_BUFFER_BIT);

    shader_activate(shad);
    VAO_bind(vao1);
    printf("ASDASD\n");
    glDrawElements(GL_TRIANGLES, 9, GL_UNSIGNED_INT, 0);

    glfwSwapBuffers(window);
    glfwPollEvents();
  }


  VAO_free(vao1);
  VBO_free(vbo1);
  EBO_free(ebo1);
  shader_free(shad);

  glfwDestroyWindow(window);
  glfwTerminate();
  return 0;
}

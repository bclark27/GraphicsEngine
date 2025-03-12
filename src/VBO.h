#ifndef VBO_H_
#define VBO_H_

#include <GL/glew.h>
#include <GLFW/glfw3.h>

/*
 * Types
 */

typedef struct VBO
{
  GLuint ID; 
} VBO;


VBO* VBO_create(GLfloat* vertices, GLsizeiptr size);
void VBO_bind(VBO* vbo);
void VBO_unbind(VBO* vbo);
void VBO_free(VBO* vbo);

#endif

#ifndef VAO_H_
#define VAO_H_

#include <GL/glew.h>
#include <GLFW/glfw3.h>

#include "VBO.h"

/*
 * Types
 */

typedef struct VAO
{
  GLuint ID;
  
  GLuint curr_vbo;
  GLuint curr_layout;
} VAO;

VAO* VAO_create();
void VAO_free(VAO* vao);

void VAO_link(VAO* vao, VBO* vbo, GLuint layout);
void VAO_bind(VAO* vao);
void VAO_unbind(VAO* vao);

#endif

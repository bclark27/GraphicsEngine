#ifndef EBO_H_
#define EBO_H_

#include <GL/glew.h>
#include <GLFW/glfw3.h>

/*
 * Types
 */

typedef struct EBO
{
  GLuint ID;
} EBO;


EBO* EBO_create(GLuint* idxs, GLsizeiptr size);
void EBO_bind(EBO* ebo);
void EBO_unbind(EBO* ebo);
void EBO_free(EBO* ebo);

#endif

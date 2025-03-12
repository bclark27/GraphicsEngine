#include "VBO.h"
#include "comm/Common.h"

/*
* Funcs
*/


VBO* VBO_create(GLfloat* vertices, GLsizeiptr size)
{
  VBO* vbo = malloc(sizeof(VBO));

  glGenBuffers(1, &vbo->ID);
  glBindBuffer(GL_ARRAY_BUFFER, vbo->ID);
  glBufferData(GL_ARRAY_BUFFER, size, vertices, GL_STATIC_DRAW);

  return vbo;
}

void VBO_bind(VBO* vbo)
{
  if (!vbo)
    return;

  glBindBuffer(GL_ARRAY_BUFFER, vbo->ID);
}

void VBO_unbind(VBO* vbo)
{
  if (!vbo)
    return;

  glBindBuffer(GL_ARRAY_BUFFER, 0);
}

void VBO_free(VBO* vbo)
{
  if (!vbo)
    return;

  glDeleteBuffers(1, &vbo->ID);

  free(vbo);
}



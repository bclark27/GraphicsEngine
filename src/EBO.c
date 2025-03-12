#include "EBO.h"
#include "comm/Common.h"

/*
* Funcs
*/


EBO* EBO_create(GLuint* idxs, GLsizeiptr size)
{
  EBO* ebo = malloc(sizeof(EBO));

  glGenBuffers(1, &ebo->ID);
  glBindBuffer(GL_ELEMENT_ARRAY_BUFFER, ebo->ID);
  glBufferData(GL_ELEMENT_ARRAY_BUFFER, size, idxs, GL_STATIC_DRAW);

  return ebo;
}

void EBO_bind(EBO* ebo)
{
  if (!ebo)
    return;

  glBindBuffer(GL_ELEMENT_ARRAY_BUFFER, ebo->ID);
}

void EBO_unbind(EBO* ebo)
{
  if (!ebo)
    return;

  glBindBuffer(GL_ELEMENT_ARRAY_BUFFER, 0);
}

void EBO_free(EBO* ebo)
{
  if (!ebo)
    return;

  glDeleteBuffers(1, &ebo->ID);

  free(ebo);
}



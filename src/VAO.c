#include "VAO.h"
#include "comm/Common.h"

/*
* Funcs
*/



VAO* VAO_create()
{
  VAO* vao = malloc(sizeof(VAO));
  vao->curr_layout = 0;
  vao->curr_vbo = 0;

  glGenVertexArrays(1, &vao->ID);

  return vao;
}

void VAO_free(VAO* vao)
{
  if (!vao)
    return;

  VAO_unbind(vao);

  glDeleteVertexArrays(1, &vao->ID);

  free(vao);
}

void VAO_link(VAO* vao, VBO* vbo, GLuint layout)
{
  if (!vao || !vbo)
    return;

  VBO_bind(vbo);

  glVertexAttribPointer(layout, 3, GL_FLOAT, GL_FALSE, 0, (void*)0);
  glEnableVertexAttribArray(layout);

  vao->curr_vbo = vbo->ID;
  vao->curr_layout = layout;

  VBO_unbind(vbo);
}

void VAO_bind(VAO* vao)
{
  if (!vao)
    return;

  glBindVertexArray(vao->ID);
}

void VAO_unbind(VAO* vao)
{
  if (!vao)
    return;

  glBindVertexArray(0);
}



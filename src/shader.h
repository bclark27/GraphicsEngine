#ifndef SHADER_H_
#define SHADER_H_

#include <GL/glew.h>
#include <GLFW/glfw3.h>

/*
 * Types
 */

typedef struct shader
{
  GLuint shaderProgram;
} shader;

shader* shader_createShader(const char* vertexShaderFile, const char* fragShaderFile);
void shader_activate(shader* s);
void shader_destroyShader(shader* s);

#endif

#include "shader.h"
#include "comm/Common.h"

/*
* Funcs
*/

const char* read_file(const char *filename) {
    FILE *file = fopen(filename, "rb");  // Open file in binary mode
    if (!file) {
        perror("Failed to open file");
        return NULL;
    }

    // Seek to end to determine file size
    fseek(file, 0, SEEK_END);
    long file_size = ftell(file);
    rewind(file);  // Move back to the beginning

    // Allocate memory for file contents + null terminator
    char *buffer = (char *)malloc(file_size + 1);
    if (!buffer) {
        perror("Memory allocation failed");
        fclose(file);
        return NULL;
    }

    // Read file into buffer
    fread(buffer, 1, file_size, file);
    buffer[file_size] = '\0';  // Null-terminate the string

    fclose(file);
    return (const char*)buffer;
}

shader* shader_createShader(const char* vertexShaderFile, const char* fragShaderFile)
{
  const char* vShaderSrc = read_file(vertexShaderFile);
  if (!vShaderSrc)
    return NULL;

  const char* fragShaderSrc = read_file(fragShaderFile);
  if (!fragShaderSrc)
  {
    free((void*)vShaderSrc);
    return NULL;
  }

  GLuint vShader = glCreateShader(GL_VERTEX_SHADER);
  glShaderSource(vShader, 1, &vShaderSrc, NULL);
  glCompileShader(vShader);

  GLuint fragShader = glCreateShader(GL_FRAGMENT_SHADER);
  glShaderSource(fragShader, 1, &fragShaderSrc, NULL);
  glCompileShader(fragShader);

  GLuint shaderProg = glCreateProgram();
  glAttachShader(shaderProg, vShader);
  glAttachShader(shaderProg, fragShader);
  glLinkProgram(shaderProg);

  glDeleteShader(vShader);
  glDeleteShader(fragShader);

  free((void*)vShaderSrc);
  free((void*)fragShaderSrc);

  shader* s = malloc(sizeof(shader));
  s->shaderProgram = shaderProg;

  return s;

}

void shader_activate(shader* s)
{
  glUseProgram(s->shaderProgram);
}

void shader_destroyShader(shader* s)
{
  if (!s)
    return;

  glDeleteProgram(s->shaderProgram);
}

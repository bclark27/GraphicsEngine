#ifndef MESH_H_
#define MESH_H_

#include "triangle.h"

/*
 * Types
 */

typedef struct mesh
{
  unsigned int triCount;
  triangle* triangles;
} mesh;

#endif

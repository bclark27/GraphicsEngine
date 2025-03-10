#ifndef VEC_3D_H_
#define VEC_3D_H_

/*
 * Types
 */

typedef struct vec3d
{
  float x;
  float y;
  float z;
} vec3d;

/*
 * Functions
 */

void vec3d_Add(vec3d* a, vec3d* b, vec3d* res);


#endif

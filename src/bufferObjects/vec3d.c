#include "vec3d.h"


/*
  * Functions
  */

void vec3d_Add(vec3d* a, vec3d* b, vec3d* res)
{
  res->x = a->x + b->x;
  res->y = a->y + b->y;
  res->z = a->z + b->z;
}

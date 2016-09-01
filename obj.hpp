#ifndef OBJ_HPP
#define OBJ_HPP

#include "Sphere.hpp"
#include "rt.hpp"

typedef struct OBJ{
  Sphere sphere;
  COLOR_T color;
  struct OBJ *next;
} OBJ_T;

COLOR_T cast(RAY_T, OBJ_T*);
void read_objs(OBJ_T**);

#endif

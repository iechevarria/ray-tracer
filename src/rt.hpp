#ifndef RT_HPP
#define RT_HPP

#include "Vector.hpp"

typedef struct {
  Vector org;
  Vector dir;
} RAY_T;

typedef struct {
  double r;
  double g;
  double b;
} COLOR_T;

#endif

#ifndef SPHERE_HPP
#define SPHERE_HPP

#include "Vector.hpp"
#include "rt.hpp"

class Sphere {
  private:
    Vector ctr;
    double rad;
  public:
    Sphere (void) {};
    Sphere (double x, double y, double z, double rad);
    void set (double x, double y, double z, double rad);
    
    double intersect (RAY_T ray, double &t, Vector &int_pt, Vector &normal);
};

#endif
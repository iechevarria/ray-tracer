#ifndef LIGHT_HPP
#define LIGHT_HPP

#include "rt.hpp"
#include "Vector.hpp"

class Light {
  private:
    Vector loc;
  public:
    Light (void) {};
    Light (double x, double y, double z);
    void set (double x, double y, double z);
    COLOR_T illuminate(RAY_T ray, COLOR_T surface_color, Vector int_pt, Vector normal);
};

#endif
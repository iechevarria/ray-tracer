#include "Light.hpp"
#include <iostream>

Light::Light (double x, double y, double z) {
  set(x,y,z);
};

void Light::set (double x, double y, double z) {
  this -> loc.set(x,y,z);
};


COLOR_T Light::illuminate(RAY_T ray, COLOR_T surface_color, Vector int_pt, Vector normal) {
  //ambient
  COLOR_T col;
  col.r = surface_color.r * 0.1;
  col.g = surface_color.g * 0.1;
  col.b = surface_color.b * 0.1;
  
  //diffuse
  double dot;
  Vector L;  
  L = loc - int_pt;
  L.normalize();
  dot = L.dot(normal);
  
  if (dot > 0) {
    col.r += dot * surface_color.r;
    col.g += dot * surface_color.g;
    col.b += dot * surface_color.b;
    
    //specular highlights
    Vector R;
    R = L - normal * 2 * normal.dot(L) ;
    R.normalize();
    double dot2 = R.dot(ray.dir);
    
    if (dot2 > 0) {
      col.r += pow(dot2, 200.0);
      col.g += pow(dot2, 200.0);
      col.b += pow(dot2, 200.0);
    } //dot2
  }
  
  return(col);
}

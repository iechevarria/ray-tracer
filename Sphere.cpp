#include "Sphere.hpp"

Sphere::Sphere (double xctr, double yctr, double zctr, double rad) {
  set(xctr,yctr,zctr,rad);
};

void Sphere::set (double x, double y, double z, double rad) {
  this -> ctr.set(x, y, z);
  this -> rad = rad;
};

double Sphere::intersect (RAY_T ray, double &t, Vector &int_pt, Vector &normal) {

  double A = 1.0;
  double B = 2.0 * ray.dir.dot(ray.org - ctr);
  Vector tmp = ray.org - ctr;
  double C = (tmp*tmp).sum_components() - (rad*rad);
  double dis = (B*B) - (4*A*C);
  

  //return 0 because discriminant is 0 or lower
  if (dis <= 0) {
    return 0;
  }
  
  double t1 = ((-1*B) + sqrt(dis)) / (2.0*A);
  double t2 = ((-1*B) - sqrt(dis)) / (2.0*A);
  
  //get the distance of the closest sphere, return whether or not there is an intersection
  if ((t1 < 0) && (t2 < 0)) {
    return 0;
  } 
  else if (t2 < 0) {
    t = t1;
  }
  else {
    t = fminf(t1,t2);
  }
  
  int_pt = ray.org + ray.dir * t;
  normal = (int_pt - ctr).scalar_divide(rad);
  
  return 1; 
};
  
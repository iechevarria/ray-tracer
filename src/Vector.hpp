#ifndef VECTOR_HPP
#define VECTOR_HPP

#include <math.h>

class Vector {
  
  private:
    double x;
    double y;
    double z;
    
  public:
    Vector (void) {};
    Vector (double x, double y, double z);
    void set (double x, double y, double z);
    
    void normalize (void);
    double dot (Vector);
    
    Vector add (Vector);
    Vector operator+ (Vector);
    Vector subtract (Vector);
    Vector operator- (Vector);
    Vector mult (Vector);
    Vector operator* (Vector);
    
    Vector scalar_mult (double);
    Vector operator* (double);
    Vector scalar_divide (double);
    Vector operator/ (double);
    
    double sum_components (void);
    double length (void);
};

#endif 
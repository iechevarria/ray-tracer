# include "Vector.hpp"

Vector::Vector (double x, double y, double z) {
  set(x,y,z);
}

void Vector::set (double x, double y, double z) {
  this -> x = x;
  this -> y = y;
  this -> z = z;
}

Vector Vector::normalize (void) {
  // Figure out how to call the function right now
  double len = sqrt((x*x) + (y*y) + (z*z));
  this -> x /= len;
  this -> y /= len;
  this -> z /= len;
}

double Vector::dot (Vector v) { 
  return x*v.x + y*v.y + z*v.z;
}

Vector Vector::add (Vector v) {
  Vector rv;
  rv.x = x + v.x;
  rv.y = y + v.y;
  rv.z = z + v.z;
  return rv;
}

Vector Vector::operator+ (Vector v) {
  return this -> add(v);
}

Vector Vector::subtract (Vector v) {
  Vector rv;
  rv.x = x - v.x;
  rv.y = y - v.y;
  rv.z = z - v.z;
  return rv;
}

Vector Vector::operator- (Vector v) {
  return this -> subtract(v);
}

Vector Vector::mult (Vector v) {
  Vector rv;
  rv.x = x * v.x;
  rv.y = y * v.y;
  rv.z = z * v.z;
  return rv;
}

Vector Vector::operator* (Vector v) {
  return this -> mult(v);
}

Vector Vector::scalar_mult (double a) {
  Vector rv;
  rv.x = x*a;
  rv.y = y*a;
  rv.z = z*a;
  return rv;
}

Vector Vector::operator* (double a) {
  return this -> scalar_mult(a);
}

Vector Vector::scalar_divide (double a) {
  Vector rv;
  rv.x = x/a;
  rv.y = y/a;
  rv.z = z/a;
  return rv;
}

Vector Vector::operator/ (double a){
  return this -> scalar_divide(a);
}

double Vector::sum_components (void) {
  double sum = x + y + z;
  return sum;
}

double Vector::length (void) {
  double len = sqrt((x*x) + (y*y) + (z*z));
  return len;
}

  
  
  
  
  
  
  
  
  
  
  
  
  
  

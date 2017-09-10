#include "obj.hpp"
#include "Light.hpp"
#include <iostream>

#ifdef _MSC_VER
#include <io.h>   // note that I changed this to a more suitable include
#include <fcntl.h>
#endif

void read_objs(OBJ_T **list) {
  //read in objects and add them to the linked list
  double x, y, z, rad, r, g, b;
  OBJ_T *node;
  while (std::cin >> x >> y >> z >> rad >> r >> g >> b) {
    node = new OBJ_T;
    node -> sphere.set(x,y,z,rad);
    node -> color.r = r;
    node -> color.g = g;
    node -> color.b = b;
    node -> next = *list;
    (*list) = node;
  }
}
  
  
COLOR_T trace(RAY_T ray, OBJ_T *list, Light light) {
  //set background color
  COLOR_T color;
  color.r = 0.0;
  color.g = 0.0;
  color.b = 0.0;
  OBJ_T *obj;
  
  Vector int_pt;
  Vector normal;
  
  OBJ_T *closest_obj = NULL;
  Vector closest_int_pt;
  Vector closest_normal;
  
  double min_t = 1000.0;
  double t;
  
  //get the color of the closest sphere
  for(obj = list; obj != NULL; obj = obj -> next) {
    if (obj -> sphere.intersect(ray, t, int_pt, normal)) {
      if (t < min_t) {
	color.r = obj -> color.r;
	color.g = obj -> color.g;
	color.b = obj -> color.b;
	
	closest_obj = obj;
	closest_int_pt = int_pt;
	closest_normal = normal;
	
	min_t = t;
      }  
    }
  }
  
  if (closest_obj != NULL) {
    color = light.illuminate(ray, color, closest_int_pt, closest_normal);
  }
  
  return color;
}


int main() {
  #ifdef _MSC_VER
  _setmode(_fileno(stdout), _O_BINARY);
  #endif
  
  //initialize values
  Sphere sphere; 
  RAY_T ray;
  OBJ_T *list = NULL;
  read_objs(&list);
  Light light;
  light.set(5.0, 10.0, 0.0);
  
  double t;
  int x, y; 

  ray.org.set(0.0,0.0,0.0);
  
  //make the ppm header
  std::cout << "P6\n1000 1000\n255\n";
  
  //loop over all 1 million pixels
  for (y = 0; y < 1000; y++) {
    for (x = 0; x < 1000; x++) {
      
      //set ray direction
      double tmpx = (-0.5 + (x/1000.0));
      double tmpy = (0.5 - (y/1000.0));
      double tmpz = 1.0;
      ray.dir.set(tmpx, tmpy, tmpz);

      //normalize ray direction and get color values
      ray.dir.normalize();
      COLOR_T col = trace(ray, list, light);
      
      if (col.r > 1) {
        col.r = 1.0;
      }
      if (col.g > 1) {
        col.g = 1.0;
      }
      if (col.b > 1) {
        col.b = 1.0;
      }
      
      //write the color values out
      std::cout << (unsigned char)(255 * col.r) << (unsigned char)(255 * col.g) << (unsigned char)(255 * col.b);
    }
  }

  //free memory
  OBJ_T *curr;
  while (list != NULL) {
      curr = list;
      list = list->next;
      delete curr;
  }
}
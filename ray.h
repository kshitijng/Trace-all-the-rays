// The ray representation class. 
#ifndef RAYH
#define RAYH

#include "vec.h"

class ray {
public:    
    vec A;
    vec B;
    ray() {}
    ray(const vec& a, const vec&b) {A = a; B = b;}
    vec origin() {return A; }
    vec direction() {return B;}
    vec get_ray_at_point(float t) {return A + t*B;} 
};

#endif
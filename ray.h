// defines a (light) ray.

#ifndef RAYH
#define RAYH

#include "vec.h"

class ray {
public:    
    vec A;
    vec B;
    ray() {}
    ray(const vec& a, const vec&b) {A = a; B = b;}
    const vec origin() const {
        const vec newVec = vec(A);
        return newVec;
    }
    vec direction() const{return B;}
    vec get_ray_at_point(float t) {return A + t*B;} 
    vec get_ray_at_point(float t) const {return A + t*B;}
};

#endif

// defines a hittable object i.e. any object that can 'interact' with a ray.
// TODO: Currently only supports spherical objects, add other types.

#ifndef HITTABLEOBJECTH
#define HITTABLEOBJECTH

#include "ray.h"

struct hit_record {
    vec p;
    vec normal;
};

class hittable_object {
    public:
        virtual bool hit(const ray&r, hit_record &rec) const = 0;
};

#endif
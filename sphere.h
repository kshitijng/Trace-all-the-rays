// defines a sphere object.

#ifndef SPHEREH
#define SPHEREH

#include "hittable_object.h"

class sphere : public hittable_object {
    public:
        sphere() {};
        sphere(vec center, float radius) : center(center), radius(radius) {};
        virtual bool hit(const ray&r, hit_record &rec) const;
        vec center;
        float radius;
};

bool sphere::hit(const ray &incidentRay, hit_record &rec) const {
    const vec fromSphereCenterToRayOrigin = incidentRay.origin() - center;
    float a = dot_product(incidentRay.direction(), incidentRay.direction());
    float b = 2 * dot_product(incidentRay.direction(), fromSphereCenterToRayOrigin);
    float c = dot_product(fromSphereCenterToRayOrigin, fromSphereCenterToRayOrigin) - (radius * radius);
    float dis = ((b*b) - (4 * a * c));
    if (dis > 0) {
        rec.p = incidentRay.get_ray_at_point((-b - sqrt(dis))/(2.0 * a));
        rec.normal = (rec.p - center) /radius;
        return true;
    }
    return false;
}

#endif

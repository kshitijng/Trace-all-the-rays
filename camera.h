/*  Defines a camera
    A camera is the Point-Of-View from which we view the scence
    It is aligned to the given co-ordinates in a cartesian system.
*/

#ifndef CAMERAH
#define CAMERAH

#include <iostream>
#include "ray.h"

class camera {
    public:
        camera() {
            lowerLeftCorner = vec(-2.0, -1.0, -1.0);
            horizontal = vec(4.0, 0.0, 0.0);
            vertical = vec(0.0, 2.0, 0.0);
            origin = vec(0.0, 0.0, 0.0);
        }

        // Get a ray from origin to point u,v
        ray get_ray(float u, float v) {
            return ray(origin, lowerLeftCorner + u*horizontal + v*vertical - origin);
        }

        vec origin;
        vec lowerLeftCorner;
        vec horizontal;
        vec vertical;
};

#endif
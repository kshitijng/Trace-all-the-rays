// This class is an abstraction for the camera.
// Currently we use a single camera which is aligned to the given co-ordinates in a cartesian system.
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
        ray get_ray(float u, float v) {
            // std::cout << "U: " << u << "\n";
            // std::cout << "V: " << v << "\n";
            // std::cout << "lowerLeftCorner: " << lowerLeftCorner.x() << "\n";
            // std::cout << "horizontal: " << horizontal.x() << "\n";
            // std::cout << "vertical: " << vertical.x() << "\n";
            // std:: cout << "SUM: " << lowerLeftCorner.x() + (u * horizontal.x()) + (v * vertical.x()) << "\n";
            return ray(origin, lowerLeftCorner + u*horizontal + v*vertical - origin);
        }

        vec origin;
        vec lowerLeftCorner;
        vec horizontal;
        vec vertical;
};

#endif
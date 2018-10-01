// This is the main output file
#include <iostream>
#include <stdlib.h>
#include "vec.h"
#include "ray.h"
#include "camera.h"

vec colour(ray r);

int main() {
    int rows = 300;
    int columns = 300;
    // For AntiAliasing, number of rays to sample per pixel.
    int numberOfSamplePerPixel = 1000;

    camera cam;
    std::cout << "P3\n" << columns << " " << rows << "\n255\n";
    for (int i = 0; i < rows; ++i) {
        for (int j = 0; j < columns; ++j) {
            vec col(0, 0, 0);
            for (int k = 0; k < numberOfSamplePerPixel; ++k) {
                float u = float(i + drand48()) / float(rows);
                float v = float(j + drand48()) / float(columns);
                // std::cout << "U: " << u << "\n";
                // std::cout << "V: " << v << "\n";
                ray r = cam.get_ray(u, v);
                // std::cout << "rayA:" << r.A.x() << " " << r.A.y() << " " << r.A.z() << "\n";
                // std::cout << "rayB:" << r.B.x() << " " << r.B.y() << " " << r.B.z() << "\n";
                vec p = r.get_ray_at_point(2.0);
                col = col + colour(r);
            }
            col = col/numberOfSamplePerPixel;
            int ir = int(255.99*col[0]);
            int ig = int(255.99*col[1]);
            int ib = int(255.99*col[2]);
            std::cout << ir << " " << ig << " " << ib << "\n";
        }
    }
    // for(int i = 0; i < columns; ++i) {
    //     for(int j = rows-1; j >=0; j--) {
    //         float r = float(j)/float(rows);
    //         float g = float(i)/float(columns);
    //         ray myRay(origin, lowerLeftCorner + r*horizontal + g*vertical);
    //         vec col = colour(myRay);
    //         int ir = int(255.99*col[0]);
    //         int ig = int(255.99*col[1]);
    //         int ib = int(255.99*col[2]);
    //         std::cout << ir << " " << ig << " " << ib << "\n";
    //     }
    // }
}

// Returns true if the incident ray hits the sphere.
// bool interacts_with_the_sphere(float sphereRadius, const vec& sphereCenter, const ray& incidentRay) {
//     const vec fromSphereCenterToRayOrigin = incidentRay.origin() - sphereCenter;
//     float a = dot_product(incidentRay.direction(), incidentRay.direction());
//     float b = 2 * dot_product(incidentRay.direction(), fromSphereCenterToRayOrigin);
//     float c = dot_product(fromSphereCenterToRayOrigin, fromSphereCenterToRayOrigin) - (sphereRadius * sphereRadius);
//     // std::cout << a <<  " " << b << " " << c << "\n";
//     float dis = ((b*b) - (4 * a * c));
//     // std::cout << (dis > 0);
//     return dis > 0;
// }

// Returns
float interacts_with_the_sphere(float sphereRadius, const vec& sphereCenter, const ray& incidentRay) {
    const vec fromSphereCenterToRayOrigin = incidentRay.origin() - sphereCenter;
    float a = dot_product(incidentRay.direction(), incidentRay.direction());
    float b = 2 * dot_product(incidentRay.direction(), fromSphereCenterToRayOrigin);
    float c = dot_product(fromSphereCenterToRayOrigin, fromSphereCenterToRayOrigin) - (sphereRadius * sphereRadius);
    float dis = ((b*b) - (4 * a * c));
    // If the ray does not hit the sphere of specified parameters.
    if (dis < 0) {
        return -1.0;
    }

    return (-b - sqrt(dis))/(2.0 * a);
}

// Returns a vec of colours for an incident ray.
vec colour(ray r) {
    /* Code without calculating normal ray
    if (interacts_with_the_sphere(0.5, vec(0, 0, -1), r)) {
        return vec(0.8, 0.6, 0);
    }*/
    float t = interacts_with_the_sphere(0.5, vec(0, 0, -1), r);
    if (t > 0.0) {
        vec normal = get_unit_vector(r.get_ray_at_point(t) - vec(0, 0, -1));
        return 0.5*vec(normal.x() + 1, normal.y() + 1, normal.z() + 1);
    }
    vec unit_direction = get_unit_vector(r.direction());
    // std::cout << unit_direction.y() << "\n";
    // 0 < t < 1
    t = 0.5 *(unit_direction.y() + 1.0);
    // Forms a linear blend/lerp
    return (1.0-t)*vec(0.4, 0.6, 0.3) + t*vec(0.5, 0.7, 1.0);
}
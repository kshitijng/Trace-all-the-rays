// This is the main output file
#include <iostream>
#include <stdlib.h>
#include "vec.h"
#include "ray.h"
#include "camera.h"
#include "sphere.h"
#include "object_list.h"

vec colour(ray r);
vec colour(ray r, hittable_object *scene);

int main() {
    // Set up the size of the scene.
    int rows = 300;
    int columns = 300;
    // For Anti-Aliasing, number of rays to sample per pixel.
    int numberOfSamplePerPixel = 10;

    int list_size = 1;
    // Make a list to store the objects in the scence.
    hittable_object *list[list_size];

    // Objects defined
    list[0] = new sphere(vec(0, 0, -1), 0.5);
    // list[1] = new sphere(vec(0, -100.5, -1), 100.0);

    // Store the Objects
    hittable_object *scene = new object_list(list, list_size);

    // Set up the camera
    camera cam;

    std::cout << "P3\n" << columns << " " << rows << "\n255\n";
    for (int i = 0; i < rows; ++i) {
        for (int j = 0; j < columns; ++j) {
            vec col(0, 0, 0);
            for (int k = 0; k < numberOfSamplePerPixel; ++k) {
                float u = float(i + drand48()) / float(rows);
                float v = float(j + drand48()) / float(columns);
                ray r = cam.get_ray(u, v);
                vec p = r.get_ray_at_point(2.0);
                col = col + colour(r, scene);
            }
            col = col/float(numberOfSamplePerPixel);
            int ir = int(255.99*col[0]);
            int ig = int(255.99*col[1]);
            int ib = int(255.99*col[2]);
            std::cout << ir << " " << ig << " " << ib << "\n";
        }
    }
}

// Returns true if the incident ray hits the sphere.
// Obsolete
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

// Returns the visible point where the ray hits the sphere, and -1.0 if it does not. 
// Obsolete
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
// Obsolete
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

vec diffuse() {
    vec p;
    do {
        p = 2.0 * vec(drand48(), drand48(), drand48()) - vec(1, 1, 1);
    } while (p.length_squared() >= 1.0);
    return p;
}
// Returns a vec of colours for an incident ray in a scence.
// Currently in Matte
vec colour(ray r, hittable_object *scene) {
    hit_record rec;
    if (scene->hit(r, rec)) {
        /*vec target = rec.p + rec.normal + diffuse();
        return 0.5*colour( ray(rec.p, target - rec.p), scene);*/
        vec normal = get_unit_vector(r.get_ray_at_point(t) - vec(0, 0, -1));
        return 0.5*vec(normal.x() + 1, normal.y() + 1, normal.z() + 1);
    }
    vec unit_direction = get_unit_vector(r.direction());
    float t = 0.5 *(unit_direction.y() + 1.0);
    return (1.0-t)*vec(0.4, 0.6, 0.3) + t*vec(0.5, 0.7, 1.0);
}
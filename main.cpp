// This is the main output file
#include <iostream>
#include "vec.h"
#include "ray.h"

vec colour(ray r);

int main() {
    int rows = 900;
    int columns = 1440;
    vec lowerLeftCorner(-2.0, -1.0, -1.0);
    vec horizontal(4.0, 0.0, 0.0);
    vec vertical(0.0, 2.0, 0.0);
    vec origin(0.0, 0.0, 0.0);
    std::cout << "P3\n" << columns << " " << rows << "\n255\n";
    for (int i = 0; i < rows; ++i) {
        for (int j = 0; j < columns; ++j) {
            float r = float (i)/float(rows);
            float g = float (j)/float(columns);
            ray myRay(origin, lowerLeftCorner + r*horizontal + g*vertical);
            vec col = colour(myRay);
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

vec colour(ray r) {
    vec unit_direction = get_unit_vector(r.direction());
    // std::cout << unit_direction.y() << "\n";
    // 0 < t < 1
    float t = 0.5 *(unit_direction.y() + 1.0);
    // Forms a linear blend/lerp
    return (1.0-t)*vec(0.4, 0.6, 0.3) + t*vec(0.5, 0.7, 1.0);
}
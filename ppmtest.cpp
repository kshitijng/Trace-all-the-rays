// outputs a test .ppm file.

#include <iostream>

int main() {
    int rows = 100;
    int columns = 200;
    std::cout << "P3\n" << columns << " " << rows << "\n255\n";
    for (int i = rows - 1; i >= 0; i--) {
        for (int j = 0; j < columns; ++j) {
            float r = float(j)/float(columns);
            float g = float(i)/float(rows);
            float b = 0.2;
            int ir = int(255.99*r);
            int ig = int(255.99*g);
            int ib = int(255.99*b);
            std::cout << ir << " " << ig << " " << ib << "\n";
        }
    }
}

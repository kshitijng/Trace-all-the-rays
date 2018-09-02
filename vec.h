// The vector header file dealing with the vector definitions and 
// the vector functions.

#ifndef VECH
#define VECH

#include <math.h>
#include <stdlib.h>
#include <iostream>

class vec {
    public:
        float e[3];
        vec() {}
        vec(float e0, float e1, float e2) {
            e[0] = e0;
            e[1] = e1;
            e[2] = e2;
        }
        inline float x() const {return e[0];}
        inline float y() const {return e[1];}
        inline float z() const {return e[2];}
        inline float r() const {return e[0];}
        inline float g() const {return e[1];}
        inline float b() const {return e[2];}

        inline const vec& operator+() const {return *this;}
        inline const vec operator-() const {return vec(-e[0], -e[1], -e[2]);}
        inline float operator[](int i) const {return e[i];}
        inline float& operator[](int i) { return e[i]; };

        inline vec& operator+=(const vec &v2);
        inline vec& operator-=(const vec &v2);
        inline vec& operator*=(const vec &v2);
        inline vec& operator/=(const vec &v2);
        inline vec& operator*=(const float t);
        inline vec& operator/=(const float t);

        inline float length() const {
            return sqrt(e[0]*e[0] + e[1]*e[1] + e[2]*e[2]);
        }
        inline float length_squared() const {
            return e[0]*e[0] + e[1]*e[1] + e[2]*e[2];
        }
        inline void convert_to_unit_vector();
};

inline vec operator*(const float t, const vec &v) {
    return vec(t*v.e[0], t*v.e[1], t*v.e[2]); 
}

inline vec operator/(const vec &v, const float f) {
    return vec(v.e[0]/f, v.e[1]/f, v.e[2]/f); 
}

inline vec operator+(const vec &v1, const vec &v2) {
    return vec(v1.e[0] + v2.e[0], v1.e[1] + v2.e[1], v1.e[2] + v2.e[2]); 
}

inline vec get_unit_vector(vec v) {
    return v/v.length();
}

#endif
#ifndef RAYTRACER_VECTOR_H
#define RAYTRACER_VECTOR_H
#include <iostream>

struct Vector {
    float x, y, z;

    Vector(float x, float y, float z);
    Vector(const Vector & other);
    Vector();

    const float len() const;
    const float len_sqr() const;

    Vector normalized() const;
    Vector & normalize();

    float operator*(const Vector & other) const;
    Vector operator^(const Vector & other) const;

    Vector operator+(const Vector & other) const;
    Vector operator-(const Vector & other) const;
    Vector operator*(const float mul) const;
    Vector operator/(const float div) const;

    Vector operator-() const;

    Vector & operator+=(const Vector & other);
    Vector & operator-=(const Vector & other);
    Vector & operator*=(const float mul);
    Vector & operator/=(const float div);
};

Vector reflect(const Vector & dir, const Vector & normal);

Vector refract(const Vector &dir, const Vector &normal, const float power);

inline Vector operator*(const float mul, const Vector& v) {
    return v * mul;
}

std::ostream& operator<<(std::ostream& os, const Vector& v);

#endif
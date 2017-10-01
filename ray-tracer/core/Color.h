#ifndef RAYTRACER_COLOR_H
#define RAYTRACER_COLOR_H
#include <iostream>


struct Color {
    float r, g, b;

    Color();
    Color(float r, float g, float b);
    Color(const Color & other);

    Color & clip();

    Color operator+(const Color & other);
    Color operator-(const Color & other);
    Color operator*(const Color & other);
    Color operator/(const Color & other);

    Color& operator+=(const Color & other);
    Color& operator-=(const Color & other);
    Color& operator*=(const Color & other);
    Color& operator/=(const Color & other);

    Color operator*(const float mul);
    Color operator/(const float div);

    Color& operator*=(const float mul);
    Color& operator/=(const float div);
};

std::ostream & operator<<(std::ostream & os, const Color& c);

#endif
#include "Color.h"

#ifndef MAX
#define MAX(a, b) ((a) > (b)) ? (a) : (b)
#endif

#ifndef MIN
#define MIN(a, b) ((a) < (b)) ? (a) : (b)
#endif


Color::Color() {
    r = g = b = 0.0f;
}

Color::Color(float r, float g, float b) {
    this->r = r; this->g = g; this->b = b;
}

Color::Color(const Color &other) {
    r = other.r; g = other.g; b = other.b;
}

Color Color::operator+(const Color &other) {
    Color result(r + other.r, g + other.g, b + other.b);
    return result;
}

Color Color::operator-(const Color &other) {
    Color result(r - other.r, g - other.g, b - other.b);
    return result;
}

Color Color::operator*(const Color &other) {
    Color result(r * other.r, g * other.g, b * other.b);
    return result;
}

Color Color::operator/(const Color &other) {
    Color result(r / other.r, g / other.g, b / other.b);
    return result;
}

Color Color::operator*(const float mul) {
    Color result(r * mul, g * mul, b * mul);
    return result;
}

Color Color::operator/(const float div) {
    Color result(r / div, g / div, b / div);
    return result;
}

Color & Color::operator*=(const Color & other) {
    r *= other.r; g *= other.g; b *= other.b;
    return *this;
}

Color & Color::operator/=(const Color & other) {
    r /= other.r; g /= other.g; b /= other.b;
    return *this;
}

Color & Color::operator+=(const Color & other) {
    r += other.r; g += other.g; b += other.b;
    return *this;
}

Color & Color::operator-=(const Color & other) {
    r -= other.r; g -= other.g; b -= other.b;
    return *this;
}

Color & Color::operator*=(const float mul) {
    r *= mul; g *= mul; b *= mul;
    return *this;
}

Color & Color::operator/=(const float div) {
    r /= div; g /= div; b /= div;
    return *this;
}

Color & Color::clip() {
    r = MAX(MIN(1.0f, r), 0.0f);
    g = MAX(MIN(1.0f, g), 0.0f);
    b = MAX(MIN(1.0f, b), 0.0f);
    return * this;
}

std::ostream& operator<<(std::ostream& os, const Color& c) {
    os << "Color ( " << c.r << ", " << c.g << ", " << c.b << " )";
    return os;
}

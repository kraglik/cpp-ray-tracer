#include "Vector.h"
#include <cmath>

Vector Vector::operator+(const Vector &other) const {
    Vector result(x + other.x, y + other.y, z + other.z);
    return result;
}

Vector Vector::operator-(const Vector &other) const {
    Vector result(x - other.x, y - other.y, z - other.z);
    return result;
}

Vector Vector::operator*(const float mul) const {
    Vector result(x * mul, y * mul, z * mul);
    return result;
}

Vector Vector::operator/(const float div) const {
    Vector result(x / div, y / div, z / div);
    return result;
}

Vector Vector::operator-() const {
    Vector result(-x, -y, -z);
    return result;
}

std::ostream& operator<<(std::ostream &os, const Vector &v) {
    os << "Vector ( " << v.x << ", " << v.y << ", " << v.z << " )";
    return os;
}

Vector::Vector(const Vector &other) {
    x = other.x;
    y = other.y;
    z = other.z;
}

Vector::Vector(float x, float y, float z) {
    this->x = x; this->y = y; this->z = z;
}

Vector::Vector() {
    x = y = z = 0.0f;
}

const float Vector::len() const {
    return sqrt(x * x + y * y + z * z);
}

const float Vector::len_sqr() const {
    return x * x + y * y + z * z;
}

Vector reflect(const Vector & dir, const Vector & normal) {
    return dir - normal * 2 * (dir * normal);
}

Vector refract(const Vector & dir, const Vector & normal, const float power) {
    float nv = normal * dir;
    if (nv > 0.0f)
        return refract(dir, -normal, power);
    float a = 1.0f / power;
    float d = 1.0f - (a * a) * (1.0f - nv * nv);
    if (d < 0.0f) {
        return Vector(0.0f, 0.0f, 0.0f);
    }
    float b = nv * a + sqrtf(d);
    return dir * a - normal * b;
}

Vector Vector::normalized() const {
    Vector result(x, y, z);
    float length = len();
    if (length != 0) result /= length;
    return result;
}

Vector & Vector::normalize() {
    float length = len();
    if (length != 0) {
        x /= length;
        y /= length;
        z /= length;
    }
    return * this;
}

Vector & Vector::operator+=(const Vector & other) {
    x += other.x; y += other.y; z += other.z;
    return * this;
}

Vector & Vector::operator-=(const Vector & other) {
    x -= other.x; y -= other.y; z -= other.z;
    return * this;
}

Vector & Vector::operator*=(const float mul) {
    x *= mul; y *= mul; z *= mul;
    return * this;
}

Vector & Vector::operator/=(const float div) {
    x /= div; y /= div; z /= div;
    return * this;
}

float Vector::operator*(const Vector &other) const {
    return x * other.x + y * other.y + z * other.z;
}

Vector Vector::operator^(const Vector &other) const {
    Vector result(
        y * other.z - z * other.y,
        x * other.z - z * other.x,
        x * other.y - y * other.x
    );
    return result;
}


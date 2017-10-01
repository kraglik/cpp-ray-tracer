#include "Sphere.h"

Sphere::Sphere(const Vector &center, const float radius):
    center(center), radius(radius){

}

bool Sphere::intersect(Hit &hit) const {
    Vector temp = hit.ray.pos - center;
    float a = hit.ray.dir * hit.ray.dir;
    float b = temp * 2.0f * hit.ray.dir;
    float c = temp * temp - radius * radius;
    float d = b * b - 4.0f * a * c;
    if (d < 0)
        return false;
    float e = sqrtf(d);
    float t = (-b - e) / (2.0f * a);

    if (t > 0.001) {
        hit.distance = t;
        hit.pos = hit.ray.pos + t * hit.ray.dir;
        hit.normal = (hit.pos - center).normalize();
        return true;
    }

    return false;
}

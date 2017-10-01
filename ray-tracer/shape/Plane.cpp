#include "Plane.h"

Plane::Plane(const Vector &pos, const Vector &normal)
    : pos(pos), normal(normal) {

}

bool Plane::intersect(Hit &hit) const {
    float temp = hit.ray.dir * normal;
    float t;
    if (temp != 0.0) {
        t = (pos - hit.ray.pos) * normal / temp;
    }
    else {
        t = 0.0;
    }
    if (t > 0.001) {
        hit.distance = t;
        hit.pos = hit.ray.pos + (t * hit.ray.dir);
        hit.normal = normal;
        return true;
    }
    return false;
}
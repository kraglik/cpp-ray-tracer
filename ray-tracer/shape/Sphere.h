#ifndef RAYTRACER_SPHERE_H
#define RAYTRACER_SPHERE_H

#include "../Shape.h"

class Sphere: public Shape {
private:
    Vector center;
    float radius;
public:
    Sphere(const Vector &center, const float radius);

    bool intersect(Hit & hit) const override;
};

#endif
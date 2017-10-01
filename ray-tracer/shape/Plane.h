#ifndef RAYTRACER_PLANE_H
#define RAYTRACER_PLANE_H

#include "../Shape.h"

class Plane: public Shape {
private:
    const Vector &pos, &normal;
public:
    Plane(const Vector &pos, const Vector& normal);

    bool intersect(Hit & hit) const override;
};

#endif
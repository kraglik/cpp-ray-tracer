#ifndef RAYTRACER_RAY_H
#define RAYTRACER_RAY_H
#include "Vector.h"

struct Ray {
    Vector pos, dir;

    Ray(const Vector &Pos, const Vector &Dir) :
            pos(Pos), dir(Dir) { }

    Ray() : pos(), dir() { }

    ~Ray() = default;
};

std::ostream& operator<<(std::ostream& os, const Ray& r);

#endif

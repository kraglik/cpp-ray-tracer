#ifndef RAYTRACER_SHAPE_H
#define RAYTRACER_SHAPE_H

#include "core/Ray.h"
#include "core/Hit.h"

class Shape {
public:
    virtual bool intersect(Hit &hit) const = 0;
};

#endif
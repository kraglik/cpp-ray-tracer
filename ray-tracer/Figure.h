#ifndef RAYTRACER_FIGURE_H
#define RAYTRACER_FIGURE_H

#include "core/Hit.h"
#include "Shape.h"

struct Figure {
    const Material & material;
    const Shape & shape;

    bool intersect(Hit &hit) const {
        return shape.intersect(hit);
    }

    Figure(const Shape & shape, const Material & material)
            : material(material), shape(shape) {

    }
};

#endif
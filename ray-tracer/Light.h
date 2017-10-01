#ifndef RAYTRACER_LIGHT_H
#define RAYTRACER_LIGHT_H

#include "core/Color.h"
#include "core/Hit.h"

class Light {
public:
    virtual Color color_at(const Hit & hit) const = 0;
    // Считает одновременно мощность тени и цвет освещения в точке.
    virtual Vector dir_at(const Hit & hit) const = 0;
};

#endif
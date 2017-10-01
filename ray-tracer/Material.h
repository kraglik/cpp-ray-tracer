#ifndef RAYTRACER_MATERIAL_H
#define RAYTRACER_MATERIAL_H

#include "core/Vector.h"
#include "core/Color.h"
#include "core/Hit.h"

struct Material {
    Color ambient, diffuse, specular, reflective, refractive;
    float phong_power, refraction_power;
    bool is_reflective, is_refractive;
};

#endif
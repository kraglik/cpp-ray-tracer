#ifndef RAYTRACER_HIT_H
#define RAYTRACER_HIT_H
#include "Vector.h"
#include "Ray.h"
#include "../Material.h"
#include "Color.h"
#include <cmath>

struct Scene;
struct Material;

struct Hit {
    const Scene & scene;
    Vector pos, normal;
    Material * material;
    Ray ray;
    float distance;

    Hit(const Scene & scene)
            : scene(scene), pos(), normal(), material(nullptr), ray(), distance(INFINITY) {

    }

    Hit & operator=(const Hit & other) {
        pos = other.pos;
        normal = other.normal;
        material = other.material;
        ray = other.ray;
        distance = other.distance;
        return * this;
    }
};

#endif
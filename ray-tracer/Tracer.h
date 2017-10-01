#ifndef RAYTRACER_TRACER_H
#define RAYTRACER_TRACER_H

#include "core/Color.h"
#include "core/Ray.h"
#include "core/Hit.h"
#include "Scene.h"

class Tracer {
private:
    Scene & scene;
    int max_depth;

    Color shade(const Hit & hit, int depth) const;

public:
    Tracer(Scene & scene, int max_depth);

    Color trace(const Ray & ray, int depth=0) const;
};

#endif
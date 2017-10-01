#ifndef RAYTRACER_SCENE_H
#define RAYTRACER_SCENE_H

#include <vector>
#include "Figure.h"
#include "Light.h"

struct Scene {
    const std::vector<Figure*> figures;
    const std::vector<Light*> lights;
    Color ambient;

    Scene(
            const std::vector<Figure*> &figures,
            const std::vector<Light*> &lights,
            const Color & ambient
    ) : figures(figures), lights(lights), ambient(ambient) {

    }
};

#endif
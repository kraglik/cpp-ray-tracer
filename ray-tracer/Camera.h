#ifndef RAYTRACER_CAMERA_H
#define RAYTRACER_CAMERA_H


#include "Tracer.h"

struct ViewPlane {
    float distance, ratio;
    int width, height;
};


class Camera {
private:
    const Tracer & tracer;
    Vector pos, target, up, U, V, W;
    ViewPlane viewPlane;

    void initUVW();

    Ray create_ray(const float x, const float y) const;

public:
    Camera(
            const Tracer & tracer,
            const Vector & pos,
            const Vector & target,
            const Vector & up,
            ViewPlane & viewPlane
    );

    std::vector<std::vector<Color>*> render() const;

    void render(const std::string & path) const;
};

#endif
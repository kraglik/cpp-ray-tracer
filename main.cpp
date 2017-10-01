#include <iostream>
#include "ray-tracer/core/Vector.h"
#include "ray-tracer/core/Color.h"
#include "ray-tracer/Material.h"
#include "ray-tracer/Figure.h"
#include "bitmap/bitmap_image.hpp"
#include "ray-tracer/shape/Sphere.h"
#include "ray-tracer/shape/Plane.h"
#include "ray-tracer/Tracer.h"
#include "ray-tracer/light/Directed.h"
#include "ray-tracer/Camera.h"

int main() {
    Material sphere_mat {
            .ambient = Color(1.0f, 1.0f, 1.0f) * 0.00,
            .diffuse = Color(1.0f, 0.0f, 0.0f) * 0.6,
            .specular = Color(1.0f, 0.0f, 0.0f) * 0.3,
            .reflective = Color(1.0f, 1.0f, 1.0f) * 0.1
    };

    sphere_mat.is_reflective = true;
    sphere_mat.is_refractive = false;
    sphere_mat.phong_power = 7.0f;

    Material glass_mat {
            .ambient = Color(0.2f, 0.3f, 1.0f) * 0.01,
            .diffuse = Color(0.2f, 0.3f, 1.0f) * 0.02,
            .specular = Color(0.2f, 0.3f, 1.0f) * 0.08,
            .reflective = Color(0.2f, 0.3f, 1.0f) * 0.15,
            .refractive = Color(0.2f, 0.3f, 1.0f) * 0.74
    };

    glass_mat.is_reflective = true;
    glass_mat.is_refractive = true;
    glass_mat.phong_power = 4.0f;
    glass_mat.refraction_power = 2.0f;

    Material plane_mat {
            .ambient = Color(1.0f, 1.0f, 1.0f) * 0.05,
            .diffuse = Color(0.8f, 0.9f, 0.3f) * 0.65,
            .specular = Color(0.8f, 0.9f, 0.3f) * 0.2,
            .reflective = Color(1.0f, 1.0f, 1.0f) * 0.1
    };

    plane_mat.is_reflective = true;
    plane_mat.is_refractive = false;
    plane_mat.phong_power = 5.0f;

    Figure sphere (Sphere(Vector(0, 0, 0), 1.5f), sphere_mat);

    Figure plane(Plane(Vector(0, -1.5f, 0), Vector(0, 1, 0)),plane_mat);

    Figure glass_sphere(Sphere(Vector(-2.5f, 0, 0.7f), 0.8f), glass_mat);

    std::vector<Light *> lights = {
            new Directed(Vector(1, -1, -1).normalized(), Color(1.0, 1.0, 1.0))
    };

    std::vector<Figure *> figures = {
            &sphere, &plane, &glass_sphere
    };

    Scene scene(figures, lights, Color(0.2, 0.4, 0.8));

    Tracer tracer(scene, 4);

    ViewPlane viewPlane {
            .distance = 2.0f, .ratio = (1920.0f / 1080.0f),
            .width = 1920, .height = 1080
    };

    Camera camera(
            tracer,
            Vector(-10.0f, 1.0f, 0.0),
            Vector(0.0, 0.0, 0.0),
            Vector(0.0, 1.0, 0.0),
            viewPlane
    );

    camera.render("result.bmp");

    return 0;
}
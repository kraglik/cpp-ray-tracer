#include "Tracer.h"

Tracer::Tracer(Scene &scene, const int max_depth)
    : scene(scene), max_depth(max_depth) {

}

Color Tracer::trace(const Ray &ray, int depth) const {
    if (depth >= max_depth)
        return Color(scene.ambient);
    Hit best(scene), temp(scene);
    temp.ray = ray;
    Color result = Color(scene.ambient);

    for (auto figure: scene.figures) {
        if (figure->intersect(temp)) {
            if (temp.distance < best.distance) {
                best = temp;
                best.material = &const_cast<Material&>(figure->material);
            }
        }
    }

    if (best.distance < INFINITY)
        result = shade(best, depth);

    return result;
}

Color lambert(
        const Color & diffuse,
        const Vector & normal,
        const Vector & light_dir
) {
    Color result(diffuse);
    float mul = ((-light_dir) * normal);
    if (mul <= 0) return Color(0, 0, 0);
    return result * mul;
}

Color phong(const Hit & hit, const Vector & light_dir) {
    float power = hit.ray.dir * reflect(-light_dir, hit.normal);
    Color result(0, 0, 0);
    if (power > 0.0f)
        result = hit.material->specular * powf(power, hit.material->phong_power);
    return result;
}


Color Tracer::shade(const Hit &hit, int depth) const {
    Color result = hit.material->ambient * hit.scene.ambient;
    Material & material = * hit.material;

    for (auto light: scene.lights) {
        Vector light_dir = light->dir_at(hit);
        Color light_color = light->color_at(hit);
        if (!(light_color.r == 0 && light_color.g == 0 && light_color.b == 0))
        result += light_color * (
                                        lambert(material.diffuse, hit.normal, light_dir) +
                                        phong(hit, light_dir)
                                );
    }

    if (material.is_reflective) {
        Ray reflected(hit.pos, reflect(hit.ray.dir, hit.normal));
        result += trace(reflected, depth + 1) * material.reflective;
    }

    if (material.is_refractive) {
        Vector refraction_dir(refract(hit.ray.dir, hit.normal, material.refraction_power));
        refraction_dir.normalize();
        if (refraction_dir.len_sqr() != 0.0f) {
            Ray refracted(hit.pos, refraction_dir);
            result += trace(refracted, depth + 1) * material.refractive;
        }
    }

    return result;
}



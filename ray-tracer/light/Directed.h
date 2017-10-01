#ifndef RAYTRACER_DIRECTED_H
#define RAYTRACER_DIRECTED_H


#include "../Light.h"

class Directed: public Light {
private:
    const Vector &dir;
    const Color &color;
public:
    Directed(const Vector &dir, const Color& color);

    Color color_at(const Hit & hit) const override;

    Vector dir_at(const Hit & hit) const override;
};


#endif
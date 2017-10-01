#ifndef RAYTRACER_TEXTURE_H
#define RAYTRACER_TEXTURE_H

#include "core/Vector.h"
#include "core/Color.h"

class Texture {
public:
    virtual Color color_at(const Vector & point) = 0;
};

#endif
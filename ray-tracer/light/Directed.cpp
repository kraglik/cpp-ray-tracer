#include <vector>
#include "Directed.h"
#include "../Figure.h"
#include "../Scene.h"

Directed::Directed(const Vector &dir, const Color &color)
    : dir(dir), color(color) {

}

Vector Directed::dir_at(const Hit &hit) const {
    return dir;
}

Color Directed::color_at(const Hit &hit) const {
    Color result(color);
    const std::vector<Figure*> &figures = hit.scene.figures;
    Hit temp(hit.scene);
    temp.ray = Ray(hit.pos, -dir);
    for (auto figure: figures) {
        if (figure->intersect(temp)) {
            if (figure->material.is_refractive)
                result *= figure->material.refractive;
            else {
                result = {0.0f, 0.0f, 0.0f};
                break;
            }
        }
    }
    return result;
}

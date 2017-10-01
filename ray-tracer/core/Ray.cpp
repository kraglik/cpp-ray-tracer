#include "Ray.h"

std::ostream& operator<<(std::ostream& os, const Ray& r) {
    os << "Ray { pos: " << r.pos << ", dir: " << r.dir << " }";
    return os;
}


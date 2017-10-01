#include "Camera.h"
#include "../bitmap/bitmap_image.hpp"

Camera::Camera(const Tracer &tracer,
               const Vector &pos,
               const Vector &target,
               const Vector &up,
               ViewPlane &viewPlane)
        : tracer(tracer),
          pos(pos),
          target(target),
          up(up),
          viewPlane(viewPlane) {
    initUVW();
}

void Camera::initUVW() {
    W = (pos - target).normalize();
    U = (up ^ W).normalize();
    V = W ^ U;
}

Ray Camera::create_ray(const float x, const float y) const {
    Vector ray_dir = (x * U + y * V - viewPlane.distance * W).normalize();
    return Ray(pos, ray_dir);
}

std::vector<std::vector<Color>*> Camera::render() const {
    auto result = * new std::vector<std::vector<Color>*>(viewPlane.width);
    for (int i = 0; i < viewPlane.width; i++)
        result[i] = new std::vector<Color>(viewPlane.height);

    #pragma omp parallel for
    for (int x = 0; x < viewPlane.width; x++) {
        for (int y = 0; y < viewPlane.height; y++) {
            Color color = {0.0f, 0.0f, 0.0f};

            for (int i = 0; i < 3; i++)
                for (int j = 0; j < 3; j++) {
                    float X = viewPlane.ratio * (x - 0.5f * viewPlane.width + ((float) i / 3.0f)) / (float) viewPlane.width;
                    float Y = (y - 0.5f * viewPlane.height + ((float) j / 3.0f)) / (float) viewPlane.height;
                    Ray ray = create_ray(X, Y);
                    color += tracer.trace(ray);
                }
            color = (color / 9.0f).clip();
            (*result[x])[y] = color;
        }
    }
    return result;
}

void Camera::render(const std::string & path) const {
    bitmap_image img(viewPlane.width, viewPlane.height);
    auto result = render();
    for (int i = 0; i < viewPlane.width; i++)
        for (int j = 0; j < viewPlane.height; j++) {
            auto color = (*result[i])[j];
            img.set_pixel(i, j,
                          (unsigned char) (color.r * 255.0f),
                          (unsigned char) (color.g * 255.0f),
                          (unsigned char) (color.b * 255.0f)
            );
        }
    img.save_image(path);

    for (auto arr: result)
        delete arr;
}

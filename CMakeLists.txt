cmake_minimum_required(VERSION 3.8)
project(RayTracer)

set(CMAKE_CXX_STANDARD 14)
SET (CMAKE_CXX_COMPILER             "/usr/bin/clang++")
SET (CMAKE_CXX_FLAGS                "-Wall -lm -lomp -fopenmp")
SET (CMAKE_CXX_FLAGS_DEBUG          "-g")
SET (CMAKE_CXX_FLAGS_MINSIZEREL     "-Os -DNDEBUG")
SET (CMAKE_CXX_FLAGS_RELEASE        "-O4 -DNDEBUG")
SET (CMAKE_CXX_FLAGS_RELWITHDEBINFO "-O2 -g")

set(SOURCE_FILES main.cpp ray-tracer/core/Vector.cpp ray-tracer/core/Vector.h ray-tracer/core/Color.cpp ray-tracer/core/Color.h ray-tracer/core/Ray.h ray-tracer/core/Ray.cpp ray-tracer/Tracer.h ray-tracer/Shape.h ray-tracer/core/Hit.h ray-tracer/Material.h ray-tracer/Texture.h ray-tracer/Scene.h ray-tracer/Figure.h ray-tracer/shape/Sphere.h ray-tracer/shape/Plane.h ray-tracer/shape/Sphere.cpp ray-tracer/light/Pointed.cpp ray-tracer/light/Pointed.h ray-tracer/light/Directed.cpp ray-tracer/light/Directed.h ray-tracer/Light.h ray-tracer/shape/Plane.cpp ray-tracer/Camera.cpp ray-tracer/Camera.h ray-tracer/Tracer.cpp)
add_executable(RayTracer ${SOURCE_FILES})
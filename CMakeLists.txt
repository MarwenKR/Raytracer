cmake_minimum_required(VERSION 3.10.0)
project(Raytracer VERSION 0.1.0 LANGUAGES CXX)

set(SOURCE_RAYTRACER
    src/camera.h
    src/interval.h
    src/utils.h
    src/hittable_list.h
    src/hittable.h
    src/sphere.h
    src/color.h
    src/ray.h
    src/vec3.h
    src/main.cpp
)

include_directories(src)

# Executable
add_executable(Raytracer ${SOURCE_RAYTRACER})

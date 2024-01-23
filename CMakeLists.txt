cmake_minimum_required(VERSION 3.10.0)
project(Raytracer VERSION 0.1.0 LANGUAGES CXX)

set(SOURCE_RAYTRACER
    src/color.h
    src/ray.h
    src/vec3.h
    src/main.cpp
)

include_directories(src)

# Executable
add_executable(Raytracer ${SOURCE_RAYTRACER})

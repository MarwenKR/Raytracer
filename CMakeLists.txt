cmake_minimum_required(VERSION 3.0.0)
project(Raytracer VERSION 0.1.0 LANGUAGES C CXX)
set ( RAY_TRACER

  Raytracer/color.h
  Raytracer/vec3.h

  Raytracer/main.cpp
)
add_executable(Raytracer  ${RAY_TRACER})




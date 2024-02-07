cmake_minimum_required(VERSION 3.10.0)
project(Raytracer VERSION 0.1.0 LANGUAGES CXX)

set(SOURCE_RAYTRACER
    src/camera.cpp
    src/color.cpp
       
    
    src/hittable_list.cpp 
    src/utils.cpp  
    src/ray.cpp 
    src/sphere.cpp    
    

    src/metal.cpp
    src/lambertian.cpp
    src/dielectric.cpp

    src/main.cpp
)

# Executable
add_executable(Raytracer ${SOURCE_RAYTRACER})
# Set include directories
target_include_directories(Raytracer PUBLIC ${CMAKE_CURRENT_SOURCE_DIR}/src/include lib/)
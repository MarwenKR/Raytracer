#pragma once

#include "utils.h"
#include "color.h"
#include "ray.h"
#include "material.h"
#include <iostream>
//#include <omp.h>


class camera {
public:
    double  aspect_ratio      = 1.0; // Ratio of image width over height
    int     image_width       = 100;    // Rendered image width in pixel count
    int     samples_per_pixel = 10;   // Count of random samples for each pixel
    int     max_depth         = 10;   // Maximum number of ray bounces into scene
    double vfov = 90; // vertical field of view
    point3 lookfrom = point3(0,0,-1); // looking from
    point3 lookat = point3(0,0,0); // looking at
    vec3 vup = vec3(0,1,0); // camera relative up direction

    void render(std::ostream &file, const hittable& world);

private:
    int image_height;    // Rendered image height
    point3 center;       // Camera center
    point3 pixel00_loc;  // Location of pixel 0, 0
    vec3 pixel_delta_u;  // Offset to pixel to the right
    vec3 pixel_delta_v;  // Offset to pixel below
    vec3 u, v, w; // camera basis
    void initialize();
    color ray_color(const ray& r, int depth, const hittable& world) const;
    ray get_ray(int i, int j) const;
    vec3 pixel_sample_square() const;
};


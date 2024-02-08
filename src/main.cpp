#include <chrono>
#include <fstream>
#include <iostream>
#include <memory>
#include <string>

#include "camera.h"
#include "color.h"
#include "dielectric.h"
#include "hittable_list.h"
#include "lambertian.h"
#include "material.h"
#include "metal.h"
#include "sphere.h"
#include "utils.h"


int main(){
    
    // world
    hittable_list world;
   
    auto material_ground = make_shared<lambertian>(color(0.8, 0.8, 0.0));
    auto material_center = make_shared<lambertian>(color(0.1, 0.2, 0.5));
    auto material_left   = make_shared<dielectric>(1.5);
    auto material_right  = make_shared<metal>(color(0.8, 0.6, 0.2), 0.0);

    world.add(make_shared<sphere>(point3( 0.0, -100.5, -1.0), 100.0, material_ground));
    world.add(make_shared<sphere>(point3( 0.0,    0.0, -1.0),   0.5, material_center));
    world.add(make_shared<sphere>(point3(-1.0,    0.0, -1.0),   0.5, material_left));
    world.add(make_shared<sphere>(point3(-1.0,    0.0, -1.0),  -0.4, material_left));
    world.add(make_shared<sphere>(point3( 1.0,    0.0, -1.0),   0.5, material_right));

    // camera
    camera cam;
    cam.aspect_ratio = 16.0/9.0;
    cam.image_width = 400;
    cam.samples_per_pixel = 100;
    cam.max_depth = 50;
    cam.vfov = 20;
    cam.lookat = point3(0,0,-1);
    cam.lookfrom = point3(-2,2,1);
    cam.vup = point3(0,1,0);
    cam.focus_dist = 3.4;
    cam.defocus_angle = 10.0;

    //create an output file
    std::ofstream output_file;
    std::string label = "Defocus_test";
    std::string filename = "images/Render_"+label+"_" + std::to_string(cam.image_width);
    filename += "_spp" + std::to_string(cam.samples_per_pixel);
    filename += "_d" + std::to_string(cam.max_depth);
    filename += ".ppm";
    output_file.open(filename);
    
    //render
    auto start = std::chrono::steady_clock::now();
    cam.render(output_file, world);
    output_file.close();
    auto end = std::chrono::steady_clock::now();
    auto elapsed = std::chrono::duration_cast<std::chrono::milliseconds>(end - start).count() / 1000.0;
    std::cerr << "\nDone! Written to " << filename << " -- Render took " << elapsed << " seconds.\n";
    
    
}
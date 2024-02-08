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
   

   // scene
    auto ground_material = make_shared<lambertian>(color(0.5, 0.5, 0.5));
    world.add(make_shared<sphere>(point3(0,-1000,0), 1000, ground_material));

    for (int a = -11; a < 11; a++) {
        for (int b = -11; b < 11; b++) {
            auto choose_mat = random_double();
            point3 center(a + 0.9*random_double(), 0.2, b + 0.9*random_double());

            if ((center - point3(4, 0.2, 0)).norm()> 0.9) {
                shared_ptr<material> sphere_material;

                if (choose_mat < 0.8) {
                    // diffuse
                    color albedo =  color::Random().array()* color::Random().array();
                    sphere_material = make_shared<lambertian>(albedo);
                    world.add(make_shared<sphere>(center, 0.2, sphere_material));
                } else if (choose_mat < 0.95) {
                    // metal
                    double r = random_double(0.5,1);
                    double g = random_double(0.5,1);
                    double b = random_double(0.5,1);

                    color albedo = color(r,g,b);
                    double fuzz = random_double(0, 0.5);
                    sphere_material = make_shared<metal>(albedo, fuzz);
                    world.add(make_shared<sphere>(center, 0.2, sphere_material));
                } else {
                    // glass
                    sphere_material = make_shared<dielectric>(1.5);
                    world.add(make_shared<sphere>(center, 0.2, sphere_material));
                }
            }
        }
    }

    auto material1 = make_shared<dielectric>(1.5);
    world.add(make_shared<sphere>(point3(0, 1, 0), 1.0, material1));

    auto material2 = make_shared<lambertian>(color(0.4, 0.2, 0.1));
    world.add(make_shared<sphere>(point3(-4, 1, 0), 1.0, material2));

    auto material3 = make_shared<metal>(color(0.7, 0.6, 0.5), 0.0);
    world.add(make_shared<sphere>(point3(4, 1, 0), 1.0, material3));


    // camera
    camera cam;

    cam.aspect_ratio      = 16.0 / 9.0;
    cam.image_width       = 1200;
    cam.samples_per_pixel = 500;
    cam.max_depth         = 50;

    cam.vfov     = 20;
    cam.lookfrom = point3(13,2,3);
    cam.lookat   = point3(0,0,0);
    cam.vup      = vec3(0,1,0);

    cam.defocus_angle = 0.6;
    cam.focus_dist    = 10.0;

    //create an output file
    std::ofstream output_file;
    std::string label = "Final_Scene";
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
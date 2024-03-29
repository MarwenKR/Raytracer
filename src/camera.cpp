#include "camera.h"

void camera::render(std::ostream &file, const hittable& world) {
    initialize();
    file << "P3\n" << image_width << ' ' << image_height << "\n255\n";
    for (int j = 0; j < image_height; ++j) {
        for (int i = 0; i < image_width; ++i) {
            color pixel_color(0,0,0);
            for(int sample=0;sample<samples_per_pixel;++sample){
                ray r = get_ray(i,j);
                pixel_color+=ray_color(r,max_depth,world);
            }
            write_color(file, pixel_color,samples_per_pixel);
        }
    }
}

void camera::initialize() {
    image_height = static_cast<int>(image_width / aspect_ratio);
    image_height = (image_height < 1) ? 1 : image_height;

    center = lookfrom;

    // Determine viewport dimensions.

    auto theta = degrees_to_radians(vfov);
    auto h = tan(theta/2);
    auto viewport_height = 2.0 * h * focus_dist;
    auto viewport_width = viewport_height * (static_cast<double>(image_width) / image_height);
   
    //Calculate the camera coordinate frame
    w = (lookfrom-lookat).normalized();
    u = vup.cross(w).normalized();
    v = w.cross(u);

    // Calculate the vectors across the horizontal and down the vertical viewport edges.
    auto viewport_u = viewport_width * u;
    auto viewport_v = viewport_height * -v;

    // Calculate the horizontal and vertical delta vectors from pixel to pixel.
    pixel_delta_u = viewport_u / image_width;
    pixel_delta_v = viewport_v / image_height;

    // Calculate the location of the upper left pixel.
    auto viewport_upper_left = center - (focus_dist *w) - viewport_u / 2 - viewport_v / 2;
    pixel00_loc = viewport_upper_left + 0.5 * (pixel_delta_u + pixel_delta_v);

    // Calculate the camera defcus disk basis vectors.
    auto defocus_radius = focus_dist*tan(degrees_to_radians(defocus_angle/2));
    defocus_disk_u = u * defocus_radius;
    defocus_disk_v = v * defocus_radius;
}

point3 camera::defocus_disk_sample() const{
    // Returns a random point in the camera defocus disk.
    point3 p  = random_in_unit_disk();
    return center+ (p.x()*defocus_disk_u) + (p.y()*defocus_disk_v);
}

color camera::ray_color(const ray& r, int depth, const hittable& world) const {
    hit_record rec;

    // If we've exceeded the ray bounce limit, no more light is gathered.
    if (depth <= 0)
        return color(0,0,0);

    if (world.hit(r, interval(0.001, infinity), rec)) {
        ray scattered;
        color attenuation;
        if (rec.mat->scatter(r, rec, attenuation, scattered))
            return attenuation.array() * ray_color(scattered, depth-1, world).array();
        return color(0,0,0);
    }

    vec3 unit_direction = r.direction().normalized();

    auto a = 0.5 * (unit_direction.y() + 1.0);
    return (1.0 - a) * color(1.0, 1.0, 1.0) + a * color(0.5, 0.7, 1.0);
}

ray camera::get_ray(int i, int j) const {
    // Get a randomly sampled camera ray for the pixel at location i,j, 
    //originating from the camera defocus disk

    point3 pixel_center = pixel00_loc + (i * pixel_delta_u) + (j * pixel_delta_v);
    point3 pixel_sample = pixel_center + pixel_sample_square();

    point3 ray_origin = (defocus_angle==0)? center:defocus_disk_sample();
    vec3 ray_direction = pixel_sample - ray_origin;

    return ray(ray_origin, ray_direction);
}

vec3 camera::pixel_sample_square() const {
    // Returns a random point in the square surrounding a pixel at the origin.
    auto px = -0.5 + random_double();
    auto py = -0.5 + random_double();
    return (px * pixel_delta_u) + (py * pixel_delta_v);
}


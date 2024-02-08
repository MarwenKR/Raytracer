#include "utils.h"


// Utility Functions
double degrees_to_radians(double degrees) {
    return degrees * PI / 180.0;
}

double random_double() {
    // Return a random real between 0 and 1.
    return rand() / (RAND_MAX + 1.0);
}

double random_double(double min, double max) {
    return min + (max - min) * random_double();
}


bool near_zero(const vec3& e)  {
        // Return true if the vector is close to zero in all dimensions.
        return ((std::fabs(e(0)) < EPS) && (std::fabs(e(1)) < EPS) && (std::fabs(e(2)) < EPS));
    }

vec3 random_unit_vector() {
    double theta = random_double(0, 2*PI);
    double z = random_double(-1, 1);
    double r = std::sqrt(1 - z*z);
    return vec3(r*std::cos(theta), r*std::sin(theta), z);
    }
vec3 random_in_unit_disk() {
    //generate a vector in unit disk using polar coordinates
        double theta = 2*PI*random_double(); // angle between 0 and 2.PI
        double r = sqrt(random_double()); // radius between 0 and 1
        double x = r * cos(theta);
        double y = r * sin(theta);

        return vec3(x,y,0);
    }
vec3 random_on_hemisphere(const vec3& normal) {
        vec3 on_unit_sphere = random_unit_vector();
        if (on_unit_sphere.dot( normal) > 0.0) // In the same hemisphere as the normal
            return on_unit_sphere;
        else
            return -on_unit_sphere;
    }

 vec3 reflect(const vec3& v, const vec3& n) {
    return v - 2*v.dot(n)*n;
}

vec3 refract(const vec3& uv, const vec3& n, double eta_ratio){
    auto cos_theta =  std::fmin(-1.0*uv.dot(n), 1.0);
    vec3 r_out_prep = eta_ratio * (uv+cos_theta*n);
    vec3 r_out_parallel = -std::sqrt(std::fabs(1.0-r_out_prep.squaredNorm()))*n;
    return r_out_parallel+r_out_prep;
}


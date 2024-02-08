#pragma once
#pragma optimize( "", on )

#include <cmath>
#include <cstdlib>
#include <limits>
#include <memory>
#include <Eigen/Dense>

// Usings
using std::shared_ptr;
using std::make_shared;
using std::sqrt;

using vec3 = Eigen::Vector3d;
using point3 = Eigen::Vector3d;

// Constants
const double infinity = std::numeric_limits<double>::infinity();
const double PI = 3.1415926535897932385;
const double EPS = 1e-8;


// Utility Functions

double degrees_to_radians(double degrees);
double random_double();
double random_double(double min, double max);
bool near_zero(const vec3& e);


vec3 random_unit_vector() ;
vec3 random_in_unit_disk();
vec3 random_on_hemisphere(const vec3& normal) ;
vec3 reflect(const vec3& v, const vec3& n) ;

vec3 refract(const vec3& uv, const vec3& n, double eta_ratio);


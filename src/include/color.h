#pragma once

#include <Eigen/Dense>
#include "utils.h"
#include "interval.h"
#include <iostream>

using color = Eigen::Vector3d;
inline double linear_to_gamma(double linear_component);

void write_color(std::ostream &out, color pixel_color, int sample_per_pixel);


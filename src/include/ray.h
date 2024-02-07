#pragma once

#include "utils.h"


class ray {
public:
    ray();
    ray(const point3& origin, const vec3& direction);

    point3 origin() const;
    vec3 direction() const;
    point3 at(double t) const;

private:
    point3 orig;
    vec3 dir;
};


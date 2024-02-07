#pragma once


#include "hittable.h"
#include "material.h"
#include "utils.h"

class sphere : public hittable {
public:
    sphere(point3 _center, double _radius, shared_ptr<material> _material);

    bool hit(const ray& r, interval ray_t, hit_record& rec) const override;

private:
    point3 center;
    double radius;
    shared_ptr<material> mat;
};

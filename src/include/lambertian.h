#pragma once
#include <material.h>
#include "utils.h"

class lambertian : public material {
public:
    lambertian(const color& a) : albedo(a) {}
        
    bool scatter(const ray& r_in, const hit_record& rec, color& attenuation, ray& scattered) const override;
private:
    color albedo;
};
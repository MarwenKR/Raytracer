#pragma once
#include <material.h>

class dielectric : public material {
public:
    dielectric(double index_of_refraction) : ir(index_of_refraction) {}

    bool scatter(const ray& r_in, const hit_record& rec, color& attenuation, ray& scattered) const override;

    double ir; // index of refraction

    static double reflectance(double cosine, double ref_idx);
};
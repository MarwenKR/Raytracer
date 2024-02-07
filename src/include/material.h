#pragma once

#include "hittable_list.h"
#include "utils.h"
#include "color.h"

class hit_record;

class material{
public:
    virtual ~material() = default;
    virtual bool scatter(const ray& r_in, const hit_record& rec, color& attenuation, ray& scattered) const = 0;  
};


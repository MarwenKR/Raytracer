#pragma once

#include "utils.h"
#include "ray.h"
#include "interval.h"

class material;
class hit_record{
    public:
        point3 p;
        vec3 normal;
        shared_ptr<material> mat;
        double t;
        bool front_face;

        void set_face_normal(const ray& r, const vec3& outward_normal) {
        // Sets the hit record normal vector.
        // `outward_normal` is assumed to have unit length.
        front_face = r.direction().dot( outward_normal) < 0;
        normal = front_face ? outward_normal : -outward_normal;
        }

};

class hittable{
    public:
        virtual ~hittable() = default;

        virtual bool hit(const ray& r, interval ray_t, hit_record& rec) const=0;
};

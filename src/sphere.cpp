#include <sphere.h>

sphere::sphere(point3 _center, double _radius, shared_ptr<material> _material)
    : center(_center), radius(_radius), mat(_material) {}

bool sphere::hit(const ray& r, interval ray_t, hit_record& rec) const {
    vec3 oc = r.origin() - center;
    double a = r.direction().dot( r.direction());
    double half_b = oc.dot( r.direction());
    double c = oc.squaredNorm() - radius * radius;
    double discriminant = half_b * half_b - a * c;
    
    if (discriminant < 0)
        return false;

    double sqrtd = std::sqrt(discriminant);
    double inv_a = 1/a;
    // find the nearest root in the range
    double root = (-half_b - sqrtd) * inv_a;
    if (!ray_t.surrounds(root)) {
        root = (-half_b + sqrtd) * inv_a;
        if (!ray_t.surrounds(root))
            return false;
    }


    rec.t = root;
    rec.p = r.at(rec.t);
    vec3 outward_normal = (rec.p - center) / radius;
    rec.set_face_normal(r, outward_normal);
    rec.mat = mat;
    return true;
}

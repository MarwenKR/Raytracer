#include <sphere.h>

sphere::sphere(point3 _center, double _radius, shared_ptr<material> _material)
    : center(_center), radius(_radius), mat(_material) {}

bool sphere::hit(const ray& r, interval ray_t, hit_record& rec) const {
    vec3 oc = r.origin() - center;
    auto a = r.direction().dot( r.direction());
    auto half_b = oc.dot( r.direction());
    auto c = oc.squaredNorm() - radius * radius;
    auto discriminant = half_b * half_b - a * c;
    if (discriminant < 0)
        return false;

    auto sqrtd = std::sqrt(discriminant);

    // find the nearest root in the range
    auto root = (-half_b - sqrtd) / a;
    if (!ray_t.surrounds(root)) {
        root = (-half_b + sqrtd) / a;
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

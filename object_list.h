// Stores a list of hittable_object(s) that are present in the scene.

#ifndef OBJECTLISTH
#define OBJECTLISTH

#include "hittable_object.h"

class object_list : public hittable_object {
    public:
        object_list() {};
        object_list(hittable_object **l, int size) : list(l), size(size) {};
        virtual bool hit(const ray&r, hit_record &rec) const;
        hittable_object **list;
        int size;
};

bool object_list::hit(const ray &r, hit_record &rec) const {
    bool hit = false;
    for (int i = 0; i < size; i++) {
        if(list[i]->hit(r, rec)) {
            hit = true;
        }
    }
    return hit;
}
#endif
/*
 * A vector (mathematical vector) implementation in ANSI C. Inspired by Roblox's
 * Vector object.
*/

#include <math.h>

#include "ct_vector.h"

struct CtVector3 ct_vector3_init(double x, double y, double z) {
    struct CtVector3 new_vector = {x, y, z};

    return new_vector;
}

int ct_vector3_compare(struct CtVector3 vector_a, struct CtVector3 vector_b) {
    if(vector_a.vec_x != vector_b.vec_x) {
        return 0;
    }

    if(vector_a.vec_y != vector_b.vec_y) {
        return 0;
    }

    if(vector_a.vec_z != vector_b.vec_z) {
        return 0;
    }

    return 1;
}

struct CtVector3 ct_vector3_add(struct CtVector3 a, struct CtVector3 b) {
    struct CtVector3 new_vector;

    new_vector.vec_x = a.vec_x + b.vec_x;
    new_vector.vec_y = a.vec_y + b.vec_y;
    new_vector.vec_z = a.vec_z + b.vec_z;

    return new_vector;
}

struct CtVector3 ct_vector3_subtract(struct CtVector3 a, struct CtVector3 b) {
    struct CtVector3 new_vector;

    new_vector.vec_x = a.vec_x - b.vec_x;
    new_vector.vec_y = a.vec_y - b.vec_y;
    new_vector.vec_z = a.vec_z - b.vec_z;

    return new_vector;
}

struct CtVector3 ct_vector3_multiply(struct CtVector3 a, struct CtVector3 b) {
    struct CtVector3 new_vector;

    new_vector.vec_x = a.vec_x * b.vec_x;
    new_vector.vec_y = a.vec_y * b.vec_y;
    new_vector.vec_z = a.vec_z * b.vec_z;

    return new_vector;
}

struct CtVector3 ct_vector3_divide(struct CtVector3 a, struct CtVector3 b) {
    struct CtVector3 new_vector;

    new_vector.vec_x = a.vec_x / b.vec_x;
    new_vector.vec_y = a.vec_y / b.vec_y;
    new_vector.vec_z = a.vec_z / b.vec_z;

    return new_vector;
}

struct CtVector3 ct_vector3_scale(struct CtVector3 vector, double scalar) {
    struct CtVector3 new_vector;

    new_vector.vec_x = vector.vec_x * scalar;
    new_vector.vec_y = vector.vec_y * scalar;
    new_vector.vec_z = vector.vec_z * scalar;

    return new_vector;
}

double ct_vector3_magnitude(struct CtVector3 vector) {
    return sqrt(pow(vector.vec_x, 2) +
                pow(vector.vec_y, 2) +
                pow(vector.vec_z, 2));
}

struct CtVector3 ct_vector3_unit(struct CtVector3 vector) {
    double vector_magnitude = ct_vector3_magnitude(vector);

    return ct_vector3_divide(vector, ct_vector3_init(vector_magnitude,
                                                     vector_magnitude,
                                                     vector_magnitude));
}

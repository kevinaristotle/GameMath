#ifndef GAMEMATH_VECTOR_H
#define GAMEMATH_VECTOR_H

#include <math.h>

typedef struct {
    float x, y, z;
} Vector3f;

Vector3f vector3f_add(Vector3f v1, Vector3f v2) {
    Vector3f sum = {
        v1.x + v2.x,
        v1.y + v2.y,
        v1.z + v2.z
    };

    return sum;
}

Vector3f vector3f_sub(Vector3f v1, Vector3f v2) {
    Vector3f diff = {
        v1.x - v2.x,
        v1.y - v2.y,
        v1.z - v2.z
    };

    return diff;
}

Vector3f vector3f_mul(Vector3f v, float scalar) {
    Vector3f scaled = {
        v.x * scalar,
        v.y * scalar,
        v.z * scalar
    };

    return scaled;
}

float vector3f_dot(Vector3f v1, Vector3f v2) {
    return v1.x * v2.x + v1.y * v2.y + v1.z * v2.z;
}

float vector3f_length(Vector3f v) {
    return sqrt(v.x * v.x + v.y * v.y + v.z * v.z);
}

float vector3f_length_squared(Vector3f v) {
    return v.x * v.x + v.y * v.y + v.z * v.z;
}

float vector3f_distance(Vector3f v1, Vector3f v2) {
    float dx = v2.x - v1.x;
    float dy = v2.y - v1.y;
    float dz = v2.z - v1.z;

    return sqrt(dx * dx + dy * dy + dz * dz);
}

float vector3f_distance_squared(Vector3f v1, Vector3f v2) {
    float dx = v2.x - v1.x;
    float dy = v2.y - v1.y;
    float dz = v2.z - v1.z;

    return dx * dx + dy * dy + dz * dz;
}

Vector3f vector3f_nomalized(Vector3f v) {
    float length = vector3f_length(v);

    Vector3f normalized = {
        v.x / length,
        v.y / length,
        v.z / length
    };

    return normalized;
}

Vector3f vector3f_lerp(Vector3f start, Vector3f end, float amount) {
    Vector3f start_portion = vector3f_mul(start, 1.0f - amount);
    Vector3f end_portion = vector3f_mul(end, amount);

    return vector3f_add(start_portion, end_portion);
}

#endif

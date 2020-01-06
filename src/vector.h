#ifndef GAMEMATH_VECTOR_H
#define GAMEMATH_VECTOR_H

#include <math.h>
#include "matrix.h"

typedef struct {
    float x, y, z;
} Vector3f;

typedef struct {
    float x, y, z, w;
} Vector4f;

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

Vector3f vector3f_cross(Vector3f a, Vector3f b) {
    Vector3f c = {
        a.y * b.z - a.z * b.y,
        a.z * b.x - a.x * b.z,
        a.x * b.y - a.y * b.x
    };

    return c;
}

Vector3f vector3f_lerp(Vector3f start, Vector3f end, float amount) {
    Vector3f start_portion = vector3f_mul(start, 1.0f - amount);
    Vector3f end_portion = vector3f_mul(end, amount);

    return vector3f_add(start_portion, end_portion);
}

int vector3f_is_unit(Vector3f v) {
    return vector3f_length(v) == 1.0f;
}

Vector4f vector4f_mul(Vector4f v, float scalar) {
    Vector4f scaled = {
        v.x * scalar,
        v.y * scalar,
        v.z * scalar,
        v.w * scalar
    };

    return scaled;
}

Vector4f vector4f_mul_matrix4x4(Vector4f v, Matrix4x4 m) {
    Vector4f o;
    o.x = v.x * m.m[0][0] + v.y * m.m[1][0] + v.z * m.m[2][0] + v.w * m.m[3][0];
    o.y = v.x * m.m[0][1] + v.y * m.m[1][1] + v.z * m.m[2][1] + v.w * m.m[3][1];
    o.z = v.x * m.m[0][2] + v.y * m.m[1][2] + v.z * m.m[2][2] + v.w * m.m[3][2];
    o.w = v.x * m.m[0][3] + v.y * m.m[1][3] + v.z * m.m[2][3] + v.w * m.m[3][3];
    return o;
}

#endif

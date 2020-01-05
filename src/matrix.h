#ifndef GAMEMATH_MATRIX_H
#define GAMEMATH_MATRIX_H

#include <math.h>

typedef struct {
    float m[4][4];
} Matrix4x4;

Matrix4x4 matrix4x4_zero() {
    Matrix4x4 m = {
        0.0f, 0.0f, 0.0f, 0.0f,
        0.0f, 0.0f, 0.0f, 0.0f,
        0.0f, 0.0f, 0.0f, 0.0f,
        0.0f, 0.0f, 0.0f, 0.0f
    };

    return m;
}

Matrix4x4 matrix4x4_identity() {
    Matrix4x4 m = {
        1.0f, 0.0f, 0.0f, 0.0f,
        0.0f, 1.0f, 0.0f, 0.0f,
        0.0f, 0.0f, 1.0f, 0.0f,
        0.0f, 0.0f, 0.0f, 1.0f
    };

    return m;
}

Matrix4x4 matrix4x4_translation(float x, float y, float z) {
    Matrix4x4 m = {
        1.0f, 0.0f, 0.0f, 0.0f,
        0.0f, 1.0f, 0.0f, 0.0f,
        0.0f, 0.0f, 1.0f, 0.0f,
           x,    y,    z, 1.0f
    };

    return m;
}

Matrix4x4 matrix4x4_rotation_x(float rads) {
    Matrix4x4 m = {
        1.0f,              0.0f,             0.0f, 0.0f,
        0.0f, (float) cos(rads), (float)sin(rads), 0.0f,
        0.0f, (float)-sin(rads), (float)cos(rads), 0.0f,
        0.0f,              0.0f,             0.0f, 1.0f
    };

    return m;
}

Matrix4x4 matrix4x4_rotation_y(float rads) {
    Matrix4x4 m = {
        (float)cos(rads), 0.0f, (float)-sin(rads), 0.0f,
                    0.0f, 1.0f,              0.0f, 0.0f,
        (float)sin(rads), 0.0f, (float) cos(rads), 0.0f,
                    0.0f, 0.0f,              0.0f, 1.0f
    };

    return m;
}

Matrix4x4 matrix4x4_rotation_z(float rads) {
    Matrix4x4 m = {
        (float) cos(rads), (float)sin(rads), 0.0f, 0.0f,
        (float)-sin(rads), (float)cos(rads), 0.0f, 0.0f,
                     0.0f,             0.0f, 1.0f, 0.0f,
                     0.0f,             0.0f, 0.0f, 1.0f
    };
    return m;
}

Matrix4x4 matrix4x4_scale(float x, float y, float z) {
    Matrix4x4 m = {
           x, 0.0f, 0.0f, 0.0f,
        0.0f,    y, 0.0f, 0.0f,
        0.0f, 0.0f,    z, 0.0f,
        0.0f, 0.0f, 0.0f, 1.0f
    };

    return m;
}

Matrix4x4 matrix4x4_projection_orthographic(float width, float height, float near_clip, float far_clip) {
    float a = 2.0f / width;
    float b = 2.0f / height;
    float c = 1.0f / (far_clip - near_clip);
    float d = -near_clip / (far_clip - near_clip);

    Matrix4x4 m = {
           a, 0.0f, 0.0f, 0.0f,
        0.0f,    b, 0.0f, 0.0f,
        0.0f, 0.0f,    c, 0.0f,
        0.0f, 0.0f,    d, 1.0f
    };

    return m;
}

Matrix4x4 matrix4x4_viewport_scale(float x, float y, float width, float height) {
    float hw = width / 2;
    float hh =  height / 2;
    
    Matrix4x4 m = {
            hw,   0.0f, 0.0f, 0.0f,
          0.0f,    -hh, 0.0f, 0.0f,
          0.0f,   0.0f, 1.0f, 0.0f,
        hw + x, hh + y, 0.0f, 1.0f
    };

    return m;
}

Matrix4x4 matrix4x4_mul_matrix4x4(Matrix4x4 a, Matrix4x4 b) {
    Matrix4x4 m = matrix4x4_zero();

    int i, j, k;
    for(i = 0; i < 4; i++) {
        for(j = 0; j < 4; j++) {
            for(k = 0; k < 4; k++) {
                m.m[i][j] += a.m[i][k] * b.m[k][j];
            }
        }
    }

    return m;
}

#endif

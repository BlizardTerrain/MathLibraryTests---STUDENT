#pragma once

namespace MathClasses
{
#include "Vector3.h"
#include <string>
    struct Matrix3
    {
        union {
            // as individual floats
            struct {
                float m1, m2, m3, m4, m5, m6, m7, m8, m9;
            };

            // as a 1-D array
            float v[9];

            // as a 2-D array
            float mm[3][3];

            // as Vector3s
            Vector3 axis[3];
        };

        // Default constructor - zero initializes all values
        Matrix3() {
            m1 = m2 = m3 = m4 = m5 = m6 = m7 = m8 = m9 = 0.0f;
        }

        static Matrix3 MakeIdentity()
        {
            Matrix3 identity;
            identity.m1 = 1;
            identity.m2 = 0;
            identity.m3 = 0;

            identity.m4 = 0;
            identity.m5 = 1;
            identity.m6 = 0;

            identity.m7 = 0;
            identity.m8 = 0;
            identity.m9 = 1;

            return identity;
        }

        // mutable access to each element
        float& operator [](int dim) {
            return v[dim];
        }

        // const-qualified access to each element
        const float& operator [](int dim) const {
            return v[dim];
        }

        // TODO:  implement both iterations of the operator, for use on mutable and const-qualified matrices.

        Matrix3 operator *(Matrix3 rhs) const {
            // TODO

            Matrix3 result;

            // iterate through first matrix
            for (size_t i = 0; i < 3; ++i) {
                // current row from first matrix
                Vector3 row(mm[0][i], mm[1][i], mm[2][i]);

                // iterate through columns in the second matrix
                for (size_t j = 0; j < 3; ++j) {
                    // current column from the second matrix
                    rhs.axis[j];
                }
            }
            return result;
        }

        Matrix3 operator *(Matrix3 rhs) const {
            return Matrix3(
                m1 * rhs.m1 + m4 * rhs.m2 + m7 * rhs.m3,
                m2 * rhs.m1 + m5 * rhs.m2 + m8 * rhs.m3,
                m3 * rhs.m1 + m6 * rhs.m2 + m9 * rhs.m3,

                m1 * rhs.m4 + m4 * rhs.m5 + m7 * rhs.m6,
                m2 * rhs.m4 + m5 * rhs.m5 + m8 * rhs.m6,
                m3 * rhs.m4 + m6 * rhs.m5 + m9 * rhs.m6,

                m1 * rhs.m7 + m4 * rhs.m8 + m7 * rhs.m9,
                m2 * rhs.m7 + m5 * rhs.m8 + m8 * rhs.m9,
                m3 * rhs.m7 + m6 * rhs.m8 + m9 * rhs.m9);
        }

        Vector3 operator *(Vector3 rhs) const {
            return Vector3(
                Vector3(m1, m4, m7).Dot(rhs),
                Vector3(m2, m5, m8).Dot(rhs),
                Vector3(m3, m6, m9).Dot(rhs)
            );
        }

        Matrix3 Transposed() const {
            return Matrix3(m1, m4, m7, m2, m5, m8, m3, m6, m9);
        }

        std::string ToString() const {
            std::string str = std::to_string(v[0]);
            for (size_t i = 1; i < 9; ++i) {
                str += "," + std::to_string(v[i]);
            }
            return str;
        }

        //
        // MATRIX TRANSFORMATIONS
        //

        static Matrix3 MakeRotateX(float a) {
            return Matrix3(1, 0, 0,
                0, cosf(a), -sinf(a),
                0, sinf(a), cosf(a));
        }

        static Matrix3 MakeRotateY(float a) {
            return Matrix3(cosf(a), 0, -sinf(a),
                0, 1, 0,
                sinf(a), 0, cosf(a));
        }

        static Matrix3 MakeRotateZ(float a) {
            return Matrix3(cosf(a), sinf(a), 0,
                -sinf(a), cosf(a), 0,
                0, 0, 1);
        }

        Matrix3 modelMatrix = Matrix3::MakeIdentity();
        
        // rotate this by 3 units on the x-axis
        modelMatrix *= Matrix3::MakeRoateX(3.0f);

        static Matrix3 MakeEuler(float pitch, float yaw, float roll) {
            Matrix3 x = MakeRotateX(pitch);
            Matrix3 y = MakeRotateY(yaw);
            Matrix3 z = MakeRotateZ(roll);
            // combine rotations in a specific order
            return (z * y * x);
        }

        static Matrix3 MakeScale(float xScale, float yScale, float zScale) {
            return Matrix3(xScale, 0.0f, 0.0f,
                0.0f, yScale, 0.0f,
                0.0f, 0.0f, zScale);
        }

        static Matrix3 MakeScale(Vector3 scale) {
            // just reuses the above function
            return MakeScale(scale.x, scale.y, scale.z);
        }

        Matrix3 modelMatrix = Matrix3::MakeIdentity();

        // scale this model by 3 on all axes
        modelMatrix *= Matrix3::MakeScale(3, 3, 3);

        //
        // Homogenous Transforms
        //

        class Vector3 {
        public:
            union {
                struct {
                    float x, y;
                    union {
                        float z, w;
                    };
                };
                float data[3];
            };
        };

        
    };
} 
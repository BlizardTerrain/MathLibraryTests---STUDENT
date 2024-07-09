#pragma once

namespace MathClasses
{
#include "Vector3.h"
#include <string>
	using namespace std;

    struct Matrix3
    {
        union {
            // as individual floats
            struct
            {
                float m1, m2, m3, m4, m5, m6, m7, m8, m9;
            };

            // as a 1-D array
            float v[9];

            // as a 2-D array
            float mm[3][3];

            // as Vector3's
            Vector3 axis[3];
        };

        // Default Constructor - zero initializes all values
        Matrix3() {
            m1 = m2 = m3 = m4 = m5 = m6 = m7 = m8 = m9 = 0.0f;
        }

        // Constructor using const m1 - m9
        Matrix3(const float m1, const float m2, const float m3, const float m4, const float m5, const float m6, const float m7, const float m8, const float m9) {
            this->m1 = m1;
            this->m2 = m2;
            this->m3 = m3;
            this->m4 = m4;
            this->m5 = m5;
            this->m6 = m6;
            this->m7 = m7;
            this->m8 = m8;
            this->m9 = m9;
        }

        static Matrix3 MakeIdentity() {
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

        //
        // Maths Operators

        // operator +=
        Matrix3& operator +=(const Matrix3& rhs)
        {
	        for (int i = 0; i < 9; i++)
	        {
                v[i] += rhs.v[i];
	        }
            return *this;
        }

        // operator -=
		Matrix3& operator -=(const Matrix3& rhs)
		{
			for (int i = 0; i < 9; i++)
			{
				v[i] -= rhs.v[i];
			}
			return *this;
		}

        // operator *=
        Matrix3& operator *=(const Matrix3& rhs)
        {
            *this = *this * rhs;
            return *this;
        }

        // operator /=
        Matrix3& operator /=(const float rhs)
        {
	        for (int i = 0; i < 9; ++i)
	        {
                v[i] /= rhs;
	        }
            return *this;
        }

        // operator ==(Matrix, Matrix)
        bool operator ==(const Matrix3& rhs) const
        {
	        for (int i = 0; i < 9; i++)
	        {
		        if(fabs(v[i] - rhs.v[i]) > 1e-6f)
		        {
                    return false;
		        }
	        }
            return true;
        }

        // operator !=(Matrix, Matrix)
        bool operator !=(const Matrix3& rhs) const
        {
            return !(*this == rhs);
        }

        // Matrix Multiplication
        Matrix3 operator *(const Matrix3 rhs) const {
            // stores the return value
            Matrix3 result;

            // iterate through first matrix
            for (size_t i = 0; i < 3; ++i) {
                // current row from first matrix
                Vector3 row(mm[0][i], mm[1][i], mm[2][i]);

                // iterate through columns in the second matrix
                for (size_t j = 0; j < 3; ++j) {
                    // dot each row with each column and assign to result matrix
                    // result is calculated row-by-row
                    result.mm[j][i] = row.Dot(rhs.axis[j]);
                }
            }
            return result;
        }

        //
        // Matrix Multiplication against a Vector

        Vector3 operator *(const Vector3 rhs) const {
            return Vector3(
                Vector3(m1, m4, m7).Dot(rhs),
                Vector3(m2, m5, m8).Dot(rhs),
                Vector3(m3, m6, m9).Dot(rhs)
            );
        }

        //
        // Matrix Transposition
        Matrix3 Transposed() const {
            return Matrix3(m1, m4, m7, m2, m5, m8, m3, m6, m9);
        }

        //
        // ToString

        string ToString() const {
            string str = to_string(v[0]);
            for (size_t i = 1; i < 9; ++i) {
                str += ", " + to_string(v[i]);
            }
            return str;
        }

        //
        // Matrix Transformations
        //

        // Rotate X-axis
        static Matrix3 MakeRotateX(float a) {
            return Matrix3(1, 0, 0, 
                0, cosf(a), -sinf(a), 
                0, sinf(a), cosf(a));
        }

        // Rotate Y-axis
        static Matrix3 MakeRotateY(float a) {
            return Matrix3(cosf(a), 0, -sinf(a), 
                0, 1, 0, 
                sinf(a), 0, cosf(a));
        }

        // Rotate Z-axis
        static Matrix3 MakeRotateZ(float a) {
            return Matrix3(cosf(a), sinf(a), 0, 
                -sinf(a), cosf(a), 0, 
                0, 0, 1);
        }

        //
        //Rotate an existing Matrix

        static Matrix3 MakeRotatedIdentity(float angle) {
            Matrix3 modelMatrix = Matrix3::MakeIdentity();
            modelMatrix *= Matrix3::MakeRotateX(angle);
            return modelMatrix;
        }

        //
        // Euler Angle Rotations

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
            // reuses the function above
            return MakeScale(scale.x, scale.y, scale.z);
        }

        static Matrix3 MakeScale(float xScale, float yScale)
        {
            return Matrix3(xScale, 0.0f, 0.0f,
                0.0f, yScale, 0.0f,
                0.0f, 0.0f, 1.0f);
        }


        static Matrix3 MakeTranslation(float x, float y, float z) {
            Matrix3 result = MakeIdentity();
            result.m7 = x;
            result.m8 = y;
            result.m9 = z;
            return result;
        }

        static Matrix3 MakeTranslation(Vector3 vec) {
            return MakeTranslation(vec.x, vec.y, vec.z);
        }

        static Matrix3 MakeEuler(Vector3 rot) {
            return MakeEuler(rot.x, rot.y, rot.z);
        }
    };
}
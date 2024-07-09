#pragma once
namespace MathClasses
{
#include "Vector4.h"
#include <string>
    using namespace std;

	struct Matrix4
	{
		union
		{
			// as individual floats
			struct
			{
				float m1, m2, m3, m4, m5, m6, m7, m8, m9, m10, m11, m12, m13, m14, m15, m16;
			};

			// as a 1-D array
			float v[16];

			// as a 2-D array
			float mm[4][4];

			// as Vector4's
			Vector4 axis[4];
		};

		// Default Constructor - zero initializes all values
		Matrix4()
		{
			m1 = m2 = m3 = m4 = m5 = m6 = m7 = m8 = m9 = m10 = m11 = m12 = m13 = m14 = m15 = m16 = 0.0f;
		}

		// Constructor using const m1 - m16
		Matrix4(const float m1, const float m2, const float m3, const float m4, const float m5, const float m6, const float m7, const float m8, const float m9, const float m10, const float m11, const float m12, const float m13, const float m14, const float m15, const float m16)
		{
			this->m1 = m1;
			this->m2 = m2;
			this->m3 = m3;
			this->m4 = m4;
			this->m5 = m5;
			this->m6 = m6;
			this->m7 = m7;
			this->m8 = m8;
			this->m9 = m9;
			this->m10 = m10;
			this->m11 = m11;
			this->m12 = m12;
			this->m13 = m13;
			this->m14 = m14;
			this->m15 = m15;
			this->m16 = m16;
		}

		static Matrix4 MakeIdentity()
		{
			Matrix4 identity;
			identity.m1 = 1;
			identity.m2 = 0;
			identity.m3 = 0;
			identity.m4 = 0;

			identity.m5 = 0;
			identity.m6 = 1;
			identity.m7 = 0;
			identity.m8 = 0;

			identity.m9 = 0;
			identity.m10 = 0;
			identity.m11 = 1;
			identity.m12 = 0;

			identity.m13 = 0;
			identity.m14 = 0;
			identity.m15 = 0;
			identity.m16 = 1;

			return identity;
		}

		// mutable access to each element
		float& operator [](int dim)
		{
			return v[dim];
		}

		// const-qualified access to each element
		const float& operator [](int dim) const
		{
			return v[dim];
		}

		//
		// Maths Operators

		// operator +=
		Matrix4& operator +=(const Matrix3& rhs)
		{
			for (int i = 0; i < 16; i++)
			{
				v[i += rhs.v[i]];
			}
			return *this;
		}

		// operator -=
		Matrix4& operator -=(const Matrix4& rhs)
		{
			for (int i = 0; i < 16; i++)
			{
				v[i] -= rhs.v[i];
			}
			return *this;
		}

		// operator *=
		Matrix4& operator *=(const Matrix4& rhs)
		{
			*this = *this * rhs;
			return *this;
		}

		// operator /=
		Matrix4& operator /=(const float rhs)
		{
			for (int i = 0; i < 16; i++)
			{
				v[i] /= rhs;
			}
			return *this;
		}

		// operator ==(Matrix, Matrix)
		bool operator ==(const Matrix4& rhs) const
		{
			for (int i = 0; i < 9; i++)
			{
				if (fabs(v[i] - rhs.v[i]) > 1e-6f)
				{
					return false;
				}
			}
			return true;
		}

		// operator !=(matrix, matrix)
		bool operator !=(const Matrix4& rhs) const
		{
			return !(*this == rhs);
		}

		// Matrix Multiplication
		Matrix4 operator *(const Matrix4 rhs) const
		{
			// stores the return value
			Matrix4 result;

			// iterate through first matrix
			for (size_t i = 0; i < 4; ++i)
			{
				// current row from first matrix
				Vector4 row(mm[0][i], mm[1][i], mm[2][i]);

				// iterate through columns in the second matrix
				for (size_t j = 0; j < 4; ++j)
				{
					// dot each row with each column and assign to result matrix
					// result is calculated row-by-row
					result.mm[j][i] = row.Dot(rhs.axis[j]);
				}
			}
			return result;
		}

		// Matrix Multiplication against a Vector
		Vector4 operator *(const Vector4 rhs) const
		{
			return Vector4(
				Vector4(m1, m5, m9, m13).Dot(rhs),
				Vector4(m2, m6, m10, m14).Dot(rhs),
				Vector4(m3, m7, m11, m15).Dot(rhs),
				Vector4(m4, m8, m12, m16).Dot(rhs)
			);
		}

		//
		// Matrix4 Transposition
		Matrix4 Transposed() const
		{
			return Matrix4(m1, m5, m9, m13, m2, m6, m10, m14, m3, m7, m11, m15, m4, m8, m12, m16);
		}

		//
		// ToString
		string ToString() const
		{
			string str = to_string(v[0]);
			for (size_t i = 1; i < 16; ++i)
			{
				str += "," + to_string(v[i]);
			}
			return str;
		}

		//
		// Matrix transformations
		//

		// Rotate X-axis
		static Matrix4 MakeRotateX(float a)
		{
			return Matrix4(1, 0, 0, 0,
				0, cosf(a), -sinf(a), 0,
				0, sinf(a), cosf(a), 0,
				0, 0, 0, 1);
		}

		// Rotate y-axis
		static Matrix4 MakeRotateY(float a)
		{
			return Matrix4(cosf(a), 0, -sinf(a), 0,
				0, 1, 0, 0,
				sinf(a), 0, cosf(a), 0,
				0, 0, 0, 1);
		}

		// Rotate z-axis
		static Matrix4 MakeRotateZ(float a)
		{
			return Matrix4(cosf(a), sinf(a), 0, 0,
				-sinf(a), cosf(a), 0, 0,
				0, 0, 1, 0,
				0, 0, 0, 1);
		}
	};
}

/*
#pragma once

namespace MathClasses
{
#include "Vector4.h"
#include <string>
	using namespace std;

	struct Matrix4
	{
		union {
			// as individual floats
			struct
			{
				float m1, m2, m3, m4, m5, m6, m7, m8, m9, m10, m11, m12, m13, m14, m15, m16;
			};

			// as a 1-D array
			float v[16];

			// as a 2-D array
			float mm[4][4];

			// as Vector4's
			Vector4 axis[4];
		};

		// Default Constructor - zero initializes all values
		Matrix4() {
			m1 = m2 = m3 = m4 = m5 = m6 = m7 = m8 = m9 = m10 = m11 = m12 = m13 = m14 = m15 = m16 = 0.0f;
		}

		// Constructor using const m1 - m16
		Matrix4(const float m1, const float m2, const float m3, const float m4,
				const float m5, const float m6, const float m7, const float m8,
				const float m9, const float m10, const float m11, const float m12,
				const float m13, const float m14, const float m15, const float m16) {
			this->m1 = m1;
			this->m2 = m2;
			this->m3 = m3;
			this->m4 = m4;
			this->m5 = m5;
			this->m6 = m6;
			this->m7 = m7;
			this->m8 = m8;
			this->m9 = m9;
			this->m10 = m10;
			this->m11 = m11;
			this->m12 = m12;
			this->m13 = m13;
			this->m14 = m14;
			this->m15 = m15;
			this->m16 = m16;
		}

		static Matrix4 MakeIdentity() {
			Matrix4 identity;
			identity.m1 = 1;
			identity.m2 = 0;
			identity.m3 = 0;
			identity.m4 = 0;

			identity.m5 = 0;
			identity.m6 = 1;
			identity.m7 = 0;
			identity.m8 = 0;

			identity.m9 = 0;
			identity.m10 = 0;
			identity.m11 = 1;
			identity.m12 = 0;

			identity.m13 = 0;
			identity.m14 = 0;
			identity.m15 = 0;
			identity.m16 = 1;

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
		Matrix4& operator +=(const Matrix4& rhs)
		{
			for (int i = 0; i < 16; i++)
			{
				v[i] += rhs.v[i];
			}
			return *this;
		}

		// operator -=
		Matrix4& operator -=(const Matrix4& rhs)
		{
			for (int i = 0; i < 16; i++)
			{
				v[i] -= rhs.v[i];
			}
			return *this;
		}

		// operator *=
		Matrix4& operator *=(const Matrix4& rhs)
		{
			*this = *this * rhs;
			return *this;
		}

		// operator /=
		Matrix4& operator /=(const float rhs)
		{
			for (int i = 0; i < 16; ++i)
			{
				v[i] /= rhs;
			}
			return *this;
		}

		// operator ==(Matrix, Matrix)
		bool operator ==(const Matrix4& rhs) const
		{
			for (int i = 0; i < 16; i++)
			{
				if(fabs(v[i] - rhs.v[i]) > 1e-6f)
				{
					return false;
				}
			}
			return true;
		}

		// operator !=(Matrix, Matrix)
		bool operator !=(const Matrix4& rhs) const
		{
			return !(*this == rhs);
		}

		// Matrix Multiplication
		Matrix4 operator *(const Matrix4 rhs) const {
			// stores the return value
			Matrix4 result;

			// iterate through first matrix
			for (size_t i = 0; i < 4; ++i) {
				// current row from first matrix
				Vector4 row(mm[0][i], mm[1][i], mm[2][i], mm[3][i]);

				// iterate through columns in the second matrix
				for (size_t j = 0; j < 4; ++j) {
					// dot each row with each column and assign to result matrix
					// result is calculated row-by-row
					result.mm[j][i] = row.Dot(rhs.axis[j]);
				}
			}
			return result;
		}

		//
		// Matrix Multiplication against a Vector

		Vector4 operator *(const Vector4 rhs) const {
			return Vector4(
				Vector4(m1, m5, m9, m13).Dot(rhs),
				Vector4(m2, m6, m10, m14).Dot(rhs),
				Vector4(m3, m7, m11, m15).Dot(rhs),
				Vector4(m4, m8, m12, m16).Dot(rhs)
			);
		}

		//
		// Matrix Transposition
		Matrix4 Transposed() const {
			return Matrix4(m1, m5, m9, m13,
						   m2, m6, m10, m14,
						   m3, m7, m11, m15,
						   m4, m8, m12, m16);
		}

		//
		// ToString

		string ToString() const {
			string str = to_string(v[0]);
			for (size_t i = 1; i < 16; ++i) {
				str += ", " + to_string(v[i]);
			}
			return str;
		}

		//
		// Matrix Transformations
		//

		// Rotate X-axis
		static Matrix4 MakeRotateX(float a) {
			return Matrix4(1, 0, 0, 0,
						   0, cosf(a), -sinf(a), 0,
						   0, sinf(a), cosf(a), 0,
						   0, 0, 0, 1);
		}

		// Rotate Y-axis
		static Matrix4 MakeRotateY(float a) {
			return Matrix4(cosf(a), 0, sinf(a), 0,
						   0, 1, 0, 0,
						   -sinf(a), 0, cosf(a), 0,
						   0, 0, 0, 1);
		}

		// Rotate Z-axis
		static Matrix4 MakeRotateZ(float a) {
			return Matrix4(cosf(a), -sinf(a), 0, 0,
						   sinf(a), cosf(a), 0, 0,
						   0, 0, 1, 0,
						   0, 0, 0, 1);
		}

		//
		//Rotate an existing Matrix

		static Matrix4 MakeRotatedIdentity(float angle) {
			Matrix4 modelMatrix = Matrix4::MakeIdentity();
			modelMatrix *= Matrix4::MakeRotateX(angle);
			return modelMatrix;
		}

		//
		// Euler Angle Rotations

		static Matrix4 MakeEuler(float pitch, float yaw, float roll) {
			Matrix4 x = MakeRotateX(pitch);
			Matrix4 y = MakeRotateY(yaw);
			Matrix4 z = MakeRotateZ(roll);

			// combine rotations in a specific order
			return (z * y * x);
		}

		static Matrix4 MakeScale(float xScale, float yScale, float zScale) {
			return Matrix4(xScale, 0.0f, 0.0f, 0.0f,
						   0.0f, yScale, 0.0f, 0.0f,
						   0.0f, 0.0f, zScale, 0.0f,
						   0.0f, 0.0f, 0.0f, 1.0f);
		}

		static Matrix4 MakeScale(Vector4 scale) {
			// reuses the function above
			return MakeScale(scale.x, scale.y, scale.z);
		}

		static Matrix4 MakeScale(float xScale, float yScale)
		{
			return Matrix4(xScale, 0.0f, 0.0f, 0.0f,
						   0.0f, yScale, 0.0f, 0.0f,
						   0.0f, 0.0f, 1.0f, 0.0f,
						   0.0f, 0.0f, 0.0f, 1.0f);
		}


		static Matrix4 MakeTranslation(float x, float y, float z) {
			Matrix4 result = MakeIdentity();
			result.m13 = x;
			result.m14 = y;
			result.m15 = z;
			return result;
		}

		static Matrix4 MakeTranslation(Vector4 vec) {
			return MakeTranslation(vec.x, vec.y, vec.z);
		}

		static Matrix4 MakeEuler(Vector4 rot) {
			return MakeEuler(rot.x, rot.y, rot.z);
		}
	};
}

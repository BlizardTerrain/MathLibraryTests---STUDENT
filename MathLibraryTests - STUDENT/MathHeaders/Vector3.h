#pragma once
#include <string>

namespace MathClasses
{
    //
    // POINTS AND VECTORS
    //
    struct Vector3
    {
        float x, y, z;

        // Default constructor
        Vector3() : x{ 0 }, y{ 0 }, z{ 0 } {}

        Vector3(float x, float y, float z) : x{ x }, y{ y }, z{ z } {}

        union {
            struct { float x, y, z; }; // 12-bytes
            float data[3]; // 12-bytes
        };

        float& operator [](int dim)
        {
            return data[dim];
        }

        const  float& operator [](int dim) const
        {
            return data[dim];
        }

        // cast to float array
        operator float* () { return data; }

        // cast to float array - const-qualified
        operator const float* () const { return data; }

        // operator + (Vector, Vector)
        Vector3 operator +(const Vector3& rhs) const {
            Vector3 sum;

            sum.x = x + rhs.x;
            sum.y = y + rhs.y;
            sum.z = z + rhs.z;
            return sum;
        }

        // operator - (Vector, Vector)
        Vector3 operator -(const Vector3& rhs) const {
            Vector3 sum;

            sum.x = x - rhs.x;
            sum.y = y - rhs.y;
            sum.z = z - rhs.z;
            return sum;
        }

        // operator * (Vector, float)
        Vector3 operator *(float rhs) const {
            Vector3 sum;

            sum.x = x * rhs;
            sum.y = y * rhs;
            sum.z = z * rhs;
            return sum;
        }

        // operator * (float, Vector)
        Vector3 operator *(const Vector3& rhs) const {
            Vector3 sum;

            sum.x = x * rhs.x;
            sum.y = y * rhs.y;
            sum.z = z * rhs.z;
            return sum;
        }

        // operator / (Vector, float)
        Vector3 operator /(float rhs) const {
            Vector3 sum;

            sum.x = x / rhs;
            sum.y = y / rhs;
            sum.z = z / rhs;
            return sum;
        }

        // +=
        Vector3 operator +=(const Vector3& rhs) {
            x += rhs.x;
            y += rhs.y;
            z += rhs.z;
            return *this;
        }

        // -=)
        Vector3 operator -=(const Vector3& rhs) {
            x -= rhs.x;
            y -= rhs.y;
            z -= rhs.z;
            return *this;
        }

        // *=
        Vector3 operator *=(float rhs) {
            x *= rhs;
            y *= rhs;
            z *= rhs;
            return *this;
        }

        // /=
        Vector3 operator /=(float rhs) {
            x /= rhs;
            y /= rhs;
            z /= rhs;
            return *this;
        }

        bool operator == (const Vector3& rhs) const
        {
            float xDist = fabsf(x - rhs.x);
            float yDist = fabsf(y - rhs.y);
            float zDist = fabsf(z - rhs.z);

            const float THRESHOLD = 0.00001f;

            return xDist < THRESHOLD && yDist < THRESHOLD && zDist < THRESHOLD;
        }

        bool operator != (const Vector3& rhs) const
        {
            return !(*this == rhs);
        }

        std::string ToString() const {
            return std::to_string(x) + ", " + std::to_string(y) + ", " + std::to_string(z);
        }

        //
        // MAGNITUDE & NORMALISATION
        //

        float Magnitude() const {
            return sqrtf(x * x + y * y + z * z);
        }

        float MagnitudeSqr() const {
            return x * x + y * y + z * z;
        }

        float Distance(const Vector3& other) const {
            return (*this - other).Magnitude();
        }

        // Normalise the vector
        void Normalise() {
            float m = Magnitude();

            x /= m;
            y /= m;
            z /= m;
        }

        // Returns a normalised copy of the Vector
        Vector3 Normalised() const {
            Vector3 copy = *this;
            copy.Normalise();

            return copy;
        }

        //
        // DOT & CROSS PRODUCT
        //

        float Dot(const Vector3& other) {
            return x * other.x + y * other.y + z * other.z;
        }

        Vector3 Vector3::Cross(const Vector3& other) {
            return Vector3(y * other.z - z * other.y,
                z * other.x - x * other.z,
                x * other.y - y * other.x);
        }

        float AngleBetween(const Vector3& other) const {
            // normalise the vectors
            Vector3 a = Normalised();
            Vector3 b = other.Normalised();

            // calculate the dot product
            float d = a.Dot(other);

            // return the angle between them
            return acosf(d);
        }
    };
}
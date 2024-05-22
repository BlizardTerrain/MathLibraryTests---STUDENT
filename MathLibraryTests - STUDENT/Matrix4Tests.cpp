#include "CppUnitTest.h"
#include "TestToString.h"

#include "Utils.h"
#include "MathHeaders/Matrix4.h"

using namespace Microsoft::VisualStudio::CppUnitTestFramework;
using ::MathClasses::Matrix4;
using ::MathClasses::Vector4;

namespace MathLibraryTests
{
    TEST_CLASS(Matrix4Tests)
    {
    public:
        // default constructor
        TEST_METHOD(Constructor)
        {
            Matrix4 mat;

            Assert::AreEqual(0.f, mat.m1);
            Assert::AreEqual(0.f, mat.m2);
            Assert::AreEqual(0.f, mat.m3);
            Assert::AreEqual(0.f, mat.m4);

            Assert::AreEqual(0.f, mat.m5);
            Assert::AreEqual(0.f, mat.m6);
            Assert::AreEqual(0.f, mat.m7);
            Assert::AreEqual(0.f, mat.m8);

            Assert::AreEqual(0.f, mat.m9);
            Assert::AreEqual(0.f, mat.m10);
            Assert::AreEqual(0.f, mat.m11);
            Assert::AreEqual(0.f, mat.m12);


            Assert::AreEqual(0.f, mat.m13);
            Assert::AreEqual(0.f, mat.m14);
            Assert::AreEqual(0.f, mat.m15);
            Assert::AreEqual(0.f, mat.m16);
        }
        // parameterized constructor (individual)
        TEST_METHOD(ConstructorParamFloats)
        {
            Matrix4 mat(1.0f, 2.0f, 3.0f, 4.0f,
                5.0f, 6.0f, 7.0f, 8.0f,
                9.0f, 10.0f, 11.0f, 12.0f,
                13.0f, 14.0f, 15.0f, 16.0f);

            Assert::AreEqual(1.f, mat.m1);
            Assert::AreEqual(2.f, mat.m2);
            Assert::AreEqual(3.f, mat.m3);
            Assert::AreEqual(4.f, mat.m4);

            Assert::AreEqual(5.f, mat.m5);
            Assert::AreEqual(6.f, mat.m6);
            Assert::AreEqual(7.f, mat.m7);
            Assert::AreEqual(8.f, mat.m8);

            Assert::AreEqual(9.f, mat.m9);
            Assert::AreEqual(10.f, mat.m10);
            Assert::AreEqual(11.f, mat.m11);
            Assert::AreEqual(12.f, mat.m12);

            Assert::AreEqual(13.f, mat.m13);
            Assert::AreEqual(14.f, mat.m14);
            Assert::AreEqual(15.f, mat.m15);
            Assert::AreEqual(16.f, mat.m16);
        }
        // parameterized constructor (array)
        TEST_METHOD(ConstructorParamArray)
        {
            float numbers[] =
            {
                1.f, 2.f, 3.f, 4.f,
                5.f, 6.f, 7.f, 8.f,
                9.f, 10.f, 11.f, 12.f,
                13.f, 14.f, 15.f, 16.f
            };
            Matrix4 mat(numbers);

            Assert::AreEqual(1.f, mat.m1);
            Assert::AreEqual(2.f, mat.m2);
            Assert::AreEqual(3.f, mat.m3);
            Assert::AreEqual(4.f, mat.m4);

            Assert::AreEqual(5.f, mat.m5);
            Assert::AreEqual(6.f, mat.m6);
            Assert::AreEqual(7.f, mat.m7);
            Assert::AreEqual(8.f, mat.m8);

            Assert::AreEqual(9.f, mat.m9);
            Assert::AreEqual(10.f, mat.m10);
            Assert::AreEqual(11.f, mat.m11);
            Assert::AreEqual(12.f, mat.m12);

            Assert::AreEqual(13.f, mat.m13);
            Assert::AreEqual(14.f, mat.m14);
            Assert::AreEqual(15.f, mat.m15);
            Assert::AreEqual(16.f, mat.m16);
        }
        // mat4 * vec4
        TEST_METHOD(OperatorMultiplyMat4Vec4)
        {
            // homogeneous point translation
            Matrix4 m4b(1, 0, 0, 0,
                0, 1, 0, 0,
                0, 0, 1, 0,
                55, 44, 99, 1);

            Vector4 v4a(13.5f, -48.23f, -54, 1);

            Vector4 actual = m4b * v4a;
            Assert::AreEqual(Vector4(68.5f, -4.23f, 45, 1), actual);
        }
        // mat4 * mat4
        TEST_METHOD(OperatorMultiplyMat4Mat4)
        {
            Matrix4 m4a(1, 4, 1, 7,
                2, 3, 2, 8,
                3, 2, 3, 9,
                4, 1, 4, 1);

            Matrix4 m4b(4, 7, 3, 4,
                5, 6, 4, 6,
                6, 5, 6, 8,
                7, 4, 5, 2);

            Matrix4 actual = m4a * m4b;

            Assert::AreEqual(Matrix4(43, 47, 43, 115,
                53, 52, 53, 125,
                66, 59, 66, 144,
                38, 52, 38, 128),
                actual);
        }
        // make identity
        TEST_METHOD(MakeIdentity)
        {
            Matrix4 mat = Matrix4::MakeIdentity();

            Assert::AreEqual(1.f, mat.m1);
            Assert::AreEqual(0.f, mat.m2);
            Assert::AreEqual(0.f, mat.m3);
            Assert::AreEqual(0.f, mat.m4);

            Assert::AreEqual(0.f, mat.m5);
            Assert::AreEqual(1.f, mat.m6);
            Assert::AreEqual(0.f, mat.m7);
            Assert::AreEqual(0.f, mat.m8);

            Assert::AreEqual(0.f, mat.m9);
            Assert::AreEqual(0.f, mat.m10);
            Assert::AreEqual(1.f, mat.m11);
            Assert::AreEqual(0.f, mat.m12);


            Assert::AreEqual(0.f, mat.m13);
            Assert::AreEqual(0.f, mat.m14);
            Assert::AreEqual(0.f, mat.m15);
            Assert::AreEqual(1.f, mat.m16);
        }
    };
}
namespace MathLibraryTests_OPTIONAL
{
    TEST_CLASS(Matrix4OptionalTests)
    {
        TEST_METHOD(SubscriptReference) {
            Matrix4 m4a(1, 4, 1, 7,
                2, 3, 2, 8,
                3, 2, 3, 9,
                4, 1, 4, 1);

            Assert::AreEqual(m4a[0], 1.f);
            Assert::AreEqual(m4a[1], 4.f);
            Assert::AreEqual(m4a[2], 1.f);
            Assert::AreEqual(m4a[3], 7.f);

            Assert::AreEqual(m4a[4], 2.f);
            Assert::AreEqual(m4a[5], 3.f);
            Assert::AreEqual(m4a[6], 2.f);
            Assert::AreEqual(m4a[7], 8.f);

            Assert::AreEqual(m4a[8], 3.f);
            Assert::AreEqual(m4a[9], 2.f);
            Assert::AreEqual(m4a[10], 3.f);
            Assert::AreEqual(m4a[11], 9.f);

            Assert::AreEqual(m4a[12], 4.f);
            Assert::AreEqual(m4a[13], 1.f);
            Assert::AreEqual(m4a[14], 4.f);
            Assert::AreEqual(m4a[15], 1.f);
        }

        TEST_METHOD(Subscript) {
            Matrix4 m4a(1, 4, 1, 7,
                2, 3, 2, 8,
                3, 2, 3, 9,
                4, 1, 4, 1);

            float i = 0;
            for (int c = 0; c < 4; ++c) {
                for (int r = 0; r < 4; ++r) {
                    m4a.mm[c][r] = i;
                    Assert::AreEqual(m4a[c * 4 + r], i);
                    i += 5;
                }
            }
        }

        TEST_METHOD(Cast)
        {
            Matrix4 m4a(1, 4, 1, 7,
                2, 3, 2, 8,
                3, 2, 3, 9,
                4, 1, 4, 1);

            float* p = (float*)m4a;
            Assert::AreEqual(p[0], 1.f);
            Assert::AreEqual(p[1], 4.f);
            Assert::AreEqual(p[2], 1.f);
            Assert::AreEqual(p[3], 7.f);

            Assert::AreEqual(p[4], 2.f);
            Assert::AreEqual(p[5], 3.f);
            Assert::AreEqual(p[6], 2.f);
            Assert::AreEqual(p[7], 8.f);

            Assert::AreEqual(p[8], 3.f);
            Assert::AreEqual(p[9], 2.f);
            Assert::AreEqual(p[10], 3.f);
            Assert::AreEqual(p[11], 9.f);

            Assert::AreEqual(p[12], 4.f);
            Assert::AreEqual(p[13], 1.f);
            Assert::AreEqual(p[14], 4.f);
            Assert::AreEqual(p[15], 1.f);

            const float* q = (float*)m4a;
            Assert::AreEqual(q[0], 1.f);
            Assert::AreEqual(q[1], 4.f);
            Assert::AreEqual(q[2], 1.f);
            Assert::AreEqual(q[3], 7.f);

            Assert::AreEqual(q[4], 2.f);
            Assert::AreEqual(q[5], 3.f);
            Assert::AreEqual(q[6], 2.f);
            Assert::AreEqual(q[7], 8.f);

            Assert::AreEqual(q[8], 3.f);
            Assert::AreEqual(q[9], 2.f);
            Assert::AreEqual(q[10], 3.f);
            Assert::AreEqual(q[11], 9.f);

            Assert::AreEqual(q[12], 4.f);
            Assert::AreEqual(q[13], 1.f);
            Assert::AreEqual(q[14], 4.f);
            Assert::AreEqual(q[15], 1.f);
        }
    };
}
#include "CppUnitTest.h"
#include "TestToString.h"

#include "Utils.h"
#include "MathHeaders/Vector3.h"

using namespace Microsoft::VisualStudio::CppUnitTestFramework;
using ::MathClasses::Vector3;
using namespace MathClasses;

namespace MathLibraryTests
{
	TEST_CLASS(Vector3Tests)
	{
	public:
		TEST_METHOD(DefaultConstructor)
		{
			Vector3 vec;
			Assert::AreEqual(0.f, vec.x);
			Assert::AreEqual(0.f, vec.y);
			Assert::AreEqual(0.f, vec.z);
		}

		TEST_METHOD(SpecializedConstructor)
		{
			Vector3 vec(1.f,2.f,3.f);
			Assert::AreEqual(1.f, vec.x);
			Assert::AreEqual(2.f, vec.y);
			Assert::AreEqual(3.f, vec.z);
		}

		TEST_METHOD(Magnitude)
		{
				Vector3 v3a(13.5f, -48.23f, 862);
				float mag3 = v3a.Magnitude();
				Assert::AreEqual(863.453735352f, mag3, MAX_FLOAT_DELTA);

				Vector3 v3b(0, 0, 0);
				mag3 = v3b.Magnitude();
				Assert::AreEqual(0.f, mag3, MAX_FLOAT_DELTA);
		}

        TEST_METHOD(Normalised)
        {
            Vector3 v3a(13.5f, -48.23f, 862);
            Assert::AreEqual(Vector3(0.0156349f, -0.0558571f, 0.998316f), v3a.Normalised());

            Vector3 v3b(0, 0, 0);
            Assert::AreEqual(Vector3(0, 0, 0), v3b.Normalised());
        }

		TEST_METHOD(Normalise)
		{
			Vector3 v3a(13.5f, -48.23f, 862);
			v3a.Normalise();
			Assert::AreEqual(Vector3(0.0156349f, -0.0558571f, 0.998316f), v3a);
			
			Vector3 v3b(0, 0, 0);
			v3b.Normalise();
			Assert::AreEqual(Vector3(0,0,0), v3b);
		}		
		
		TEST_METHOD(Dot)
		{
			Vector3 v3a(13.5f, -48.23f, 862);
			Vector3 v3b(5, 3.99f, -12);
			float dot3 = v3a.Dot(v3b);

			Assert::AreEqual(-10468.9375f, dot3);
			
			
			Vector3 v3c(0, 0, 0);
			Vector3 v3d(5, 3.99f, -12);
			dot3 = v3c.Dot(v3d);

			Assert::AreEqual(0.0f, dot3);
		}

		TEST_METHOD(Cross)
		{
			Vector3 v3a(13.5f, -48.23f, 862);
			Vector3 v3b(5, 3.99f, -12);
			Vector3 v3c = v3a.Cross(v3b);

			Assert::AreEqual(Vector3(-2860.62011719f, 4472.00000000f, 295.01498413f), v3c);
		}

		TEST_METHOD(Add)
		{
			Vector3 v3a(13.5f, -48.23f, 862);
			Vector3 v3b(5, 3.99f, -12);
			Vector3 v3c = v3a + v3b;

			Assert::AreEqual(Vector3(18.5f, -44.24f, 850), v3c);
		}

		TEST_METHOD(Subtract)
		{
			Vector3 v3a(13.5f, -48.23f, 862);
			Vector3 v3b(5, 3.99f, -12);
			Vector3 v3c = v3a - v3b;

			Assert::AreEqual(Vector3(8.5f, -52.22f, 874), v3c);
		}

		TEST_METHOD(ScalarMulVectorRight)
		{
			Vector3 v3a(13.5f, -48.23f, 862);
			Vector3 v3c = v3a * 0.256f;

			Assert::AreEqual(Vector3(3.45600008965f, -12.3468809128f, 220.672012329f), v3c);
		}

		TEST_METHOD(ScalarMulVectorLeft)
		{
			Vector3 v3a(13.5f, -48.23f, 862);
			Vector3 v3c = 0.256f * v3a;

			Assert::AreEqual(Vector3(3.45600008965f, -12.3468809128f, 220.672012329f), v3c);
		}

		
		// TODO: implement tests for compound operators
	};

}

namespace MathLibraryTests_OPTIONAL
{
	TEST_CLASS(Vector3OptionalTests)
	{
		TEST_METHOD(ScalarDivide)
		{
			Vector3 v3a(13.5f, -48.23f, 862);
			Vector3 v3c = v3a / 0.256f;

			Assert::AreEqual(Vector3(52.734371f, -188.398422f, 3367.187256f), v3c);
		}
		TEST_METHOD(Equality)
		{
			Vector3 v3a(13.5f, -48.23f, 862);
			Vector3 v3b(13.5f, -48.23f, 862);

			Assert::IsTrue(v3a == v3b);
		}

		TEST_METHOD(Inequality)
		{
			Vector3 v3a(13.5f, -48.23f, 862);
			Vector3 v3b(0.0f, 0.0f, 0.0f);

			Assert::IsTrue(v3a != v3b && !(v3a == v3b));
		}
		TEST_METHOD(SubscriptReference) {
			const Vector3 v3a(13.5f, -48.23f, 862);

			Assert::AreEqual(v3a[0], 13.5f);
			Assert::AreEqual(v3a[1], -48.23f);
			Assert::AreEqual(v3a[2], 862.f);
		}
		TEST_METHOD(Subscript) {
			Vector3 v3a(0, 0, 0);
			v3a[0] = 3;
			Assert::AreEqual(v3a[0], 3.f);
			v3a[1] = 4;
			Assert::AreEqual(v3a[1], 4.f);
			v3a[2] = 6;
			Assert::AreEqual(v3a[2], 6.f);
		}
		TEST_METHOD(Cast)
		{
			Vector3 v3a(10, 2, 6);

			float* p = (float*)v3a;
			Assert::AreEqual(p[0], 10.f);
			Assert::AreEqual(p[1], 2.f);
			Assert::AreEqual(p[2], 6.f);

			const float* q = (float*)v3a;
			Assert::AreEqual(q[0], 10.f);
			Assert::AreEqual(q[1], 2.f);
			Assert::AreEqual(q[2], 6.f);
		}
	};
}

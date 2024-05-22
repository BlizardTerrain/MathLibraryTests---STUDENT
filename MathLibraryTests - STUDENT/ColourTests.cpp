#include "CppUnitTest.h"
#include "TestToString.h"

#include "Utils.h"
#include "MathHeaders/Colour.h"
#include <UnitTestLib.h>

using namespace Microsoft::VisualStudio::CppUnitTestFramework;
using ::MathClasses::Colour;
using ::UnitLib::Byte;

namespace MathLibraryTests
{
	TEST_CLASS(ColourTests)
	{
	public:
		// default constructor
		TEST_METHOD(ColourDefaultConstructor)
		{
			Colour actual;
			Assert::AreEqual( Colour(0, 0, 0, 255).colour, UnitLib::BuildColour(0,0,0,255) ); 
		}

		// parameterized constructor
		TEST_METHOD(ColourParamConstructor)
		{
			Colour actual{ 32, 64, 10, 255 };

			Assert::AreEqual( UnitLib::BuildColour(32, 64, 10, 255), actual.colour );
		}

		// Check equality method
		TEST_METHOD(ColourEqualityOperator)
		{
			Colour actual;
			Assert::IsTrue( Colour(0, 0, 0, 255) == actual);
		}

		// setting r
		TEST_METHOD(SetRed)
		{
			Colour actual(32, 64, 10, 255);
			actual.SetRed(128);
			Assert::AreEqual( UnitLib::BuildColour(128, 64, 10, 255), actual.colour);
		}
		
		// setting g
		TEST_METHOD(SetGreen)
		{
			Colour actual(32, 64, 10, 255);
			actual.SetGreen(128);
			Assert::AreEqual(UnitLib::BuildColour(32, 128, 10, 255), actual.colour);
		}

		// setting b
		TEST_METHOD(SetBlue)
		{
			Colour actual(32, 64, 10, 255);
			actual.SetBlue(128);
			Assert::AreEqual(UnitLib::BuildColour(32, 64, 128, 255), actual.colour);
		}

		// setting a
		TEST_METHOD(SetAlpha)
		{
			Colour actual(32, 64, 10, 255);
			actual.SetAlpha(128);
			Assert::AreEqual(UnitLib::BuildColour(32, 64, 10, 128), actual.colour);
		}
		// Get Red
		TEST_METHOD(GetRed)
		{
			Colour actual(32, 64, 10, 255);
			auto red = actual.GetRed();
			Assert::AreEqual(red, (Byte)32);
		}
		// Get Green
		TEST_METHOD(GetGreen)
		{
			Colour actual(32, 64, 10, 255);
			auto green = actual.GetGreen();
			Assert::AreEqual(green, (Byte)64);
		}
		// Get Blue
		TEST_METHOD(GetBlue)
		{
			Colour actual(32, 64, 10, 255);
			auto blue = actual.GetBlue();
			Assert::AreEqual(blue, (Byte)10);
		}
		// Get Alpha
		TEST_METHOD(GetAlpha)
		{
			Colour actual(32, 64, 0, 255);
			auto alpha = actual.GetAlpha();
			Assert::AreEqual(alpha, (Byte)255);
		}
	};
}

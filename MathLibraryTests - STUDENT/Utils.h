#pragma once

#define _USE_MATH_DEFINES
#include <cmath>

#include "MathHeaders/Colour.h"

namespace MathClasses
{
    // Maximum tolerance for comparing floats
	constexpr float MAX_FLOAT_DELTA = 0.00001f;

	inline float ApproximatelyEquals(float a, float b)
	{
		return fabsf(a - b) < MAX_FLOAT_DELTA;
	}

    inline float AngleFrom2D(float x, float y)
    {
        return atan2f(y, x);
    }

    // Constant for Pi
    constexpr float Pi = 3.14159265358979323846264338327950288f;

    // Deg2Rad
    constexpr float Deg2Rad = Pi * 2.0f / 360.0f;

    // Rad2Deg
    constexpr float Rad2Deg = 1.0f / Deg2Rad;
}
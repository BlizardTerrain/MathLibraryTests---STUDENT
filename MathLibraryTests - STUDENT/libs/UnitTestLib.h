#pragma once

//#include "../../C++ Unit test - TEACHER ONLY/Colour.h"

namespace UnitLib
{
    using Byte = unsigned char;

    unsigned int BuildColour(Byte r, Byte g, Byte b, Byte a);
    
    Byte GetRed(unsigned int colour);
    Byte GetGreen(unsigned int colour);
    Byte GetBlue(unsigned int colour);
    Byte GetAlpha(unsigned int colour);
}
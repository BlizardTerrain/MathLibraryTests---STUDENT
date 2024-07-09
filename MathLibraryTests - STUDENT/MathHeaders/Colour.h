#pragma once

namespace MathClasses
{
    struct Colour
    {
        // Add the struct data fields and methods, as per the tutorials and exercises, here...
        // ...
        unsigned int colour;

        //unsigned char is a 1 byte number that stores a value from 0 to 255, perfect for colours!
        unsigned char GetRed() const {
            return colour >> 24;
        }

        unsigned char GetGreen() const {
            return colour >> 16;
        }

        unsigned char GetBlue() const {
            return colour >> 8;
        }

        unsigned char GetAlpha() const {
            return colour >> 0;
        }

        void SetRed(unsigned char red) {
            //Slide the red bits into the correct position;
            unsigned int v = (unsigned int)red << 24;
            //Clear the current red values
            colour = colour & 0x00ffffff;
            //Put the new red values into place.
            colour = colour | v;
        }

        void SetGreen(unsigned char green) {
            unsigned int v = (unsigned int)green << 16;
            colour = colour & 0xff00ffff;
            colour = colour | v;
        }

        void SetBlue(unsigned char blue) {
            unsigned int v = (unsigned int)blue << 8;
            colour = colour & 0xffff00ff;
            colour = colour | v;
        }

        void SetAlpha(unsigned char alpha) {
            unsigned int v = (unsigned int)alpha << 0;
            colour = colour & 0xffffff00;
            colour = colour | v;
        }

        Colour() {
            // initialize all colour components to 0 except Alpha which is 255
            SetRed(0);
            SetBlue(0);
            SetGreen(0);
            SetAlpha(255);
        }

		Colour(unsigned char red, unsigned char green, unsigned char blue, unsigned char alpha) : colour((static_cast<unsigned int>(red) << 24) | (static_cast<unsigned int>(green) << 16) | (static_cast<unsigned int>(blue) << 8) |static_cast<unsigned int>(alpha)) {
            // initialize all colour components as per the parameters
        }
    };
}
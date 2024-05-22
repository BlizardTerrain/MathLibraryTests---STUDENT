#pragma once

#include <cstdlib>
#include <string>

#include "CppUnitTestAssert.h"

#include "MathHeaders/Vector3.h"
#include "MathHeaders/Vector4.h"
#include "MathHeaders/Matrix3.h"
#include "MathHeaders/Matrix4.h"
#include "MathHeaders/Colour.h"

namespace Microsoft {
	namespace VisualStudio {
		namespace CppUnitTestFramework
		{
			using MathClasses::Vector3;
			using MathClasses::Vector4;
			using MathClasses::Matrix3;
			using MathClasses::Matrix4;
			using MathClasses::Colour;

			template<> inline std::wstring ToString<Vector3>(const Vector3& t)
			{
				auto str = t.ToString();

				// mbstowcs_s will expect space to write L'\0' if it isn't already included
				// in the src buffer
				//
				// we don't expect that with ToString() which returns a std::string, so we
				// add 1 to the length here
				//
				// without it, it will raise a runtime "Invalid parameter" error
				// 
				// see https://en.cppreference.com/w/c/string/multibyte/mbstowcs
				std::wstring ws(str.length()+1, L' ');

				size_t size = 0;
				mbstowcs_s(&size, &ws[0], ws.length(), str.c_str(), str.length());

				ws.resize(size); // resize to actual fit
				return ws;
			}

			template<> inline std::wstring ToString<Vector4>(const Vector4& t)
			{
				auto str = t.ToString();

				// mbstowcs_s will expect space to write L'\0' if it isn't already included
				// in the src buffer
				//
				// we don't expect that with ToString() which returns a std::string, so we
				// add 1 to the length here
				//
				// without it, it will raise a runtime "Invalid parameter" error
				// 
				// see https://en.cppreference.com/w/c/string/multibyte/mbstowcs
				std::wstring ws(str.length() + 1, L' ');

				size_t size = 0;
				mbstowcs_s(&size, &ws[0], ws.length(), str.c_str(), str.length());

				ws.resize(size); // resize to actual fit
				return ws;
			}

			template<> inline std::wstring ToString<Matrix3>(const Matrix3& t)
			{
				auto str = t.ToString();

				// mbstowcs_s will expect space to write L'\0' if it isn't already included
				// in the src buffer
				//
				// we don't expect that with ToString() which returns a std::string, so we
				// add 1 to the length here
				//
				// without it, it will raise a runtime "Invalid parameter" error
				// 
				// see https://en.cppreference.com/w/c/string/multibyte/mbstowcs
				std::wstring ws(str.length() + 1, L' ');

				size_t size = 0;
				mbstowcs_s(&size, &ws[0], ws.length(), str.c_str(), str.length());

				ws.resize(size); // resize to actual fit
				return ws;
			}

			template<> inline std::wstring ToString<Matrix4>(const Matrix4& t)
			{
				auto str = t.ToString();

				// mbstowcs_s will expect space to write L'\0' if it isn't already included
				// in the src buffer
				//
				// we don't expect that with ToString() which returns a std::string, so we
				// add 1 to the length here
				//
				// without it, it will raise a runtime "Invalid parameter" error
				// 
				// see https://en.cppreference.com/w/c/string/multibyte/mbstowcs
				std::wstring ws(str.length() + 1, L' ');

				size_t size = 0;
				mbstowcs_s(&size, &ws[0], ws.length(), str.c_str(), str.length());

				ws.resize(size); // resize to actual fit
				return ws;
			}

			template<> inline std::wstring ToString<Colour>(const Colour& t)
			{
				auto str =	std::to_string(t.GetRed()) +
							std::to_string(t.GetGreen()) +
							std::to_string(t.GetBlue()) +
							std::to_string(t.GetAlpha());

				// mbstowcs_s will expect space to write L'\0' if it isn't already included
				// in the src buffer
				//
				// we don't expect that with ToString() which returns a std::string, so we
				// add 1 to the length here
				//
				// without it, it will raise a runtime "Invalid parameter" error
				// 
				// see https://en.cppreference.com/w/c/string/multibyte/mbstowcs
				std::wstring ws(str.length() + 1, L' ');

				size_t size = 0;
				mbstowcs_s(&size, &ws[0], ws.length(), str.c_str(), str.length());

				ws.resize(size); // resize to actual fit
				return ws;
			}
		}
	}
}
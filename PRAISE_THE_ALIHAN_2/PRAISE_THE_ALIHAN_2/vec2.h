#pragma once

#include <iostream>
/********************************************
Author: Charles Miller
vec2.h
Header file meant to create a struct named vec2
that holds 2 elements plus operations with the struct.
********************************************/

namespace prototype {
	namespace maths {

		struct vec2 {
			float x, y;

			vec2();
			vec2(const float& x, const float& y);

			vec2& add(const vec2& other);
			vec2& subtract(const vec2& other);
			vec2& multiply(const vec2& other);
			vec2& divide(const vec2& other);

			friend vec2& operator+(vec2 left, const vec2& right);
			friend vec2& operator-(vec2 left, const vec2& right);
			friend vec2& operator*(vec2 left, const vec2& right);
			friend vec2& operator/(vec2 left, const vec2& right);

			vec2& operator+=(const vec2& other);
			vec2& operator-=(const vec2& other);
			vec2& operator*=(const vec2& other);
			vec2& operator/=(const vec2& other);

			bool operator==(const vec2& other);
			bool operator!=(const vec2& other);


			friend std::ostream& operator<<(std::ostream& stream, const vec2& vector);
		};
	}
}
#pragma once

#include <iostream>
/********************************************
Author: Charles Miller
vec3.h
Header file meant to create a struct named vec3
that holds 3 elements plus operations with the struct.
********************************************/

namespace prototype {
	namespace maths {

		struct vec3 {
			float x, y, z;

			vec3();
			vec3(const float& x, const float& y, const float& z);

			vec3& add(const vec3& other);
			vec3& subtract(const vec3& other);
			vec3& multiply(const vec3& other);
			vec3& divide(const vec3& other);

			friend vec3& operator+(vec3 left, const vec3& right);
			friend vec3& operator-(vec3 left, const vec3& right);
			friend vec3& operator*(vec3 left, const vec3& right);
			friend vec3& operator/(vec3 left, const vec3& right);

			vec3& operator+=(const vec3& other);
			vec3& operator-=(const vec3& other);
			vec3& operator*=(const vec3& other);
			vec3& operator/=(const vec3& other);

			bool operator==(const vec3& other);
			bool operator!=(const vec3& other);


			friend std::ostream& operator<<(std::ostream& stream, const vec3& vector);
		};
	}
}
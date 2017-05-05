#pragma once

#include <iostream>
#include <vector>
#include "vector.h"

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

			inline vec3& operator=(Vector3& other) {
				double a = other.getX();
				double b = other.getY();
				double c = other.getZ();
				x = (float)a;
				y = (float)b;
				z = (float)c;
			}

			inline vec3& operator=(Vector2& other) {
				double a = other.getX();
				double b = other.getY();
				x = (float)a;
				y = (float)b;
			}

			friend std::ostream& operator<<(std::ostream& stream, const vec3& vector);
		};
	}
}
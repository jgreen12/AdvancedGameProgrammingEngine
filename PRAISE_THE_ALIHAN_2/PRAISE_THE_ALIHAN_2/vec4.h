#pragma once

#include <iostream>
#include <vector>
#include "vector.h"

namespace prototype {
	namespace maths {

		struct vec4 {
			float x, y, z, w;

			vec4() = default;
			vec4(const float& x, const float& y, const float& z, const float& w);

			vec4& add(const vec4& other);
			vec4& subtract(const vec4& other);
			vec4& multiply(const vec4& other);
			vec4& divide(const vec4& other);

			friend vec4& operator+(vec4 left, const vec4& right);
			friend vec4& operator-(vec4 left, const vec4& right);
			friend vec4& operator*(vec4 left, const vec4& right);
			friend vec4& operator/(vec4 left, const vec4& right);

			vec4& operator+=(const vec4& other);
			vec4& operator-=(const vec4& other);
			vec4& operator*=(const vec4& other);
			vec4& operator/=(const vec4& other);

			bool operator==(const vec4& other);
			bool operator!=(const vec4& other);

			inline vec4& operator=(Vector3& other) {
				double a = other.getX();
				double b = other.getY();
				double c = other.getZ();
				x = (float)a;
				y = (float)b;
				z = (float)x;
			}

			inline vec4& operator=(Vector2& other) {
				double a = other.getX();
				double b = other.getY();
				x = (float)a;
				y = (float)b;
			}


			friend std::ostream& operator<<(std::ostream& stream, const vec4& vector);
		};
	}
}
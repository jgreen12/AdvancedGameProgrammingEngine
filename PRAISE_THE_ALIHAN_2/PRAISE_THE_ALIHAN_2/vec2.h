#pragma once

#include <iostream>
#include <vector>
#include "vector.h"

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

			inline vec2& operator=(Vector2& other) {
				double a = other.getX();
				double b = other.getY();
				x = (float)a;
				y = (float)b;
			}


			friend std::ostream& operator<<(std::ostream& stream, const vec2& vector);
		};
	}
}
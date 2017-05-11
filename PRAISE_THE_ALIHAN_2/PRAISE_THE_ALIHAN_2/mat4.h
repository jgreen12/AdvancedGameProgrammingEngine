#pragma once
#include "mathsFunc.h"
#include "vec3.h"
#include "vec4.h"
/********************************************
Author: Charles Miller
mat4.h
Header file meant to create a struct named mat4
that holds 16 (four columns, four rows) elements plus
linear algebra operations with the struct, including
orthographic, perspective, translation, rotation, and scale.
********************************************/

namespace prototype {
	namespace maths {

//		float toRadians(float degrees);

		struct mat4 {


			union {
				float elements[4 * 4];
				vec4 columns[4];
			};

			mat4();
			mat4(float diagonal);

			static mat4 identity();
			mat4& multiply(const mat4& other);
			friend mat4 operator*(mat4 left, const mat4& right);
			mat4& operator*=(mat4& other);

			static mat4 orhtographic(float left, float right, float bottom, float top, float near, float far);
			static mat4 perspective(float fov, float aspectRatio, float near, float far);

			static mat4 translation(const vec3& translation);
			static mat4 rotation(float angle, const vec3& axis);
			static mat4 scale(const vec3& scale);

		};
	}
}
#pragma once
#include "renderable2d.h"
#include <GL\glew.h>
#include "maths.h"

namespace prototype {
	namespace graphics {
		class Renderer2D {
		protected:
			virtual void submit(const Renderable2D* renderable) = 0;
			virtual void flush() = 0;
		};
	}
}
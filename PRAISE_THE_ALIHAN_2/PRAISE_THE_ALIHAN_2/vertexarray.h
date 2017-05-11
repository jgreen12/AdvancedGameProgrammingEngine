#pragma once

#include <vector>
#include <GL\glew.h>
#include "buffer.h"
/********************************************
Author: Charles Miller
vertexarray.h
CPP file for header file indexbuffer.h meant to create a
general vertex array with attributes defined by the
programmer that then are binded to the array and then
unbinded for access in buffer.
********************************************/

namespace prototype {
	namespace graphics {
		class VertexArray {
		private: 
			GLuint m_ArrayID;
			std::vector<Buffer*> m_Buffers;
		public:
			VertexArray();
			~VertexArray();

			void addBuffer(Buffer* buffer, GLuint index);
			void bind() const;
			void unbind() const;
		};
	}
}
#include "buffer.h"

/********************************************
Author: Charles Miller
buffer.cpp
CPP file for header file buffer.h meant to create a buffer
from creation, binding, data, and rebinding after data
implementation and also to either bind or unbind it.
********************************************/


namespace prototype {
	namespace graphics {
		Buffer::Buffer(GLfloat* data, GLsizei count, GLuint componentCount) : m_ComponentCount(componentCount){
			glGenBuffers(1, &m_BufferID);
			glBindBuffer(GL_ARRAY_BUFFER, m_BufferID);
			glBufferData(GL_ARRAY_BUFFER, count * sizeof(GLfloat), data, GL_STATIC_DRAW);
			glBindBuffer(GL_ARRAY_BUFFER, 0);
		}

		void Buffer::bind() const {
			glBindBuffer(GL_ARRAY_BUFFER, m_BufferID);
		}
		void Buffer::unbind() const {
			glBindBuffer(GL_ARRAY_BUFFER, 0);
		}
	}
}
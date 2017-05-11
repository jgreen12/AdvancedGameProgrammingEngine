#include "indexbuffer.h"
/********************************************
Author: Charles Miller
simple2drenderer.h
Header file meant to step through the m_RenderQueue
to render multiple objects.
********************************************/


namespace prototype {
	namespace graphics {
		IndexBuffer::IndexBuffer(GLushort* data, GLsizei count) : m_Count(count) {
			glGenBuffers(1, &m_BufferID);
			glBindBuffer(GL_ELEMENT_ARRAY_BUFFER, m_BufferID);
			glBufferData(GL_ELEMENT_ARRAY_BUFFER, count * sizeof(GLushort), data, GL_STATIC_DRAW);
			glBindBuffer(GL_ELEMENT_ARRAY_BUFFER, 0);
		}

		void IndexBuffer::bind() const {
			glBindBuffer(GL_ELEMENT_ARRAY_BUFFER, m_BufferID);
		}
		void IndexBuffer::unbind() const {
			glBindBuffer(GL_ELEMENT_ARRAY_BUFFER, 0);
		}
	}
}
#pragma once
#include <GL\glew.h>

/********************************************
Author: Charles Miller
buffer.h
Header file meant to create a buffer from creation, binding,
data, and rebinding after data implementation and also
to either bind or unbind it.
********************************************/


namespace prototype {
	namespace graphics {
		class Buffer {
		private:
			GLuint m_BufferID;
			GLuint m_ComponentCount;
		public:
			Buffer(GLfloat* data, GLsizei count, GLuint componentCount);

			void bind() const;
			void unbind() const;

			inline GLuint getComponentCount() const { return m_ComponentCount;}
		};

	}
}
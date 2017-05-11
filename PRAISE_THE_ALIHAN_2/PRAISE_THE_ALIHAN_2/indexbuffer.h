#pragma once
#include <GL\glew.h>

/********************************************
Author: Charles Miller
indexbuffer.h
Header file meant to create an index buffer from creation,
binding, data, and rebinding after data implementation
and also to either bind or unbind it.
********************************************/


namespace prototype {
	namespace graphics {
		class IndexBuffer {
		private:
			GLuint m_BufferID;
			GLuint m_Count;
		public:
			IndexBuffer(GLushort* data, GLsizei count);

			void bind() const;
			void unbind() const;

			inline GLuint getCount() const { return m_Count; }
		};

	}
}
#pragma once
#include "buffer.h"
#include "indexbuffer.h"
#include "vertexarray.h"
#include "maths.h"
#include "shader.h"


namespace prototype {
	namespace graphics {
		class Renderable2D {
		protected:
			maths::vec3 m_Position;
			maths::vec2 m_Size;
			maths::vec4 m_Color;

			Shader& m_Shader;
			VertexArray* m_VertexArray;
			IndexBuffer* m_IndexBuffer;
		public:
			Renderable2D(maths::vec3 position, maths::vec2 size, maths::vec4 color, Shader& shader) : m_Position(position), m_Size(size), m_Color(color), m_Shader(shader) {
				m_VertexArray = new VertexArray();
				GLfloat verticies[] = {
				0, 0, 0,
				0, size.y, 0,
				size.x, size.y, 0,
				size.x, 0, 0
				};

				GLfloat colors[] = {
					color.x, color.y, color.z, color.w,
					color.x, color.y, color.z, color.w,
					color.x, color.y, color.z, color.w,
					color.x, color.y, color.z, color.w
				};

				m_VertexArray->addBuffer(new Buffer(verticies, 4 * 3, 3), 0);
				m_VertexArray->addBuffer(new Buffer(colors, 4 * 4, 4), 1);


				GLushort indicies[] = { 0, 1, 2, 2, 3, 0 };
				m_IndexBuffer = new IndexBuffer(indicies, 6);
			}

			virtual ~Renderable2D() {
				delete m_VertexArray;
				delete m_IndexBuffer;
			}

			inline const VertexArray* getVAO() const { return m_VertexArray; }
			inline const IndexBuffer* getIBO() const { return m_IndexBuffer; }

			inline Shader& getShader() const { return m_Shader; }

			inline const maths::vec3& getPosition() const { return m_Position; }
			maths::vec2& getSize() { return m_Size; }
			inline const maths::vec4& getColor() const { return m_Color; }

			inline void update(maths::vec3 translation) {
				m_Position = translation;
				//std::cout << "Translation: " << m_Position << std::endl;
			}

			inline Renderable2D operator=(const Renderable2D& other) {
				m_Position = other.m_Position;
				m_Size = other.m_Size;
				m_Color = other.m_Color;

				m_Shader = other.m_Shader;
				m_VertexArray = other.m_VertexArray;
				m_IndexBuffer = other.m_IndexBuffer;

				return *this;
			}
		};
	}
}
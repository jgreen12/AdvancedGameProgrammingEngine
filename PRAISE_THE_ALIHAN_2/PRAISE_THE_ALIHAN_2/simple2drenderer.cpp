#include "simple2drenderer.h"
/********************************************
Author: Charles Miller
simple2drenderer.cpp
CPP file for header file simple2drenderer.h meant to step
through the m_RenderQueue to render multiple objects.
********************************************/

namespace prototype {
	namespace graphics {
		void Simple2DRenderer::submit(const Renderable2D* renderable) {
			m_RenderQueue.push_back(renderable);

		}
		void Simple2DRenderer::flush() {
			while (!m_RenderQueue.empty()) {
				const Renderable2D* renderable = m_RenderQueue.front();
				renderable->getVAO()->bind();
				renderable->getIBO()->bind();

				renderable->getShader().setUniformMat4("ml_matrix", maths::mat4::translation(renderable->getPosition()));
				glDrawElements(GL_TRIANGLES, renderable->getIBO()->getCount(), GL_UNSIGNED_SHORT, nullptr);

				renderable->getIBO()->unbind();
				renderable->getVAO()->unbind();

				m_RenderQueue.pop_front();
			}
		}
	}
}
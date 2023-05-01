#include "Renderer.h"

namespace R {
	void renderer::draw(const VertexArray& va, const R::IndexBuffer& ib, const Shader& shader)
	{
		va.Bind();
		shader.Bind();
		ib.Bind();
		glDrawElements(GL_TRIANGLES, ib.GetCount(), GL_UNSIGNED_INT, 0);
	}
}
#pragma once
#include <GL/glew.h>
#include "../glObj/VertexArray.h"
#include "../glObj/IndexBuffer.h"
#include "../glObj/Shader.h"

namespace R {
	struct Renderer {
		void Draw(const VertexArray& va, const IndexBuffer& ib, const Shader& shader);
		void Clear();
	};
}
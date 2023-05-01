#pragma once
#include <GL/glew.h>
#include "../glObj/Buffer.h"
#include "../glObj/Shader.h"
#include "../glObj/VertexArray.h"

namespace R {
	class renderer {
	public:
		static void draw(const VertexArray& va, const R::IndexBuffer& ib, const Shader& shader);
	};
}
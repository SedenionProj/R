#pragma once
#include <GL/glew.h>
#include "Buffer.h"

class VertexArray {
private:
	unsigned int ID;
	unsigned int pos;
public:
	VertexArray();
	~VertexArray();
	void AddBuffer(const R::VertexBuffer& vb, int size, int stride, int offset);
	void Bind()const;
	void Unbind()const;
};
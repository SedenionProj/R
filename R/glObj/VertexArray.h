#pragma once
#include <GL/glew.h>
#include "VertexBuffer.h"

class VertexArray {
private:
	unsigned int ID;
	unsigned int pos;
public:
	VertexArray();
	~VertexArray();
	void AddBuffer(const VertexBuffer& vb, int size, int stride, int offset);
	void Bind()const;
	void Unbind()const;
	void Test(const VertexBuffer& vb, int size, int stride, int offset);
};
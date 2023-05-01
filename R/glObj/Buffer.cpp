#include "buffer.h"

namespace R {
	VertexBuffer::VertexBuffer(const int size, const float data[])
	{
		glGenBuffers(1, &ID);
		glBindBuffer(GL_ARRAY_BUFFER, ID);
		glBufferData(GL_ARRAY_BUFFER, size, data, GL_STATIC_DRAW);
	}
	VertexBuffer::~VertexBuffer() {
		glDeleteBuffers(1, &ID);
	}

	void VertexBuffer::Bind() const {
		glBindBuffer(GL_ARRAY_BUFFER, ID);
	}
	void VertexBuffer::Unbind() const {
		glBindBuffer(GL_ARRAY_BUFFER, 0);
	}



	IndexBuffer::IndexBuffer(const int size, const unsigned int data[]) : count(size)
	{
		glGenBuffers(1, &ID);
		glBindBuffer(GL_ELEMENT_ARRAY_BUFFER, ID);
		glBufferData(GL_ELEMENT_ARRAY_BUFFER, size, data, GL_STATIC_DRAW);
	}
	IndexBuffer::~IndexBuffer() {
		glDeleteBuffers(1, &ID);
	}

	void IndexBuffer::Bind() const {
		glBindBuffer(GL_ELEMENT_ARRAY_BUFFER, ID);
	}
	void IndexBuffer::Unbind() const {
		glBindBuffer(GL_ELEMENT_ARRAY_BUFFER, 0);
	}



	ShaderStorageBuffer::ShaderStorageBuffer(const int size, const float data[], const unsigned int& pos)
	{
		glGenBuffers(1, &ID);
		glBindBuffer(GL_SHADER_STORAGE_BUFFER, ID);
		glBufferData(GL_SHADER_STORAGE_BUFFER, size, data, GL_STATIC_DRAW);
		glBindBufferBase(GL_SHADER_STORAGE_BUFFER, pos, ID);
		glBindBuffer(GL_SHADER_STORAGE_BUFFER, 0);
	}
	ShaderStorageBuffer::~ShaderStorageBuffer() {
		glDeleteBuffers(1, &ID);
	}
	void ShaderStorageBuffer::Bind() const {
		glBindBuffer(GL_SHADER_STORAGE_BUFFER, ID);
	}
	void ShaderStorageBuffer::Unbind() const {
		glBindBuffer(GL_SHADER_STORAGE_BUFFER, 0);
	}




	UniformBuffer::UniformBuffer(const int size, const float data[], const unsigned int& pos)
	{
		glGenBuffers(1, &ID);
		glBindBuffer(GL_UNIFORM_BUFFER, ID);
		glBufferData(GL_UNIFORM_BUFFER, size, data, GL_STATIC_DRAW);
		glBindBufferBase(GL_UNIFORM_BUFFER, pos, ID);
		glBindBuffer(GL_SHADER_STORAGE_BUFFER, 0);
	}
	UniformBuffer::~UniformBuffer() {
		glDeleteBuffers(1, &ID);
	}
	void UniformBuffer::Bind() const {
		glBindBuffer(GL_ARRAY_BUFFER, ID);
	}
	void UniformBuffer::Unbind() const {
		glBindBuffer(GL_ARRAY_BUFFER, 0);
	}
}

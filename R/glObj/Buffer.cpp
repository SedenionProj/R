#include "buffer.h"

namespace R {
	//VBO
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


	//IBO/EBO
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


	//UBO
	UniformBuffer::UniformBuffer(const int size, const std::vector<glm::vec4>& data, const unsigned int binding) : _binding(binding)
	{
		glGenBuffers(1, &ID);
		glBindBuffer(GL_UNIFORM_BUFFER, ID);
		glBufferData(GL_UNIFORM_BUFFER, size, &data[0], GL_STATIC_DRAW);
		glBindBufferBase(GL_UNIFORM_BUFFER, _binding, ID);
		glBindBuffer(GL_SHADER_STORAGE_BUFFER, 0);
	}

	UniformBuffer::UniformBuffer(const int size) : _binding(0)
	{
		glGenBuffers(1, &ID);
		glBindBuffer(GL_UNIFORM_BUFFER, ID);
		glBufferData(GL_UNIFORM_BUFFER, size, NULL, GL_STATIC_DRAW);
		glBindBufferBase(GL_UNIFORM_BUFFER, _binding, ID);
		glBindBuffer(GL_SHADER_STORAGE_BUFFER, 0);
	}

	UniformBuffer::~UniformBuffer() {
		glDeleteBuffers(1, &ID);
	}

	template <typename T>
	void UniformBuffer::data(const int offset, T data, const int size, const unsigned int binding) {
		_binding = binding;
		glBindBuffer(GL_UNIFORM_BUFFER, ID);
		glBufferSubData(GL_UNIFORM_BUFFER, offset, size, &data[0]);
		glBindBufferBase(GL_UNIFORM_BUFFER, _binding, ID);
		glBindBuffer(GL_UNIFORM_BUFFER, 0);
	}
	template
	void UniformBuffer::data<glm::mat4>(const int, glm::mat4, const int, const unsigned int);
	template
	void UniformBuffer::data<glm::vec4>(const int, glm::vec4, const int, const unsigned int);

	void UniformBuffer::Bind() const {
		glBindBuffer(GL_ARRAY_BUFFER, ID);
	}
	void UniformBuffer::Unbind() const {
		glBindBuffer(GL_ARRAY_BUFFER, 0);
	}

	//SSBO
	ShaderStorageBuffer::ShaderStorageBuffer(const int size, const std::vector<glm::vec4>& data, const unsigned int binding) : _binding(binding)
	{
		glGenBuffers(1, &ID);
		glBindBuffer(GL_SHADER_STORAGE_BUFFER, ID);
		glBufferData(GL_SHADER_STORAGE_BUFFER, size, &data[0], GL_STATIC_DRAW);
		glBindBufferBase(GL_SHADER_STORAGE_BUFFER, binding, ID);
		glBindBuffer(GL_SHADER_STORAGE_BUFFER, 0);
	}
	ShaderStorageBuffer::ShaderStorageBuffer(const int size) : _binding(0)
	{
		glGenBuffers(1, &ID);
		glBindBuffer(GL_SHADER_STORAGE_BUFFER, ID);
		glBufferData(GL_SHADER_STORAGE_BUFFER, size, NULL, GL_STATIC_DRAW);
		glBindBufferBase(GL_SHADER_STORAGE_BUFFER, _binding, ID);
		glBindBuffer(GL_SHADER_STORAGE_BUFFER, 0);
	}
	template <typename T>
	void ShaderStorageBuffer::data(const int offset, T data, const int size, const unsigned int binding) {
		_binding = binding;
		glBindBuffer(GL_SHADER_STORAGE_BUFFER, ID);
		glBufferSubData(GL_SHADER_STORAGE_BUFFER, offset, size, &data[0]);
		glBindBufferBase(GL_SHADER_STORAGE_BUFFER, _binding, ID);
		glBindBuffer(GL_SHADER_STORAGE_BUFFER, 0);
	}
	template
		void ShaderStorageBuffer::data<glm::mat4>(const int, glm::mat4, const int, const unsigned int);
	template
		void ShaderStorageBuffer::data<glm::vec4>(const int, glm::vec4, const int, const unsigned int);
	ShaderStorageBuffer::~ShaderStorageBuffer() {
		glDeleteBuffers(1, &ID);
	}
	void ShaderStorageBuffer::Bind() const {
		glBindBuffer(GL_SHADER_STORAGE_BUFFER, ID);
	}
	void ShaderStorageBuffer::Unbind() const {
		glBindBuffer(GL_SHADER_STORAGE_BUFFER, 0);
	}
}

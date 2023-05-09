#include "UniformBuffer.h"

UniformBuffer::UniformBuffer(const int size, const float data[],const unsigned int pos)
{
	glGenBuffers(1, &ID);
	glBindBuffer(GL_UNIFORM_BUFFER, ID);
	glBufferData(GL_UNIFORM_BUFFER, size, data, GL_STATIC_DRAW);
	glBindBufferBase(GL_UNIFORM_BUFFER, pos, ID);
	glBindBuffer(GL_SHADER_STORAGE_BUFFER, 0);
}
UniformBuffer::~UniformBuffer() {
	glDeleteBuffers(1,&ID);
}
void UniformBuffer::Bind() const {
	glBindBuffer(GL_ARRAY_BUFFER, ID);
}
void UniformBuffer::Unbind() const {
	glBindBuffer(GL_ARRAY_BUFFER, 0);
}

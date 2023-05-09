#pragma once
#include <GL/glew.h>

class UniformBuffer {
private:
	unsigned int ID;
public:
	UniformBuffer(const int size, const float data[], const unsigned int pos = 0);
	~UniformBuffer();
	inline unsigned int getId() const { return ID; }
	void Bind() const;
	void Unbind() const;
};
#pragma once
#include <GL/glew.h>

namespace R {
	class VertexBuffer {
	private:
		unsigned int ID;
	public:
		VertexBuffer(const int size, const float data[]);
		~VertexBuffer();

		void Bind() const;
		void Unbind() const;
	};

	class IndexBuffer {
	private:
		unsigned int ID;
		unsigned int count;
	public:
		IndexBuffer(const int size, const unsigned int data[]);
		~IndexBuffer();

		void Bind() const;
		void Unbind() const;
		inline unsigned int GetCount() const { return count; }

	};

	class UniformBuffer {
	private:
		unsigned int ID;
	public:
		UniformBuffer(const int size, const float data[], const unsigned int& pos = 0);
		~UniformBuffer();
		inline unsigned int getId() const { return ID; }
		void Bind() const;
		void Unbind() const;
	};

	class ShaderStorageBuffer {
	private:
		unsigned int ID;
	public:
		ShaderStorageBuffer(const int size, const float data[], const unsigned int& pos = 0);
		~ShaderStorageBuffer();
		inline unsigned int getId() const { return ID; }
		void Bind() const;
		void Unbind() const;
	};
}
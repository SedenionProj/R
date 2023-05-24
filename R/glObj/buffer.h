#pragma once
#include <GL/glew.h>
#include "../libs/GLM/glm/glm.hpp"
#include <vector>

namespace R {
	class VertexBuffer {
	private:
		unsigned int ID;
	public:
		VertexBuffer(const int size, const float data[]);
		~VertexBuffer();

		void Bind() const;
		void Unbind() const;

		inline unsigned int getId() const { return ID; }
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
		inline unsigned int getId() const { return ID; }

	};

	class UniformBuffer {
	private:
		unsigned int ID;
		unsigned int _binding;
	public:
		template <typename T>
		UniformBuffer(const int size, const T& data, const unsigned int binding = 0);
		UniformBuffer(const int size);
		~UniformBuffer();
		template <typename T>
		void data(const int offset,const T& data, const int size, const unsigned int binding = 0);
		inline unsigned int getId() const { return ID; }
		void Bind() const;
		void Unbind() const;
	};

	class ShaderStorageBuffer {
	private:
		unsigned int ID;
		unsigned int _binding;
	public:
		template <typename T>
		ShaderStorageBuffer(const int size, const T& data, const unsigned int binding = 0);
		ShaderStorageBuffer(const int size);
		~ShaderStorageBuffer();
		inline unsigned int getId() const { return ID; }
		template <typename T>
		void data(const int offset,const T& data, const int size, const unsigned int binding = 0);
		void Bind() const;
		void Unbind() const;
	};
}
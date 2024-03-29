#pragma once
#include <common.hpp>
#include "array/array.hpp"

namespace vertex {
	class Buffer {
	private:
		unsigned int m_renderID;
	public:
		Buffer(const void* data, unsigned int size);
		~Buffer();

		void bind() const;
		void unbind() const;
	};
}


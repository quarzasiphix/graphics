#pragma once
#include <common.hpp>

namespace index {
	class Buffer
	{
	private:
		unsigned int m_renderID;
		unsigned int m_count;
	public:
		Buffer(const unsigned int* data, unsigned int size);
		~Buffer();

		void bind() const;
		void unbind() const;

		inline unsigned int getCount() const { return m_count; }
	};
}

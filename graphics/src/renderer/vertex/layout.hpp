#pragma once
#include <common.hpp>

namespace vertex {
	struct element {
		unsigned int type;
		unsigned int count;
		unsigned char normalized;

		static unsigned int getSizeOfType(unsigned int type)
		{
			switch (type)
			{
				case GL_FLOAT:			return 4;
				case GL_UNSIGNED_INT:	return 4;
				case GL_UNSIGNED_BYTE:	return 1;
			}
			ASSERT(false);
			return 0;
		}

	};

	class Layout {
	private:
		std::vector<element> m_elements;
		unsigned int m_stride;
	public:
		Layout() : m_stride(0) {}

		template <typename T>
		void Push(unsigned int count) {
			static_assert(false);
		}

		template<>
		void Push<float>(unsigned int count) {
			m_elements.push_back({GL_FLOAT, count, false});
			m_stride += count * element::getSizeOfType(GL_FLOAT);
		}

		template<>
		void Push<unsigned int>(unsigned int count) {
			m_elements.push_back({ GL_UNSIGNED_INT, count, GL_TRUE });
			m_stride += count * element::getSizeOfType(GL_UNSIGNED_INT);
		}

		template<>
		void Push<unsigned char>(unsigned int count) {
			m_elements.push_back({ GL_UNSIGNED_BYTE, count, GL_FALSE });
			m_stride += count * element::getSizeOfType(GL_UNSIGNED_BYTE);
		}

		inline const std::vector<element> m_elements_get() const { return m_elements; };
		inline unsigned int m_stride_get() const { return m_stride; };

	};
}
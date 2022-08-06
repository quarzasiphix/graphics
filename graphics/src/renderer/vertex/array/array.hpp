#pragma once
#include <app.hpp>

namespace vertex {
	class Array {
	private:
		unsigned int m_renderID;
	public:
		Array();
		~Array();

		void addbuffer(const Buffer& vb, const Layout& layout);

		void bind() const;
		void unbind() const;
	};
}
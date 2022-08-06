#pragma once
#include <common.hpp>

class indexBuffer
{
private:
	unsigned int m_renderID;
	unsigned int m_count;

public:
	indexBuffer(const unsigned int* data, unsigned int size);
	~indexBuffer();

	void bind() const;
	void unbind() const;

	inline unsigned int getCount() const { return m_count; }
};


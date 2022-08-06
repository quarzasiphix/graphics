#pragma once
#include <common.hpp>

class indexBuffer
{
private:
	unsigned int m_RenderID;
	unsigned int m_Count;

public:
	indexBuffer(const unsigned int* data, unsigned int size);
	~indexBuffer();

	void bind() const;
	void unbind() const;

	inline unsigned int getCount() const { return m_Count; }
};


#pragma once
#include <common.hpp>

class vertexBuffer
{
private:
	unsigned int m_RenderID;
public:
	vertexBuffer(const void* data, unsigned int size);
	~vertexBuffer();

	void bind() const;
	void unbind() const;
};


#include <app.hpp>

vertexBuffer::vertexBuffer(const void* data, unsigned int size) {
    gl(glGenBuffers(1, &m_RenderID));
    gl(glBindBuffer(GL_ARRAY_BUFFER, m_RenderID));
    gl(glBufferData(GL_ARRAY_BUFFER, size, data, GL_STATIC_DRAW));
}

vertexBuffer::~vertexBuffer() {
    gl(glDeleteBuffers(1, &m_RenderID));
}

void vertexBuffer::bind() const{
    gl(glBindBuffer(GL_ARRAY_BUFFER, m_RenderID));
}

void vertexBuffer::unbind() const{
    gl(glBindBuffer(GL_ARRAY_BUFFER, 0));
}

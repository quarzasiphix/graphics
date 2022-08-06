#include <app.hpp>

indexBuffer::indexBuffer(const unsigned int* data, unsigned int count) {
    ASSERT(sizeof(unsigned int) == sizeof(GLuint));
      
    gl(glGenBuffers(1, &m_RenderID));
    gl(glBindBuffer(GL_ARRAY_BUFFER, m_RenderID));
    gl(glBufferData(GL_ARRAY_BUFFER, count * sizeof(unsigned int), data, GL_STATIC_DRAW));
}

indexBuffer::~indexBuffer() {
    gl(glDeleteBuffers(1, &m_RenderID));
}

void indexBuffer::bind() const{
    gl(glBindBuffer(GL_ELEMENT_ARRAY_BUFFER, m_RenderID));
}

void indexBuffer::unbind() const{
    gl(glBindBuffer(GL_ELEMENT_ARRAY_BUFFER, 0));
}

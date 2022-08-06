#include <app.hpp>

indexBuffer::indexBuffer(const unsigned int* data, unsigned int count) {
    ASSERT(sizeof(unsigned int) == sizeof(GLuint));
      
    gl(glGenBuffers(1, &m_renderID));
    gl(glBindBuffer(GL_ARRAY_BUFFER, m_renderID));
    gl(glBufferData(GL_ARRAY_BUFFER, count * sizeof(unsigned int), data, GL_STATIC_DRAW));
}

indexBuffer::~indexBuffer() {
    gl(glDeleteBuffers(1, &m_renderID));
}

void indexBuffer::bind() const{
    gl(glBindBuffer(GL_ELEMENT_ARRAY_BUFFER, m_renderID));
}

void indexBuffer::unbind() const{
    gl(glBindBuffer(GL_ELEMENT_ARRAY_BUFFER, 0));
}

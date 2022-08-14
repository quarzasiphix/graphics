#include <app.hpp>
namespace index {
    Buffer::Buffer(const unsigned int* data, unsigned int count)
    : m_count(count) {
        ASSERT(sizeof(unsigned int) == sizeof(GLuint));
        gl(glGenBuffers(1, &m_renderID));
        gl(glBindBuffer(GL_ELEMENT_ARRAY_BUFFER, m_renderID));
        gl(glBufferData(GL_ELEMENT_ARRAY_BUFFER, count * sizeof(unsigned int), data, GL_STATIC_DRAW));
    }

    Buffer::~Buffer() {
        gl(glDeleteBuffers(1, &m_renderID));
    }

    void Buffer::bind() const{
        gl(glBindBuffer(GL_ELEMENT_ARRAY_BUFFER, m_renderID));
    }

    void Buffer::unbind() const{
        gl(glBindBuffer(GL_ELEMENT_ARRAY_BUFFER, 0));
    }
}

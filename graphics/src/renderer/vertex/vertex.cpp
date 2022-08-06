#include <app.hpp>
namespace vertex {
    Buffer::Buffer(const void* data, unsigned int size) {
        gl(glGenBuffers(1, &m_renderID));
        gl(glBindBuffer(GL_ARRAY_BUFFER, m_renderID));
        gl(glBufferData(GL_ARRAY_BUFFER, size, data, GL_STATIC_DRAW));
    }

    Buffer::~Buffer() {
        gl(glDeleteBuffers(1, &m_renderID));
    }

    void Buffer::bind() const {
        gl(glBindBuffer(GL_ARRAY_BUFFER, m_renderID));
    }

    void Buffer::unbind() const {
        gl(glBindBuffer(GL_ARRAY_BUFFER, 0));
    }
}
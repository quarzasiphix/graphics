#include <app.hpp>

namespace vertex {
    Array::Array() {
        gl(glGenVertexArrays(1, &m_renderID));
    }

    Array::~Array() {
        gl(glDeleteVertexArrays(1, &m_renderID));
    }

    void Array::addbuffer(const Buffer& vb, const Layout& layout) {
        bind();
        vb.bind();
        const auto elements = layout.m_elements_get();
        unsigned int offset = 0;
        for (unsigned int i = 0; i < elements.size(); i++) {
            const auto& element = elements[i];
            glEnableVertexAttribArray(0);
            glVertexAttribPointer(i, element.count, element.type, 
                element.normalized, layout.m_stride_get(), (const void*)offset);
            offset += element.count * element::getSizeOfType(element.type);
        }

    }

    void Array::bind() const {
        gl(glBindVertexArray(m_renderID));
    }

    void Array::unbind() const {
        gl(glBindVertexArray(0));
    }

}

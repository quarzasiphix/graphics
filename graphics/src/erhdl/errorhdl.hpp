#pragma once
#include "common.hpp"

namespace gl {
    struct errorHandler {

        void clear() {
            while (glGetError() != GL_NO_ERROR);
        }

        void check() {
            //runs while error is not false
            while (GLenum error = glGetError()) {
                //loger();
                //std::cout << erlog + error << std::endl;
            }
        }
    };
};
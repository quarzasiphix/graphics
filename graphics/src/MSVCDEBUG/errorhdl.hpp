#pragma once
#include <Windows.h>
#include "common.hpp"
#ifdef msvcopengl
#define ASSERT(x) if(!(x)) __debugbreak();
#endif // msvcopengl
#define gl(x) glerclear();\
    x;\
    ASSERT(glercheck(#x, __FILE__, __LINE__))

void glerclear();
bool glercheck(const char* function, const char* file, int line);

/*
* 
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
};*/
#include <app.hpp>

void glerclear() {
    while (glGetError() != GL_NO_ERROR);
}
bool glercheck(const char* function, const char* file, int line) {
    //runs while error is not false
    while (GLenum error = glGetError()) {
        std::cout << "[OGLER]: (" << error << ")" << function <<
            " " << file << ":" << line << std::endl;
        return false;
    } return true;
}

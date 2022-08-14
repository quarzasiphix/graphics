#include <app.hpp>
int main(void)
{
    GLFWwindow* window;

    /* Initialize the library */
    if (!glfwInit())
        return -1;

    /* Create a windowed mode window and its OpenGL context */
    window = glfwCreateWindow(640, 480, "Hello World", NULL, NULL);
    if (!window)
    {
        glfwTerminate();
        return -1;
    }

    /* Make the window's context current */
    glfwMakeContextCurrent(window);

    GLenum err = glewInit();
    if(GLEW_OK != err) {
        std::cerr << "fucked up: " << glewGetErrorString(err) << std::endl;
    }

    std::cout << glGetString(GL_VERSION) << std::endl;

    {
        float positions[] = {
           //left
           -0.5f, -0.5f,
           //top
            0.5f, -0.5f,
           //rgiht
            0.5f,  0.5f,
        
            //-0.5f,  0.5f
        
        };

        unsigned int indices[]{
            0, 1, 2,
            2, 3, 0
        };

        unsigned int vao;
        gl(glGenVertexArrays(1, &vao));
        gl(glBindVertexArray(vao));

        vertex::Array va;
        vertex::Buffer vb(positions, 4 * 2 * sizeof(float));

        vertex::Layout layout;
        layout.Push<float>(2);
        va.addbuffer(vb, layout);

        index::Buffer ib(indices, 6);

        shader::basic basicShader("shaders/basic.shader");

        gl(int location = glGetUniformLocation(basicShader.program, "u_Color"));
        ASSERT(location != -1);
        gl(glUniform4f(location, 0.5, 0.0, 1.0, 1.0));

        gl(glBindVertexArray(0));
        gl(glUseProgram(0));
        gl(glBindBuffer(GL_ARRAY_BUFFER, 0));
        gl(glBindBuffer(GL_ELEMENT_ARRAY_BUFFER, 0));

        /* Loop until the user closes the window */
        while (!glfwWindowShouldClose(window))
        {
            /*render type*/
            gl(glClear(GL_COLOR_BUFFER_BIT));

            gl(glUseProgram(shader));
            gl(glUniform4f(location, 0.5, 0.0, 1.0, 1.0));

            gl(va.bind());
            gl(ib.bind());

            gl(glDrawElements(GL_TRIANGLES, 6, GL_UNSIGNED_INT, nullptr));

            gl(glfwSwapBuffers(window));

            /* Poll for and process events */
            glfwPollEvents();
        }
        //glDeleteProgram(shader);
    }

    glfwTerminate();
    return 0;
}

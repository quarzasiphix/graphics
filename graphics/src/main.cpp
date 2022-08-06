#include <app.hpp>

struct shaderProgramSource {
    std::string Vertex;
    std::string Fragment;
};

static shaderProgramSource parseShader(const std::string& filepath)
{
    std::ifstream stream(filepath);

    enum class shaderType
    {
        NONE = -1, VERTEX = 0, FRAGMENT = 1
    };

    shaderType type = shaderType::NONE;
    std::stringstream ss[2];
    std::string line;
    while (getline(stream, line))
    {
        if(line.find("shader") != std::string::npos)
        {
            if(line.find("vertex") != std::string::npos)
                type = shaderType::VERTEX;
            else if (line.find("fragment") != std::string::npos)
                type = shaderType::FRAGMENT;
        }
        else {
            ss[(int)type] << line << '\n';
        }
    }

    return { ss[0].str(), ss[1].str() };
}

static unsigned int compileShader(unsigned int type, const std::string& source)
{
    unsigned int id = glCreateShader(type);

    const char* src = source.c_str(); 
    glShaderSource(id, 1, &src, nullptr);
    glCompileShader(id);

    int result;
    glGetShaderiv(id, GL_COMPILE_STATUS, &result);
    if (result == GL_FALSE)
    {
        int length;
        glGetShaderiv(id, GL_INFO_LOG_LENGTH, &length);
        GLchar* message = new GLchar[length + 1];
        glGetShaderInfoLog(id, length, &length, message);

        std::cout << "failed to compile" << std::endl <<
            (type == GL_VERTEX_SHADER ? "vertex" : "fragment") << " shader" 
            << std::endl;
        std::cout << message << std::endl;
        glDeleteShader(id);

        return 0;
    }

    return id;
}

static unsigned int CreateShader(const std::string& vertexShader, const std::string& fragmentShader)
{
    unsigned int program = glCreateProgram();
    unsigned int vs = compileShader(GL_VERTEX_SHADER, vertexShader);
    unsigned int fs = compileShader(GL_FRAGMENT_SHADER, fragmentShader);

    glAttachShader(program, vs);
    glAttachShader(program, fs);

    glLinkProgram(program);
    glValidateProgram(program);

    //glDeleteShader(vs);
    //glDeleteShader(fs);

    return program;
}
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
           -0.5f, -0.5f,
            0.5f, -0.5f,
            0.5f,  0.5f,
           -0.5f,  0.5f
        };

        unsigned int indices[]{
            0, 1, 2,
            2, 3, 0
        };

        unsigned int vao;
        glGenVertexArrays(1, &vao);
        glBindVertexArray(vao);

        vertexBuffer vb(positions, 4 * 2 * sizeof(float));

        glEnableVertexAttribArray(0);
        glVertexAttribPointer(0, 2, GL_FLOAT, GL_FALSE, sizeof(float) * 2, 0);
         
        indexBuffer ib(indices, 6);

        shaderProgramSource shaderSource = parseShader("shaders/basic.shader");
        unsigned int shader = CreateShader(shaderSource.Vertex, shaderSource.Fragment);
        glUseProgram(shader);

        gl(int location = glGetUniformLocation(shader, "u_Color"));
        ASSERT(location != -1);
        gl(glUniform4f(location, 0.5, 0.0, 1.0, 1.0));


        /* Loop until the user closes the window */
        while (!glfwWindowShouldClose(window))
        {
            /*render type*/
            gl(glClear(GL_COLOR_BUFFER_BIT));

            gl(glUseProgram(shader));
            gl(glUniform4f(location, 0.5, 0.0, 1.0, 1.0));

            gl(glBindVertexArray(vao));
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

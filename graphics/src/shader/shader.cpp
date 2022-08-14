#include <app.hpp>
shader::basic::sources shader::basic::parse(std::string& filepath) {
    std::ifstream stream(filepath);
    std::stringstream ss[2];
    type shader = type::NONE;
    std::string line;
    while (getline(stream, line)) {
        if (line.find("shader") != std::string::npos) {
            if (line.find("vertex") != std::string::npos)
                shader = type::VERTEX;
            else if (line.find("fragment") != std::string::npos)
                shader = type::FRAGMENT;
        }
        else {
            ss[(int)shader] << line << '\n';
        }
    }

    return { ss[0].str(), ss[1].str() };
}

unsigned int shader::basic::compile(unsigned int type, const std::string& source) {
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

unsigned int shader::basic::create()
{
    unsigned int program = glCreateProgram();
    unsigned int vs = compile(GL_VERTEX_SHADER, source.vertex);
    unsigned int fs = compile(GL_FRAGMENT_SHADER, source.fragment);

    glAttachShader(program, vs);
    glAttachShader(program, fs);

    glLinkProgram(program);
    glValidateProgram(program);

    glDeleteShader(vs);
    glDeleteShader(fs);

    return program;
}

shader::basic::basic(std::string filepath) : m_filepath(filepath) {
    source = parse(filepath);
    program = create();
    gl(glUseProgram(program));
}

shader::basic::~basic() {
    gl(glDeleteProgram(program));
}


/*#include "shader.hpp"

gl::shader::shaders gl::shader::parser::parse(std::string filepath) {
    std::ifstream stream(filepath);

    enum class shaderType
    {
        NONE = -1, VERTEX = 0, FRAGMENT = 1
    };

    //unsigned int shaders = shader;
    shaderType type = shaderType::NONE;
    std::stringstream ss[2];
    std::string line;
    while (getline(stream, line))
    {
        if (line.find("shader") != std::string::npos)
        {
            if (line.find("vertex") != std::string::npos)
                type = shaderType::VERTEX;
            else if (line.find("fragment") != std::string::npos)
                type = shaderType::FRAGMENT;
        }
        else ss[(int)type] << line << '\n';
    }
    
    

    return { ss[0].str(), ss[1].str() };
}


//compile shader from source function (specific source format)
bool gl::shader::compile::build(unsigned int type)
{
    id = glCreateShader(type);
 
    //glShaderSource(id, 1, &src, nullptr);
    glCompileShader(id);
    glGetShaderiv(id, GL_COMPILE_STATUS, &result);
    if (result == GL_FALSE)
        //compres = compile result
        compres(type);
    return true;
}

unsigned int gl::shader::compile::compres(unsigned int type)
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


gl::shader::load::load()
{
    /*
    glAttachShader(program, vs);
    glAttachShader(program, fs);

    glLinkProgram(program);
    glValidateProgram(program);

    glDeleteShader(vs);
    glDeleteShader(fs);

    glUseProgram(shader);
    
}*/
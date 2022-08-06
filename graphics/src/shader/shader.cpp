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


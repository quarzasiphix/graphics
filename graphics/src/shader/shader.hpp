#pragma once
#include <common.hpp>
class shader {
public:
    class basic {
        unsigned int compile(unsigned int type, const std::string& source);
        unsigned int create();
    public:
        std::string m_filepath;
        unsigned int program;
        struct sources {
            std::string vertex = "vertex";
            std::string fragment = "fragment";
        };
        enum class type {
            NONE = -1,
            VERTEX = 0,
            FRAGMENT = 1
        };
        sources source;
        basic::sources parse(std::string& source);
        basic(std::string filepath);
        ~basic();
    };
};

/*
namespace gl {
    struct shader {
        unsigned int program,
            vs, fs, shader;
        struct shaders {
            std::string vertex, fragment;
        };

        shaders shader;
        struct parser {
            std::string filepath;
            shaders parse(std::string filepath);
        };
        /struct source {
            shaders sources;
            std::string filepath;
            void parse(const std::string& filepath);
            source(std::string filepath) : filepath(filepath) {
                parse(filepath);
            }
        };
        struct compile {
            parser parser;
            int result;
            unsigned int id, shaders;
            compile(std::string source) {
                parser.parse(source);
                
            }
            bool build(unsigned int type);
            //compres = compile result
            unsigned int compres(unsigned int type);
        };

        struct load {
            compile* comp;
            load();
            //load(const char* vertexShader, const char* fragmentShader);
        };
    };
}
*/
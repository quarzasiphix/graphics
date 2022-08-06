#pragma once
#include "common.hpp"

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
#pragma once
#include <GL/glew.h>
#include <iostream>
#include <fstream>
#include <sstream>
#define SHADER_PATH_DIR std::string("../res/")


class Shader {
public:

    Shader(const std::string& filePath);

    void applyShader();

    unsigned int getID() const;

    const std::string& getPath(); 

    ~Shader();

private:

    struct ShaderProgramSource {
        std::string VertexSource;
        std::string FragmentSource;
    } source;
    
    ShaderProgramSource parseShader(const std::string& filePath);

    unsigned int CompileShader(unsigned int type, const std::string& source);

    unsigned int CreateShader(const std::string& vertexShader, const std::string& fragmentShader);

    unsigned int shaderID;

    const std::string shaderPath;

};


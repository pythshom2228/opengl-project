#pragma once
#include <glm/glm.hpp>
#include <array>
#include "Shaders.h"



struct Cube {

    static struct {
        unsigned int VAO;
        unsigned int VBO;
        unsigned int EBO;
    } buffer;

    static unsigned int textureID;

    glm::vec3 position;
    glm::mat4 rotation{1.0f};

    static const std::array<float,120> vertexes;
    static const std::array<unsigned int,36> indices;

};

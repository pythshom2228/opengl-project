#pragma once
#include <glm/glm.hpp>
#include <array>
#include "Shaders.h"


struct Cube {
    enum types {
        DIRT = 1,
        GRASS = 2,
        STONE = 3
    };

    Cube(const types& typeID);

    void setPosition(glm::vec3 pos);

    glm::vec3& getPosition();

    const types& getTypeID() const;

    
    static const std::array<float,120> vertexes;
    static const std::array<unsigned int,36> indices;



    static struct {
        unsigned int VAO;
        unsigned int VBO;
        unsigned int EBO;
    } buffer;

    glm::mat4 rotation{1.0f};
private:


    glm::vec3 _position;
    glm::mat4 _textureArea;
    const types _typeID;
    

};

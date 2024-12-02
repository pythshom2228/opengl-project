#pragma once
#include <glm/glm.hpp>
#include <array>
#include "Shaders.h"


struct Cube {
    enum types {
        NONE = 0,
        DIRT,
        GRASS,
        STONE
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
        const std::int8_t positionCoordsNum = 3;
        const std::int8_t textureCoordsNum = 2;
    } buffer;

    glm::mat4 rotation{1.0f};
private:


    glm::vec3 _position;
    const types _typeID;
    

};

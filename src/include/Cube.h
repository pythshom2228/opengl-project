#pragma once
#include <glm/glm.hpp>
#include <array>
#include "Shaders.h"
#include "Texture.h"


struct Cube {
    Cube(const unsigned int& typeID);

    void setPosition(glm::vec3 pos);

    glm::vec3& getPosition() {
        return _position;
    }
    const unsigned int getTypeID() const;

    
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
    const unsigned int _typeID;
    

};

#include "../include/Cube.h"
#include <glm/gtc/matrix_transform.hpp>

Cube::Cube(const types& typeID) 
    : _typeID(typeID),
    _currentRenderSides({
        {sides::front,buffer.EBO[sides::front]},
        {sides::back,buffer.EBO[sides::back]},
        {sides::top,buffer.EBO[sides::top]},
        {sides::bottom,buffer.EBO[sides::bottom]},
        {sides::right,buffer.EBO[sides::right]},
        {sides::left,buffer.EBO[sides::left]}
    })
    {}
    
Cube::buffer_t Cube::buffer = {};

void Cube::setPosition(glm::vec3 pos) {
    this->_position = pos;
}

glm::vec3& Cube::getPosition() {
    return _position;
}

const Cube::types& Cube::getTypeID() const {
    return this->_typeID;
}

const std::array<float,120> Cube::vertexes = {
//      x     y    z      S    T
     0.5f,  0.5f, -0.5f,  -0.5f,-0.5f, // 0
     0.5f, -0.5f, -0.5f,  -0.5f,0.0f, // 1
    -0.5f, -0.5f, -0.5f,  0.0f,0.0f, // 2
    -0.5f,  0.5f, -0.5f,  0.0f,-0.5f, // 3

     0.5f,   0.5f, 0.5f, -0.5f,-0.5f,   // 4
     0.5f,  -0.5f, 0.5f, -0.5f,0.0f,   // 5
    -0.5f,  -0.5f, 0.5f, 0.0f,0.0f,   // 6
    -0.5f,   0.5f, 0.5f, 0.0f,-0.5f,    // 

    0.5f,  0.5f, -0.5f, -0.5f,-0.5f, // 8
    0.5f, -0.5f, -0.5f, -0.5f,0.0f, // 9
    0.5f, -0.5f,  0.5f, 0.0f,0.0f, // 10
    0.5f,  0.5f,  0.5f, 0.0f,-0.5f, // 11

    -0.5f,  0.5f, -0.5f, -0.5f,-0.5f,   // 12
    -0.5f, -0.5f, -0.5f, -0.5f,0.0f,   // 13
    -0.5f, -0.5f, 0.5f,  0.0f,0.0f,   // 14
    -0.5f,  0.5f, 0.5f,  0.0f,-0.5f,    // 15

     0.5f,  0.5f, -0.5f,  -0.5f,0.5f, // 16
     0.5f,  0.5f,  0.5f,  -0.5f,0.0f, // 17
    -0.5f,  0.5f,  0.5f,  0.0f,0.0f, // 18
    -0.5f,  0.5f, -0.5f,  0.0f,0.5f, // 19

     0.5f, -0.5f, -0.5f,  0.5f, 0.5f,   // 20
     0.5f, -0.5f,  0.5f,  0.5f, 0.0f,   // 21
    -0.5f, -0.5f,  0.5f,  0.0f, 0.0f,   // 22
    -0.5f, -0.5f, -0.5f,  0.0f, 0.5f    // 23
};


const Cube::index_t Cube::indices[] {
    {
        .side = sides::front,
        .elements = {
            4,5,6,
            4,6,7
        }
    },

    {
        .side = sides::back,
        .elements = {
            0,1,3,
            1,2,3
        }
    },

    {
        .side = sides::top,
        .elements = {
            16,17,19,
            17,18,19
        }
    },

    {
        .side = sides::bottom,
        .elements = {
            20,21,23,
            21,22,23
        }
    },

    {
        .side = sides::right,
        .elements = {
            8,9,11,
            9,10,11
        }
    },

    {
        .side = sides::left,
        .elements = {
            12,13,15,
            13,14,15
        }
    }
};


void Cube::popRenderSide(sides side) {
    this->_currentRenderSides.erase(side);
}

void Cube::pushRenderSide(sides side) {
    this->_currentRenderSides.insert({side,buffer.EBO[side]});
}


std::unordered_map<Cube::sides,const unsigned int>& Cube::getCurrentRendrSides() {
    return this->_currentRenderSides;
}

void Cube::setModelMatrix() {
    if(!isModelMatrixChanged) {
        _modelMatrix = glm::translate(glm::mat4(1.0),this->_position);
        isModelMatrixChanged = 1;
    }
}

const glm::mat4& Cube::getModelMatrix() {
    return _modelMatrix;
}
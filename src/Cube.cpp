#include "include/Cube.h"

Cube::Cube(const types& typeID) : _typeID(typeID) {}

decltype(Cube::buffer) Cube::buffer = {};

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

const std::array<unsigned int,36> Cube::indices = {
    0,1,3,
    1,2,3,

    4,5,6,
    4,6,7,

    8,9,11,
    9,10,11,

    12,13,15,
    13,14,15,

    16,17,19,
    17,18,19,

    20,21,23,
    21,22,23
};

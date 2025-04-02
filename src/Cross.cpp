#include "../include/Cross.h"

 const std::array<float,16> Cross::vertexes = {
    0.5f,0.1f,
    -0.5f,0.1f, 
    -0.5f,-0.1f,
    0.5f,-0.1f,
    
    0.1f,0.6f, 
    -0.1f,0.6f, 
    -0.1f,-0.6f, 
    0.1f,-0.6f
};


const std::array<unsigned int, 12> Cross::indices = {
    0,1,2,
    0,2,3,

    4,5,6,
    4,6,7
};

decltype(Cross::buffer) Cross::buffer = {};

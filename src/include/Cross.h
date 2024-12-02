#include <array> 
#include <cstdint>

struct Cross {        
    static const std::array<float,16> vertexes;
    static const std::array<unsigned int,12> indices;

    static struct {
        unsigned int VAO;
        unsigned int VBO;
        unsigned int EBO;
        const std::int8_t positionCoordsNum = 2;
    } buffer;

};

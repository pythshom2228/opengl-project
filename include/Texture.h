#pragma once
#include <GL/glew.h>
#include <glm/glm.hpp>
#include <string>
#include <memory>
#include <unordered_map>
#include "Cube.h"

class Texture {
public:

    Texture() = default;

    Texture(const Cube::types& textureType);

    ~Texture();

    std::unique_ptr<unsigned int>& getID();

    static std::unordered_map<Cube::types,const std::string> textureMap;

private:
    std::unique_ptr<unsigned int> _textureID;
};

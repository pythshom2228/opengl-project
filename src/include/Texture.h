#pragma once
#include <GL/glew.h>
#include <glm/glm.hpp>
#include <string>
#include <memory>
#include <unordered_map>

class Texture {
public:
    enum types {
        DIRT = 1,
        GRASS = 2,
        STONE = 3
    };

    Texture() = default;

    Texture(const types& textureType);

    ~Texture();

    const std::string& getPath() const;

    static std::unique_ptr<unsigned int>& getID();

private:
    static const std::unordered_map<unsigned int,glm::mat4&> textureMap;


    void selectTexture(const unsigned int& textureType);
    int b = 1;
    static std::string _texturePath;
    static std::unique_ptr<unsigned int> _textureID;
};

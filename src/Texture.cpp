#include "../include/Texture.h"
#include <iostream>
#include <stb_image.h>


Texture::Texture(const Cube::types& textureType) {
    _textureID = std::make_unique<unsigned int>();
    int width,height,nrChannels;
    stbi_set_flip_vertically_on_load(true);
    unsigned char* datatexture = stbi_load(Texture::textureMap[textureType].c_str(),&width,&height,&nrChannels,0);
    glGenTextures(1, &(*_textureID));

    glBindTexture(GL_TEXTURE_2D, *_textureID);


    if (datatexture){
        glTexImage2D(GL_TEXTURE_2D,0,GL_RGBA8,width,height,0,GL_RGB,GL_UNSIGNED_BYTE,datatexture);
        glGenerateMipmap(GL_TEXTURE_2D);
    }
    else std::cout << "Failed to load texture" << "\n";


    glTexParameteri(GL_TEXTURE_2D, GL_TEXTURE_WRAP_S, GL_REPEAT);
    glTexParameteri(GL_TEXTURE_2D, GL_TEXTURE_WRAP_T, GL_REPEAT);
    glTexParameteri(GL_TEXTURE_2D, GL_TEXTURE_MIN_FILTER, GL_LINEAR_MIPMAP_LINEAR);
    glTexParameteri(GL_TEXTURE_2D, GL_TEXTURE_MAG_FILTER, GL_LINEAR);
    glTexParameteri(GL_TEXTURE_2D,GL_TEXTURE_MAX_ANISOTROPY_EXT,8);

    glBindTexture(GL_TEXTURE_2D,0);
    stbi_image_free(datatexture);
    
}

Texture::~Texture() {
    glDeleteTextures(1,this->_textureID.get());
}

std::unique_ptr<unsigned int>& Texture::getID() {
    return _textureID;
}



std::unordered_map<Cube::types,const std::string> Texture::textureMap = {
    {Cube::DIRT,"../res/textures/dirt.jpg"},
    {Cube::GRASS,"../res/textures/grass.jpg"},
    {Cube::COBBLESTONE,"../res/textures/cobblestone.jpg"},
    {Cube::PLANKS,"../res/textures/planks.jpg"}
};

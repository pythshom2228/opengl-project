#include "include/Texture.h"
#include <iostream>
#include <stb_image.h>


Texture::Texture(const Texture::types& textureType) {
        glEnable(GL_TEXTURE_3D);
        glGenTextures(1, &(*_textureID));
        glBindTexture(GL_TEXTURE_2D_ARRAY, *_textureID);
        glTexParameteri(GL_TEXTURE_2D, GL_TEXTURE_WRAP_S, GL_REPEAT);
        glTexParameteri(GL_TEXTURE_2D, GL_TEXTURE_WRAP_T, GL_REPEAT);
        glTexParameteri(GL_TEXTURE_2D, GL_TEXTURE_MIN_FILTER, GL_LINEAR_MIPMAP_LINEAR);
        glTexParameteri(GL_TEXTURE_2D, GL_TEXTURE_MAG_FILTER, GL_LINEAR);
        glTexParameteri(GL_TEXTURE_2D,GL_TEXTURE_MAX_ANISOTROPY_EXT,8);

        stbi_set_flip_vertically_on_load(true);
        int width,height,nrChannels;
        unsigned char* datatexture = stbi_load(_texturePath.c_str(),&width,&height,&nrChannels,0);

        if (datatexture)
        {
            glTexImage2D(GL_TEXTURE_2D, 0, GL_RGB, width, height, 0, GL_RGB, GL_UNSIGNED_BYTE, datatexture);
            glGenerateMipmap(GL_TEXTURE_2D);
        }
        else
        {
            std::cout << "Failed to load texture" << std::endl;
        }
        stbi_image_free(datatexture);
        selectTexture(textureType);
}

Texture::~Texture() {
    glDeleteTextures(1,this->_textureID.get());
}

const std::string& Texture::getPath() const {
    return this->_texturePath;
}

std::unique_ptr<unsigned int>& Texture::getID() {
    return _textureID;
}

void Texture::selectTexture(const unsigned int& textureType) {

}


std::string Texture::_texturePath = "../res/textures/grass.jpg";

const std::unordered_map<unsigned int,glm::mat4&> Texture::textureMap = 
{
};

std::unique_ptr<unsigned int> Texture::_textureID = std::make_unique<unsigned int>(); 

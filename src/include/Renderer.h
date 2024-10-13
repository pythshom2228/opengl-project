#pragma once
#include <iostream>
#include <vector>
#include <unordered_map>

#include <glm/glm.hpp>
#include <glm/gtc/matrix_transform.hpp>
#include <glm/gtc/type_ptr.hpp>

#include <GL/glew.h>

#include "Cube.h"
#include "Shaders.h"
#include "Camera.h"


class Renderer {
public:
    Renderer(std::vector<Cube>* renderObjectsptr,Camera* _cameraptr);

    ~Renderer();

    void render();
    

private:

    Camera* _cameraptr;
    std::unordered_map<std::string,Shader> _shaders;
    std::vector<Cube>* _renderObjectsptr;
};
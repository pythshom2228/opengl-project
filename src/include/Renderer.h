#pragma once
#include <iostream>
#include <cmath>
#include <vector>
#include <unordered_map>
#include <GL/glew.h>
#include "Cube.h"
#include <glm/glm.hpp>
#include <glm/gtc/matrix_transform.hpp>
#include <glm/gtc/type_ptr.hpp>
#include "Shaders.h"
#include "Camera.h"


class Renderer {
public:
    Renderer(std::vector<Cube>* renderObjectsptr);

    ~Renderer();

    void render();
    

private:
    Camera _camera;
    std::unordered_map<std::string,Shader> _shaders;
    std::vector<Cube>* _renderObjectsptr;
};
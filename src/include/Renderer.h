#pragma once
#include <iostream>
#include <cmath>
#include <vector>
#include <unordered_map>
#include <GL/glew.h>
#include "Cube.h"
#include "Shaders.h"
#include "Camera.h"


class Renderer {
public:

    Renderer(std::vector<Cube>* renderObjectsptr);

    ~Renderer();

    void render();
    

private:
    Camera _camera;
    size_t _currentObjectsNum;
    std::vector<Cube>* _renderObjectsptr;
};
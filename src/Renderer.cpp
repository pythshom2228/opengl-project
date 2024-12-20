#include "include/Renderer.h"

Renderer::Renderer(std::vector<Cube>* renderObjectsptr,Camera* cameraptr)
 : _renderObjectsptr(renderObjectsptr), _cameraptr(cameraptr) {

    glEnable(GL_DEPTH_TEST);

    glewExperimental = GL_TRUE;
    
    if(GLEW_OK != glewInit())
        std::cout << "Failed to initialize GLEW" << "\n";
    
    std::cout << glGetString(GL_VERSION) << "\n";
    
    this->generateCubeBuffer();
    this->generateCrossBuffer();

    _shaders.emplace("basic",SHADER_PATH_DIR + "basic.shader");
    _shaders.emplace("cross", SHADER_PATH_DIR + "cross.shader");
    glUseProgram(_shaders["basic"].getID());
    
    for(auto& [cubeType,path] : Texture::textureMap) 
    {
        _textures.emplace(cubeType,cubeType);
        if(cubeType != Cube::types::NONE) {
            glUniform1i(glGetUniformLocation(_shaders["basic"].getID(), "border"),1);
        }
        else {
            glUniform1i(glGetUniformLocation(_shaders["basic"].getID(), "baseTexture"),0);
        }
    }

}

Renderer::~Renderer() {
    glDeleteVertexArrays(1, &Cube::buffer.VAO);
    glDeleteBuffers(1, &Cube::buffer.VBO);
    for(auto& EBO : Cube::buffer.EBO)
    glDeleteBuffers(1, &EBO);
}

void Renderer::render() {
    glClearColor(1.0f,1.0f,1.0f,1.0f);
    glClear(GL_COLOR_BUFFER_BIT | GL_DEPTH_BUFFER_BIT);


    glActiveTexture(GL_TEXTURE0);
    glUseProgram(_shaders["basic"].getID());

    _cameraptr->projection = 0;
    _cameraptr->view =  glm::lookAt(_cameraptr->cameraPos, _cameraptr->cameraPos + _cameraptr->cameraFront, _cameraptr->cameraUp), 
    _cameraptr->projection = glm::perspective(glm::radians(_cameraptr->zoom), 1200.0f / 800.0f, 0.1f, 1000.0f);

    glUniformMatrix4fv(glGetUniformLocation(_shaders["basic"].getID(),"projection"),1,GL_FALSE,glm::value_ptr(_cameraptr->projection));
    glUniformMatrix4fv(glGetUniformLocation(_shaders["basic"].getID(),"view"),1,GL_FALSE,glm::value_ptr(_cameraptr->view));

    glBindVertexArray(Cube::buffer.VAO);
    for(auto& cube : *_renderObjectsptr) {
        _cameraptr->model = {1.0};
        _cameraptr->model = glm::translate(_cameraptr->model,cube.getPosition());
        
        glUniformMatrix4fv(glGetUniformLocation(_shaders["basic"].getID(),"model"),1,GL_FALSE,glm::value_ptr(_cameraptr->model));

        glBindVertexArray(cube.buffer.VAO);
        glBindTexture(GL_TEXTURE_2D,*_textures[cube.getTypeID()].getID());
        for(const auto& [side,EBO] : cube.getCurrentRendrSides()) {
            glBindBuffer(GL_ELEMENT_ARRAY_BUFFER,EBO);
            glDrawElements(GL_TRIANGLES, Cube::indices[Cube::front].elements.size(), GL_UNSIGNED_INT, 0);
        }
    }

    glUseProgram(_shaders["cross"].getID());
    glBindVertexArray(Cross::buffer.VAO);
    glDrawElements(GL_TRIANGLES,Cross::indices.size(),GL_UNSIGNED_INT,0);
}

Cross Renderer::cursor = {};

void Renderer::generateCubeBuffer() {
    const std::int8_t cubePosCoords = Cube::buffer.positionCoordsNum;
    const std::int8_t cubeTextureCoords = Cube::buffer.textureCoordsNum;
    const std::int8_t stride = cubePosCoords + cubeTextureCoords;

    glGenVertexArrays(1, &Cube::buffer.VAO);
    glGenBuffers(1, &Cube::buffer.VBO);
    for(auto& EBO : Cube::buffer.EBO)
        glGenBuffers(1, &EBO);

    glBindVertexArray(Cube::buffer.VAO);

    glBindBuffer(GL_ARRAY_BUFFER,Cube::buffer.VBO);
    glBufferData(GL_ARRAY_BUFFER, sizeof(Cube::vertexes[0]) * Cube::vertexes.size(), Cube::vertexes.data(), GL_STATIC_DRAW);

    //glBindBuffer(GL_ELEMENT_ARRAY_BUFFER, Cube::buffer.EBO[Cube::sides::back]);
    //glBufferData(GL_ELEMENT_ARRAY_BUFFER,sizeof(Cube::indices[Cube::sides::back].elements[0])*Cube::indices[Cube::sides::back].elements.size(),Cube::indices[Cube::sides::back].elements.data(),GL_STATIC_DRAW);
    for(std::size_t next = 0; next < CUBE_SIDES; next++) {
        glBindBuffer(GL_ELEMENT_ARRAY_BUFFER, Cube::buffer.EBO[next]);
        glBufferData(
            GL_ELEMENT_ARRAY_BUFFER, 
            sizeof(Cube::indices[next].elements[0])*Cube::indices[next].elements.size(),
            Cube::indices[Cube::sides::front+next].elements.data(),
            GL_STATIC_DRAW
        );
    }

    glVertexAttribPointer(0, cubePosCoords, GL_FLOAT, GL_FALSE, stride * sizeof(float), (void*)0);
    glEnableVertexAttribArray(0);
    
    glVertexAttribPointer(1, cubeTextureCoords, GL_FLOAT, GL_FALSE, stride * sizeof(float), (void*)(cubePosCoords * sizeof(float)));
    glEnableVertexAttribArray(1);
    
    glBindVertexArray(0);
    glBindBuffer(GL_ARRAY_BUFFER,0);
    glBindBuffer(GL_ELEMENT_ARRAY_BUFFER,0);

}

void Renderer::generateCrossBuffer() {

    const std::int8_t crossPosCoords = Cross::buffer.positionCoordsNum;

    glGenVertexArrays(1,&Cross::buffer.VAO);
    glGenBuffers(1,&Cross::buffer.VBO);
    glGenBuffers(1,&Cross::buffer.EBO);
    
    glBindVertexArray(Cross::buffer.VAO);
    glBindBuffer(GL_ARRAY_BUFFER,Cross::buffer.VBO);
    glBindBuffer(GL_ELEMENT_ARRAY_BUFFER, Cross::buffer.EBO);


    glBufferData(GL_ARRAY_BUFFER,sizeof(Cross::vertexes[0]) * Cross::vertexes.size(),Cross::vertexes.data(),GL_STATIC_DRAW);
    glBufferData(GL_ELEMENT_ARRAY_BUFFER,sizeof(Cross::indices[0]) * Cross::indices.size(),Cross::indices.data(),GL_STATIC_DRAW);

    glVertexAttribPointer(0,crossPosCoords,GL_FLOAT,GL_FALSE, crossPosCoords *sizeof(float),(void*)0);
    glEnableVertexAttribArray(0);


    glBindVertexArray(0);
    glBindBuffer(GL_ARRAY_BUFFER,0);
    glBindBuffer(GL_ELEMENT_ARRAY_BUFFER,0);
}


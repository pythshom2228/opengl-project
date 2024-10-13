#include "include/Renderer.h"
#include <stb_image.h>

Renderer::Renderer(std::vector<Cube>* renderObjectsptr,Camera* cameraptr)
 : _renderObjectsptr(renderObjectsptr), _cameraptr(cameraptr) {

    glEnable(GL_DEPTH_TEST);

    glewExperimental = GL_TRUE;
    
    if(GLEW_OK != glewInit())
        std::cout << "Failed to initialize GLEW" << "\n";
    
    #ifdef _DEBUG
        std::cout << glGetString(GL_VERSION) << "\n";
    #endif

    
    _shaders.emplace("basic",SHADER_PATH_DIR + "basic.shader");

    glGenVertexArrays(1, &Cube::buffer.VAO);
    glGenBuffers(1, &Cube::buffer.VBO);
    glGenBuffers(1, &Cube::buffer.EBO);

    glBindVertexArray(Cube::buffer.VAO);

    glBindBuffer(GL_ARRAY_BUFFER,Cube::buffer.VBO);
    glBindBuffer(GL_ELEMENT_ARRAY_BUFFER, Cube::buffer.EBO);

    glBufferData(GL_ARRAY_BUFFER, sizeof(Cube::vertexes), Cube::vertexes.data(), GL_STATIC_DRAW);
    glBufferData(GL_ELEMENT_ARRAY_BUFFER, sizeof(Cube::indices), Cube::indices.data(), GL_STATIC_DRAW);


    glVertexAttribPointer(0, 3, GL_FLOAT, GL_FALSE, 5 * sizeof(float), (void*)0);
    glEnableVertexAttribArray(0);
    
    glVertexAttribPointer(1, 2, GL_FLOAT, GL_FALSE, 5 * sizeof(float), (void*)(3 * sizeof(float)));
    glEnableVertexAttribArray(1);

    glGenTextures(1,&Cube::textureID);
    glBindTexture(GL_TEXTURE_2D,Cube::textureID);
    glTexParameteri(GL_TEXTURE_2D, GL_TEXTURE_WRAP_S, GL_REPEAT);
    glTexParameteri(GL_TEXTURE_2D, GL_TEXTURE_WRAP_T, GL_REPEAT);
    glTexParameteri(GL_TEXTURE_2D, GL_TEXTURE_MIN_FILTER, GL_LINEAR_MIPMAP_LINEAR);
    glTexParameteri(GL_TEXTURE_2D, GL_TEXTURE_MAG_FILTER, GL_LINEAR);

    int width,height,nrChannels;
    unsigned char* datatexture = stbi_load("../res/textures/dirt.jpg",&width,&height,&nrChannels,0);

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

    glUniform1i(glGetUniformLocation(_shaders["basic"].getID(), "texture1"),1);
}

Renderer::~Renderer() {
    glDeleteVertexArrays(1, &Cube::buffer.VAO);
    glDeleteBuffers(1, &Cube::buffer.VBO);
    glDeleteBuffers(1, &Cube::buffer.EBO);
    glDeleteProgram(_shaders["basic"].getID());
    glDeleteTextures(1,&Cube::textureID);

}

void Renderer::render() {
    glClearColor(1.0f,1.0f,1.0f,1.0f);
    glClear(GL_COLOR_BUFFER_BIT | GL_DEPTH_BUFFER_BIT);


    glActiveTexture(GL_TEXTURE0);
    glBindTexture(GL_TEXTURE_2D,Cube::textureID);
    glUseProgram(_shaders["basic"].getID());
    
    _cameraptr->projection = 0;
    _cameraptr->view =  glm::lookAt(_cameraptr->cameraPos, _cameraptr->cameraPos + _cameraptr->cameraFront, _cameraptr->cameraUp), 
    _cameraptr->projection = glm::perspective(glm::radians(45.0f), 800.0f / 600.0f, 0.1f, 100.0f);

    glUniformMatrix4fv(glGetUniformLocation(_shaders["basic"].getID(),"projection"),1,GL_FALSE,glm::value_ptr(_cameraptr->projection));
    glUniformMatrix4fv(glGetUniformLocation(_shaders["basic"].getID(),"view"),1,GL_FALSE,glm::value_ptr(_cameraptr->view));

    glBindVertexArray(Cube::buffer.VAO);
    for(auto& cube : *_renderObjectsptr) {
        _cameraptr->model = {1.0};
        _cameraptr->model = glm::translate(_cameraptr->model,cube.position);
        //_cameraptr->model = glm::scale(_cameraptr->model,glm::vec3(0.5,0.5,0.5));
        
        glUniformMatrix4fv(glGetUniformLocation(_shaders["basic"].getID(),"model"),1,GL_FALSE,glm::value_ptr(_cameraptr->model));
        glUniformMatrix4fv(glGetUniformLocation(_shaders["basic"].getID(),"rotation"),1,GL_FALSE,glm::value_ptr(cube.rotation));


        glDrawElements(GL_TRIANGLES, Cube::indices.size(), GL_UNSIGNED_INT, 0);
    }
}

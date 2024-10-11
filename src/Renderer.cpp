#include "include/Renderer.h"

Renderer::Renderer() {
    glEnable(GL_DEPTH_TEST);

    glewExperimental = GL_TRUE;
    
    if(GLEW_OK != glewInit())
        std::cout << "Failed to initialize GLEW" << "\n";
    
    #ifdef _DEBUG
        std::cout << glGetString(GL_VERSION) << "\n";
    #endif

}

Renderer::~Renderer() {
    
}
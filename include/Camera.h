#pragma once
#include <glm/glm.hpp>
#include <glm/gtc/matrix_transform.hpp>
#include <glm/gtc/type_ptr.hpp>

struct Camera {

    Camera() = default;

    ~Camera() = default;

    glm::vec3 cameraPos         = glm::vec3(0.0f,0.0f,0.0f);
    glm::vec3 cameraFront       = glm::vec3(0.0f, 0.0f, -1.0f);
    glm::vec3 cameraUp          = glm::vec3(0.0f, 1.0f,  0.0f);
    glm::vec3 cameraRight       = glm::normalize(glm::cross(cameraUp, glm::normalize(cameraPos)));

    float yaw         =  0.0f;
    float pitch       =  0.0f;
    glm::vec3 direction;
    
    float zoom = 60.0f;
    glm::mat4 projection;
    glm::mat4 view;
    glm::mat4 model = {1.0};
};
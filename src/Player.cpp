#include "include/Player.h"
#include <iostream>

Player::Player() : hp(100) {
    
}

void Player::processInput() {
    if(_keyboard.isKeyPressed(sf::Keyboard::W)) {
        position += camera.cameraSpeed * camera.cameraFront;
        camera.cameraPos = position;
    }
    if(_keyboard.isKeyPressed(sf::Keyboard::S)) {
        position -= camera.cameraSpeed * camera.cameraFront;
        camera.cameraPos = position;
    }
    if(_keyboard.isKeyPressed(sf::Keyboard::A)) {
        position -= glm::normalize(glm::cross(camera.cameraFront, camera.cameraUp)) * camera.cameraSpeed;
        camera.cameraPos = position;
    }
    if(_keyboard.isKeyPressed(sf::Keyboard::D)) {
        position += glm::normalize(glm::cross(camera.cameraFront, camera.cameraUp)) * camera.cameraSpeed;
        camera.cameraPos = position;    
    }
    if(_keyboard.isKeyPressed(sf::Keyboard::Space)) {
        position += camera.cameraSpeed * camera.cameraUp;
        camera.cameraPos = position;
    }
    if(_keyboard.isKeyPressed(sf::Keyboard::LShift)){
        position -= camera.cameraSpeed * camera.cameraUp;
        camera.cameraPos = position;
    }
    if(_keyboard.isKeyPressed(sf::Keyboard::C)) {

    }
}

void Player::handleMouseMoves(const sf::Window& window) {
    //if(_mouse.isButtonPressed(_mouse.Left))
    //    _mouse.setPosition(window.getPosition() + sf::Vector2i(window.getSize().x/2,window.getSize().y/2));
    float xpos = _mouse.getPosition().x, ypos = _mouse.getPosition().y;


    if(camera.firstMouse) {
        camera.lastX = xpos/2;
        camera.lastY = ypos/2;
        camera.firstMouse = false;
    }


    float xoffset = xpos - camera.lastX;
    float yoffset = camera.lastY - ypos;
    camera.lastX = xpos;
    camera.lastY = ypos;

    

    xoffset *= sensitivity;
    yoffset *= sensitivity;

    camera.yaw += xoffset;
    camera.pitch += yoffset;

    if(camera.pitch > 89.0f)
        camera.pitch =  89.0f;
    if(camera.pitch < -89.0f)
        camera.pitch = -89.0f;

    glm::vec3 direction;
    direction.x = cos(glm::radians(camera.yaw)) * cos(glm::radians(camera.pitch));
    direction.y = sin(glm::radians(camera.pitch));
    direction.z = sin(glm::radians(camera.yaw)) * cos(glm::radians(camera.pitch));
    camera.cameraFront = glm::normalize(direction);

}